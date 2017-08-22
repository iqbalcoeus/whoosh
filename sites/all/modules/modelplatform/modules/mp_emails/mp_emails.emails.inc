<?php

/**
 * Created by PhpStorm.
 * User: cimpleo
 * Date: 14.08.17
 * Time: 14:50
 */

/**
 * Model email. Model job reminder.
 */
function _mp_emails_model_job_reminder_notification($email_params) {
  $module = 'mp_emails';
  $key = 'mp_emeils_job_propose';

  $to = $email_params['@model_mail'];
  $from = variable_get('site_mail', 'admin@example.com');
  $language = $email_params['@model_language'];

  $message_text = i18n_variable_get('mpe_job_reminder_notification', $language);
  $message = _mp_emails_prepare_message($message_text, $email_params);

  $params = array(
    'subject' => 'The Reminder for the option request.',
    'message' => $message,
  );
  $send = TRUE;

  drupal_mail($module, $key, $to, $language, $params, $from, $send);
}

/**
 * Customer email. Customer optioned model.
 */
function _mp_emails_customer_job_option_notification($email_params) {
  $module = 'mp_emails';
  $key = 'mp_emeils_job_propose';

  $to = $email_params['@model_mail'];
  $from = variable_get('site_mail', 'admin@example.com');
  $language = $email_params['@model_language'];

  $message_text = i18n_variable_get('mpe_customer_job_option_notification', $language);
  $message = _mp_emails_prepare_message($message_text, $email_params);

  $params = array(
    'subject' => 'The Reminder for the option request.',
    'message' => $message,
  );
  $send = TRUE;

  drupal_mail($module, $key, $to, $language, $params, $from, $send);
}

/**
 * Model email. Model was optioned.
 */
function _mp_emails_model_job_option_notification($email_params) {
  $module = 'mp_emails';
  $key = 'mp_emeils_job_propose';

  $to = $email_params['@model_mail'];
  $from = variable_get('site_mail', 'admin@example.com');
  $language = $email_params['@model_language'];

  $message_text = i18n_variable_get('mpe_model_job_option_notification', $language);
  $message = _mp_emails_prepare_message($message_text, $email_params);

  $params = array(
    'subject' => 'New job propose - ' . $email_params['@job_title'],
    'message' => $message,
  );

  $send = TRUE;

  drupal_mail($module, $key, $to, $language, $params, $from, $send);
}

/**
 * Customer email. Model confirmed option.
 */
function _mp_emails_customer_job_option_model_confirm($email_params) {
  $module = 'mp_emails';
  $key = 'mp_emeils_job_propose';

  $to = $email_params['@model_mail'];
  $from = variable_get('site_mail', 'admin@example.com');
  $language = $email_params['@model_language'];

  $message_text = i18n_variable_get('mpe_customer_job_option_model_confirm', $language);
  $message = _mp_emails_prepare_message($message_text, $email_params);

  $params = array(
    'subject' => 'The Reminder for the option request.',
    'message' => $message,
  );
  $send = TRUE;

  drupal_mail($module, $key, $to, $language, $params, $from, $send);
}

/**
 * Customer. Auction email.
 */
function _mp_emails_customer_job_auction($email_params) {
  $module = 'mp_emails';
  $key = 'mp_emeils_job_propose';

  $to = $email_params['@model_mail'];
  $from = variable_get('site_mail', 'admin@example.com');
  $language = $email_params['@model_language'];

  $message_text = i18n_variable_get('mpe_customer_job_auction', $language);
  $message = _mp_emails_prepare_message($message_text, $email_params);

  $params = array(
    'subject' => 'The Reminder for the option request.',
    'message' => $message,
  );
  $send = TRUE;

  drupal_mail($module, $key, $to, $language, $params, $from, $send);
}

/**
 * Model. Job confirmed.
 */
function _mp_emails_model_job_confirmed($email_params) {
  $module = 'mp_emails';
  $key = 'mp_emeils_job_propose';

  $to = $email_params['@model_mail'];
  $from = variable_get('site_mail', 'admin@example.com');
  $language = $email_params['@model_language'];

  $message_text = i18n_variable_get('mpe_model_job_confirmed', $language);
  $message = _mp_emails_prepare_message($message_text, $email_params);

  $params = array(
    'subject' => 'Job confirmed - ' . $email_params['@job_title'],
    'message' => $message,
  );
  $send = TRUE;

  drupal_mail($module, $key, $to, $language, $params, $from, $send);
}

/**
 * Model. Calendar.
 */
function _mp_emails_model_calendar($email_params) {
  $module = 'mp_emails';
  $key = 'mp_emeils_job_propose';

  $to = $email_params['@model_mail'];
  $from = variable_get('site_mail', 'admin@example.com');
  $language = $email_params['@model_language'];

  $message_text = i18n_variable_get('mpe_model_calendar', $language);
  $message = _mp_emails_prepare_message($message_text, $email_params);

  $params = array(
    'subject' => 'Job confirmed - ' . $email_params['@job_title'],
    'message' => $message,
  );
  $send = TRUE;

  drupal_mail($module, $key, $to, $language, $params, $from, $send);
}