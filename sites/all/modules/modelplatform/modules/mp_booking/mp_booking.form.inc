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

  $model_account = user_load($model_uid);
  $field_full_name = field_get_items('user', $model_account, 'field_full_name');
  if (isset($field_full_name[0]['value'])) {
    $full_name = $field_full_name[0]['value'];
    $title_params = array(
      '@model_name' => $full_name,
    );
  }
  else {
    $title_params = array(
      '@model_name' => $model_account->name,
    );
  }
  $title = t('Book of @model_name', $title_params);
  drupal_set_title($title);

  if (!is_numeric($customer_uid) || !$customer_uid) {
    $customer_uid = $user->uid;
  }

  $customer_jobs = _mp_booking_get_customer_jobs($customer_uid, array('nid', 'title'));
  $defult_job_nid = NULL;
  $count_jobs = count($customer_jobs);
  if ($count_jobs) {
    if ($count_jobs == 1) {
      $nids = array_keys($customer_jobs);
      $defult_job_nid = $nids[0];
    }

    $auctioned_job = _mp_booking_get_job_auction($model_uid, $customer_uid);
    if ($auctioned_job) {
      $start_date = $end_date = NULL;
      // Job dates.
      if (isset($auctioned_job->field_job_start_date[LANGUAGE_NONE][0]['value'])) {
        $start_date = $auctioned_job->field_job_start_date[LANGUAGE_NONE][0]['value'];
      }
      if (isset($auctioned_job->field_job_start_date[LANGUAGE_NONE][0]['value2'])) {
        $end_date = $auctioned_job->field_job_start_date[LANGUAGE_NONE][0]['value2'];
      }

      $model_auctions = _mp_booking_get_model_auctions($model_uid, $start_date, $end_date);
      $keys = array_keys($model_auctions);
      $idx = array_search($auctioned_job->nid, $keys);
      $auction_id = $model_auctions[$auctioned_job->nid];
      $auction = mp_auction_load($auction_id);
      $status = t('Empty status');
      $decision = '';
      if ($auction) {
        $field_status = field_get_items('mp_auction', $auction, 'field_auction_status');
        if (isset($field_status[0]['value'])) {
          $status = $field_status[0]['value'];
        }
        $field_decision = field_get_items('mp_auction', $auction, 'field_auction_decision');
        if (isset($field_decision[0]['value'])) {
          $decision = $field_decision[0]['value'];
        }
      }




      $form['auction_id'] = array(
        '#type' => 'value',
        '#value' => $auction_id,
      );

      $form['job_status'] = array(
        '#type' => 'markup',
        '#prefix' => '<div class="job-status">',
        '#markup' =>  $status,
        '#suffix' => '</div>',
      );

      $form['job_number'] = array(
        '#type' => 'markup',
        '#prefix' => '<div class="job-number">',
        '#markup' =>  $idx > 0 ? $idx + 1 : '<b>' . $idx + 1 . '</b>',
        '#suffix' => '</div>',
      );

      $form['actions'] = array(
        '#type' => 'container',
        '#tree' => TRUE,
      );
      $form['actions']['confirm'] = array(
        '#type' => 'submit',
        '#value' => t('Confirm'),
        '#name' => 'job_confirm',
        '#submit' => array(
          'mp_booking_job_model_invite_form_confirm_submit',
        ),
      );
      $form['actions']['cancel'] = array(
        '#type' => 'submit',
        '#value' => t('Cancel'),
        '#name' => 'job_cancel',
        '#submit' => array(
          'mp_booking_job_model_invite_form_cancel_submit',
        ),
      );
      $form['actions']['decision'] = array(
        '#type' => 'markup',
        '#prefix' => '<div class="auction-decision">',
        '#markup' => $decision,
        '#suffix' => '</div>',
      );
    }
    else {
      // Get model unit.
      $model_account = user_load($model_uid);
      $unit = _mp_booking_get_unit('user', $model_account);
      $form_state['#unit'] = $unit;

      $form['model_uid'] = array(
        '#type' => 'value',
        '#value' => $model_uid,
      );

      $form['jobs'] = array(
        '#type' => 'select',
        '#options' => $customer_jobs,
        '#default_value' => $defult_job_nid,
      );

      $form['job_invite'] = array(
        '#type' => 'submit',
        '#value' => t('Option Please'),
        '#name' => "job_invite",
        '#submit' => array(
          'mp_booking_job_model_invite_form_submit',
        ),
        '#validate' => array(
          'mp_booking_job_model_invite_form_validate',
        ),
      );
      $form['#validate'] = 'mp_booking_job_model_invite_form_validate';
    }
  }
  else {
    $form['info'] = array(
      '#type' => 'markup',
      '#markup' => t('You have no active Jobs'),
    );
  }

  return $form;
}

/**
 * Form validate.
 *
 * @see mp_booking_job_model_invite_form()
 */
function mp_booking_job_model_invite_form_validate($form, &$form_state) {
  $values = $form_state['values'];

  $job_nid = $values['jobs'];
  $job = node_load($job_nid);

  $start_date = $end_date = NULL;

  // Job dates check.
  if (!isset($job->field_job_start_date[LANGUAGE_NONE][0]['value'])) {
    form_set_error('jobs', t('Job start date is empty'));
  }
  else {
    $start_date = $job->field_job_start_date[LANGUAGE_NONE][0]['value'];
  }
  if (!isset($job->field_job_start_date[LANGUAGE_NONE][0]['value2'])) {
    form_set_error('jobs', t('Job end date is empty'));
  }
  else {
    $end_date = $job->field_job_start_date[LANGUAGE_NONE][0]['value2'];
  }

  // Model availability check.
  if ($start_date && $end_date) {
    // Get unit events.
    $events = _mp_booking_get_unit_events($form_state['#unit'], $start_date, $end_date, 1, FALSE);

    // Check events.
    if (count($events)) {
      form_set_error('jobs', t('Model is already busy on this dates.'));
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

  $values = $form_state['values'];

  $job_nid = $values['jobs'];
  $job = node_load($job_nid);

  $start_date = $job->field_job_start_date[LANGUAGE_NONE][0]['value'];
  $end_date = $job->field_job_start_date[LANGUAGE_NONE][0]['value2'];

  // Get model unit.
  $model_account = user_load($values['model_uid']);
  $unit = _mp_booking_get_unit('user', $model_account);

  // Create event.
  $event = _mp_booking_event_create($unit->unit_id, MP_BOOKING_STATE_AUCTION, $user->uid, $job_nid, $start_date, $end_date);
  bat_event_save($event);

  // Create auction.
  module_load_include('inc', 'mp_auction', 'mp_auction_mp_auction.admin');
  $auction = mp_auction_create(array('type' => 'auction'));
  $auction->name = 'Auction uid - ' . $user->uid;
  $auction->uid = $user->uid;
  $auction->field_auction_event[LANGUAGE_NONE][0]['target_id'] = $event->event_id;
  $auction->field_auction_status[LANGUAGE_NONE][0]['value'] = MP_BOOKING_AUCTION_REQUEST_SENT;
  mp_auction_save($auction);

  drupal_set_message(t('Model was optioned'));

  // Redirect to the auction page.
//  $link = 'job/model/' . $event->event_id . '/auction';
//  $form_state['redirect'] = $link;
}

/**
 * Form submit.
 *
 * @see mp_booking_job_model_invite_form()
 */
function mp_booking_job_model_invite_form_confirm_submit($form, $form_state) {
  $mp_auction_id = $form_state['values']['auction_id'];
  $auction = mp_auction_load($mp_auction_id);
  $auction->field_auction_decision[LANGUAGE_NONE][0]['value'] = 'Accept';
  mp_auction_save($auction);
}

/**
 * Form submit.
 *
 * @see mp_booking_job_model_invite_form()
 */
function mp_booking_job_model_invite_form_cancel_submit($form, $form_state) {
  $mp_auction_id = $form_state['values']['auction_id'];
  $auction = mp_auction_load($mp_auction_id);
  $auction->field_auction_decision[LANGUAGE_NONE][0]['value'] = 'Decline';
  mp_auction_save($auction);
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
      $auction->field_auction_cost_propose[LANGUAGE_NONE][0]['amount'] = $form_state['values']['field_auction_cost_propose'];
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

      if (isset($_auction->field_auction_cost_propose[LANGUAGE_NONE][0]['amount'])) {
        $amount = $_auction->field_auction_cost_propose[LANGUAGE_NONE][0]['amount'];
        $currency_code = $_auction->field_auction_cost_propose[LANGUAGE_NONE][0]['currency_code'];
        $form['auctions'][$delta]['cost'] = array(
          '#title' => t('Cost propose'),
          '#type' => 'markup',
          '#prefix' => '<div class="cost-propose">',
          '#markup' => commerce_currency_format($amount, $currency_code),
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

/**
 * Submit action.
 *
 * @see mp_booking_job_auction_form()
 */
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

/**
 * Submit action.
 *
 * @see mp_booking_job_auction_form()
 */
function mp_booking_job_auction_form_decline($form, &$form_state) {
  $delta = $form_state['triggering_element']['#parents'][1];

  $auction_id = $form_state['values']['auctions'][$delta]['auction_id'];
  $auction = mp_auction_load($auction_id);
  $auction->field_auction_decision[LANGUAGE_NONE][0]['value'] = 'Decline';
  mp_auction_save($auction);
}

/**
 * Submit action.
 *
 * @see mp_booking_job_auction_form()
 */
function mp_booking_job_auction_form_submit($form, &$form_state) {
  $form_state['redirect'] = NULL;
}

/**
 * Booking form.
 */
function mp_booking_calendar_form($form, &$form_state, $account = NULL) {
  if ($account) {
    // Get BAT Unit object.
    $unit = _mp_booking_get_unit('user', $account);

    // Create BAT event object.
    module_load_include('inc', 'bat_event', 'bat_event.admin');
    $event = _mp_booking_event_create($unit->unit_id, MP_BOOKING_STATE_BUSY, $account->uid);

    if ($event) {
      // Create form.
      $form = bat_event_edit_form($form, $form_state, $event);

      // Hide other fields.
      // @TODO Create module configuration for this fields.
      $form['user']['#access'] = FALSE;
      $form['event_history']['#access'] = FALSE;
      $form['event_bat_unit_reference']['#access'] = FALSE;
      $form['event_state_reference']['#access'] = FALSE;
      $form['field_job']['#access'] = FALSE;
      $form['field_job_cost']['#access'] = FALSE;
      $form['actions']['cancel']['#access'] = FALSE;

      // Change date format.
      $date_format = 'Y-m-d h:i A';
      $date_year_range = '0:+1';

      $form['bat_date_range']['bat_start_date']['#date_format'] = $date_format;
      $form['bat_date_range']['bat_start_date']['#date_year_range'] = $date_year_range;

      $form['bat_date_range']['bat_end_date']['#date_format'] = $date_format;
      $form['bat_date_range']['bat_end_date']['#date_year_range'] = $date_year_range;

      // I had to disable the validation of the form, because BAT generates
      // new values for the start and end date, even if they have not been entered
      // by the user, which causes the error when form submit.
      $form['#validate'] = array(
        '_rcb_bat_event_form_validate',
      );
      $form['bat_date_range']['bat_start_date']['#element_validate'] = array('_rcb_bat_date_validate');
      $form['bat_date_range']['bat_end_date']['#element_validate'] = array('_rcb_bat_date_validate');

      $form['actions']['submit']['#submit'] = array('mp_booking_calendar_form_submit');
      $form['actions']['submit']['#value'] = t('Mark as unavailable');
    }
  }

  return $form;
}

/**
 * Element validate callback for the bat_date_range fields.
 *
 * Ensure a start and end date was entered and provide default value for time.
 */
function _rcb_bat_date_validate($element, &$form_state, $form) {
  if (empty($element['#value']['date'])) {
    form_error($element, t('Please choose a @title.', array('@title' => $element['#title'])));
  }
  elseif (empty($element['#value']['time'])) {
    $form_state['values'][$element['#name']]['time'] = '10:00 AM';
  }
}

/**
 * BAT event additional form validation.
 *
 * @see mp_booking_calendar_form()
 */
function _rcb_bat_event_form_validate($form, &$form_state) {
  $error = FALSE;

  // Start date.
  if (!isset($form_state['input']['bat_start_date']['date'])
    || !$form_state['input']['bat_start_date']['date']) {
    $error = TRUE;
    form_set_error('bat_date_range][bat_start_date');
  }

  // End date.
  if (!isset($form_state['input']['bat_end_date']['date'])
    || !$form_state['input']['bat_end_date']['date']) {
    $error = TRUE;
    form_set_error('bat_date_range][bat_end_date');
  }

  // If default bat event validation will execute with date error
  // it will create fatal error, so we need to prevent it.
  if (!$error) {
    bat_form_start_end_dates_validate($form, $form_state);
    bat_event_edit_form_validate($form, $form_state);
  }
}

/**
 * Form submit.
 *
 * @see mp_booking_calendar_form()
 */
function mp_booking_calendar_form_submit($form, &$form_state) {
  // Call exists BAT submit function.
  bat_event_edit_form_submit($form, $form_state);

  $form_state['redirect'] = NULL;
}
