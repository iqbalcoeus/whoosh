<?php
/**
 * @file
 * profile2_model_private_data.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function profile2_model_private_data_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_model_documents|profile2|model_private_data|form';
  $field_group->group_name = 'group_model_documents';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'model_private_data';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_model_tabs';
  $field_group->data = array(
    'label' => 'Documents',
    'weight' => '2',
    'children' => array(
      0 => 'field_identity_card_or_pasport',
      1 => 'field_local_registration_documen',
      2 => 'field_other_documents',
      3 => 'field_parental_approval_for_mino',
      4 => 'field_income_tax_certificate',
      5 => 'field_travel_passport',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-model-documents field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_model_documents|profile2|model_private_data|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_model_tabs|profile2|model_private_data|form';
  $field_group->group_name = 'group_model_tabs';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'model_private_data';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '0',
    'children' => array(
      0 => 'group_personal_data',
      1 => 'group_model_documents',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-model-tabs field-group-htabs',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_model_tabs|profile2|model_private_data|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_personal_data|profile2|model_private_data|form';
  $field_group->group_name = 'group_personal_data';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'model_private_data';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_model_tabs';
  $field_group->data = array(
    'label' => 'Personal data',
    'weight' => '1',
    'children' => array(
      0 => 'field_complete_address',
      1 => 'field_income_tax_number',
      2 => 'field_account_number_paypal',
      3 => 'field_instagram',
      4 => 'field_model_agency',
      5 => 'field_model_agensy_terms_of_use',
      6 => 'field_model_mega',
      7 => 'field_agency_link_to_sedcard',
      8 => 'field_account_holder',
      9 => 'field_iban',
      10 => 'field_paypal',
      11 => 'field_c_base_city',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_personal_data|profile2|model_private_data|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Documents');
  t('Personal data');

  return $field_groups;
}
