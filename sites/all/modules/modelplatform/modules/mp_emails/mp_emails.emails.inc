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
  if($language == 'de'){
    $message_text = '
    @model_salutation, @model_full_name.
    
    leider hast Du nicht noch auf die Anfrage unseres Kunden @customer_full_name reagiert. 
    Es wäre schön, wenn Du Dich melden könntest, damit für beide Seiten klar ist, ob es zu einer Zusammenarbeit kommt. 
    Nur so hast Du die Chance auf einen neuen Auftrag!
    
    Herzliche Grüße, 
    Dein Team von myFab Models
  ';

  } else {
    $message_text= '
      @model_salutation, @model_full_name.

      Unfortunately you have not responded to the request of our customer @customer_full_name. 
      It would be nice if you could report, so that it is clear for both sides whether a cooperation is coming. 
      This is the only chance you have a new order!

      Best regards,
      Your team of myFab Models
    ';
  }
  $message = _mp_emails_prepare_message($message_text, $email_params);

  $params = array(
    'subject' => 'The Reminder for the option request.',
    'message' => $message,
  );
  $send = TRUE;

    if($language=='de'){
        $noti_title='Der Reminder für die Optionsanfrage.';
        $noti_text="Liebe {$email_params['@model_full_name']}, lieber {$email_params['@model_full_name']}, 
        
leider hast Du nicht noch auf die Anfrage unseres Kunden {$email_params['@customer_full_name']} reagiert. Bitte gehe ins Backend.
Greetings myFab Models";
    } else {
        $noti_title='The reminder for the option request.';
        $noti_text="Love {$email_params['@model_full_name']}, dear {$email_params['@model_full_name']}, 
        
Unfortunately, you have not responded to the request of our customer {$email_params['@customer_full_name']}. Please go to the backend.
Greetings myFab Models";
    }

    $notification = array('title' => $noti_title, 'text' => $noti_text);

    _send_push_notification($to,$notification);

  drupal_mail($module, $key, $to, $language, $params, $from, $send, $cc = _get_admin_email());
}

/**
 * Customer email. Customer optioned model.
 */
function _mp_emails_customer_job_option_notification($email_params) {
  $module = 'mp_emails';
  $key = 'mp_emeils_job_propose';

  $to = $email_params['@customer_mail'];
  $from = variable_get('site_mail', 'admin@megaonline.com');
  $language = $email_params['@customer_language'];

  $message_text = i18n_variable_get('mpe_customer_job_option_notification', $language);
  $message = _mp_emails_prepare_message($message_text, $email_params);

  $params = array(
    'subject' => 'The Reminder for the option request.',
    'message' => $message,
  );
  $send = TRUE;

  drupal_mail($module, $key, $to, $language, $params, $from, $send, $cc = _get_admin_email());
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

    if($language=='de'){
        $noti_title='Die Optionsanfrage für das Model.';
        $noti_text="Liebe {$email_params['@model_full_name']}, lieber {$email_params['@model_full_name']}, 
        
Unser Kunde {$email_params['@customer_full_name']} hat eine Option für ein Projekt mit Dir gewählt.
Herzliche Grüße myFab Models";
    } else {
        $noti_title='The option request for the model.';
        $noti_text="Love {$email_params['@model_full_name']}, dear {$email_params['@model_full_name']}, 
        
Our customer {$email_params['@customer_full_name']} has chosen an option for a project with you.
Greetings myFab Models";
    }

    $notification = array('title' => $noti_title, 'text' => $noti_text);

    _send_push_notification($to,$notification);
  drupal_mail($module, $key, $to, $language, $params, $from, $send, $cc = _get_admin_email());
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
    'subject' => t('Offer Accepted.'),
    'message' => $message,
  );
  $send = TRUE;

    if($language=='de'){
        $noti_title='Option wird Festbuchung.';
        $noti_text="Liebe {$email_params['@model_full_name']}, lieber {$email_params['@model_full_name']}, 
        
Deine Option durch {$email_params['@customer_full_name']} ist nun eine Festbuchung geworden.
Herzlichen Glückwunsch – wir wünschen eine erfolgreiche Zusammenarbeit!";
    } else {
        $noti_title='Option becomes fixed booking.';
        $noti_text="Love {$email_params['@model_full_name']}, dear {$email_params['@model_full_name']}, 
        
Your option through {$email_params['@customer_full_name']} has now become a fixed booking.
Congratulations - we wish you a successful cooperation!";
    }

    $notification = array('title' => $noti_title, 'text' => $noti_text);

    _send_push_notification($to,$notification);

  drupal_mail($module, $key, $to, $language, $params, $from, $send, $cc = _get_admin_email());
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

  drupal_mail($module, $key, $to, $language, $params, $from, $send, $cc = _get_admin_email());
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

  drupal_mail($module, $key, $to, $language, $params, $from, $send, $cc = _get_admin_email());
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

  drupal_mail($module, $key, $to, $language, $params, $from, $send, $cc = _get_admin_email());
}


function _get_admin_email(){
    if($user_fields = user_load(1)){
        return $user_fields->mail;
    }
    return '';
}


function _send_push_notification($to,$notification){
    if (function_exists('push_notification_send')) {
        if($user_fields=user_load_by_mail($to)) {
            $data = array("alert" => "");
            push_notification_send($user_fields->uid, $notification, $data);
        }
    }
}