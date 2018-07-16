<?php

/**
 * @file
 * Model Platform - Invoices Page callbacks.
 */

/**
 * Page callback.
 *
 * @see mp_invoices_menu()
 */
function mp_invoices_page_callback($account, $order) {
  $page = array();

  // Header.
  $page['header'] = array(
    'img' => 'https://megamodelonline.com/sites/default/files/Logo_MegaOnline_Black.jpg',//variable_get('mpi_page_header_img_url', NULL),
    'text' => array(
      'column1' => t(variable_get('mpi_page_header_column_1', NULL)),
      'column2' => t(variable_get('mpi_page_header_column_2', NULL)),
    ),
  );

  // Content.
  $page['content'] = array();

  $order_wrapper = entity_metadata_wrapper('commerce_order', $order);
  $event = $order_wrapper->field_event->value();

  $event_wrapper = entity_metadata_wrapper('bat_event', $event);
  $job = $event_wrapper->field_job->value();
  $job_wrapper = entity_metadata_wrapper('node', $job);

  $unit = $event_wrapper->event_bat_unit_reference->value();

  // Content - addresses.
  $page['content']['address'] = array();
  $customer_uid = $job->uid;
  $model_uid = $unit->uid;

  // Customer address.
  $customer = user_load($customer_uid);
  $customer_profiles = profile2_load_by_user($customer);
  if (isset($customer_profiles['customer_private_data'])) {
    $customer_wrapper = entity_metadata_wrapper('user', $customer);
    $customer_profile_wrapper = entity_metadata_wrapper('profile2', $customer_profiles['customer_private_data']);
    $page['content']['address']['customer'] = array(
      'prefix' => variable_get('mpi_customer_address_prefix', ''),
      'company_name' => '',
      'name' => $customer_wrapper->field_full_name->value(),
      'street' => $customer_profile_wrapper->field_model_street->value(),
      'house' => $customer_profile_wrapper->field_model_house->value(),
      'postal_code' => $customer_profile_wrapper->field_model_postal_code->value(),
      'city' => $customer_profile_wrapper->field_complete_address->value()['locality'],
    );
  }

  // Model address.
  $model = user_load($model_uid);
  $model_profiles = profile2_load_by_user($model);
  $is_german_model = _mp_invoices_model_is_german($model);
  if (isset($model_profiles['model_private_data'])) {
    $model_wrapper = entity_metadata_wrapper('user', $model);
    $model_profile_wrapper = entity_metadata_wrapper('profile2', $model_profiles['model_private_data']);
    $page['content']['address']['model'] = array(
      'name' => $model_wrapper->field_full_name->value(),
      'street' => $model_profile_wrapper->field_model_street->value(),
      'house' => $model_profile_wrapper->field_model_house->value(),
      'postal_code' => $model_profile_wrapper->field_model_postal_code->value(),
      'city' => $model_profile_wrapper->field_complete_address->value()['locality'],
      'appartment' => $model_profile_wrapper->field_model_apartment->value(),
      'tax_id' => $model_profile_wrapper->field_income_tax_id->value(),
    );
  }
  $page['content']['address']['prefix'] = t(variable_get('mpi_address_prefix', ''));
  $page['content']['address']['suffix'] = t(variable_get('mpi_address_suffix', ''));

  $page['content']['job'] = array(
    'job_dates' => array(
      'start_date' => $event->start_date_object,
      'end_date' => $event->end_date_object,
    ),
    'company' => '',
    'details' => $job_wrapper->body->summary->value(),
  );

  // Get order line items.
  $line_items = $order_wrapper->commerce_line_items->value();

  $main_lines = array();
  $tax_lines = array();
  $additional_lines = array();

  foreach ($line_items as $_line_item) {
    $_line_item_wrapper = entity_metadata_wrapper('commerce_line_item', $_line_item);
    $type = $_line_item_wrapper->field_line_item_type->value();

    $_amount = $_line_item_wrapper->commerce_total->amount->value();
    $_currency_code = $_line_item_wrapper->commerce_total->currency_code->value();

    $line = array(
      'label' => t($_line_item->line_item_label),
      'quantity' => $_line_item->quantity,
      'amount' => $_amount,
      'currency_code' => $_currency_code,
    );

    switch ($type) {
      case MP_INVOICES_LINE_ITEM_TYPE_MAIN:
        $main_lines[] = $line;
        break;

      case MP_INVOICES_LINE_ITEM_TYPE_TAX:
        $tax_lines[] = $line;
        break;

      case MP_INVOICES_LINE_ITEM_TYPE_ADDITIONAL:
        $additional_lines[] = $line;
        break;

      default:
        // Nothing to do.
    }
  }

  $page['content']['bills'] = array(
    'main' => array(
      'prefix' => t(variable_get('mpi_main_prefix', '')),
      'lines' => $main_lines,
      'suffix' => t(variable_get('mpi_main_suffix', '')),
    ),
    'tax' => array(
      'prefix' => t(variable_get('mpi_tax_prefix', '')),
      'lines' => $tax_lines,
      'suffix' => t(variable_get('mpi_tax_suffix', '')),
    ),
    'additional' => array(
      'prefix' => t(variable_get('mpi_additional_prefix', '')),
      'lines' => $additional_lines,
      'suffix' => t(variable_get('mpi_additional_suffix', '')),
    ),
    'total' => array(
      'label' => t('Total Invoice:'),
      'amount' => $order_wrapper->commerce_order_total->amount->value(),
      'currency_code' => $_currency_code,
    ),
  );

  $page['footer'] = array();
  $page['footer']['part_1'] = t(variable_get('mpi_footer_part_1', ''));
  $page['footer']['part_2'] = t(variable_get('mpi_footer_part_2', ''));

  $output = theme('mp_invoices_page', $page);

  return $output;
}