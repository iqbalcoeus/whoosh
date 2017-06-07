<?php
/**
 * @file
 * model_additional_reciepts_check.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function model_additional_reciepts_check_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'model_additional_reciepts';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'field_collection_item';
  $view->human_name = 'Model additional reciepts';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Model additional reciepts check';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'item_id' => 'item_id',
    'field_document' => 'field_document',
    'field_reciept_admin' => 'field_reciept_admin',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'item_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_document' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_reciept_admin' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: BAT Event */
  $handler->display->display_options['relationships']['field_additional_receipts_bat_event']['id'] = 'field_additional_receipts_bat_event';
  $handler->display->display_options['relationships']['field_additional_receipts_bat_event']['table'] = 'field_collection_item';
  $handler->display->display_options['relationships']['field_additional_receipts_bat_event']['field'] = 'field_additional_receipts_bat_event';
  $handler->display->display_options['relationships']['field_additional_receipts_bat_event']['ui_name'] = 'BAT Event';
  $handler->display->display_options['relationships']['field_additional_receipts_bat_event']['label'] = 'BAT Event';
  $handler->display->display_options['relationships']['field_additional_receipts_bat_event']['required'] = TRUE;
  /* Field: Events: Events ID */
  $handler->display->display_options['fields']['event_id']['id'] = 'event_id';
  $handler->display->display_options['fields']['event_id']['table'] = 'bat_events';
  $handler->display->display_options['fields']['event_id']['field'] = 'event_id';
  $handler->display->display_options['fields']['event_id']['relationship'] = 'field_additional_receipts_bat_event';
  $handler->display->display_options['fields']['event_id']['exclude'] = TRUE;
  /* Field: Field collection item: Field collection item ID */
  $handler->display->display_options['fields']['item_id']['id'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['table'] = 'field_collection_item';
  $handler->display->display_options['fields']['item_id']['field'] = 'item_id';
  /* Field: Field collection item: Document */
  $handler->display->display_options['fields']['field_document']['id'] = 'field_document';
  $handler->display->display_options['fields']['field_document']['table'] = 'field_data_field_document';
  $handler->display->display_options['fields']['field_document']['field'] = 'field_document';
  $handler->display->display_options['fields']['field_document']['click_sort_column'] = 'fid';
  /* Field: Field collection item: Reciept admin */
  $handler->display->display_options['fields']['field_reciept_admin']['id'] = 'field_reciept_admin';
  $handler->display->display_options['fields']['field_reciept_admin']['table'] = 'field_data_field_reciept_admin';
  $handler->display->display_options['fields']['field_reciept_admin']['field'] = 'field_reciept_admin';
  $handler->display->display_options['fields']['field_reciept_admin']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_reciept_admin']['settings'] = array(
    'link' => 1,
  );
  /* Field: Field collection item: Reciept cost */
  $handler->display->display_options['fields']['field_reciept_cost']['id'] = 'field_reciept_cost';
  $handler->display->display_options['fields']['field_reciept_cost']['table'] = 'field_data_field_reciept_cost';
  $handler->display->display_options['fields']['field_reciept_cost']['field'] = 'field_reciept_cost';
  $handler->display->display_options['fields']['field_reciept_cost']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['field_reciept_cost']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Actions';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="/job/event/[event_id]/approve/[item_id]">Approve</a>
<a href="/job/event/[event_id]/remove/[item_id]">Remove</a>';
  /* Filter criterion: Field collection item: Reciept admin (field_reciept_admin) */
  $handler->display->display_options['filters']['field_reciept_admin_target_id']['id'] = 'field_reciept_admin_target_id';
  $handler->display->display_options['filters']['field_reciept_admin_target_id']['table'] = 'field_data_field_reciept_admin';
  $handler->display->display_options['filters']['field_reciept_admin_target_id']['field'] = 'field_reciept_admin_target_id';
  $handler->display->display_options['filters']['field_reciept_admin_target_id']['operator'] = 'empty';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/modelplatform/invoice_reciepts';
  $translatables['model_additional_reciepts'] = array(
    t('Master'),
    t('Model additional reciepts check'),
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
    t('Events ID'),
    t('.'),
    t(','),
    t('Field collection item ID'),
    t('Document'),
    t('Reciept admin'),
    t('Reciept cost'),
    t('Actions'),
    t('<a href="/job/event/[event_id]/approve/[item_id]">Approve</a>
<a href="/job/event/[event_id]/remove/[item_id]">Remove</a>'),
    t('Page'),
  );
  $export['model_additional_reciepts'] = $view;

  return $export;
}
