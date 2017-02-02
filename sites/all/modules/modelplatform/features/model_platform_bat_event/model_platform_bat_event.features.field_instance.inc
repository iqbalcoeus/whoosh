<?php
/**
 * @file
 * model_platform_bat_event.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function model_platform_bat_event_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'bat_event-model_availability-event_bat_unit_reference'.
  $field_instances['bat_event-model_availability-event_bat_unit_reference'] = array(
    'bundle' => 'model_availability',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'bat_event',
    'field_name' => 'event_bat_unit_reference',
    'label' => 'Unit',
    'required' => FALSE,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'bat_event-model_availability-event_state_reference'.
  $field_instances['bat_event-model_availability-event_state_reference'] = array(
    'bundle' => 'model_availability',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'bat_event',
        'settings' => array(),
        'type' => 'bat_event_state_reference_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'bat_event',
    'field_name' => 'event_state_reference',
    'label' => 'State',
    'required' => FALSE,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'event_type' => 'model_availability',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'bat_event',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'autocomplete_path' => 'bat_event/state_event/autocomplete',
        'size' => 60,
      ),
      'type' => 'bat_event_reference_autocomplete',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'bat_event-model_availability-field_job'.
  $field_instances['bat_event-model_availability-field_job'] = array(
    'bundle' => 'model_availability',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'bat_event',
    'field_name' => 'field_job',
    'label' => 'Job',
    'required' => 1,
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

  // Exported field_instance: 'bat_event-model_availability-field_job_cost'.
  $field_instances['bat_event-model_availability-field_job_cost'] = array(
    'bundle' => 'model_availability',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => FALSE,
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'bat_event',
    'field_name' => 'field_job_cost',
    'label' => 'Cost',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'commerce_price',
      'settings' => array(
        'currency_code' => 'default',
      ),
      'type' => 'commerce_price_full',
      'weight' => 3,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Cost');
  t('Job');
  t('State');
  t('Unit');

  return $field_instances;
}
