<?php
/**
 * @file
 * model_platform_my_invoices.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function model_platform_my_invoices_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'my_invoices';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'commerce_order';
  $view->human_name = 'My invoices';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My invoices';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: BAT Event */
  $handler->display->display_options['relationships']['field_event_target_id']['id'] = 'field_event_target_id';
  $handler->display->display_options['relationships']['field_event_target_id']['table'] = 'field_data_field_event';
  $handler->display->display_options['relationships']['field_event_target_id']['field'] = 'field_event_target_id';
  $handler->display->display_options['relationships']['field_event_target_id']['ui_name'] = 'BAT Event';
  $handler->display->display_options['relationships']['field_event_target_id']['label'] = 'BAT Event';
  $handler->display->display_options['relationships']['field_event_target_id']['required'] = TRUE;
  /* Relationship: Job */
  $handler->display->display_options['relationships']['field_job_target_id']['id'] = 'field_job_target_id';
  $handler->display->display_options['relationships']['field_job_target_id']['table'] = 'field_data_field_job';
  $handler->display->display_options['relationships']['field_job_target_id']['field'] = 'field_job_target_id';
  $handler->display->display_options['relationships']['field_job_target_id']['relationship'] = 'field_event_target_id';
  $handler->display->display_options['relationships']['field_job_target_id']['ui_name'] = 'Job';
  $handler->display->display_options['relationships']['field_job_target_id']['label'] = 'Job';
  $handler->display->display_options['relationships']['field_job_target_id']['required'] = TRUE;
  /* Relationship: Unit */
  $handler->display->display_options['relationships']['event_bat_unit_reference_target_id']['id'] = 'event_bat_unit_reference_target_id';
  $handler->display->display_options['relationships']['event_bat_unit_reference_target_id']['table'] = 'field_data_event_bat_unit_reference';
  $handler->display->display_options['relationships']['event_bat_unit_reference_target_id']['field'] = 'event_bat_unit_reference_target_id';
  $handler->display->display_options['relationships']['event_bat_unit_reference_target_id']['relationship'] = 'field_event_target_id';
  $handler->display->display_options['relationships']['event_bat_unit_reference_target_id']['ui_name'] = 'Unit';
  $handler->display->display_options['relationships']['event_bat_unit_reference_target_id']['label'] = 'Unit';
  $handler->display->display_options['relationships']['event_bat_unit_reference_target_id']['required'] = TRUE;
  /* Relationship: Model */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'bat_units';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['relationship'] = 'event_bat_unit_reference_target_id';
  $handler->display->display_options['relationships']['uid']['ui_name'] = 'Model';
  $handler->display->display_options['relationships']['uid']['label'] = 'Model';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Field: Commerce Order: Order ID */
  $handler->display->display_options['fields']['order_id']['id'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_id']['field'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['exclude'] = TRUE;
  /* Field: Unit: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'bat_units';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'event_bat_unit_reference_target_id';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_job_target_id';
  $handler->display->display_options['fields']['title']['label'] = 'Job';
  /* Field: User: Full name */
  $handler->display->display_options['fields']['field_full_name']['id'] = 'field_full_name';
  $handler->display->display_options['fields']['field_full_name']['table'] = 'field_data_field_full_name';
  $handler->display->display_options['fields']['field_full_name']['field'] = 'field_full_name';
  $handler->display->display_options['fields']['field_full_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_full_name']['label'] = 'Model';
  $handler->display->display_options['fields']['field_full_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_full_name']['alter']['path'] = 'job/model/[uid]/invite';
  /* Field: Events: Start Date */
  $handler->display->display_options['fields']['start_date']['id'] = 'start_date';
  $handler->display->display_options['fields']['start_date']['table'] = 'bat_events';
  $handler->display->display_options['fields']['start_date']['field'] = 'start_date';
  $handler->display->display_options['fields']['start_date']['relationship'] = 'field_event_target_id';
  $handler->display->display_options['fields']['start_date']['date_format'] = 'bat';
  $handler->display->display_options['fields']['start_date']['second_date_format'] = 'bat_daily';
  /* Field: Events: End Date */
  $handler->display->display_options['fields']['end_date']['id'] = 'end_date';
  $handler->display->display_options['fields']['end_date']['table'] = 'bat_events';
  $handler->display->display_options['fields']['end_date']['field'] = 'end_date';
  $handler->display->display_options['fields']['end_date']['relationship'] = 'field_event_target_id';
  $handler->display->display_options['fields']['end_date']['date_format'] = 'bat';
  $handler->display->display_options['fields']['end_date']['second_date_format'] = 'bat_daily';
  /* Field: Commerce Order: Order Balance */
  $handler->display->display_options['fields']['balance']['id'] = 'balance';
  $handler->display->display_options['fields']['balance']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['balance']['field'] = 'balance';
  /* Field: Commerce Order: Order total */
  $handler->display->display_options['fields']['commerce_order_total']['id'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['table'] = 'field_data_commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['field'] = 'commerce_order_total';
  $handler->display->display_options['fields']['commerce_order_total']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['commerce_order_total']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Actions';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href=\'/user/[uid]/invoices/[order_id]\' >View invoice</a>
<a href=\'/mp_pdf/invoices/[order_id]\' >PDF</a>';
  /* Contextual filter: Commerce Order: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'commerce_order';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'user/%/invoices';
  $translatables['my_invoices'] = array(
    t('Master'),
    t('My invoices'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('BAT Event'),
    t('Job'),
    t('Unit'),
    t('Model'),
    t('Order ID'),
    t('Uid'),
    t('Start Date'),
    t('End Date'),
    t('Order Balance'),
    t('Order total'),
    t('Actions'),
    t('<a href=\'/user/[uid]/invoices/[order_id]\' >View invoice</a>
<a href=\'/mp_pdf/invoices/[order_id]\' >PDF</a>'),
    t('All'),
    t('Page'),
  );
  $export['my_invoices'] = $view;

  return $export;
}
