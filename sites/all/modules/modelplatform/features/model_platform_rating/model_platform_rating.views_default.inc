<?php
/**
 * @file
 * model_platform_rating.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function model_platform_rating_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'rate_job_event';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'bat_events';
  $view->human_name = 'Rate job event';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Rate job event';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_job_target_id']['id'] = 'field_job_target_id';
  $handler->display->display_options['relationships']['field_job_target_id']['table'] = 'field_data_field_job';
  $handler->display->display_options['relationships']['field_job_target_id']['field'] = 'field_job_target_id';
  $handler->display->display_options['relationships']['field_job_target_id']['label'] = 'Job';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid_1']['id'] = 'uid_1';
  $handler->display->display_options['relationships']['uid_1']['table'] = 'node';
  $handler->display->display_options['relationships']['uid_1']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid_1']['relationship'] = 'field_job_target_id';
  $handler->display->display_options['relationships']['uid_1']['label'] = 'Customer';
  /* Field: User: Rating */
  $handler->display->display_options['fields']['field_rating_1']['id'] = 'field_rating_1';
  $handler->display->display_options['fields']['field_rating_1']['table'] = 'field_data_field_rating';
  $handler->display->display_options['fields']['field_rating_1']['field'] = 'field_rating';
  $handler->display->display_options['fields']['field_rating_1']['relationship'] = 'uid_1';
  $handler->display->display_options['fields']['field_rating_1']['label'] = 'Your rate';
  $handler->display->display_options['fields']['field_rating_1']['click_sort_column'] = 'rating';
  $handler->display->display_options['fields']['field_rating_1']['settings'] = array(
    'widget' => array(
      'fivestar_widget' => 'default',
    ),
    'expose' => 1,
    'style' => 'user',
    'text' => 'none',
  );
  /* Contextual filter: Events: Events ID */
  $handler->display->display_options['arguments']['event_id']['id'] = 'event_id';
  $handler->display->display_options['arguments']['event_id']['table'] = 'bat_events';
  $handler->display->display_options['arguments']['event_id']['field'] = 'event_id';
  $handler->display->display_options['arguments']['event_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['event_id']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['event_id']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['event_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['event_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['event_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Events: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'bat_events';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'model_availability' => 'model_availability',
  );
  /* Filter criterion: Content: Job status (field_job_status) */
  $handler->display->display_options['filters']['field_job_status_tid']['id'] = 'field_job_status_tid';
  $handler->display->display_options['filters']['field_job_status_tid']['table'] = 'field_data_field_job_status';
  $handler->display->display_options['filters']['field_job_status_tid']['field'] = 'field_job_status_tid';
  $handler->display->display_options['filters']['field_job_status_tid']['relationship'] = 'field_job_target_id';
  $handler->display->display_options['filters']['field_job_status_tid']['value'] = array(
    98 => '98',
  );
  $handler->display->display_options['filters']['field_job_status_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_job_status_tid']['vocabulary'] = 'job_status';
  /* Filter criterion: Events: End Date */
  $handler->display->display_options['filters']['end_date']['id'] = 'end_date';
  $handler->display->display_options['filters']['end_date']['table'] = 'bat_events';
  $handler->display->display_options['filters']['end_date']['field'] = 'end_date';
  $handler->display->display_options['filters']['end_date']['operator'] = '<=';
  $handler->display->display_options['filters']['end_date']['value']['value'] = '+7 day';
  $handler->display->display_options['filters']['end_date']['value']['type'] = 'offset';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['relationship'] = 'field_job_target_id';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'job' => 'job',
  );

  /* Display: Model */
  $handler = $view->new_display('block', 'Model', 'block');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    5 => '5',
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Events: Model rate */
  $handler->display->display_options['fields']['field_model_rate']['id'] = 'field_model_rate';
  $handler->display->display_options['fields']['field_model_rate']['table'] = 'field_data_field_model_rate';
  $handler->display->display_options['fields']['field_model_rate']['field'] = 'field_model_rate';
  $handler->display->display_options['fields']['field_model_rate']['label'] = 'Your rate';
  $handler->display->display_options['fields']['field_model_rate']['click_sort_column'] = 'rating';
  $handler->display->display_options['fields']['field_model_rate']['settings'] = array(
    'widget' => array(
      'fivestar_widget' => 'sites/all/modules/fivestar/widgets/basic/basic.css',
    ),
    'expose' => 1,
    'style' => 'user',
    'text' => 'none',
  );
  $handler->display->display_options['block_description'] = 'Model job rate form';

  /* Display: Customer */
  $handler = $view->new_display('block', 'Customer', 'block_1');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    4 => '4',
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Events: Customer rate */
  $handler->display->display_options['fields']['field_customer_rate']['id'] = 'field_customer_rate';
  $handler->display->display_options['fields']['field_customer_rate']['table'] = 'field_data_field_customer_rate';
  $handler->display->display_options['fields']['field_customer_rate']['field'] = 'field_customer_rate';
  $handler->display->display_options['fields']['field_customer_rate']['label'] = 'Your rate';
  $handler->display->display_options['fields']['field_customer_rate']['click_sort_column'] = 'rating';
  $handler->display->display_options['fields']['field_customer_rate']['settings'] = array(
    'widget' => array(
      'fivestar_widget' => 'sites/all/modules/fivestar/widgets/basic/basic.css',
    ),
    'expose' => 1,
    'style' => 'user',
    'text' => 'none',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_job_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Events: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'bat_events';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'model_availability' => 'model_availability',
  );
  /* Filter criterion: Content: Job status (field_job_status) */
  $handler->display->display_options['filters']['field_job_status_tid']['id'] = 'field_job_status_tid';
  $handler->display->display_options['filters']['field_job_status_tid']['table'] = 'field_data_field_job_status';
  $handler->display->display_options['filters']['field_job_status_tid']['field'] = 'field_job_status_tid';
  $handler->display->display_options['filters']['field_job_status_tid']['relationship'] = 'field_job_target_id';
  $handler->display->display_options['filters']['field_job_status_tid']['value'] = array(
    98 => '98',
  );
  $handler->display->display_options['filters']['field_job_status_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_job_status_tid']['vocabulary'] = 'job_status';
  /* Filter criterion: Events: End Date */
  $handler->display->display_options['filters']['end_date']['id'] = 'end_date';
  $handler->display->display_options['filters']['end_date']['table'] = 'bat_events';
  $handler->display->display_options['filters']['end_date']['field'] = 'end_date';
  $handler->display->display_options['filters']['end_date']['operator'] = '<=';
  $handler->display->display_options['filters']['end_date']['value']['value'] = '+7 day';
  $handler->display->display_options['filters']['end_date']['value']['type'] = 'offset';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['relationship'] = 'field_job_target_id';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'job' => 'job',
  );
  $handler->display->display_options['block_description'] = 'Customer job rate form';
  $translatables['rate_job_event'] = array(
    t('Master'),
    t('Rate job event'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Job'),
    t('Customer'),
    t('Your rate'),
    t('All'),
    t('Model'),
    t('Model job rate form'),
    t('Customer job rate form'),
  );
  $export['rate_job_event'] = $view;

  $view = new view();
  $view->name = 'user_rating';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'User rating';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'User rating';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: User: Rating */
  $handler->display->display_options['fields']['field_rating']['id'] = 'field_rating';
  $handler->display->display_options['fields']['field_rating']['table'] = 'field_data_field_rating';
  $handler->display->display_options['fields']['field_rating']['field'] = 'field_rating';
  $handler->display->display_options['fields']['field_rating']['label'] = '';
  $handler->display->display_options['fields']['field_rating']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_rating']['click_sort_column'] = 'rating';
  $handler->display->display_options['fields']['field_rating']['settings'] = array(
    'widget' => array(
      'fivestar_widget' => 'sites/all/modules/fivestar/widgets/basic/basic.css',
    ),
    'expose' => 0,
    'style' => 'average',
    'text' => 'none',
  );
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Model rating - invite page */
  $handler = $view->new_display('block', 'Model rating - invite page', 'block');
  $handler->display->display_options['block_description'] = 'Model rating - invite page';

  /* Display: Model rating - invite page */
  $handler = $view->new_display('block', 'Model rating - invite page', 'block_1');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['block_description'] = 'User rating - user page';

  /* Display: Customer rating - dashboard page */
  $handler = $view->new_display('block', 'Customer rating - dashboard page', 'block_2');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['block_description'] = 'Customer rating - dashboard page';
  $translatables['user_rating'] = array(
    t('Master'),
    t('User rating'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('All'),
    t('Model rating - invite page'),
    t('User rating - user page'),
    t('Customer rating - dashboard page'),
  );
  $export['user_rating'] = $view;

  return $export;
}
