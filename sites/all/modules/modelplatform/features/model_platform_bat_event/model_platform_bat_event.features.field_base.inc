<?php
/**
 * @file
 * model_platform_bat_event.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function model_platform_bat_event_field_default_field_bases() {
  $field_bases = array();

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

  // Exported field_base: 'event_state_reference'.
  $field_bases['event_state_reference'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'event_state_reference',
    'indexes' => array(
      'state_id' => array(
        0 => 'state_id',
      ),
    ),
    'locked' => 1,
    'module' => 'bat_event',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'event_type' => '',
    ),
    'translatable' => 0,
    'type' => 'bat_event_state_reference',
  );

  // Exported field_base: 'field_job'.
  $field_bases['field_job'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_job',
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
          'job' => 'job',
        ),
      ),
      'profile2_private' => FALSE,
      'target_type' => 'node',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_job_cost'.
  $field_bases['field_job_cost'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_job_cost',
    'indexes' => array(
      'currency_price' => array(
        0 => 'amount',
        1 => 'currency_code',
      ),
    ),
    'locked' => 0,
    'module' => 'commerce_price',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'commerce_price',
  );

  return $field_bases;
}
