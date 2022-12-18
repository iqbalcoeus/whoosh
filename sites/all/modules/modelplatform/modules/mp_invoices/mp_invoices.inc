<?php

/**
 * @file
 * Model Platform - Invoices helper functions.
 */

/**
 * Return TRUE if model is from the Germany.
 */
function _mp_invoices_model_is_german($model) {
  $model_profiles = profile2_load_by_user($model);
  $is_german_model = FALSE;
  if (isset($model_profiles['model_private_data'])) {
    $model_profile_wrapper = entity_metadata_wrapper('profile2', $model_profiles['model_private_data']);
    $is_german_model = ($model_profile_wrapper->field_complete_address->value()['country'] == 'DE');
  }

  return $is_german_model;
}

/**
 * Create commerce line item without product.
 */
function _mp_invoices_line_item_create($order_id, $label, $qty, $price, $type) {
  $line_item = commerce_line_item_new('basic_line_item', $order_id);
  $line_item->line_item_label = $label;
  $line_item->quantity = $qty;
  $price['data'] = commerce_price_component_add($price, 'basic_line_item', $price, TRUE, FALSE);
  $line_item->commerce_unit_price[LANGUAGE_NONE][0] = $price;
  $line_item->field_line_item_type[LANGUAGE_NONE][0]['value'] = $type;
  commerce_line_item_save($line_item);

  return $line_item;
}