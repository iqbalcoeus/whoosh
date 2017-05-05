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

  return $field_groups;
}
