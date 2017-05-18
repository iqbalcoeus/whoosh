<?php
/**
 * @file
 * model_platform_model_job_auction.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function model_platform_model_job_auction_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'job_propose_auctions';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'mp_auction';
  $view->human_name = 'Job propose auctions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Job propose auctions';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Events */
  $handler->display->display_options['relationships']['field_auction_event_target_id']['id'] = 'field_auction_event_target_id';
  $handler->display->display_options['relationships']['field_auction_event_target_id']['table'] = 'field_data_field_auction_event';
  $handler->display->display_options['relationships']['field_auction_event_target_id']['field'] = 'field_auction_event_target_id';
  $handler->display->display_options['relationships']['field_auction_event_target_id']['ui_name'] = 'Events';
  $handler->display->display_options['relationships']['field_auction_event_target_id']['label'] = 'Events';
  $handler->display->display_options['relationships']['field_auction_event_target_id']['required'] = TRUE;
  /* Relationship: Auction author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'mp_auction';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['ui_name'] = 'Auction author';
  $handler->display->display_options['relationships']['uid']['label'] = 'Auction author';
  /* Relationship: Decision User */
  $handler->display->display_options['relationships']['field_decision_user_target_id']['id'] = 'field_decision_user_target_id';
  $handler->display->display_options['relationships']['field_decision_user_target_id']['table'] = 'field_data_field_decision_user';
  $handler->display->display_options['relationships']['field_decision_user_target_id']['field'] = 'field_decision_user_target_id';
  $handler->display->display_options['relationships']['field_decision_user_target_id']['ui_name'] = 'Decision User';
  $handler->display->display_options['relationships']['field_decision_user_target_id']['label'] = 'Decision User';
  /* Field: MP Auction: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'mp_auction';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'bat';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'bat_daily';
  /* Field: MP Auction: Mp auction ID */
  $handler->display->display_options['fields']['mp_auction_id']['id'] = 'mp_auction_id';
  $handler->display->display_options['fields']['mp_auction_id']['table'] = 'mp_auction';
  $handler->display->display_options['fields']['mp_auction_id']['field'] = 'mp_auction_id';
  $handler->display->display_options['fields']['mp_auction_id']['exclude'] = TRUE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['relationship'] = 'uid';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['exclude'] = TRUE;
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = FALSE;
  $handler->display->display_options['fields']['picture']['image_style'] = '512_512';
  /* Field: User: Full name */
  $handler->display->display_options['fields']['field_full_name']['id'] = 'field_full_name';
  $handler->display->display_options['fields']['field_full_name']['table'] = 'field_data_field_full_name';
  $handler->display->display_options['fields']['field_full_name']['field'] = 'field_full_name';
  $handler->display->display_options['fields']['field_full_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_full_name']['label'] = '';
  $handler->display->display_options['fields']['field_full_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_full_name']['alter']['text'] = '<div class="user-picture">[picture]</div>
<div class="user-full-name">[field_full_name]</div>';
  $handler->display->display_options['fields']['field_full_name']['element_label_colon'] = FALSE;
  /* Field: MP Auction: Status */
  $handler->display->display_options['fields']['field_auction_status']['id'] = 'field_auction_status';
  $handler->display->display_options['fields']['field_auction_status']['table'] = 'field_data_field_auction_status';
  $handler->display->display_options['fields']['field_auction_status']['field'] = 'field_auction_status';
  $handler->display->display_options['fields']['field_auction_status']['exclude'] = TRUE;
  /* Field: MP Auction: Cost propose */
  $handler->display->display_options['fields']['field_auction_cost_propose']['id'] = 'field_auction_cost_propose';
  $handler->display->display_options['fields']['field_auction_cost_propose']['table'] = 'field_data_field_auction_cost_propose';
  $handler->display->display_options['fields']['field_auction_cost_propose']['field'] = 'field_auction_cost_propose';
  $handler->display->display_options['fields']['field_auction_cost_propose']['label'] = '';
  $handler->display->display_options['fields']['field_auction_cost_propose']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_auction_cost_propose']['click_sort_column'] = 'amount';
  $handler->display->display_options['fields']['field_auction_cost_propose']['settings'] = array(
    'calculation' => FALSE,
  );
  /* Field: Field: Decision */
  $handler->display->display_options['fields']['field_auction_decision']['id'] = 'field_auction_decision';
  $handler->display->display_options['fields']['field_auction_decision']['table'] = 'field_data_field_auction_decision';
  $handler->display->display_options['fields']['field_auction_decision']['field'] = 'field_auction_decision';
  $handler->display->display_options['fields']['field_auction_decision']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_auction_decision']['empty'] = 'Have no decision yet';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid_1']['id'] = 'uid_1';
  $handler->display->display_options['fields']['uid_1']['table'] = 'users';
  $handler->display->display_options['fields']['uid_1']['field'] = 'uid';
  $handler->display->display_options['fields']['uid_1']['relationship'] = 'field_decision_user_target_id';
  $handler->display->display_options['fields']['uid_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid_1']['link_to_user'] = FALSE;
  /* Field: User: Full name */
  $handler->display->display_options['fields']['field_full_name_1']['id'] = 'field_full_name_1';
  $handler->display->display_options['fields']['field_full_name_1']['table'] = 'field_data_field_full_name';
  $handler->display->display_options['fields']['field_full_name_1']['field'] = 'field_full_name';
  $handler->display->display_options['fields']['field_full_name_1']['relationship'] = 'field_decision_user_target_id';
  $handler->display->display_options['fields']['field_full_name_1']['label'] = '';
  $handler->display->display_options['fields']['field_full_name_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_full_name_1']['element_label_colon'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture_1']['id'] = 'picture_1';
  $handler->display->display_options['fields']['picture_1']['table'] = 'users';
  $handler->display->display_options['fields']['picture_1']['field'] = 'picture';
  $handler->display->display_options['fields']['picture_1']['relationship'] = 'field_decision_user_target_id';
  $handler->display->display_options['fields']['picture_1']['label'] = '';
  $handler->display->display_options['fields']['picture_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['picture_1']['alter']['text'] = '<div class="user-picture">[picture_1]</div>
<div class="user-full-name">[field_full_name_1]</div>
<div class="auction-decision">[field_auction_decision]</div>';
  $handler->display->display_options['fields']['picture_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture_1']['link_photo_to_profile'] = FALSE;
  $handler->display->display_options['fields']['picture_1']['image_style'] = '512_512';
  /* Contextual filter: Events: Events ID */
  $handler->display->display_options['arguments']['event_id']['id'] = 'event_id';
  $handler->display->display_options['arguments']['event_id']['table'] = 'bat_events';
  $handler->display->display_options['arguments']['event_id']['field'] = 'event_id';
  $handler->display->display_options['arguments']['event_id']['relationship'] = 'field_auction_event_target_id';
  $handler->display->display_options['arguments']['event_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['event_id']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['event_id']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['event_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['event_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['event_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: MP Auction: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'mp_auction';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'auction' => 'auction',
  );

  /* Display: Job propose - auction */
  $handler = $view->new_display('block', 'Job propose - auction', 'block');
  $translatables['job_propose_auctions'] = array(
    t('Master'),
    t('Job propose auctions'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Events'),
    t('Auction author'),
    t('Decision User'),
    t('Mp auction ID'),
    t('.'),
    t(','),
    t('<div class="user-picture">[picture]</div>
<div class="user-full-name">[field_full_name]</div>'),
    t('Status'),
    t('Decision'),
    t('Have no decision yet'),
    t('Uid'),
    t('<div class="user-picture">[picture_1]</div>
<div class="user-full-name">[field_full_name_1]</div>
<div class="auction-decision">[field_auction_decision]</div>'),
    t('All'),
    t('Job propose - auction'),
  );
  $export['job_propose_auctions'] = $view;

  return $export;
}
