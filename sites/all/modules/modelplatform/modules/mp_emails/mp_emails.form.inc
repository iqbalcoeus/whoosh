<?php

function mp_emails_form($form, $form_state) {
  require_once 'mp_emails.default_variables.inc';
  global $language;

  $form = array();

  $form['mpe_description'] = array(
    '#type' => 'markup',
    '#markup' => '    
     <h2>Available replacements</h2>
     <p>
       <label>Model</label>
       <ul>       
         <li><span>@model_full_name</span> - <span>Full name</span></li>
         <li><span>@model_language</span> - <span>Language code</span></li>
         <li><span>@model_mail</span> - <span>mail</span></li>
         <li><span>@model_salutation</span> - <span>salutation</span></li>
       </ul>
     </p>
     <p>
       <label>Customer</label>
       <ul>       
         <li><span>@customer_full_name</span> - <span>Full name</span></li>
         <li><span>@customer_language</span> - <span>Language code</span></li>
         <li><span>@customer_mail</span> - <span>mail</span></li>
         <li><span>@customer_salutation</span> - <span>salutation</span></li>
       </ul>
     </p>
     <p>
      <label>Job</label>
       <ul>       
         <li><span>@job_title</span> - <span>Title</span></li>
         <li><span>!job_description</span> - <span>Description</span></li>
         <li><span>@job_date</span> - <span>Dates</span></li>
         <li><span>@job_daily_rate</span> - <span>Daily rate</span></li>
         <li><span>@url</span> - <span>URL</span></li>
       </ul> 
     </p>           
    ',
  );

  $form['mpe_model_job_reminder_notification'] = array(
    '#type' => 'textarea',
    '#title' => t('Model reminder letter'),
    '#default_value' => i18n_variable_get('mpe_model_job_reminder_notification', $language->language, _mp_emails_get_var_model_job_reminder_notification($language->language)),
  );

  $form['mpe_customer_job_option_notification'] = array(
    '#type' => 'textarea',
    '#title' => t('Customer option notification'),
    '#default_value' => i18n_variable_get('mpe_customer_job_option_notification', $language->language, _mp_emails_get_var_customer_job_option_notification($language->language)),
  );

  $form['mpe_model_job_option_notification'] = array(
    '#type' => 'textarea',
    '#title' => t('Model option notofication'),
    '#default_value' => i18n_variable_get('mpe_model_job_option_notification', $language->language, _mp_emails_get_var_model_job_option_notification($language->language)),
  );

  $form['mpe_customer_job_option_model_confirm'] = array(
    '#type' => 'textarea',
    '#title' => t('Customer. Model confirmed.'),
    '#default_value' => i18n_variable_get('mpe_customer_job_option_model_confirm', $language->language, _mp_emails_get_var_customer_job_option_model_confirm($language->language)),
  );

  $form['mpe_customer_job_auction'] = array(
    '#type' => 'textarea',
    '#title' => t('Customer auction'),
    '#default_value' => i18n_variable_get('mpe_customer_job_auction', $language->language, _mp_emails_get_var_customer_job_auction($language->language)),
  );

  $form['mpe_model_job_confirmed'] = array(
    '#type' => 'textarea',
    '#title' => t('Model job confirmed'),
    '#default_value' => i18n_variable_get('mpe_model_job_confirmed', $language->language, _mp_emails_get_var_model_job_confirmed($language->language)),
  );

  $form['mpe_model_calendar'] = array(
    '#type' => 'textarea',
    '#title' => t('Model calendar'),
    '#default_value' => i18n_variable_get('mpe_model_calendar', $language->language, _mp_emails_get_var_model_calendar($language->language)),
  );

  $form['actions'] = array(
    '#type' => 'container',
    '#tree' => TRUE,
  );
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#submit' => array('mp_emails_form_submit'),
  );
  
  return $form;
}

function mp_emails_form_submit($form, $form_state) {
  global $language;

  $values = $form_state['values'];
  foreach($values as $key => $value) {
    i18n_variable_set($key, $value, $language->language);
  }
}