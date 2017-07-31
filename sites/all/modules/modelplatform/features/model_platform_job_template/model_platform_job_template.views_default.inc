<?php
/**
 * @file
 * model_platform_job_template.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function model_platform_job_template_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'job_models';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Job - Models';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Job - Models';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'model_status' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'secondary_label' => NULL,
    'collapsible_label' => NULL,
    'combine_rewrite' => NULL,
    'reset_label' => NULL,
    'bef_filter_description' => NULL,
    'any_label' => NULL,
    'filter_rewrite_values' => NULL,
  );
  $handler->display->display_options['exposed_form']['options']['input_required'] = 0;
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'php_code';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Flags: casting_mark */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'users';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'casting_mark';
  /* Relationship: Profile - Basic informaiton */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['ui_name'] = 'Profile - Basic informaiton';
  $handler->display->display_options['relationships']['profile']['label'] = 'Profile - Basic informaiton';
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'model_basic_informaiton' => 'model_basic_informaiton',
  );
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Global: Fieldset */
  $handler->display->display_options['fields']['fieldset']['id'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset']['label'] = 'image-column';
  $handler->display->display_options['fields']['fieldset']['children'] = array(
    0 => 'picture',
    1 => 'ops',
  );
  $handler->display->display_options['fields']['fieldset']['fieldset']['type'] = 'div';
  $handler->display->display_options['fields']['fieldset']['fieldset']['classes'] = 'image-column';
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['picture']['alter']['path'] = 'job/model/[uid]/invite';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = FALSE;
  $handler->display->display_options['fields']['picture']['image_style'] = '485x728_model_main_photo';
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  /* Field: Global: Fieldset */
  $handler->display->display_options['fields']['fieldset_1']['id'] = 'fieldset_1';
  $handler->display->display_options['fields']['fieldset_1']['table'] = 'views';
  $handler->display->display_options['fields']['fieldset_1']['field'] = 'fieldset';
  $handler->display->display_options['fields']['fieldset_1']['label'] = 'info-column';
  $handler->display->display_options['fields']['fieldset_1']['children'] = array(
    0 => 'field_full_name',
    1 => 'field_height',
  );
  $handler->display->display_options['fields']['fieldset_1']['fieldset']['type'] = 'div';
  $handler->display->display_options['fields']['fieldset_1']['fieldset']['classes'] = 'info-column';
  /* Field: User: Full name */
  $handler->display->display_options['fields']['field_full_name']['id'] = 'field_full_name';
  $handler->display->display_options['fields']['field_full_name']['table'] = 'field_data_field_full_name';
  $handler->display->display_options['fields']['field_full_name']['field'] = 'field_full_name';
  $handler->display->display_options['fields']['field_full_name']['label'] = '';
  $handler->display->display_options['fields']['field_full_name']['element_label_colon'] = FALSE;
  /* Field: Profile: Height */
  $handler->display->display_options['fields']['field_height']['id'] = 'field_height';
  $handler->display->display_options['fields']['field_height']['table'] = 'field_data_field_height';
  $handler->display->display_options['fields']['field_height']['field'] = 'field_height';
  $handler->display->display_options['fields']['field_height']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_height']['element_label_type'] = 'div';
  $handler->display->display_options['fields']['field_height']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_height']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    5 => '5',
  );
  /* Filter criterion: User: Model Availability */
  $handler->display->display_options['filters']['model_status']['id'] = 'model_status';
  $handler->display->display_options['filters']['model_status']['table'] = 'users';
  $handler->display->display_options['filters']['model_status']['field'] = 'model_status';
  $handler->display->display_options['filters']['model_status']['value'] = 1;
  $handler->display->display_options['filters']['model_status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['model_status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['model_status']['expose']['label'] = 'Dates';
  $handler->display->display_options['filters']['model_status']['expose']['operator'] = 'model_status_op';
  $handler->display->display_options['filters']['model_status']['expose']['identifier'] = 'model_status';
  $handler->display->display_options['filters']['model_status']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['model_status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Profile: Daily rate (field_daily_rate:amount) */
  $handler->display->display_options['filters']['field_daily_rate_amount']['id'] = 'field_daily_rate_amount';
  $handler->display->display_options['filters']['field_daily_rate_amount']['table'] = 'field_data_field_daily_rate';
  $handler->display->display_options['filters']['field_daily_rate_amount']['field'] = 'field_daily_rate_amount';
  $handler->display->display_options['filters']['field_daily_rate_amount']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_daily_rate_amount']['operator'] = '<=';
  $handler->display->display_options['filters']['field_daily_rate_amount']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_daily_rate_amount']['expose']['operator_id'] = 'field_daily_rate_amount_op';
  $handler->display->display_options['filters']['field_daily_rate_amount']['expose']['label'] = 'Daily rate';
  $handler->display->display_options['filters']['field_daily_rate_amount']['expose']['operator'] = 'field_daily_rate_amount_op';
  $handler->display->display_options['filters']['field_daily_rate_amount']['expose']['identifier'] = 'daily_rate';
  $handler->display->display_options['filters']['field_daily_rate_amount']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );

  /* Display: Filtered models */
  $handler = $view->new_display('block', 'Filtered models', 'block');

  /* Display: Hired models */
  $handler = $view->new_display('block', 'Hired models', 'block_1');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Flags: casting_mark */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'users';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'casting_mark';
  /* Relationship: Profile - Basic informaiton */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['ui_name'] = 'Profile - Basic informaiton';
  $handler->display->display_options['relationships']['profile']['label'] = 'Profile - Basic informaiton';
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'model_basic_informaiton' => 'model_basic_informaiton',
  );
  /* Relationship: Unit */
  $handler->display->display_options['relationships']['field_bat_unit_target_id']['id'] = 'field_bat_unit_target_id';
  $handler->display->display_options['relationships']['field_bat_unit_target_id']['table'] = 'field_data_field_bat_unit';
  $handler->display->display_options['relationships']['field_bat_unit_target_id']['field'] = 'field_bat_unit_target_id';
  $handler->display->display_options['relationships']['field_bat_unit_target_id']['ui_name'] = 'Unit';
  $handler->display->display_options['relationships']['field_bat_unit_target_id']['label'] = 'Unit';
  /* Relationship: Events */
  $handler->display->display_options['relationships']['reverse_event_bat_unit_reference_bat_event']['id'] = 'reverse_event_bat_unit_reference_bat_event';
  $handler->display->display_options['relationships']['reverse_event_bat_unit_reference_bat_event']['table'] = 'bat_units';
  $handler->display->display_options['relationships']['reverse_event_bat_unit_reference_bat_event']['field'] = 'reverse_event_bat_unit_reference_bat_event';
  $handler->display->display_options['relationships']['reverse_event_bat_unit_reference_bat_event']['relationship'] = 'field_bat_unit_target_id';
  $handler->display->display_options['relationships']['reverse_event_bat_unit_reference_bat_event']['ui_name'] = 'Events';
  $handler->display->display_options['relationships']['reverse_event_bat_unit_reference_bat_event']['label'] = 'Events';
  /* Relationship: Job */
  $handler->display->display_options['relationships']['field_job_target_id']['id'] = 'field_job_target_id';
  $handler->display->display_options['relationships']['field_job_target_id']['table'] = 'field_data_field_job';
  $handler->display->display_options['relationships']['field_job_target_id']['field'] = 'field_job_target_id';
  $handler->display->display_options['relationships']['field_job_target_id']['relationship'] = 'reverse_event_bat_unit_reference_bat_event';
  $handler->display->display_options['relationships']['field_job_target_id']['ui_name'] = 'Job';
  $handler->display->display_options['relationships']['field_job_target_id']['label'] = 'Job';
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
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    5 => '5',
  );
  $translatables['job_models'] = array(
    t('Master'),
    t('Job - Models'),
    t('more'),
    t('Search'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Advanced options'),
    t('Select any filter and click on Apply to see results'),
    t('flag'),
    t('Profile - Basic informaiton'),
    t('image-column'),
    t('info-column'),
    t('Height'),
    t('Dates'),
    t('Daily rate'),
    t('Filtered models'),
    t('Hired models'),
    t('Unit'),
    t('Events'),
    t('Job'),
    t('All'),
  );
  $export['job_models'] = $view;

  return $export;
}
