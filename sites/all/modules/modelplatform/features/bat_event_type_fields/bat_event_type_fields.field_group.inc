<?php
/**
 * @file
 * bat_event_type_fields.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function bat_event_type_fields_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_model_documents|bat_event|model_availability|form';
  $field_group->group_name = 'group_model_documents';
  $field_group->entity_type = 'bat_event';
  $field_group->bundle = 'model_availability';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Model Documents',
    'weight' => '6',
    'children' => array(
      0 => 'field_additional_receipts',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-model-documents field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Model Documents');

  return $field_groups;
}
