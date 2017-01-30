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

  $form = array();

  $form['my_title'] = array(
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
    $form['jobs'][$delta]['job_invite'] = array(
      '#type' => 'submit',
      '#value' => t('Invite model'),
      '#name' => "job_invite_$delta",
      '#submit' => array(
        'mp_booking_job_model_invite_form_submit',
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
    if (!isset($form_state['values']['jobs'][$delta]['job_nid'])) {
      form_set_error(NULL, t('Job Indentifier is miss.'));
    }
    elseif (intval($form_state['values']['jobs'][$delta]['job_nid']) <= 0) {
      form_set_error(NULL, t('Job Indentifier is undefined.'));
    }
  }
}

/**
 * Form submit.
 *
 * @see mp_booking_job_model_invite_form()
 */
function mp_booking_job_model_invite_form_submit($form, &$form_state) {
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

  $event_params = array(
    'type' => MP_BOOKING_MODEL_AVAILABILITY,
  );
  $event = bat_event_create($event_params);
  $model_account = user_load($values['model_uid']);
  $unit = _mp_booking_get_unit('user', $model_account);

  $events = _mp_booking_get_unit_events($unit, $start_date, $end_date, 1, FALSE);
  if (count($events)) {
    drupal_set_message(t('Model is already busy on this dates.'));
  }
  else {
    $event->field_job[LANGUAGE_NONE][0]['target_id'] = $job_nid;
    $event->event_bat_unit_reference[LANGUAGE_NONE][0]['target_id'] = $unit->unit_id;
    $event->event_state_reference[LANGUAGE_NONE][0]['state_id'] = MP_BOOKING_STATE_AUCTION;
    $event->start_date = $start_date;
    $event->end_date = $end_date;
    bat_event_save($event);

    drupal_set_message(t('Auction was created'));
    $link = 'job/model/' . $event->event_id . '/auction';
    $form_state['redirect'] = $link;
  }
}

/**
 * Model job auction.
 */
function mp_booking_job_auction_form($form, &$form_state, $event = NULL) {
//  module_load_include('inc', 'bat_event', 'bat_event.admin');
//  $form = bat_event_edit_form($form, $form_state, $event);
//
//  $form['event_history']['#access'] = FALSE;
//  $form['user']['#access'] = FALSE;
//  $form['bat_date_range']['#access'] = FALSE;
//  $form['event_bat_unit_reference']['#access'] = FALSE;
//  $form['event_state_reference']['#access'] = FALSE;
//  $form['field_job']['#access'] = FALSE;
//  dsm($form);

  return $form;
}
