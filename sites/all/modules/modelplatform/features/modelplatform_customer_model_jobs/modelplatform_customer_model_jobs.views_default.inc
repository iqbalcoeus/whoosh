<?php
/**
 * @file
 * modelplatform_customer_model_jobs.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function modelplatform_customer_model_jobs_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'customer_model_jobs';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'bat_events';
  $view->human_name = 'Customer Model Jobs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Customer Model Jobs';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Job */
  $handler->display->display_options['relationships']['field_job_target_id']['id'] = 'field_job_target_id';
  $handler->display->display_options['relationships']['field_job_target_id']['table'] = 'field_data_field_job';
  $handler->display->display_options['relationships']['field_job_target_id']['field'] = 'field_job_target_id';
  $handler->display->display_options['relationships']['field_job_target_id']['ui_name'] = 'Job';
  $handler->display->display_options['relationships']['field_job_target_id']['label'] = 'Job';
  $handler->display->display_options['relationships']['field_job_target_id']['required'] = TRUE;
  /* Relationship: Unit */
  $handler->display->display_options['relationships']['event_bat_unit_reference_target_id']['id'] = 'event_bat_unit_reference_target_id';
  $handler->display->display_options['relationships']['event_bat_unit_reference_target_id']['table'] = 'field_data_event_bat_unit_reference';
  $handler->display->display_options['relationships']['event_bat_unit_reference_target_id']['field'] = 'event_bat_unit_reference_target_id';
  $handler->display->display_options['relationships']['event_bat_unit_reference_target_id']['ui_name'] = 'Unit';
  $handler->display->display_options['relationships']['event_bat_unit_reference_target_id']['label'] = 'Unit';
  $handler->display->display_options['relationships']['event_bat_unit_reference_target_id']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_job_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Events: Cost */
  $handler->display->display_options['fields']['field_job_cost']['id'] = 'field_job_cost';
  $handler->display->display_options['fields']['field_job_cost']['table'] = 'field_data_field_job_cost';
  $handler->display->display_options['fields']['field_job_cost']['field'] = 'field_job_cost';
  $handler->display->display_options['fields']['field_job_cost']['label'] = '';
  $handler->display->display_options['fields']['field_job_cost']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_job_cost']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['field_job_cost']['settings'] = array(
    'calculation' => FALSE,
  );
  $handler->display->display_options['fields']['field_job_cost']['group_column'] = 'entity_id';
  /* Field: Confirmed */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Confirmed';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Confirmed';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_class'] = 'confirmed';
  /* Field: Cancel job */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Cancel job';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '<a href="#">Cancel job</a>';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'field_job_target_id';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Unit: Uid */
  $handler->display->display_options['arguments']['uid_1']['id'] = 'uid_1';
  $handler->display->display_options['arguments']['uid_1']['table'] = 'bat_units';
  $handler->display->display_options['arguments']['uid_1']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid_1']['relationship'] = 'event_bat_unit_reference_target_id';
  $handler->display->display_options['arguments']['uid_1']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid_1']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['uid_1']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['uid_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid_1']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Events: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'bat_events';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'model_availability' => 'model_availability',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_description'] = 'Customer and model jobs';
  $translatables['customer_model_jobs'] = array(
    t('Master'),
    t('Customer Model Jobs'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Job'),
    t('Unit'),
    t('Confirmed'),
    t('<a href="#">Cancel job</a>'),
    t('All'),
    t('Block'),
    t('Customer and model jobs'),
  );
  $export['customer_model_jobs'] = $view;

  return $export;
}
