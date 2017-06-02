<?php
/**
 * @file
 * bat_event_type_fields.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function bat_event_type_fields_field_default_field_instances() {
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

  // Exported field_instance:
  // 'bat_event-model_availability-field_additional_receipts'.
  $field_instances['bat_event-model_availability-field_additional_receipts'] = array(
    'bundle' => 'model_availability',
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
        'weight' => 4,
      ),
    ),
    'entity_type' => 'bat_event',
    'field_name' => 'field_additional_receipts',
    'label' => 'Additional receipts',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 4,
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

  // Exported field_instance: 'bat_event-model_availability-field_order'.
  $field_instances['bat_event-model_availability-field_order'] = array(
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
        'weight' => 5,
      ),
    ),
    'entity_type' => 'bat_event',
    'field_name' => 'field_order',
    'label' => 'Order',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'commerce_order-commerce_order-field_event'.
  $field_instances['commerce_order-commerce_order-field_event'] = array(
    'bundle' => 'commerce_order',
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
        'weight' => -4,
      ),
    ),
    'entity_type' => 'commerce_order',
    'field_name' => 'field_event',
    'label' => 'Event',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => -4,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_additional_receipts-field_document'.
  $field_instances['field_collection_item-field_additional_receipts-field_document'] = array(
    'bundle' => 'field_additional_receipts',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_document',
    'label' => 'Document',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'entity_translation_sync' => FALSE,
      'file_directory' => '',
      'file_extensions' => 'jpg pdf png jpeg',
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
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_additional_receipts-field_reciept_admin'.
  $field_instances['field_collection_item-field_additional_receipts-field_reciept_admin'] = array(
    'bundle' => 'field_additional_receipts',
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
        'weight' => 5,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_reciept_admin',
    'label' => 'Reciept admin',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_additional_receipts-field_reciept_approved_by_admin'.
  $field_instances['field_collection_item-field_additional_receipts-field_reciept_approved_by_admin'] = array(
    'bundle' => 'field_additional_receipts',
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
        'weight' => 4,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_reciept_approved_by_admin',
    'label' => 'Reciept approved by admin',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_additional_receipts-field_reciept_comment'.
  $field_instances['field_collection_item-field_additional_receipts-field_reciept_comment'] = array(
    'bundle' => 'field_additional_receipts',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_reciept_comment',
    'label' => 'Reciept comment',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
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
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_additional_receipts-field_reciept_cost'.
  $field_instances['field_collection_item-field_additional_receipts-field_reciept_cost'] = array(
    'bundle' => 'field_additional_receipts',
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
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_reciept_cost',
    'label' => 'Reciept cost',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'commerce_price',
      'settings' => array(
        'currency_code' => 'EUR',
      ),
      'type' => 'commerce_price_full',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_additional_receipts-field_reciept_type'.
  $field_instances['field_collection_item-field_additional_receipts-field_reciept_type'] = array(
    'bundle' => 'field_additional_receipts',
    'default_value' => array(
      0 => array(
        'value' => 'Own receipt',
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
    'field_name' => 'field_reciept_type',
    'label' => 'Reciept type',
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
      'weight' => 0,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Additional receipts');
  t('Cost');
  t('Document');
  t('Event');
  t('Job');
  t('Order');
  t('Reciept admin');
  t('Reciept approved by admin');
  t('Reciept comment');
  t('Reciept cost');
  t('Reciept type');
  t('State');
  t('Unit');

  return $field_instances;
}
