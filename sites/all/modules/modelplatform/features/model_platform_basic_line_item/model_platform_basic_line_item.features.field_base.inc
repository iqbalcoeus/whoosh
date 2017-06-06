<?php
/**
 * @file
 * model_platform_basic_line_item.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function model_platform_basic_line_item_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_line_item_type'.
  $field_bases['field_line_item_type'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_line_item_type',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'main' => 'Main',
        'tax' => 'Tax',
        'additional' => 'Additional',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
