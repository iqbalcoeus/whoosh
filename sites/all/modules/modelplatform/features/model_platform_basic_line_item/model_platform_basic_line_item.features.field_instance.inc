<?php
/**
 * @file
 * model_platform_basic_line_item.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function model_platform_basic_line_item_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'commerce_line_item-basic_line_item-field_line_item_type'.
  $field_instances['commerce_line_item-basic_line_item-field_line_item_type'] = array(
    'bundle' => 'basic_line_item',
    'default_value' => array(
      0 => array(
        'value' => 'additional',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'commerce_line_item',
    'field_name' => 'field_line_item_type',
    'label' => 'Line item type',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Line item type');

  return $field_instances;
}
