<?php

/**
 * @file
 * Admin page callback file for the xing connect module.
 */

/**
 * Admin setting form.
 */
function login_with_xing_admin_api_key_setting($form, &$form_state) {
  $form['login_with_xing_ckey'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Xing Consumer key'),
    '#default_value' => variable_get('login_with_xing_ckey', NULL),
    '#description' => t('Also called the <em>OAuth Consumer key</em> value on Xing App settings pages. <a href="https://dev.xing.com/applications/dashboard">Xing Apps must first be created</a> before they can be added here.'),
  );
  $form['login_with_xing_login'] = array(
        '#type' => 'checkbox',
        '#title' => t('Login using xing'),
        '#description' => t('Allow user to register and login with xing.'),
        '#default_value' => variable_get('login_with_xing_login', 0),
  );
  return system_settings_form($form);
}
