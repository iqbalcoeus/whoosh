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
  dsm($form_state);
  $delta = $form_state['triggering_element']['#parents'][1];
  dsm($delta);
  $values = $form_state['values'];
  $job_nid = $values['jobs'][$delta]['job_nid'];

//  $event = bat_event_create(array('type' => MP_BOOKING_MODEL_AVAILABILITY));
//  $model_account = user_load($values['model_uid']);
//  $unit = _mp_booking_get_unit('user', $model_account);

}

/**
 * Model job auction.
 */
function mp_booking_job_auction_form($form, &$form_state, $event = NULL) {

}