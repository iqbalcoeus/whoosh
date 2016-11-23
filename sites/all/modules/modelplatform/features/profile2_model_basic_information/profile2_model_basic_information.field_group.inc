<?php
/**
 * @file
 * profile2_model_basic_information.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function profile2_model_basic_information_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dimensions|profile2|model_basic_informaiton|form';
  $field_group->group_name = 'group_dimensions';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'model_basic_informaiton';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Dimensions',
    'weight' => '4',
    'children' => array(
      0 => 'field_chest',
      1 => 'field_waist',
      2 => 'field_hip',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-dimensions field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_dimensions|profile2|model_basic_informaiton|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_model_size|profile2|model_basic_informaiton|form';
  $field_group->group_name = 'group_model_size';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'model_basic_informaiton';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Size',
    'weight' => '5',
    'children' => array(
      0 => 'field_verification_status',
      1 => 'field_model_size',
      2 => 'field_shoe_size',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-model-size field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_model_size|profile2|model_basic_informaiton|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Dimensions');
  t('Size');

  return $field_groups;
}
