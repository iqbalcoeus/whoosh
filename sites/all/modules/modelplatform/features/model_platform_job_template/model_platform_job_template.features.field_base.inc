<?php
/**
 * @file
 * model_platform_job_template.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function model_platform_job_template_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'body'.
  $field_bases['body'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'node',
    ),
    'field_name' => 'body',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'profile2_private' => FALSE,
    ),
    'translatable' => 1,
    'type' => 'text_with_summary',
  );

  // Exported field_base: 'field_job_additional_documents'.
  $field_bases['field_job_additional_documents'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_job_additional_documents',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'file',
    'settings' => array(
      'display_default' => 0,
      'display_field' => 0,
      'entity_translation_sync' => array(
        0 => 'fid',
      ),
      'profile2_private' => FALSE,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'file',
  );

  // Exported field_base: 'field_job_daily_rate_from'.
  $field_bases['field_job_daily_rate_from'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_job_daily_rate_from',
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
    'title' => 'Daily rate',
    'translatable' => 0,
    'type' => 'commerce_price',
    'weight' => -1,
  );

  // Exported field_base: 'field_job_daily_rate_to'.
  $field_bases['field_job_daily_rate_to'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_job_daily_rate_to',
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
    'title' => 'Daily rate',
    'translatable' => 0,
    'type' => 'commerce_price',
    'weight' => -1,
  );

  // Exported field_base: 'field_job_payment_approval'.
  $field_bases['field_job_payment_approval'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_job_payment_approval',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'file',
    'settings' => array(
      'display_default' => 0,
      'display_field' => 0,
      'entity_translation_sync' => array(
        0 => 'fid',
      ),
      'profile2_private' => FALSE,
      'uri_scheme' => 'private',
    ),
    'translatable' => 0,
    'type' => 'file',
  );

  // Exported field_base: 'field_job_start_date'.
  $field_bases['field_job_start_date'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_job_start_date',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'date',
    'settings' => array(
      'cache_count' => 4,
      'cache_enabled' => 0,
      'entity_translation_sync' => FALSE,
      'granularity' => array(
        'day' => 'day',
        'hour' => 'hour',
        'minute' => 'minute',
        'month' => 'month',
        'second' => 0,
        'year' => 'year',
      ),
      'profile2_private' => FALSE,
      'timezone_db' => 'UTC',
      'todate' => 'required',
      'tz_handling' => 'site',
    ),
    'translatable' => 0,
    'type' => 'datetime',
  );

  // Exported field_base: 'field_job_travel_budget'.
  $field_bases['field_job_travel_budget'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_job_travel_budget',
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

  // Exported field_base: 'field_job_travel_days'.
  $field_bases['field_job_travel_days'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_job_travel_days',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  return $field_bases;
}
