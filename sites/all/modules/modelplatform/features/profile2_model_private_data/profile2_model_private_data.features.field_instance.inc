<?php
/**
 * @file
 * profile2_model_private_data.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function profile2_model_private_data_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'field_collection_item-field_c_base_city-field_base_city_checked'.
  $field_instances['field_collection_item-field_c_base_city-field_base_city_checked'] = array(
    'bundle' => 'field_c_base_city',
    'default_value' => array(
      0 => array(
        'value' => 0,
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
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_base_city_checked',
    'label' => 'Base City Checked',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 0,
      ),
      'type' => 'options_onoff',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_c_base_city-field_model_base_city'.
  $field_instances['field_collection_item-field_c_base_city-field_model_base_city'] = array(
    'bundle' => 'field_c_base_city',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'i18n_taxonomy',
        'settings' => array(),
        'type' => 'i18n_taxonomy_term_reference_link',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_model_base_city',
    'label' => 'Base city',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'profile2-model_private_data-field_account_holder'.
  $field_instances['profile2-model_private_data-field_account_holder'] = array(
    'bundle' => 'model_private_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 13,
      ),
    ),
    'entity_type' => 'profile2',
    'field_name' => 'field_account_holder',
    'label' => 'Account holder',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'profile2-model_private_data-field_account_number_paypal'.
  $field_instances['profile2-model_private_data-field_account_number_paypal'] = array(
    'bundle' => 'model_private_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'profile2',
    'field_name' => 'field_account_number_paypal',
    'label' => 'Account number',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'profile2-model_private_data-field_agency_link_to_sedcard'.
  $field_instances['profile2-model_private_data-field_agency_link_to_sedcard'] = array(
    'bundle' => 'model_private_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'profile2',
    'field_name' => 'field_agency_link_to_sedcard',
    'label' => 'Link to Sedcard',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => '_blank',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'profile2-model_private_data-field_base_city'.
  $field_instances['profile2-model_private_data-field_base_city'] = array(
    'bundle' => 'model_private_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 12,
      ),
    ),
    'entity_type' => 'profile2',
    'field_name' => 'field_base_city',
    'label' => 'Base city',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'profile2-model_private_data-field_c_base_city'.
  $field_instances['profile2-model_private_data-field_c_base_city'] = array(
    'bundle' => 'model_private_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'field_collection',
        'settings' => array(
          'add' => 'Add',
          'delete' => 'Delete',
          'description' => TRUE,
          'edit' => 'Edit',
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_view',
        'weight' => 19,
      ),
    ),
    'entity_type' => 'profile2',
    'field_name' => 'field_c_base_city',
    'label' => 'Base city',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'profile2-model_private_data-field_complete_address'.
  $field_instances['profile2-model_private_data-field_complete_address'] = array(
    'bundle' => 'model_private_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'profile2',
    'field_name' => 'field_complete_address',
    'label' => 'Complete Address',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'addressfield',
      'settings' => array(
        'available_countries' => array(),
        'default_country' => 'DE',
        'format_handlers' => array(
          'address' => 'address',
          'address-optional' => 'address-optional',
          'address-hide-postal-code' => 0,
          'address-hide-street' => 0,
          'address-hide-country' => 0,
          'organisation' => 0,
          'name-full' => 0,
          'name-oneline' => 0,
        ),
      ),
      'type' => 'addressfield_standard',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'profile2-model_private_data-field_iban'.
  $field_instances['profile2-model_private_data-field_iban'] = array(
    'bundle' => 'model_private_data',
    'default_value' => array(
      0 => array(
        'iban_field' => '',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'iban_field',
        'settings' => array(),
        'type' => 'iban_field_default',
        'weight' => 14,
      ),
    ),
    'entity_type' => 'profile2',
    'field_name' => 'field_iban',
    'label' => 'IBAN',
    'required' => 0,
    'settings' => array(
      'iban_field_country_settings' => array(
        'iban_field_enabled_countries' => array(
          'AD' => 'AD',
          'AE' => 'AE',
          'AL' => 'AL',
          'AT' => 'AT',
          'AZ' => 'AZ',
          'BA' => 'BA',
          'BE' => 'BE',
          'BH' => 'BH',
          'BR' => 'BR',
          'CH' => 'CH',
          'CR' => 'CR',
          'CY' => 'CY',
          'CZ' => 'CZ',
          'DE' => 'DE',
          'DK' => 'DK',
          'DO' => 'DO',
          'EE' => 'EE',
          'ES' => 'ES',
          'FI' => 'FI',
          'FR' => 'FR',
          'GB' => 'GB',
          'GE' => 'GE',
          'GI' => 'GI',
          'GR' => 'GR',
          'GT' => 'GT',
          'HR' => 'HR',
          'HU' => 'HU',
          'IE' => 'IE',
          'IL' => 'IL',
          'IS' => 'IS',
        ),
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'iban_field',
      'settings' => array(),
      'type' => 'iban_field',
      'weight' => 7,
    ),
  );

  // Exported field_instance:
  // 'profile2-model_private_data-field_identity_card_or_pasport'.
  $field_instances['profile2-model_private_data-field_identity_card_or_pasport'] = array(
    'bundle' => 'model_private_data',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'profile2',
    'field_name' => 'field_identity_card_or_pasport',
    'label' => ' Copy of personal ID or passport (both sides)',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => 'model_documents/[current-user:uid]/card_pasport',
      'file_extensions' => 'pdf',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 20,
    ),
  );

  // Exported field_instance:
  // 'profile2-model_private_data-field_income_tax_certificate'.
  $field_instances['profile2-model_private_data-field_income_tax_certificate'] = array(
    'bundle' => 'model_private_data',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 17,
      ),
    ),
    'entity_type' => 'profile2',
    'field_name' => 'field_income_tax_certificate',
    'label' => 'Income tax certificate',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => 'model_documents/[current-user:uid]/tax-certificate',
      'file_extensions' => 'pdf',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 18,
    ),
  );

  // Exported field_instance:
  // 'profile2-model_private_data-field_income_tax_number'.
  $field_instances['profile2-model_private_data-field_income_tax_number'] = array(
    'bundle' => 'model_private_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'profile2',
    'field_name' => 'field_income_tax_number',
    'label' => 'Income tax ID',
    'required' => 0,
    'settings' => array(
      'max' => 100,
      'min' => 0,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'profile2-model_private_data-field_instagram'.
  $field_instances['profile2-model_private_data-field_instagram'] = array(
    'bundle' => 'model_private_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'profile2',
    'field_name' => 'field_instagram',
    'label' => 'Link to Instagram account',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => '_blank',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 9,
    ),
  );

  // Exported field_instance:
  // 'profile2-model_private_data-field_local_registration_documen'.
  $field_instances['profile2-model_private_data-field_local_registration_documen'] = array(
    'bundle' => 'model_private_data',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'profile2',
    'field_name' => 'field_local_registration_documen',
    'label' => 'Certificate of registration',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => 'model_documents/[current-user:uid]/card_pasport',
      'file_extensions' => 'pdf',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 22,
    ),
  );

  // Exported field_instance: 'profile2-model_private_data-field_model_agency'.
  $field_instances['profile2-model_private_data-field_model_agency'] = array(
    'bundle' => 'model_private_data',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'profile2',
    'field_name' => 'field_model_agency',
    'label' => 'Model agency entry',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 10,
    ),
  );

  // Exported field_instance:
  // 'profile2-model_private_data-field_model_agensy_terms_of_use'.
  $field_instances['profile2-model_private_data-field_model_agensy_terms_of_use'] = array(
    'bundle' => 'model_private_data',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'profile2',
    'field_name' => 'field_model_agensy_terms_of_use',
    'label' => 'Model Agency <a href="/content/terms">terms</a> of use',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'profile2-model_private_data-field_model_mega'.
  $field_instances['profile2-model_private_data-field_model_mega'] = array(
    'bundle' => 'model_private_data',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'profile2',
    'field_name' => 'field_model_mega',
    'label' => 'Model Mega',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 12,
    ),
  );

  // Exported field_instance:
  // 'profile2-model_private_data-field_other_documents'.
  $field_instances['profile2-model_private_data-field_other_documents'] = array(
    'bundle' => 'model_private_data',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
    ),
    'entity_type' => 'profile2',
    'field_name' => 'field_other_documents',
    'label' => 'Additional documents',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => 'model_documents/[current-user:uid]/other',
      'file_extensions' => 'pdf',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 23,
    ),
  );

  // Exported field_instance:
  // 'profile2-model_private_data-field_parental_approval_for_mino'.
  $field_instances['profile2-model_private_data-field_parental_approval_for_mino'] = array(
    'bundle' => 'model_private_data',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 16,
      ),
    ),
    'entity_type' => 'profile2',
    'field_name' => 'field_parental_approval_for_mino',
    'label' => 'Parental approval for minors',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => 'model_documents/[current-user:uid]/other',
      'file_extensions' => 'pdf',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 19,
    ),
  );

  // Exported field_instance: 'profile2-model_private_data-field_paypal'.
  $field_instances['profile2-model_private_data-field_paypal'] = array(
    'bundle' => 'model_private_data',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
        'weight' => 15,
      ),
    ),
    'entity_type' => 'profile2',
    'field_name' => 'field_paypal',
    'label' => 'PayPal',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'email',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'email_textfield',
      'weight' => 8,
    ),
  );

  // Exported field_instance:
  // 'profile2-model_private_data-field_travel_passport'.
  $field_instances['profile2-model_private_data-field_travel_passport'] = array(
    'bundle' => 'model_private_data',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 18,
      ),
    ),
    'entity_type' => 'profile2',
    'field_name' => 'field_travel_passport',
    'label' => 'Travel passport',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => 'model_documents/[current-user:uid]/card_pasport',
      'file_extensions' => 'pdf',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 21,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t(' Copy of personal ID or passport (both sides)');
  t('Account holder');
  t('Account number');
  t('Additional documents');
  t('Base City Checked');
  t('Base city');
  t('Certificate of registration');
  t('Complete Address');
  t('IBAN');
  t('Income tax ID');
  t('Income tax certificate');
  t('Link to Instagram account');
  t('Link to Sedcard');
  t('Model Agency <a href="/content/terms">terms</a> of use');
  t('Model Mega');
  t('Model agency entry');
  t('Parental approval for minors');
  t('PayPal');
  t('Travel passport');

  return $field_instances;
}
