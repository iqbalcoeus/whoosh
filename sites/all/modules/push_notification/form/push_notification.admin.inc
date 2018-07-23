<?php

/**
 * @file
 * Admin page callback file for the xing connect module.
 */

/**
 * Admin setting form.
 */
function push_notification_configurations($form, &$form_state) {

    $form['push_notification_api_url'] = array(
        '#type' => 'textfield',
        '#required' => TRUE,
        '#title' => t('Firebase api url'),
        '#default_value' => variable_get('push_notification_api_url', NULL),
        '#description' => t('Firebase <em>Api Url</em>')
    );

    $form['push_notification_server_key'] = array(
        '#type' => 'textfield',
        '#required' => TRUE,
        '#title' => t('Firebase server key'),
        '#default_value' => variable_get('push_notification_server_key', NULL),
        '#description' => t('Firebase <em>Server Key</em>'),
        '#size' => 100,
        '#maxlength' => 1024,
    );
  return system_settings_form($form);
}
