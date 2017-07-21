<?php

/**
 * @file
 * Model Platform - MangoPay configuration form.
 */

/**
 * Mangopay configuration form.
 *
 * @see mp_mangopay_config_form_submit().
 */
function mp_mangopay_config_form($form, &$form_state) {
  $form = array();

  $form['account_settings'] = array(
    '#title' => 'MangoPay account settings',
    '#type' => 'container',
    '#tree' => TRUE,
  );

  $form['account_settings']['mp_mangopay_client_id'] = array(
    '#type' => 'textfield',
    '#title' => 'Client ID',
    '#default_value' => variable_get('mp_mangopay_client_id', ''),
  );

  $form['account_settings']['mp_mangopay_client_pass'] = array(
    '#type' => 'textfield',
    '#title' => 'Client password',
    '#default_value' => variable_get('mp_mangopay_client_pass', ''),
  );

  $form['account_settings']['mp_mangopay_tmp_folder'] = array(
    '#type' => 'textfield',
    '#title' => 'Temporary folder',
    '#default_value' => variable_get('mp_mangopay_tmp_folder', '/tmp'),
  );

  $form['curl_settings'] = array(
    '#title' => 'cURL settings',
    '#type' => 'container',
    '#tree' => TRUE,
  );

  $form['actions']['apply'] = array(
    '#type' => 'submit',
    '#value' => 'Save configuration',
  );

  t('MangoPay account settings');
  t('Client ID');
  t('Client password');
  t('Temporary folder');
  t('cURL settings');
  t('Save configuration');

  return $form;
}

/**
 * Form submit action.
 *
 * @see mp_mangopay_config_form().
 */
function mp_mangopay_config_form_submit($form, &$form_state) {
  if (isset($form_state['values']) && is_array($form_state['values'])) {
    foreach ($form_state['values'] as $key => $values) {
      foreach ($values as $variable_name => $value) {
        variable_set($variable_name, $value);
      }
    }
  }
}