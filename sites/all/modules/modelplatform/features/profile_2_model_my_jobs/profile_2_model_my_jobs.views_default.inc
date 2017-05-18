<?php
/**
 * @file
 * profile_2_model_my_jobs.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function profile_2_model_my_jobs_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'model_job_proposes';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'bat_events';
  $view->human_name = 'Model Job proposes';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Model Job proposes';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Unit */
  $handler->display->display_options['relationships']['event_bat_unit_reference_target_id']['id'] = 'event_bat_unit_reference_target_id';
  $handler->display->display_options['relationships']['event_bat_unit_reference_target_id']['table'] = 'field_data_event_bat_unit_reference';
  $handler->display->display_options['relationships']['event_bat_unit_reference_target_id']['field'] = 'event_bat_unit_reference_target_id';
  $handler->display->display_options['relationships']['event_bat_unit_reference_target_id']['ui_name'] = 'Unit';
  $handler->display->display_options['relationships']['event_bat_unit_reference_target_id']['label'] = 'Unit';
  $handler->display->display_options['relationships']['event_bat_unit_reference_target_id']['required'] = TRUE;
  /* Relationship: User */
  $handler->display->display_options['relationships']['reverse_field_bat_unit_user']['id'] = 'reverse_field_bat_unit_user';
  $handler->display->display_options['relationships']['reverse_field_bat_unit_user']['table'] = 'bat_units';
  $handler->display->display_options['relationships']['reverse_field_bat_unit_user']['field'] = 'reverse_field_bat_unit_user';
  $handler->display->display_options['relationships']['reverse_field_bat_unit_user']['relationship'] = 'event_bat_unit_reference_target_id';
  $handler->display->display_options['relationships']['reverse_field_bat_unit_user']['ui_name'] = 'User';
  $handler->display->display_options['relationships']['reverse_field_bat_unit_user']['label'] = 'User';
  $handler->display->display_options['relationships']['reverse_field_bat_unit_user']['required'] = TRUE;
  /* Relationship: Job */
  $handler->display->display_options['relationships']['field_job_target_id']['id'] = 'field_job_target_id';
  $handler->display->display_options['relationships']['field_job_target_id']['table'] = 'field_data_field_job';
  $handler->display->display_options['relationships']['field_job_target_id']['field'] = 'field_job_target_id';
  $handler->display->display_options['relationships']['field_job_target_id']['ui_name'] = 'Job';
  $handler->display->display_options['relationships']['field_job_target_id']['label'] = 'Job';
  $handler->display->display_options['relationships']['field_job_target_id']['required'] = TRUE;
  /* Field: Events: Events ID */
  $handler->display->display_options['fields']['event_id']['id'] = 'event_id';
  $handler->display->display_options['fields']['event_id']['table'] = 'bat_events';
  $handler->display->display_options['fields']['event_id']['field'] = 'event_id';
  $handler->display->display_options['fields']['event_id']['label'] = '';
  $handler->display->display_options['fields']['event_id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['event_id']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_job_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'job/event/[event_id]/auction';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: field_job_daily_rate_from */
  $handler->display->display_options['fields']['field_job_daily_rate_from']['id'] = 'field_job_daily_rate_from';
  $handler->display->display_options['fields']['field_job_daily_rate_from']['table'] = 'field_data_field_job_daily_rate_from';
  $handler->display->display_options['fields']['field_job_daily_rate_from']['field'] = 'field_job_daily_rate_from';
  $handler->display->display_options['fields']['field_job_daily_rate_from']['relationship'] = 'field_job_target_id';
  $handler->display->display_options['fields']['field_job_daily_rate_from']['label'] = '';
  $handler->display->display_options['fields']['field_job_daily_rate_from']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_job_daily_rate_from']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_job_daily_rate_from']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['field_job_daily_rate_from']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Content: field_job_daily_rate_to */
  $handler->display->display_options['fields']['field_job_daily_rate_to']['id'] = 'field_job_daily_rate_to';
  $handler->display->display_options['fields']['field_job_daily_rate_to']['table'] = 'field_data_field_job_daily_rate_to';
  $handler->display->display_options['fields']['field_job_daily_rate_to']['field'] = 'field_job_daily_rate_to';
  $handler->display->display_options['fields']['field_job_daily_rate_to']['relationship'] = 'field_job_target_id';
  $handler->display->display_options['fields']['field_job_daily_rate_to']['label'] = 'Job daily rate';
  $handler->display->display_options['fields']['field_job_daily_rate_to']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_job_daily_rate_to']['alter']['text'] = '[field_job_daily_rate_from] - [field_job_daily_rate_to]';
  $handler->display->display_options['fields']['field_job_daily_rate_to']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['field_job_daily_rate_to']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Events: Cost */
  $handler->display->display_options['fields']['field_job_cost']['id'] = 'field_job_cost';
  $handler->display->display_options['fields']['field_job_cost']['table'] = 'field_data_field_job_cost';
  $handler->display->display_options['fields']['field_job_cost']['field'] = 'field_job_cost';
  $handler->display->display_options['fields']['field_job_cost']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['field_job_cost']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Events: Start Date */
  $handler->display->display_options['fields']['start_date']['id'] = 'start_date';
  $handler->display->display_options['fields']['start_date']['table'] = 'bat_events';
  $handler->display->display_options['fields']['start_date']['field'] = 'start_date';
  $handler->display->display_options['fields']['start_date']['label'] = '';
  $handler->display->display_options['fields']['start_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['start_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['start_date']['date_format'] = 'bat';
  $handler->display->display_options['fields']['start_date']['second_date_format'] = 'bat_daily';
  /* Field: Events: End Date */
  $handler->display->display_options['fields']['end_date']['id'] = 'end_date';
  $handler->display->display_options['fields']['end_date']['table'] = 'bat_events';
  $handler->display->display_options['fields']['end_date']['field'] = 'end_date';
  $handler->display->display_options['fields']['end_date']['label'] = 'Job dates';
  $handler->display->display_options['fields']['end_date']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['end_date']['alter']['text'] = '[start_date] - [end_date]';
  $handler->display->display_options['fields']['end_date']['date_format'] = 'bat';
  $handler->display->display_options['fields']['end_date']['second_date_format'] = 'bat_daily';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['relationship'] = 'field_job_target_id';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '250',
  );
  /* Field: Read more */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Read more';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Read more';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'job/event/[event_id]/auction';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'reverse_field_bat_unit_user';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Events: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'bat_events';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'model_availability' => 'model_availability',
  );

  /* Display: Model Job proposes */
  $handler = $view->new_display('block', 'Model Job proposes', 'block');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Events: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'bat_events';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'model_availability' => 'model_availability',
  );
  /* Filter criterion: Events: Start Date */
  $handler->display->display_options['filters']['start_date']['id'] = 'start_date';
  $handler->display->display_options['filters']['start_date']['table'] = 'bat_events';
  $handler->display->display_options['filters']['start_date']['field'] = 'start_date';
  $handler->display->display_options['filters']['start_date']['operator'] = '>';
  $handler->display->display_options['filters']['start_date']['value']['value'] = '-1 minute';
  $handler->display->display_options['filters']['start_date']['value']['type'] = 'offset';
  $handler->display->display_options['block_description'] = 'Model jobs - job proposes';

  /* Display: Past Jobs */
  $handler = $view->new_display('block', 'Past Jobs', 'block_1');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Events: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'bat_events';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'model_availability' => 'model_availability',
  );
  /* Filter criterion: Events: End Date */
  $handler->display->display_options['filters']['end_date']['id'] = 'end_date';
  $handler->display->display_options['filters']['end_date']['table'] = 'bat_events';
  $handler->display->display_options['filters']['end_date']['field'] = 'end_date';
  $handler->display->display_options['filters']['end_date']['operator'] = '<';
  $handler->display->display_options['filters']['end_date']['value']['value'] = '+1 minute';
  $handler->display->display_options['filters']['end_date']['value']['type'] = 'offset';
  /* Filter criterion: Events: Blocking */
  $handler->display->display_options['filters']['blocking']['id'] = 'blocking';
  $handler->display->display_options['filters']['blocking']['table'] = 'bat_events';
  $handler->display->display_options['filters']['blocking']['field'] = 'blocking';
  $handler->display->display_options['filters']['blocking']['value'] = 'blocking';
  $handler->display->display_options['block_description'] = 'Model jobs - past jobs';
  $translatables['model_job_proposes'] = array(
    t('Master'),
    t('Model Job proposes'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Unit'),
    t('User'),
    t('Job'),
    t('.'),
    t(','),
    t('Job daily rate'),
    t('[field_job_daily_rate_from] - [field_job_daily_rate_to]'),
    t('Cost'),
    t('Job dates'),
    t('[start_date] - [end_date]'),
    t('Read more'),
    t('All'),
    t('Model jobs - job proposes'),
    t('Past Jobs'),
    t('Model jobs - past jobs'),
  );
  $export['model_job_proposes'] = $view;

  return $export;
}
