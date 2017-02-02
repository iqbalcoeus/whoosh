<?php
/**
 * @file
 * model_platform_bat_unit.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function model_platform_bat_unit_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'commerce_unit_price'.
  $field_bases['commerce_unit_price'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'commerce_line_item',
    ),
    'field_name' => 'commerce_unit_price',
    'indexes' => array(
      'currency_price' => array(
        0 => 'amount',
        1 => 'currency_code',
      ),
    ),
    'locked' => 1,
    'module' => 'commerce_price',
    'settings' => array(
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'commerce_price',
  );

  // Exported field_base: 'event_bat_unit_reference'.
  $field_bases['event_bat_unit_reference'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'event_bat_unit_reference',
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 1,
    'module' => 'entityreference',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'handler' => 'base',
      'handler_settings' => array(),
      'target_type' => 'bat_unit',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_bat_unit'.
  $field_bases['field_bat_unit'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_bat_unit',
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'default' => 'default',
        ),
      ),
      'profile2_private' => FALSE,
      'target_type' => 'bat_unit',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  return $field_bases;
}
