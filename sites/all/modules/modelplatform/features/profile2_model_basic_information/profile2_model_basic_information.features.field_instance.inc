<?php
/**
 * @file
 * profile2_model_basic_information.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function profile2_model_basic_information_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'profile2-model_basic_informaiton-field_age_category'.
  $field_instances['profile2-model_basic_informaiton-field_age_category'] = array(
    'bundle' => 'model_basic_informaiton',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'i18n_taxonomy',
        'settings' => array(),
        'type' => 'i18n_taxonomy_term_reference_link',
        'weight' => 12,
      ),
    ),
    'entity_type' => 'profile2',
    'field_name' => 'field_age_category',
    'label' => 'Age category',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'options_select',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'profile2-model_basic_informaiton-field_birthday'.
  $field_instances['profile2-model_basic_informaiton-field_birthday'] = array(
    'bundle' => 'model_basic_informaiton',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_remaining_days' => FALSE,
        ),
        'type' => 'date_default',
        'weight' => 11,
      ),
    ),
    'entity_type' => 'profile2',
    'field_name' => 'field_birthday',
    'label' => 'Birthday',
    'required' => 1,
    'settings' => array(
      'default_value' => 'blank',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 1,
        'input_format' => 'm/d/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'no_fieldset' => 0,
        'text_parts' => array(),
        'year_range' => '1970:+0',
      ),
      'type' => 'date_popup',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'profile2-model_basic_informaiton-field_chest'.
  $field_instances['profile2-model_basic_informaiton-field_chest'] = array(
    'bundle' => 'model_basic_informaiton',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Please insert data in Inches',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'profile2',
    'field_name' => 'field_chest',
    'label' => 'Bust',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max' => 115,
      'min' => 75,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'profile2-model_basic_informaiton-field_daily_rate'.
  $field_instances['profile2-model_basic_informaiton-field_daily_rate'] = array(
    'bundle' => 'model_basic_informaiton',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Can\'t be less then 500',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'commerce_price',
        'settings' => array(
          'calculation' => FALSE,
        ),
        'type' => 'commerce_price_formatted_amount',
        'weight' => 21,
      ),
    ),
    'entity_type' => 'profile2',
    'field_name' => 'field_daily_rate',
    'label' => 'Daily rate',
    'required' => 1,
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
      'type' => 'commerce_price_simple',
      'weight' => 14,
    ),
  );

  // Exported field_instance: 'profile2-model_basic_informaiton-field_height'.
  $field_instances['profile2-model_basic_informaiton-field_height'] = array(
    'bundle' => 'model_basic_informaiton',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'profile2',
    'field_name' => 'field_height',
    'label' => 'Height',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max' => 189,
      'min' => 168,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'profile2-model_basic_informaiton-field_hip'.
  $field_instances['profile2-model_basic_informaiton-field_hip'] = array(
    'bundle' => 'model_basic_informaiton',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Please insert data in Inches',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'profile2',
    'field_name' => 'field_hip',
    'label' => 'Hips',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max' => 100,
      'min' => 85,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 8,
    ),
  );

  // Exported field_instance:
  // 'profile2-model_basic_informaiton-field_model_ethnicity'.
  $field_instances['profile2-model_basic_informaiton-field_model_ethnicity'] = array(
    'bundle' => 'model_basic_informaiton',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'i18n_taxonomy',
        'settings' => array(),
        'type' => 'i18n_taxonomy_term_reference_link',
        'weight' => 20,
      ),
    ),
    'entity_type' => 'profile2',
    'field_name' => 'field_model_ethnicity',
    'label' => 'Ethnicity',
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
      'weight' => 9,
    ),
  );

  // Exported field_instance:
  // 'profile2-model_basic_informaiton-field_model_eye_color'.
  $field_instances['profile2-model_basic_informaiton-field_model_eye_color'] = array(
    'bundle' => 'model_basic_informaiton',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'i18n_taxonomy',
        'settings' => array(),
        'type' => 'i18n_taxonomy_term_reference_link',
        'weight' => 18,
      ),
    ),
    'entity_type' => 'profile2',
    'field_name' => 'field_model_eye_color',
    'label' => 'Eye color',
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

  // Exported field_instance:
  // 'profile2-model_basic_informaiton-field_model_gender'.
  $field_instances['profile2-model_basic_informaiton-field_model_gender'] = array(
    'bundle' => 'model_basic_informaiton',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'i18n_taxonomy',
        'settings' => array(),
        'type' => 'i18n_taxonomy_term_reference_link',
        'weight' => 16,
      ),
    ),
    'entity_type' => 'profile2',
    'field_name' => 'field_model_gender',
    'label' => 'Gender',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 0,
    ),
  );

  // Exported field_instance:
  // 'profile2-model_basic_informaiton-field_model_hair_color'.
  $field_instances['profile2-model_basic_informaiton-field_model_hair_color'] = array(
    'bundle' => 'model_basic_informaiton',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'i18n_taxonomy',
        'settings' => array(),
        'type' => 'i18n_taxonomy_term_reference_link',
        'weight' => 17,
      ),
    ),
    'entity_type' => 'profile2',
    'field_name' => 'field_model_hair_color',
    'label' => 'Hair color',
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
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'profile2-model_basic_informaiton-field_model_instagram_followers'.
  $field_instances['profile2-model_basic_informaiton-field_model_instagram_followers'] = array(
    'bundle' => 'model_basic_informaiton',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'i18n_taxonomy',
        'settings' => array(),
        'type' => 'i18n_taxonomy_term_reference_link',
        'weight' => 19,
      ),
    ),
    'entity_type' => 'profile2',
    'field_name' => 'field_model_instagram_followers',
    'label' => 'Instagram followers',
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
      'weight' => 8,
    ),
  );

  // Exported field_instance:
  // 'profile2-model_basic_informaiton-field_model_size'.
  $field_instances['profile2-model_basic_informaiton-field_model_size'] = array(
    'bundle' => 'model_basic_informaiton',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => '',
        ),
        'type' => 'number_decimal',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'profile2',
    'field_name' => 'field_model_size',
    'label' => 'Size',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max' => '',
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
      'weight' => 12,
    ),
  );

  // Exported field_instance:
  // 'profile2-model_basic_informaiton-field_shoe_size'.
  $field_instances['profile2-model_basic_informaiton-field_shoe_size'] = array(
    'bundle' => 'model_basic_informaiton',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 2,
          'thousand_separator' => '',
        ),
        'type' => 'number_decimal',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'profile2',
    'field_name' => 'field_shoe_size',
    'label' => 'Shoe size',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max' => '',
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
      'weight' => 13,
    ),
  );

  // Exported field_instance:
  // 'profile2-model_basic_informaiton-field_verification_status'.
  $field_instances['profile2-model_basic_informaiton-field_verification_status'] = array(
    'bundle' => 'model_basic_informaiton',
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
        'weight' => 8,
      ),
    ),
    'entity_type' => 'profile2',
    'field_name' => 'field_verification_status',
    'label' => 'Measurements verification status',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'profile2-model_basic_informaiton-field_waist'.
  $field_instances['profile2-model_basic_informaiton-field_waist'] = array(
    'bundle' => 'model_basic_informaiton',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Please insert data in Inches',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'profile2',
    'field_name' => 'field_waist',
    'label' => 'Waist',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max' => 85,
      'min' => 58,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'taxonomy_term-age_category-field_age_to'.
  $field_instances['taxonomy_term-age_category-field_age_to'] = array(
    'bundle' => 'age_category',
    'default_value' => array(
      0 => array(
        'value' => 100,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_age_to',
    'label' => 'Age to',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max' => '',
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
      'weight' => 42,
    ),
  );

  // Exported field_instance: 'taxonomy_term-age_category-field_min_age'.
  $field_instances['taxonomy_term-age_category-field_min_age'] = array(
    'bundle' => 'age_category',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_min_age',
    'label' => 'Age from',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max' => '',
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
      'weight' => 41,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Age category');
  t('Age from');
  t('Age to');
  t('Birthday');
  t('Bust');
  t('Can\'t be less then 500');
  t('Daily rate');
  t('Ethnicity');
  t('Eye color');
  t('Gender');
  t('Hair color');
  t('Height');
  t('Hips');
  t('Instagram followers');
  t('Measurements verification status');
  t('Please insert data in Inches');
  t('Shoe size');
  t('Size');
  t('Waist');

  return $field_instances;
}
