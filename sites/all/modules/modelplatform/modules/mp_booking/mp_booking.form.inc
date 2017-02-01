<?php

/**
 * @file
 * Model Platform Booking - Forms.
 */

/**
 * Model job invitiation form.
 */
function mp_booking_job_model_invite_form($form, &$form_state, $model_uid, $customer_uid = 0) {
  global $user;

  if (!is_numeric($customer_uid) || !$customer_uid) {
    $customer_uid = $user->uid;
  }

  $customer_job_nids = _mp_booking_get_customer_jobs($customer_uid);

  $form['job_invitation_title'] = array(
    '#type' => 'markup',
    '#markup' => '<h5 class="font-alt mb-sm-40  widget-title">'. t('Jobs') . '</h5>',
  );
  $form['model_uid'] = array(
    '#type' => 'value',
    '#value' => $model_uid,
  );

  $form['jobs'] = array(
    '#type' => 'container',
    '#tree' => TRUE,
  );

  foreach ($customer_job_nids as $delta => $nid) {
    $job = node_load($nid);
    $job_wrapper = entity_metadata_wrapper('node', $job);
    $job_teaser = node_view($job, 'teaser');

    $form['jobs'][$delta] = array(
      '#type' => 'container',
      '#tree' => TRUE,
    );

    $form['jobs'][$delta]['job_nid'] = array(
      '#type' => 'value',
      '#value' => $nid,
    );
    $form['jobs'][$delta]['job_preview'] = array(
      '#type' => 'markup',
      '#markup' => drupal_render($job_teaser),
    );
    $form['jobs'][$delta]['job_cost'] = array(
      '#type' => 'textfield',
      '#title' => t('Cost propose'),
      '#default_value' =>  $job_wrapper->field_job_daily_rate_from->value(),
    );
    $form['jobs'][$delta]['job_invite'] = array(
      '#type' => 'submit',
      '#value' => t('Send propose'),
      '#name' => "job_invite_$delta",
      '#submit' => array(
        'mp_booking_job_model_invite_form_submit',
      ),
      '#validate' => array(
        'mp_booking_job_model_invite_form_validate',
      ),
    );
  }

  $form['#validate'] = 'mp_booking_job_model_invite_form_validate';

  return $form;
}

/**
 * Form validate.
 *
 * @see mp_booking_job_model_invite_form()
 */
function mp_booking_job_model_invite_form_validate($form, &$form_state) {
  if (!isset($form_state['triggering_element']['#parents'][1])) {
    form_set_error(NULL, t('Submit Indentifier is miss.'));
  }
  else {
    $delta = $form_state['triggering_element']['#parents'][1];

    // Node check.
    if (!isset($form_state['values']['jobs'][$delta]['job_nid'])) {
      form_set_error(NULL, t('Job Indentifier is miss.'));
    }
    elseif (intval($form_state['values']['jobs'][$delta]['job_nid']) <= 0) {
      form_set_error(NULL, t('Job Indentifier is undefined.'));
    }

    // Daily rate propose.
    $min_dily_rate = variable_get('mp_model_min_daily_rate', 500);
    if (!isset($form_state['values']['jobs'][$delta]['job_cost'])) {
      form_set_error('jobs][' . $delta, t('Daily rate propose can not be empty.'));
    }
    elseif (intval($form_state['values']['jobs'][$delta]['job_cost']) < $min_dily_rate) {
      form_set_error('jobs][' . $delta, t('Daily rate propose can not be less then @daily_rate', array('@daily_rate' => $min_dily_rate)));
    }
  }
}

/**
 * Form submit.
 *
 * @see mp_booking_job_model_invite_form()
 */
function mp_booking_job_model_invite_form_submit($form, &$form_state) {
  global $user;

  $delta = $form_state['triggering_element']['#parents'][1];
  $values = $form_state['values'];

  $job_nid = $values['jobs'][$delta]['job_nid'];
  $job = node_load($job_nid);

  // Job dates check.
  if (isset($job->field_job_start_date[LANGUAGE_NONE][0]['value'])) {
    $start_date = $job->field_job_start_date[LANGUAGE_NONE][0]['value'];
  }
  else {
    return;
  }
  if (isset($job->field_job_start_date[LANGUAGE_NONE][0]['value2'])) {
    $end_date = $job->field_job_start_date[LANGUAGE_NONE][0]['value2'];
  }
  else {
    return;
  }

  // Get model unit.
  $model_account = user_load($values['model_uid']);
  $unit = _mp_booking_get_unit('user', $model_account);

  // Get unit events.
  $events = _mp_booking_get_unit_events($unit, $start_date, $end_date, 1, FALSE);

  // Check events.
  if (count($events)) {
    drupal_set_message(t('Model is already busy on this dates.'));
    return;
  }

  // Create event.
  $event_params = array(
    'type' => MP_BOOKING_MODEL_AVAILABILITY,
  );
  $event = bat_event_create($event_params);
  $event->field_job[LANGUAGE_NONE][0]['target_id'] = $job_nid;
  $event->event_bat_unit_reference[LANGUAGE_NONE][0]['target_id'] = $unit->unit_id;
  $event->event_state_reference[LANGUAGE_NONE][0]['state_id'] = MP_BOOKING_STATE_AUCTION;
  $event->start_date = $start_date;
  $event->end_date = $end_date;
  bat_event_save($event);

  // Create auction.
  module_load_include('inc', 'mp_auction', 'mp_auction_mp_auction.admin');
  $auction = mp_auction_create(array('type' => 'auction'));
  $auction->name = 'Auction uid - ' . $user->uid;
  $auction->uid = $user->uid;
  $auction->field_auction_event[LANGUAGE_NONE][0]['target_id'] = $event->event_id;
  $auction->field_auction_cost_propose[LANGUAGE_NONE][0]['value'] = $form_state['values']['jobs'][$delta]['job_cost'];
  mp_auction_save($auction);
  drupal_set_message(t('Auction was created'));

  // Redirect to the auction page.
  $link = 'job/model/' . $event->event_id . '/auction';
  $form_state['redirect'] = $link;
}

/**
 * Model job auction.
 */
function mp_booking_job_auction_form($form, &$form_state, $event = NULL) {
  global $user;

  if (isset($event->event_id) && $event->event_id) {
    // Create auction form if user is event owner.
    if ($event->uid === $user->uid) {
      module_load_include('inc', 'mp_auction', 'mp_auction_mp_auction.admin');
      $auction = mp_auction_create(array('type' => 'auction'));
      $auction->name = 'Auction event id - ' . $event->uid;
      $auction->uid = $user->uid;
      $auction->field_auction_event[LANGUAGE_NONE][0]['target_id'] = $event->event_id;
      $auction->field_auction_cost_propose[LANGUAGE_NONE][0]['value'] = $form_state['values']['field_auction_cost_propose'];
      $form = mp_auction_edit_form($form, $form_state, $auction);
    }

    $form['#event'] = $event;
    $form['job_invitation_title'] = array(
      '#type' => 'markup',
      '#markup' => '<h5 class="font-alt mb-sm-40  widget-title">'. t('New propose') . '</h5>',
    );

    $form['auctions'] = array(
      '#type' => 'container',
      '#tree' => TRUE,
    );
    $delta = 0;

    $auctions = mp_booking_get_event_auctions($event);

    foreach ($auctions as $_auction) {
      $form['auctions'][$delta] = array(
        '#type' => 'container',
        '#tree' => TRUE,
      );

      if (isset($_auction->field_auction_cost_propose[LANGUAGE_NONE][0]['value'])) {
        $form['auctions'][$delta]['cost'] = array(
          '#title' => t('Cost propose'),
          '#type' => 'markup',
          '#prefix' => '<div class="cost-propose">',
          '#markup' => $_auction->field_auction_cost_propose[LANGUAGE_NONE][0]['value'],
          '#suffix' => '</div>',
        );
      }
      if (isset($_auction->changed)) {
        $form['auctions'][$delta]['changed'] = array(
          '#title' => t('Changed'),
          '#type' => 'markup',
          '#prefix' => '<div class="date-propose">',
          '#markup' => date('Y-m-d H:i', $_auction->created),
          '#suffix' => '</div>',
        );
      }

      $form['auctions'][$delta]['auction_id'] = array(
        '#type' => 'value',
        '#value' => $_auction->mp_auction_id,
      );

      if ($_auction->field_auction_decision[LANGUAGE_NONE][0]['value']) {
        $form['auctions'][$delta]['decision'] = array(
          '#title' => t('Decision'),
          '#type' => 'markup',
          '#prefix' => '<div class="decision-propose">',
          '#markup' => $_auction->field_auction_decision[LANGUAGE_NONE][0]['value'],
          '#suffix' => '</div>',
        );
      }
      else {
        if ($_auction->uid === $user->uid) {
          $form['auctions'][$delta]['decision'] = array(
            '#title' => t('Decision'),
            '#type' => 'markup',
            '#prefix' => '<div class="decision-propose">',
            '#markup' => t('Have no decision yet.'),
            '#suffix' => '</div>',
          );
        }
        else {
          $form['auctions'][$delta]['decision'] = array(
            '#title' => t('Decision'),
            '#type' => 'container',
            '#tree' => TRUE,
            '#prefix' => '<div class="decision-propose">',
            '#suffix' => '</div>',
          );
          $form['auctions'][$delta]['decision']['accept'] = array(
            '#type' => 'submit',
            '#value' => t('Accept'),
            '#name' => 'auction_decision_' . $delta . '_accept',
            '#submit' => array(
              'mp_booking_job_auction_form_accept',
            ),
          );
          $form['auctions'][$delta]['decision']['decline'] = array(
            '#type' => 'submit',
            '#value' => t('Decline'),
            '#name' => 'auction_decision_' . $delta . '_decline',
            '#submit' => array(
              'mp_booking_job_auction_form_decline',
            ),
          );
        }
      }

      $delta++;
    }

    // Hide filled fields.
    $form['field_auction_decision']['#access'] = FALSE;
    $form['field_auction_event']['#access'] = FALSE;
    $form['name']['#access'] = FALSE;
    $form['actions']['delete']['#access'] = FALSE;

    // Available if user is event owner.
    if ($event->uid === $user->uid) {
      if ($delta < 3) {
        $form['actions']['submit']['#value'] = t('Send new propose');
        $form['actions']['submit']['#submit'][] = 'mp_booking_job_auction_form_submit';
      }
      else {
        $form['field_auction_cost_propose']['#access'] = FALSE;
        $form['actions']['submit'] = array(
          '#type' => 'markup',
          '#markup' => t('Auction limits have been reached.'),
        );
      }
    }
  }

  return $form;
}

function mp_booking_job_auction_form_accept($form, &$form_state) {
  $delta = $form_state['triggering_element']['#parents'][1];

  $auction_id = $form_state['values']['auctions'][$delta]['auction_id'];
  $auction = mp_auction_load($auction_id);
  $auction->field_auction_decision[LANGUAGE_NONE][0]['value'] = 'Accept';
  mp_auction_save($auction);

  // @TODO Move to the entity_save hook.
  $event = $form['#event'];
  $event->field_job_cost = $auction->field_auction_cost_propose;
  $event->event_state_reference[LANGUAGE_NONE][0]['state_id'] = 3;
  bat_event_save($event);
}

function mp_booking_job_auction_form_decline($form, &$form_state) {
  $delta = $form_state['triggering_element']['#parents'][1];

  $auction_id = $form_state['values']['auctions'][$delta]['auction_id'];
  $auction = mp_auction_load($auction_id);
  $auction->field_auction_decision[LANGUAGE_NONE][0]['value'] = 'Decline';
  mp_auction_save($auction);
}

function mp_booking_job_auction_form_submit($form, &$form_state) {
  $form_state['redirect'] = NULL;
}