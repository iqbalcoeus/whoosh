<?php
/**
 * @file
 * model_platform_job_template.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function model_platform_job_template_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_job_block|node|job|default';
  $field_group->group_name = 'group_job_block';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'job';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Job block',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_job_start_date',
      2 => 'field_job_additional_documents',
      3 => 'field_job_payment_approval',
      4 => 'field_job_status',
      5 => 'field_job_daily_rate_from',
      6 => 'field_job_daily_rate_to',
      7 => 'field_job_travel_budget',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Job block',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-job-block field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_job_block|node|job|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_job_daily_rate|node|job|form';
  $field_group->group_name = 'group_job_daily_rate';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'job';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Daily payment rate',
    'weight' => '4',
    'children' => array(
      0 => 'field_job_daily_rate_from',
      1 => 'field_job_daily_rate_to',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-job-daily-rate field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_job_daily_rate|node|job|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Daily payment rate');
  t('Job block');

  return $field_groups;
}
