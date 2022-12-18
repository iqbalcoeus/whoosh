<?php

/**
 * @file
 * Model Platform - Invoices forms.
 */

/**
 * Model platform invoice params form.
 */
function mp_invoices_params_form($form, $form_state) {
  $form['header'] = array();
  $form['header']['mpi_page_header_img'] = array(
    '#title' => t('Invoices logo'),
    '#type' => 'managed_file',
    '#description' => t('This image will be show on the top of all invoice pages.'),
    '#default_value' => variable_get('mpi_page_header_img', ''),
    '#upload_location' => 'public://',
  );
  $form['header']['mpi_page_header_column_1'] = array(
    '#title' => t('Header column 1'),
    '#type' => 'textarea',
    '#description' => t('This text will be displayed on the top of all invoice pages'),
    '#default_value' => variable_get('mpi_page_header_column_1', ''),
  );
  $form['header']['mpi_page_header_column_2'] = array(
    '#title' => t('Header column 2'),
    '#type' => 'textarea',
    '#description' => t('This text will be displayed on the top of all invoice pages'),
    '#default_value' => variable_get('mpi_page_header_column_2', ''),
  );

  $form['content'] = array();
  $form['content']['mpi_customer_address_prefix'] = array(
    '#title' => t('Customer address prefix'),
    '#type' => 'textarea',
    '#default_value' => variable_get('mpi_customer_address_prefix', ''),
  );

  $form['content']['mpi_address_prefix'] = array(
    '#title' => t('Address prefix'),
    '#type' => 'textarea',
    '#default_value' => variable_get('mpi_address_prefix', ''),
  );
  $form['content']['mpi_address_suffix'] = array(
    '#title' => t('Address suffix'),
    '#type' => 'textarea',
    '#default_value' => variable_get('mpi_address_suffix', ''),
  );

  $form['content']['mpi_main_prefix'] = array(
    '#title' => t('Content main bills prefix'),
    '#type' => 'textarea',
    '#default_value' => variable_get('mpi_main_prefix', ''),
  );
  $form['content']['mpi_main_suffix'] = array(
    '#title' => t('Content main bills suffix'),
    '#type' => 'textarea',
    '#default_value' => variable_get('mpi_main_suffix', ''),
  );

  $form['content']['mpi_tax_prefix'] = array(
    '#title' => t('Content tax bills prefix'),
    '#type' => 'textarea',
    '#default_value' => variable_get('mpi_tax_prefix', ''),
  );
  $form['content']['mpi_tax_suffix'] = array(
    '#title' => t('Content tax bills suffix'),
    '#type' => 'textarea',
    '#default_value' => variable_get('mpi_tax_suffix', ''),
  );

  $form['content']['mpi_additional_prefix'] = array(
    '#title' => t('Content additional bills prefix'),
    '#type' => 'textarea',
    '#default_value' => variable_get('mpi_additional_prefix', ''),
  );
  $form['content']['mpi_additional_psuffix'] = array(
    '#title' => t('Content additional bills suffix'),
    '#type' => 'textarea',
    '#default_value' => variable_get('mpi_additional_suffix', ''),
  );

  $form['footer'] = array();
  $form['footer']['mpi_footer_part_1'] = array(
    '#title' => t('Footer part 1'),
    '#type' => 'textarea',
    '#default_value' => variable_get('mpi_footer_part_1', ''),
  );
  $form['footer']['mpi_footer_part_2'] = array(
    '#title' => t('Footer part 2'),
    '#type' => 'textarea',
    '#default_value' => variable_get('mpi_footer_part_2', ''),
  );

  $form['actions'] = array();
  $form['actions']['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#submit' => array(
      'mp_invoices_params_form_submit',
    ),
  );

  return $form;
}

/**
 * Invoice params form validate.
 *
 * @see mp_invoices_params_form().
 */
function mp_invoices_params_form_validate($form, $form_state) {
  return TRUE;
}

/**
 * Invoice params form submit.
 *
 * @see mp_invoices_params_form().
 */
function mp_invoices_params_form_submit($form, $form_state) {
  global $user;

  if (isset($form_state['values']['mpi_page_header_img'])) {
    if ($file = file_load($form_state['values']['mpi_page_header_img'])) {
      $file->status = FILE_STATUS_PERMANENT;
      file_save($file);

      file_usage_add($file, 'mp_invoices', 'user', $user->uid);
      $mpi_page_header_img_url = file_create_url($file->uri);

      variable_set('mpi_page_header_img', $file->fid);
      variable_set('mpi_page_header_img_url', $mpi_page_header_img_url);
    }
  }

  if (isset($form_state['values']['mpi_page_header_column_1'])) {
    variable_set('mpi_page_header_column_1', $form_state['values']['mpi_page_header_column_1']);
  }

  if (isset($form_state['values']['mpi_page_header_column_2'])) {
    variable_set('mpi_page_header_column_2', $form_state['values']['mpi_page_header_column_2']);
  }

  if (isset($form_state['values']['mpi_footer_part_1'])) {
    variable_set('mpi_footer_part_1', $form_state['values']['mpi_footer_part_1']);
  }

  if (isset($form_state['values']['mpi_footer_part_2'])) {
    variable_set('mpi_footer_part_2', $form_state['values']['mpi_footer_part_2']);
  }

  if (isset($form_state['values']['mpi_customer_address_prefix'])) {
    variable_set('mpi_customer_address_prefix', $form_state['values']['mpi_customer_address_prefix']);
  }
  if (isset($form_state['values']['mpi_address_prefix'])) {
    variable_set('mpi_address_prefix', $form_state['values']['mpi_address_prefix']);
  }
  if (isset($form_state['values']['mpi_address_suffix'])) {
    variable_set('mpi_address_suffix', $form_state['values']['mpi_address_suffix']);
  }

  if (isset($form_state['values']['mpi_main_prefix'])) {
    variable_set('mpi_main_prefix', $form_state['values']['mpi_main_prefix']);
  }
  if (isset($form_state['values']['mpi_main_suffix'])) {
    variable_set('mpi_main_suffix', $form_state['values']['mpi_main_suffix']);
  }

  if (isset($form_state['values']['mpi_tax_prefix'])) {
    variable_set('mpi_tax_prefix', $form_state['values']['mpi_tax_prefix']);
  }
  if (isset($form_state['values']['mpi_tax_suffix'])) {
    variable_set('mpi_tax_suffix', $form_state['values']['mpi_tax_suffix']);
  }

  if (isset($form_state['values']['mpi_additional_prefix'])) {
    variable_set('mpi_additional_prefix', $form_state['values']['mpi_additional_prefix']);
  }
  if (isset($form_state['values']['mpi_additional_suffix'])) {
    variable_set('mpi_additional_suffix', $form_state['values']['mpi_additional_suffix']);
  }
}