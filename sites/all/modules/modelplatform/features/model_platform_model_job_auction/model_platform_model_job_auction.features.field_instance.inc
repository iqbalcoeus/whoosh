<?php
/**
 * @file
 * model_platform_model_job_auction.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function model_platform_model_job_auction_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'mp_auction-auction-field_decision_user'.
  $field_instances['mp_auction-auction-field_decision_user'] = array(
    'bundle' => 'auction',
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
        'weight' => 4,
      ),
    ),
    'entity_type' => 'mp_auction',
    'field_name' => 'field_decision_user',
    'label' => 'Decision user',
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
      'weight' => 5,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Decision user');

  return $field_instances;
}
