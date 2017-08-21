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

  $message_text = '
      @model_salutation, @model_full_name.

      Unfortunately you have not responded to the request of our customer @customer_full_name. 
      It would be nice if you could report, so that it is clear for both sides whether a cooperation is coming. 
      This is the only chance you have a new order!

      Best regards,
      Your team of MegaOnline
    ';
  $message = t($message_text, $email_params);

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

  $message_text = '
      @customer_salutation, @customer_full_name.     
      
      You have chosen an option for our model @model_full_name. 
      We have forwarded your request to our model. 
      If you do not receive a message from the desired model within the next 24 hours or have any further questions, please contact us by phone.
      
      Best regards,
      Your team of MegaOnline
    ';
  $message = t($message_text, $email_params);

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

  $message_text = '
    @model_salutation, @model_full_name.
    
    Our customer @customer_full_name has chosen an option for a project with you. 
    To accept or reject this request, if you are not currently available, just click on this link: @url
    Here you also have the possibility to check whether the customer\'s suggested day rate matches your expectations or whether you would like to make a new proposal.      
    
    Here are the details, which are important for you:

    Customer: @customer_full_name
    Job description: !job_description
    Date: @job_date
    Daily rate: @job_daily_rate
    
    Best regards,
    Your team of MegaOnline
  ';
  $message = t($message_text, $email_params);

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

  $message_text = '
      @customer_salutation, @customer_full_name.     
      
      The model requested by you has confirmed your option.
      
      Best regards,
      Your team of MegaOnline
    ';
  $message = t($message_text, $email_params);

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

  $message_text = '
      @customer_salutation, @customer_full_name.

      You have chosen an option for our model @model_full_name. 
      We\'re happy about that, of course.
      Now you have to decide: If you want to make a reservation from the option, please click here: @url. 
      We will immediately inform you of the model you have chosen.
      
      Good luck with the cooperation and cordial greetings,
      Your team of MegaOnline
    ';
  $message = t($message_text, $email_params);

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

  $message_text = '
    @model_salutation, @model_full_name.
    
    Your option through @customer_full_name has now become a fixed booking.
    Congratulations - we wish you a successful cooperation!
    
    Best regards,
    Your team of MegaOnline
  ';
  $message = t($message_text, $email_params);

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

  $message_text = '
    @model_salutation, @model_full_name.
    
    Obviously, you do not have time to accept new requests. 
    In this case it would be nice to update your calendar. 
    To do this, you simply have to mark the days on which you can not be booked. 
    So your clients know they have to plan without you. 
    Thank you very much for your understanding!
    
    Best regards,
    Your team of MegaOnline
  ';
  $message = t($message_text, $email_params);

  $params = array(
    'subject' => 'Job confirmed - ' . $email_params['@job_title'],
    'message' => $message,
  );
  $send = TRUE;

  drupal_mail($module, $key, $to, $language, $params, $from, $send);
}