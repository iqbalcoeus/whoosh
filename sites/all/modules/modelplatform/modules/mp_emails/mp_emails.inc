<?php

/**
 * Created by PhpStorm.
 * User: cimpleo
 * Date: 14.08.17
 * Time: 14:49
 */

/**
 * Prepare email params by event.
 */
function _mp_emails_get_event_params($event) {
  global $base_url;

  $event_wrapper = entity_metadata_wrapper('bat_event', $event);

  $unit = $event_wrapper->event_bat_unit_reference->value();
  $job = $event_wrapper->field_job->value();
  $job_wrapper = entity_metadata_wrapper('node', $job);

  $model_uid = $unit->uid;
  $model = user_load($model_uid);
  $customer = user_load($job->uid);
  if(!empty($model) && !empty($customer)){
      $model_wrapper = entity_metadata_wrapper('user', $model);
      $customer_wrapper = entity_metadata_wrapper('user', $customer);

    $model_profiles = profile2_load_by_user($model);
    $model_basic_information = entity_metadata_wrapper('profile2', $model_profiles['model_basic_informaiton']);

    $tid = $model_basic_information->field_model_gender->tid->value();
    if ($tid == 89) {
      $model_salutation = array(
        'en' => 'Dear',
        'de' => 'Liebe',
      );
      $customer_salutation = array(
        'en' => 'Hello',
        'de' => 'Hallo',
      );
    }
    else {
      $model_salutation = array(
        'en' => 'Dear',
        'de' => 'Lieber',
      );
      $customer_salutation = array(
        'en' => 'Hello',
        'de' => 'Hallo',
      );
    }

    $job_date_format = 'Y-m-d H:i';
    $job_start_date = date($job_date_format, $job_wrapper->field_job_start_date->value->value());
    $job_end_date = date($job_date_format, $job_wrapper->field_job_start_date->value2->value());
    $job_date = "$job_start_date - $job_end_date";
    $job_daily_rate_from = commerce_currency_format($job_wrapper->field_job_daily_rate_from->amount->value(), $job_wrapper->field_job_daily_rate_from->currency_code->value());
    $job_daily_rate_to = commerce_currency_format($job_wrapper->field_job_daily_rate_to->amount->value(), $job_wrapper->field_job_daily_rate_to->currency_code->value());
    $job_daily_rate = "$job_daily_rate_from - $job_daily_rate_to";

    $email_params = array();
    $email_params['@model_full_name']     = $model_wrapper->field_full_name->value();
    $email_params['@model_language']      = $model->language;
    $email_params['@model_mail']          = $model->mail;
    $email_params['@customer_full_name']  = $customer_wrapper->field_full_name->value();
    $email_params['@customer_language']   = $customer->language;
    $email_params['@customer_mail']       = $customer->mail;
    $email_params['@model_salutation']    = $model_salutation[$model->language];
    $email_params['@customer_salutation'] = $customer_salutation[$customer->language];
    $email_params['@job_title']           = $job->title;
    $email_params['!job_description']     = count($job->body) ? $job_wrapper->body->value->value() : '';
    $email_params['@job_date']            = $job_date;
    $email_params['@job_daily_rate']      = $job_daily_rate;
    $email_params['@url']                 = $base_url . '/job/event/' . $event->event_id . '/auction';
  }

  return $email_params;
}

function _mp_emails_model_notification_callback($event_info) {
  $event = bat_event_load($event_info->event_id);
  $email_params = _mp_emails_get_event_params($event);
  _mp_emails_model_job_reminder_notification($email_params);
}

function _mp_emails_prepare_message($message, $params) {
  foreach($params as $key => $value) {
    $message = str_replace($key, $value, $message);
  }

  return $message;
}