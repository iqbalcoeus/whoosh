<?php
/**
 * @file
 * model_platform_gallery_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function model_platform_gallery_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'model_gallery';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Model gallery';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Model gallery';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<a href="/node/add/node-gallery-item" class="add-more-images">Add more images</a>
<div id="model-gallery-next"></div>
<div id="model-gallery-prev"></div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_gallery_image']['id'] = 'field_gallery_image';
  $handler->display->display_options['fields']['field_gallery_image']['table'] = 'field_data_field_gallery_image';
  $handler->display->display_options['fields']['field_gallery_image']['field'] = 'field_gallery_image';
  $handler->display->display_options['fields']['field_gallery_image']['label'] = '';
  $handler->display->display_options['fields']['field_gallery_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_gallery_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_gallery_image']['type'] = 'colorbox';
  $handler->display->display_options['fields']['field_gallery_image']['settings'] = array(
    'colorbox_node_style' => '150x225_gallery',
    'colorbox_node_style_first' => '',
    'colorbox_image_style' => '556x913_colorbox_open',
    'colorbox_gallery' => 'page',
    'colorbox_gallery_custom' => '',
    'colorbox_caption' => 'none',
    'colorbox_caption_custom' => '',
  );
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Content: Image category */
  $handler->display->display_options['fields']['field_image_category']['id'] = 'field_image_category';
  $handler->display->display_options['fields']['field_image_category']['table'] = 'field_data_field_image_category';
  $handler->display->display_options['fields']['field_image_category']['field'] = 'field_image_category';
  $handler->display->display_options['fields']['field_image_category']['label'] = '';
  $handler->display->display_options['fields']['field_image_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_category']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Verification status */
  $handler->display->display_options['fields']['field_ver_status']['id'] = 'field_ver_status';
  $handler->display->display_options['fields']['field_ver_status']['table'] = 'field_data_field_ver_status';
  $handler->display->display_options['fields']['field_ver_status']['field'] = 'field_ver_status';
  $handler->display->display_options['fields']['field_ver_status']['label'] = '';
  $handler->display->display_options['fields']['field_ver_status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ver_status']['type'] = 'taxonomy_term_reference_plain';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'node_gallery_item' => 'node_gallery_item',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div id="model-gallery-next"></div>
<div id="model-gallery-prev"></div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_gallery_image']['id'] = 'field_gallery_image';
  $handler->display->display_options['fields']['field_gallery_image']['table'] = 'field_data_field_gallery_image';
  $handler->display->display_options['fields']['field_gallery_image']['field'] = 'field_gallery_image';
  $handler->display->display_options['fields']['field_gallery_image']['label'] = '';
  $handler->display->display_options['fields']['field_gallery_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_gallery_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_gallery_image']['type'] = 'colorbox';
  $handler->display->display_options['fields']['field_gallery_image']['settings'] = array(
    'colorbox_node_style' => '150x225_gallery',
    'colorbox_node_style_first' => '',
    'colorbox_image_style' => '556x913_colorbox_open',
    'colorbox_gallery' => 'page',
    'colorbox_gallery_custom' => '',
    'colorbox_caption' => 'none',
    'colorbox_caption_custom' => '',
  );
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Content: Image category */
  $handler->display->display_options['fields']['field_image_category']['id'] = 'field_image_category';
  $handler->display->display_options['fields']['field_image_category']['table'] = 'field_data_field_image_category';
  $handler->display->display_options['fields']['field_image_category']['field'] = 'field_image_category';
  $handler->display->display_options['fields']['field_image_category']['label'] = '';
  $handler->display->display_options['fields']['field_image_category']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_category']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Verification status */
  $handler->display->display_options['fields']['field_ver_status']['id'] = 'field_ver_status';
  $handler->display->display_options['fields']['field_ver_status']['table'] = 'field_data_field_ver_status';
  $handler->display->display_options['fields']['field_ver_status']['field'] = 'field_ver_status';
  $handler->display->display_options['fields']['field_ver_status']['label'] = '';
  $handler->display->display_options['fields']['field_ver_status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ver_status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ver_status']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'node_gallery_item' => 'node_gallery_item',
  );
  /* Filter criterion: Content: Verification status (field_ver_status) */
  $handler->display->display_options['filters']['field_ver_status_tid']['id'] = 'field_ver_status_tid';
  $handler->display->display_options['filters']['field_ver_status_tid']['table'] = 'field_data_field_ver_status';
  $handler->display->display_options['filters']['field_ver_status_tid']['field'] = 'field_ver_status_tid';
  $handler->display->display_options['filters']['field_ver_status_tid']['value'] = array(
    91 => '91',
  );
  $handler->display->display_options['filters']['field_ver_status_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_ver_status_tid']['vocabulary'] = 'verification_status';
  $handler->display->display_options['block_description'] = 'Model images - Job';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['block_description'] = 'Model images - Gallery';
  $translatables['model_gallery'] = array(
    t('Master'),
    t('Model gallery'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<a href="/node/add/node-gallery-item" class="add-more-images">Add more images</a>
<div id="model-gallery-next"></div>
<div id="model-gallery-prev"></div>'),
    t('Edit'),
    t('All'),
    t('Block'),
    t('<div id="model-gallery-next"></div>
<div id="model-gallery-prev"></div>'),
    t('Model images - Job'),
    t('Model images - Gallery'),
  );
  $export['model_gallery'] = $view;

  $view = new view();
  $view->name = 'model_job_invite';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Model - job invite';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Model - job invite';
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
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = FALSE;
  $handler->display->display_options['fields']['picture']['image_style'] = '485x728_model_main_photo';
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

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_description'] = 'Model - job invite - Image';
  $translatables['model_job_invite'] = array(
    t('Master'),
    t('Model - job invite'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('All'),
    t('Block'),
    t('Model - job invite - Image'),
  );
  $export['model_job_invite'] = $view;

  $view = new view();
  $view->name = 'models';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Models';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Castinglist';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
    5 => '5',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 1,
      'secondary_label' => 'Details',
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'field_full_name_value' => array(
      'bef_format' => 'default',
      'more_options' => array(
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
    'model_status' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 1,
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
    'field_base_city_checked_value' => array(
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
    'field_model_gender_tid' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
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
    'field_model_base_city_tid' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
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
    'field_model_eye_color_tid' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
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
    'field_model_hair_color_tid' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
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
    'field_daily_rate_value_1' => array(
      'bef_format' => 'default',
      'slider_options' => array(
        'bef_slider_min' => '0',
        'bef_slider_max' => '99999',
        'bef_slider_step' => '1',
        'bef_slider_animate' => '',
        'bef_slider_orientation' => 'horizontal',
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'bef_filter_description' => NULL,
        'any_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'more_options' => array(
        'is_secondary' => 1,
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
    'field_lingerie_daily_rate_value' => array(
      'bef_format' => 'default',
      'slider_options' => array(
        'bef_slider_min' => '0',
        'bef_slider_max' => '99999',
        'bef_slider_step' => '1',
        'bef_slider_animate' => '',
        'bef_slider_orientation' => 'horizontal',
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'bef_filter_description' => NULL,
        'any_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'more_options' => array(
        'is_secondary' => 1,
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
    'field_lingerie_value' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 1,
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
          'filter_rewrite_values' => 'Yes|Lingerie',
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
    'field_teeth_gap_value' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 1,
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
          'filter_rewrite_values' => 'Yes|Teeth gap',
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
    'field_beautiful_feet_value_1' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 1,
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
          'filter_rewrite_values' => 'Yes|Beautiful feet',
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
    'field_beautiful_hands_value_1' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 1,
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
          'filter_rewrite_values' => 'Yes|Beautiful hands',
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
    'field_freckles_value' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 1,
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
          'filter_rewrite_values' => 'Yes|Freckles',
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
    'field_age_category_tid' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 1,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
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
    'field_model_ethnicity_tid' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 1,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
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
    'field_model_sports_tid' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 1,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
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
    'field_model_experience_tid' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 1,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
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
    'field_model_driving_license_tid' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 1,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
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
    'field_model_instagram_followers_tid' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 1,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            1 => 'vocabulary',
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
    'field_height_value' => array(
      'bef_format' => 'bef_slider',
      'slider_options' => array(
        'bef_slider_min' => '168',
        'bef_slider_max' => '189',
        'bef_slider_step' => '1',
        'bef_slider_animate' => '',
        'bef_slider_orientation' => 'horizontal',
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'bef_filter_description' => NULL,
        'any_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'more_options' => array(
        'is_secondary' => 1,
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
    'field_model_size_value' => array(
      'bef_format' => 'bef_slider',
      'slider_options' => array(
        'bef_slider_min' => '0',
        'bef_slider_max' => '60',
        'bef_slider_step' => '1',
        'bef_slider_animate' => '',
        'bef_slider_orientation' => 'horizontal',
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'bef_filter_description' => NULL,
        'any_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'more_options' => array(
        'is_secondary' => 1,
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
    'field_chest_value' => array(
      'bef_format' => 'bef_slider',
      'slider_options' => array(
        'bef_slider_min' => '75',
        'bef_slider_max' => '115',
        'bef_slider_step' => '1',
        'bef_slider_animate' => '',
        'bef_slider_orientation' => 'horizontal',
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'bef_filter_description' => NULL,
        'any_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'more_options' => array(
        'is_secondary' => 1,
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
    'field_waist_value' => array(
      'bef_format' => 'bef_slider',
      'slider_options' => array(
        'bef_slider_min' => '58',
        'bef_slider_max' => '85',
        'bef_slider_step' => '1',
        'bef_slider_animate' => '',
        'bef_slider_orientation' => 'horizontal',
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'bef_filter_description' => NULL,
        'any_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'more_options' => array(
        'is_secondary' => 1,
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
    'field_hip_value' => array(
      'bef_format' => 'bef_slider',
      'slider_options' => array(
        'bef_slider_min' => '85',
        'bef_slider_max' => '100',
        'bef_slider_step' => '1',
        'bef_slider_animate' => '',
        'bef_slider_orientation' => 'horizontal',
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'bef_filter_description' => NULL,
        'any_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'more_options' => array(
        'is_secondary' => 1,
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
    'field_shoe_size_value' => array(
      'bef_format' => 'bef_slider',
      'slider_options' => array(
        'bef_slider_min' => '0',
        'bef_slider_max' => '50',
        'bef_slider_step' => '1',
        'bef_slider_animate' => '',
        'bef_slider_orientation' => 'horizontal',
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'bef_filter_description' => NULL,
        'any_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'more_options' => array(
        'is_secondary' => 1,
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
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<div class="models_search_wrapper">
  <input id="models_search_filter" type="button" value="Filter" />
  <div id="loupe"></div>
  <input id="models_search_by_name" type="textfield"  placeholder="Search" />
  <div id="close_filter"></div>
</div>';
  $handler->display->display_options['header']['area']['format'] = 'php_code';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No active models.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Private data */
  $handler->display->display_options['relationships']['profile_1']['id'] = 'profile_1';
  $handler->display->display_options['relationships']['profile_1']['table'] = 'users';
  $handler->display->display_options['relationships']['profile_1']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile_1']['ui_name'] = 'Private data';
  $handler->display->display_options['relationships']['profile_1']['label'] = 'Private data';
  $handler->display->display_options['relationships']['profile_1']['bundle_types'] = array(
    'model_private_data' => 'model_private_data',
  );
  /* Relationship: Basic information */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['ui_name'] = 'Basic information';
  $handler->display->display_options['relationships']['profile']['label'] = 'Basic information';
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'model_basic_informaiton' => 'model_basic_informaiton',
  );
  /* Relationship: Additional information */
  $handler->display->display_options['relationships']['profile_2']['id'] = 'profile_2';
  $handler->display->display_options['relationships']['profile_2']['table'] = 'users';
  $handler->display->display_options['relationships']['profile_2']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile_2']['ui_name'] = 'Additional information';
  $handler->display->display_options['relationships']['profile_2']['label'] = 'Additional information';
  $handler->display->display_options['relationships']['profile_2']['bundle_types'] = array(
    'model_additional_info' => 'model_additional_info',
  );
  /* Relationship: Profile: Base city (field_c_base_city) */
  $handler->display->display_options['relationships']['field_c_base_city_value']['id'] = 'field_c_base_city_value';
  $handler->display->display_options['relationships']['field_c_base_city_value']['table'] = 'field_data_field_c_base_city';
  $handler->display->display_options['relationships']['field_c_base_city_value']['field'] = 'field_c_base_city_value';
  $handler->display->display_options['relationships']['field_c_base_city_value']['relationship'] = 'profile_1';
  $handler->display->display_options['relationships']['field_c_base_city_value']['label'] = 'base_city';
  $handler->display->display_options['relationships']['field_c_base_city_value']['delta'] = '-1';
  /* Relationship: Flags: casting_mark */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'users';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'casting_mark';
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['image_style'] = 'node_gallery_thumbnail';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: Profile: Daily rate */
  $handler->display->display_options['fields']['field_daily_rate']['id'] = 'field_daily_rate';
  $handler->display->display_options['fields']['field_daily_rate']['table'] = 'field_data_field_daily_rate';
  $handler->display->display_options['fields']['field_daily_rate']['field'] = 'field_daily_rate';
  $handler->display->display_options['fields']['field_daily_rate']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_daily_rate']['label'] = '';
  $handler->display->display_options['fields']['field_daily_rate']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_daily_rate']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Profile: Lingerie daily rate */
  $handler->display->display_options['fields']['field_lingerie_daily_rate']['id'] = 'field_lingerie_daily_rate';
  $handler->display->display_options['fields']['field_lingerie_daily_rate']['table'] = 'field_data_field_lingerie_daily_rate';
  $handler->display->display_options['fields']['field_lingerie_daily_rate']['field'] = 'field_lingerie_daily_rate';
  $handler->display->display_options['fields']['field_lingerie_daily_rate']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_lingerie_daily_rate']['label'] = '';
  $handler->display->display_options['fields']['field_lingerie_daily_rate']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_lingerie_daily_rate']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_lingerie_daily_rate']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Profile: Age category */
  $handler->display->display_options['fields']['field_age_category']['id'] = 'field_age_category';
  $handler->display->display_options['fields']['field_age_category']['table'] = 'field_data_field_age_category';
  $handler->display->display_options['fields']['field_age_category']['field'] = 'field_age_category';
  $handler->display->display_options['fields']['field_age_category']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_age_category']['element_label_colon'] = FALSE;
  /* Sort criterion: User: Rating (field_rating:rating) */
  $handler->display->display_options['sorts']['field_rating_rating']['id'] = 'field_rating_rating';
  $handler->display->display_options['sorts']['field_rating_rating']['table'] = 'field_data_field_rating';
  $handler->display->display_options['sorts']['field_rating_rating']['field'] = 'field_rating_rating';
  $handler->display->display_options['sorts']['field_rating_rating']['order'] = 'DESC';
  /* Sort criterion: User: Full name (field_full_name) */
  $handler->display->display_options['sorts']['field_full_name_value']['id'] = 'field_full_name_value';
  $handler->display->display_options['sorts']['field_full_name_value']['table'] = 'field_data_field_full_name';
  $handler->display->display_options['sorts']['field_full_name_value']['field'] = 'field_full_name_value';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'AND',
    3 => 'AND',
    4 => 'AND',
    5 => 'AND',
    6 => 'AND',
  );
  /* Filter criterion: User: Full name (field_full_name) */
  $handler->display->display_options['filters']['field_full_name_value']['id'] = 'field_full_name_value';
  $handler->display->display_options['filters']['field_full_name_value']['table'] = 'field_data_field_full_name';
  $handler->display->display_options['filters']['field_full_name_value']['field'] = 'field_full_name_value';
  $handler->display->display_options['filters']['field_full_name_value']['operator'] = 'allwords';
  $handler->display->display_options['filters']['field_full_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_full_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_full_name_value']['expose']['operator_id'] = 'field_full_name_value_op';
  $handler->display->display_options['filters']['field_full_name_value']['expose']['label'] = 'Full name';
  $handler->display->display_options['filters']['field_full_name_value']['expose']['operator'] = 'field_full_name_value_op';
  $handler->display->display_options['filters']['field_full_name_value']['expose']['identifier'] = 'field_full_name_value';
  $handler->display->display_options['filters']['field_full_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
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
  $handler->display->display_options['filters']['rid']['group'] = 1;
  /* Filter criterion: User: Model is active (field_model_is_active) */
  $handler->display->display_options['filters']['field_model_is_active_value']['id'] = 'field_model_is_active_value';
  $handler->display->display_options['filters']['field_model_is_active_value']['table'] = 'field_data_field_model_is_active';
  $handler->display->display_options['filters']['field_model_is_active_value']['field'] = 'field_model_is_active_value';
  $handler->display->display_options['filters']['field_model_is_active_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_model_is_active_value']['group'] = 1;
  /* Filter criterion: User: Model Availability */
  $handler->display->display_options['filters']['model_status']['id'] = 'model_status';
  $handler->display->display_options['filters']['model_status']['table'] = 'users';
  $handler->display->display_options['filters']['model_status']['field'] = 'model_status';
  $handler->display->display_options['filters']['model_status']['value'] = 1;
  $handler->display->display_options['filters']['model_status']['group'] = 2;
  $handler->display->display_options['filters']['model_status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['model_status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['model_status']['expose']['label'] = 'Dates';
  $handler->display->display_options['filters']['model_status']['expose']['operator'] = 'model_status_op';
  $handler->display->display_options['filters']['model_status']['expose']['identifier'] = 'model_status';
  $handler->display->display_options['filters']['model_status']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['model_status']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['model_status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Profile: Gender (field_model_gender) */
  $handler->display->display_options['filters']['field_model_gender_tid']['id'] = 'field_model_gender_tid';
  $handler->display->display_options['filters']['field_model_gender_tid']['table'] = 'field_data_field_model_gender';
  $handler->display->display_options['filters']['field_model_gender_tid']['field'] = 'field_model_gender_tid';
  $handler->display->display_options['filters']['field_model_gender_tid']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_model_gender_tid']['group'] = 3;
  $handler->display->display_options['filters']['field_model_gender_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_model_gender_tid']['expose']['operator_id'] = 'field_model_gender_tid_op';
  $handler->display->display_options['filters']['field_model_gender_tid']['expose']['operator'] = 'field_model_gender_tid_op';
  $handler->display->display_options['filters']['field_model_gender_tid']['expose']['identifier'] = 'field_model_gender_tid';
  $handler->display->display_options['filters']['field_model_gender_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_model_gender_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_model_gender_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_model_gender_tid']['vocabulary'] = 'gender';
  $handler->display->display_options['filters']['field_model_gender_tid']['error_message'] = FALSE;
  /* Filter criterion: Field collection item: Base city (field_model_base_city) */
  $handler->display->display_options['filters']['field_model_base_city_tid']['id'] = 'field_model_base_city_tid';
  $handler->display->display_options['filters']['field_model_base_city_tid']['table'] = 'field_data_field_model_base_city';
  $handler->display->display_options['filters']['field_model_base_city_tid']['field'] = 'field_model_base_city_tid';
  $handler->display->display_options['filters']['field_model_base_city_tid']['relationship'] = 'field_c_base_city_value';
  $handler->display->display_options['filters']['field_model_base_city_tid']['value'] = '';
  $handler->display->display_options['filters']['field_model_base_city_tid']['group'] = 3;
  $handler->display->display_options['filters']['field_model_base_city_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_model_base_city_tid']['expose']['operator_id'] = 'field_model_base_city_tid_op';
  $handler->display->display_options['filters']['field_model_base_city_tid']['expose']['label'] = 'Base city';
  $handler->display->display_options['filters']['field_model_base_city_tid']['expose']['operator'] = 'field_model_base_city_tid_op';
  $handler->display->display_options['filters']['field_model_base_city_tid']['expose']['identifier'] = 'field_model_base_city_tid';
  $handler->display->display_options['filters']['field_model_base_city_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_model_base_city_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_model_base_city_tid']['vocabulary'] = 'base_city';
  $handler->display->display_options['filters']['field_model_base_city_tid']['error_message'] = FALSE;
  /* Filter criterion: Profile: Eye color (field_model_eye_color) */
  $handler->display->display_options['filters']['field_model_eye_color_tid']['id'] = 'field_model_eye_color_tid';
  $handler->display->display_options['filters']['field_model_eye_color_tid']['table'] = 'field_data_field_model_eye_color';
  $handler->display->display_options['filters']['field_model_eye_color_tid']['field'] = 'field_model_eye_color_tid';
  $handler->display->display_options['filters']['field_model_eye_color_tid']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_model_eye_color_tid']['group'] = 3;
  $handler->display->display_options['filters']['field_model_eye_color_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_model_eye_color_tid']['expose']['operator_id'] = 'field_model_eye_color_tid_op';
  $handler->display->display_options['filters']['field_model_eye_color_tid']['expose']['label'] = 'Eye color';
  $handler->display->display_options['filters']['field_model_eye_color_tid']['expose']['operator'] = 'field_model_eye_color_tid_op';
  $handler->display->display_options['filters']['field_model_eye_color_tid']['expose']['identifier'] = 'field_model_eye_color_tid';
  $handler->display->display_options['filters']['field_model_eye_color_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_model_eye_color_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_model_eye_color_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_model_eye_color_tid']['vocabulary'] = 'eye_color';
  /* Filter criterion: Profile: Hair color (field_model_hair_color) */
  $handler->display->display_options['filters']['field_model_hair_color_tid']['id'] = 'field_model_hair_color_tid';
  $handler->display->display_options['filters']['field_model_hair_color_tid']['table'] = 'field_data_field_model_hair_color';
  $handler->display->display_options['filters']['field_model_hair_color_tid']['field'] = 'field_model_hair_color_tid';
  $handler->display->display_options['filters']['field_model_hair_color_tid']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_model_hair_color_tid']['group'] = 3;
  $handler->display->display_options['filters']['field_model_hair_color_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_model_hair_color_tid']['expose']['operator_id'] = 'field_model_hair_color_tid_op';
  $handler->display->display_options['filters']['field_model_hair_color_tid']['expose']['label'] = 'Hair color';
  $handler->display->display_options['filters']['field_model_hair_color_tid']['expose']['operator'] = 'field_model_hair_color_tid_op';
  $handler->display->display_options['filters']['field_model_hair_color_tid']['expose']['identifier'] = 'field_model_hair_color_tid';
  $handler->display->display_options['filters']['field_model_hair_color_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_model_hair_color_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_model_hair_color_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_model_hair_color_tid']['vocabulary'] = 'hair_color';
  /* Filter criterion: Profile: Daily rate (field_daily_rate) */
  $handler->display->display_options['filters']['field_daily_rate_value_1']['id'] = 'field_daily_rate_value_1';
  $handler->display->display_options['filters']['field_daily_rate_value_1']['table'] = 'field_data_field_daily_rate';
  $handler->display->display_options['filters']['field_daily_rate_value_1']['field'] = 'field_daily_rate_value';
  $handler->display->display_options['filters']['field_daily_rate_value_1']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_daily_rate_value_1']['operator'] = '<=';
  $handler->display->display_options['filters']['field_daily_rate_value_1']['group'] = 4;
  $handler->display->display_options['filters']['field_daily_rate_value_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_daily_rate_value_1']['expose']['operator_id'] = 'field_daily_rate_value_1_op';
  $handler->display->display_options['filters']['field_daily_rate_value_1']['expose']['label'] = 'Daily rate';
  $handler->display->display_options['filters']['field_daily_rate_value_1']['expose']['operator'] = 'field_daily_rate_value_1_op';
  $handler->display->display_options['filters']['field_daily_rate_value_1']['expose']['identifier'] = 'field_daily_rate_value_1';
  $handler->display->display_options['filters']['field_daily_rate_value_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Profile: Lingerie daily rate (field_lingerie_daily_rate) */
  $handler->display->display_options['filters']['field_lingerie_daily_rate_value']['id'] = 'field_lingerie_daily_rate_value';
  $handler->display->display_options['filters']['field_lingerie_daily_rate_value']['table'] = 'field_data_field_lingerie_daily_rate';
  $handler->display->display_options['filters']['field_lingerie_daily_rate_value']['field'] = 'field_lingerie_daily_rate_value';
  $handler->display->display_options['filters']['field_lingerie_daily_rate_value']['relationship'] = 'profile_2';
  $handler->display->display_options['filters']['field_lingerie_daily_rate_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_lingerie_daily_rate_value']['group'] = 4;
  $handler->display->display_options['filters']['field_lingerie_daily_rate_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lingerie_daily_rate_value']['expose']['operator_id'] = 'field_lingerie_daily_rate_value_op';
  $handler->display->display_options['filters']['field_lingerie_daily_rate_value']['expose']['label'] = 'Lingerie daily rate';
  $handler->display->display_options['filters']['field_lingerie_daily_rate_value']['expose']['operator'] = 'field_lingerie_daily_rate_value_op';
  $handler->display->display_options['filters']['field_lingerie_daily_rate_value']['expose']['identifier'] = 'field_lingerie_daily_rate_value';
  $handler->display->display_options['filters']['field_lingerie_daily_rate_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Profile: Lingerie (field_lingerie) */
  $handler->display->display_options['filters']['field_lingerie_value']['id'] = 'field_lingerie_value';
  $handler->display->display_options['filters']['field_lingerie_value']['table'] = 'field_data_field_lingerie';
  $handler->display->display_options['filters']['field_lingerie_value']['field'] = 'field_lingerie_value';
  $handler->display->display_options['filters']['field_lingerie_value']['relationship'] = 'profile_2';
  $handler->display->display_options['filters']['field_lingerie_value']['group'] = 4;
  $handler->display->display_options['filters']['field_lingerie_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_lingerie_value']['expose']['operator_id'] = 'field_lingerie_value_op';
  $handler->display->display_options['filters']['field_lingerie_value']['expose']['operator'] = 'field_lingerie_value_op';
  $handler->display->display_options['filters']['field_lingerie_value']['expose']['identifier'] = 'field_lingerie_value';
  $handler->display->display_options['filters']['field_lingerie_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_lingerie_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Profile: Teeth gap (field_teeth_gap) */
  $handler->display->display_options['filters']['field_teeth_gap_value']['id'] = 'field_teeth_gap_value';
  $handler->display->display_options['filters']['field_teeth_gap_value']['table'] = 'field_data_field_teeth_gap';
  $handler->display->display_options['filters']['field_teeth_gap_value']['field'] = 'field_teeth_gap_value';
  $handler->display->display_options['filters']['field_teeth_gap_value']['relationship'] = 'profile_2';
  $handler->display->display_options['filters']['field_teeth_gap_value']['group'] = 4;
  $handler->display->display_options['filters']['field_teeth_gap_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_teeth_gap_value']['expose']['operator_id'] = 'field_teeth_gap_value_op';
  $handler->display->display_options['filters']['field_teeth_gap_value']['expose']['operator'] = 'field_teeth_gap_value_op';
  $handler->display->display_options['filters']['field_teeth_gap_value']['expose']['identifier'] = 'field_teeth_gap_value';
  $handler->display->display_options['filters']['field_teeth_gap_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_teeth_gap_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Profile: Beautiful feet (field_beautiful_feet) */
  $handler->display->display_options['filters']['field_beautiful_feet_value_1']['id'] = 'field_beautiful_feet_value_1';
  $handler->display->display_options['filters']['field_beautiful_feet_value_1']['table'] = 'field_data_field_beautiful_feet';
  $handler->display->display_options['filters']['field_beautiful_feet_value_1']['field'] = 'field_beautiful_feet_value';
  $handler->display->display_options['filters']['field_beautiful_feet_value_1']['relationship'] = 'profile_2';
  $handler->display->display_options['filters']['field_beautiful_feet_value_1']['group'] = 4;
  $handler->display->display_options['filters']['field_beautiful_feet_value_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_beautiful_feet_value_1']['expose']['operator_id'] = 'field_beautiful_feet_value_1_op';
  $handler->display->display_options['filters']['field_beautiful_feet_value_1']['expose']['operator'] = 'field_beautiful_feet_value_1_op';
  $handler->display->display_options['filters']['field_beautiful_feet_value_1']['expose']['identifier'] = 'field_beautiful_feet_value_1';
  $handler->display->display_options['filters']['field_beautiful_feet_value_1']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_beautiful_feet_value_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Profile: Beautiful hands (field_beautiful_hands) */
  $handler->display->display_options['filters']['field_beautiful_hands_value_1']['id'] = 'field_beautiful_hands_value_1';
  $handler->display->display_options['filters']['field_beautiful_hands_value_1']['table'] = 'field_data_field_beautiful_hands';
  $handler->display->display_options['filters']['field_beautiful_hands_value_1']['field'] = 'field_beautiful_hands_value';
  $handler->display->display_options['filters']['field_beautiful_hands_value_1']['relationship'] = 'profile_2';
  $handler->display->display_options['filters']['field_beautiful_hands_value_1']['group'] = 4;
  $handler->display->display_options['filters']['field_beautiful_hands_value_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_beautiful_hands_value_1']['expose']['operator_id'] = 'field_beautiful_hands_value_1_op';
  $handler->display->display_options['filters']['field_beautiful_hands_value_1']['expose']['operator'] = 'field_beautiful_hands_value_1_op';
  $handler->display->display_options['filters']['field_beautiful_hands_value_1']['expose']['identifier'] = 'field_beautiful_hands_value_1';
  $handler->display->display_options['filters']['field_beautiful_hands_value_1']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_beautiful_hands_value_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Profile: Freckles (field_freckles) */
  $handler->display->display_options['filters']['field_freckles_value']['id'] = 'field_freckles_value';
  $handler->display->display_options['filters']['field_freckles_value']['table'] = 'field_data_field_freckles';
  $handler->display->display_options['filters']['field_freckles_value']['field'] = 'field_freckles_value';
  $handler->display->display_options['filters']['field_freckles_value']['relationship'] = 'profile_2';
  $handler->display->display_options['filters']['field_freckles_value']['group'] = 4;
  $handler->display->display_options['filters']['field_freckles_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_freckles_value']['expose']['operator_id'] = 'field_freckles_value_op';
  $handler->display->display_options['filters']['field_freckles_value']['expose']['operator'] = 'field_freckles_value_op';
  $handler->display->display_options['filters']['field_freckles_value']['expose']['identifier'] = 'field_freckles_value';
  $handler->display->display_options['filters']['field_freckles_value']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_freckles_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Profile: Age category (field_age_category) */
  $handler->display->display_options['filters']['field_age_category_tid']['id'] = 'field_age_category_tid';
  $handler->display->display_options['filters']['field_age_category_tid']['table'] = 'field_data_field_age_category';
  $handler->display->display_options['filters']['field_age_category_tid']['field'] = 'field_age_category_tid';
  $handler->display->display_options['filters']['field_age_category_tid']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_age_category_tid']['group'] = 5;
  $handler->display->display_options['filters']['field_age_category_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_age_category_tid']['expose']['operator_id'] = 'field_age_category_tid_op';
  $handler->display->display_options['filters']['field_age_category_tid']['expose']['label'] = 'Age category';
  $handler->display->display_options['filters']['field_age_category_tid']['expose']['operator'] = 'field_age_category_tid_op';
  $handler->display->display_options['filters']['field_age_category_tid']['expose']['identifier'] = 'field_age_category_tid';
  $handler->display->display_options['filters']['field_age_category_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_age_category_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_age_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_age_category_tid']['vocabulary'] = 'age_category';
  /* Filter criterion: Profile: Ethnicity (field_model_ethnicity) */
  $handler->display->display_options['filters']['field_model_ethnicity_tid']['id'] = 'field_model_ethnicity_tid';
  $handler->display->display_options['filters']['field_model_ethnicity_tid']['table'] = 'field_data_field_model_ethnicity';
  $handler->display->display_options['filters']['field_model_ethnicity_tid']['field'] = 'field_model_ethnicity_tid';
  $handler->display->display_options['filters']['field_model_ethnicity_tid']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_model_ethnicity_tid']['group'] = 5;
  $handler->display->display_options['filters']['field_model_ethnicity_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_model_ethnicity_tid']['expose']['operator_id'] = 'field_model_ethnicity_tid_op';
  $handler->display->display_options['filters']['field_model_ethnicity_tid']['expose']['label'] = 'Ethnicity';
  $handler->display->display_options['filters']['field_model_ethnicity_tid']['expose']['operator'] = 'field_model_ethnicity_tid_op';
  $handler->display->display_options['filters']['field_model_ethnicity_tid']['expose']['identifier'] = 'field_model_ethnicity_tid';
  $handler->display->display_options['filters']['field_model_ethnicity_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_model_ethnicity_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_model_ethnicity_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_model_ethnicity_tid']['vocabulary'] = 'ethnicity';
  /* Filter criterion: Profile: Sports (field_model_sports) */
  $handler->display->display_options['filters']['field_model_sports_tid']['id'] = 'field_model_sports_tid';
  $handler->display->display_options['filters']['field_model_sports_tid']['table'] = 'field_data_field_model_sports';
  $handler->display->display_options['filters']['field_model_sports_tid']['field'] = 'field_model_sports_tid';
  $handler->display->display_options['filters']['field_model_sports_tid']['relationship'] = 'profile_2';
  $handler->display->display_options['filters']['field_model_sports_tid']['group'] = 5;
  $handler->display->display_options['filters']['field_model_sports_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_model_sports_tid']['expose']['operator_id'] = 'field_model_sports_tid_op';
  $handler->display->display_options['filters']['field_model_sports_tid']['expose']['label'] = 'Sports';
  $handler->display->display_options['filters']['field_model_sports_tid']['expose']['operator'] = 'field_model_sports_tid_op';
  $handler->display->display_options['filters']['field_model_sports_tid']['expose']['identifier'] = 'field_model_sports_tid';
  $handler->display->display_options['filters']['field_model_sports_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_model_sports_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_model_sports_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_model_sports_tid']['vocabulary'] = 'sport';
  /* Filter criterion: Profile: Experience (field_model_experience) */
  $handler->display->display_options['filters']['field_model_experience_tid']['id'] = 'field_model_experience_tid';
  $handler->display->display_options['filters']['field_model_experience_tid']['table'] = 'field_data_field_model_experience';
  $handler->display->display_options['filters']['field_model_experience_tid']['field'] = 'field_model_experience_tid';
  $handler->display->display_options['filters']['field_model_experience_tid']['relationship'] = 'profile_2';
  $handler->display->display_options['filters']['field_model_experience_tid']['group'] = 5;
  $handler->display->display_options['filters']['field_model_experience_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_model_experience_tid']['expose']['operator_id'] = 'field_model_experience_tid_op';
  $handler->display->display_options['filters']['field_model_experience_tid']['expose']['label'] = 'Experience';
  $handler->display->display_options['filters']['field_model_experience_tid']['expose']['operator'] = 'field_model_experience_tid_op';
  $handler->display->display_options['filters']['field_model_experience_tid']['expose']['identifier'] = 'field_model_experience_tid';
  $handler->display->display_options['filters']['field_model_experience_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_model_experience_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_model_experience_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_model_experience_tid']['vocabulary'] = 'experience';
  /* Filter criterion: Profile: Driving license (field_model_driving_license) */
  $handler->display->display_options['filters']['field_model_driving_license_tid']['id'] = 'field_model_driving_license_tid';
  $handler->display->display_options['filters']['field_model_driving_license_tid']['table'] = 'field_data_field_model_driving_license';
  $handler->display->display_options['filters']['field_model_driving_license_tid']['field'] = 'field_model_driving_license_tid';
  $handler->display->display_options['filters']['field_model_driving_license_tid']['relationship'] = 'profile_2';
  $handler->display->display_options['filters']['field_model_driving_license_tid']['group'] = 5;
  $handler->display->display_options['filters']['field_model_driving_license_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_model_driving_license_tid']['expose']['operator_id'] = 'field_model_driving_license_tid_op';
  $handler->display->display_options['filters']['field_model_driving_license_tid']['expose']['label'] = 'Driving license';
  $handler->display->display_options['filters']['field_model_driving_license_tid']['expose']['operator'] = 'field_model_driving_license_tid_op';
  $handler->display->display_options['filters']['field_model_driving_license_tid']['expose']['identifier'] = 'field_model_driving_license_tid';
  $handler->display->display_options['filters']['field_model_driving_license_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_model_driving_license_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_model_driving_license_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_model_driving_license_tid']['vocabulary'] = 'driving_license';
  /* Filter criterion: Profile: Instagram followers (field_model_instagram_followers) */
  $handler->display->display_options['filters']['field_model_instagram_followers_tid']['id'] = 'field_model_instagram_followers_tid';
  $handler->display->display_options['filters']['field_model_instagram_followers_tid']['table'] = 'field_data_field_model_instagram_followers';
  $handler->display->display_options['filters']['field_model_instagram_followers_tid']['field'] = 'field_model_instagram_followers_tid';
  $handler->display->display_options['filters']['field_model_instagram_followers_tid']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_model_instagram_followers_tid']['group'] = 5;
  $handler->display->display_options['filters']['field_model_instagram_followers_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_model_instagram_followers_tid']['expose']['operator_id'] = 'field_model_instagram_followers_tid_op';
  $handler->display->display_options['filters']['field_model_instagram_followers_tid']['expose']['label'] = 'Instagram followers';
  $handler->display->display_options['filters']['field_model_instagram_followers_tid']['expose']['operator'] = 'field_model_instagram_followers_tid_op';
  $handler->display->display_options['filters']['field_model_instagram_followers_tid']['expose']['identifier'] = 'field_model_instagram_followers_tid';
  $handler->display->display_options['filters']['field_model_instagram_followers_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_model_instagram_followers_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_model_instagram_followers_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_model_instagram_followers_tid']['vocabulary'] = 'instagram_followers';
  /* Filter criterion: Profile: Height (field_height) */
  $handler->display->display_options['filters']['field_height_value']['id'] = 'field_height_value';
  $handler->display->display_options['filters']['field_height_value']['table'] = 'field_data_field_height';
  $handler->display->display_options['filters']['field_height_value']['field'] = 'field_height_value';
  $handler->display->display_options['filters']['field_height_value']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_height_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_height_value']['group'] = 6;
  $handler->display->display_options['filters']['field_height_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_height_value']['expose']['operator_id'] = 'field_height_value_op';
  $handler->display->display_options['filters']['field_height_value']['expose']['label'] = 'Height';
  $handler->display->display_options['filters']['field_height_value']['expose']['operator'] = 'field_height_value_op';
  $handler->display->display_options['filters']['field_height_value']['expose']['identifier'] = 'field_height_value';
  $handler->display->display_options['filters']['field_height_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Profile: Size (field_model_size) */
  $handler->display->display_options['filters']['field_model_size_value']['id'] = 'field_model_size_value';
  $handler->display->display_options['filters']['field_model_size_value']['table'] = 'field_data_field_model_size';
  $handler->display->display_options['filters']['field_model_size_value']['field'] = 'field_model_size_value';
  $handler->display->display_options['filters']['field_model_size_value']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_model_size_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_model_size_value']['group'] = 6;
  $handler->display->display_options['filters']['field_model_size_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_model_size_value']['expose']['operator_id'] = 'field_model_size_value_op';
  $handler->display->display_options['filters']['field_model_size_value']['expose']['label'] = 'Size';
  $handler->display->display_options['filters']['field_model_size_value']['expose']['operator'] = 'field_model_size_value_op';
  $handler->display->display_options['filters']['field_model_size_value']['expose']['identifier'] = 'field_model_size_value';
  $handler->display->display_options['filters']['field_model_size_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Profile: Bust (field_chest) */
  $handler->display->display_options['filters']['field_chest_value']['id'] = 'field_chest_value';
  $handler->display->display_options['filters']['field_chest_value']['table'] = 'field_data_field_chest';
  $handler->display->display_options['filters']['field_chest_value']['field'] = 'field_chest_value';
  $handler->display->display_options['filters']['field_chest_value']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_chest_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_chest_value']['group'] = 6;
  $handler->display->display_options['filters']['field_chest_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_chest_value']['expose']['operator_id'] = 'field_chest_value_op';
  $handler->display->display_options['filters']['field_chest_value']['expose']['label'] = 'Bust';
  $handler->display->display_options['filters']['field_chest_value']['expose']['operator'] = 'field_chest_value_op';
  $handler->display->display_options['filters']['field_chest_value']['expose']['identifier'] = 'field_chest_value';
  $handler->display->display_options['filters']['field_chest_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Profile: Waist (field_waist) */
  $handler->display->display_options['filters']['field_waist_value']['id'] = 'field_waist_value';
  $handler->display->display_options['filters']['field_waist_value']['table'] = 'field_data_field_waist';
  $handler->display->display_options['filters']['field_waist_value']['field'] = 'field_waist_value';
  $handler->display->display_options['filters']['field_waist_value']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_waist_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_waist_value']['group'] = 6;
  $handler->display->display_options['filters']['field_waist_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_waist_value']['expose']['operator_id'] = 'field_waist_value_op';
  $handler->display->display_options['filters']['field_waist_value']['expose']['label'] = 'Waist';
  $handler->display->display_options['filters']['field_waist_value']['expose']['operator'] = 'field_waist_value_op';
  $handler->display->display_options['filters']['field_waist_value']['expose']['identifier'] = 'field_waist_value';
  $handler->display->display_options['filters']['field_waist_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Profile: Hips (field_hip) */
  $handler->display->display_options['filters']['field_hip_value']['id'] = 'field_hip_value';
  $handler->display->display_options['filters']['field_hip_value']['table'] = 'field_data_field_hip';
  $handler->display->display_options['filters']['field_hip_value']['field'] = 'field_hip_value';
  $handler->display->display_options['filters']['field_hip_value']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_hip_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_hip_value']['group'] = 6;
  $handler->display->display_options['filters']['field_hip_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_hip_value']['expose']['operator_id'] = 'field_hip_value_op';
  $handler->display->display_options['filters']['field_hip_value']['expose']['label'] = 'Hips';
  $handler->display->display_options['filters']['field_hip_value']['expose']['operator'] = 'field_hip_value_op';
  $handler->display->display_options['filters']['field_hip_value']['expose']['identifier'] = 'field_hip_value';
  $handler->display->display_options['filters']['field_hip_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Profile: Shoe size (field_shoe_size) */
  $handler->display->display_options['filters']['field_shoe_size_value']['id'] = 'field_shoe_size_value';
  $handler->display->display_options['filters']['field_shoe_size_value']['table'] = 'field_data_field_shoe_size';
  $handler->display->display_options['filters']['field_shoe_size_value']['field'] = 'field_shoe_size_value';
  $handler->display->display_options['filters']['field_shoe_size_value']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_shoe_size_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_shoe_size_value']['group'] = 6;
  $handler->display->display_options['filters']['field_shoe_size_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_shoe_size_value']['expose']['operator_id'] = 'field_shoe_size_value_op';
  $handler->display->display_options['filters']['field_shoe_size_value']['expose']['label'] = 'Shoe size';
  $handler->display->display_options['filters']['field_shoe_size_value']['expose']['operator'] = 'field_shoe_size_value_op';
  $handler->display->display_options['filters']['field_shoe_size_value']['expose']['identifier'] = 'field_shoe_size_value';
  $handler->display->display_options['filters']['field_shoe_size_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Models';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['text'] = 'Prepare propose.';
  $handler->display->display_options['fields']['uid']['alter']['path'] = 'job/model/[uid]/invite';
  $handler->display->display_options['fields']['uid']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['picture']['alter']['path'] = 'job/model/[uid]/invite';
  $handler->display->display_options['fields']['picture']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['picture']['alter']['preserve_tags'] = '<a> <img>';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Profile: Daily rate */
  $handler->display->display_options['fields']['field_daily_rate']['id'] = 'field_daily_rate';
  $handler->display->display_options['fields']['field_daily_rate']['table'] = 'field_data_field_daily_rate';
  $handler->display->display_options['fields']['field_daily_rate']['field'] = 'field_daily_rate';
  $handler->display->display_options['fields']['field_daily_rate']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_daily_rate']['label'] = '';
  $handler->display->display_options['fields']['field_daily_rate']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_daily_rate']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_daily_rate']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Profile: Lingerie daily rate */
  $handler->display->display_options['fields']['field_lingerie_daily_rate']['id'] = 'field_lingerie_daily_rate';
  $handler->display->display_options['fields']['field_lingerie_daily_rate']['table'] = 'field_data_field_lingerie_daily_rate';
  $handler->display->display_options['fields']['field_lingerie_daily_rate']['field'] = 'field_lingerie_daily_rate';
  $handler->display->display_options['fields']['field_lingerie_daily_rate']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_lingerie_daily_rate']['label'] = '';
  $handler->display->display_options['fields']['field_lingerie_daily_rate']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_lingerie_daily_rate']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_lingerie_daily_rate']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Profile: Age category */
  $handler->display->display_options['fields']['field_age_category']['id'] = 'field_age_category';
  $handler->display->display_options['fields']['field_age_category']['table'] = 'field_data_field_age_category';
  $handler->display->display_options['fields']['field_age_category']['field'] = 'field_age_category';
  $handler->display->display_options['fields']['field_age_category']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_age_category']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_age_category']['element_label_colon'] = FALSE;
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  /* Field: User: Full name */
  $handler->display->display_options['fields']['field_full_name']['id'] = 'field_full_name';
  $handler->display->display_options['fields']['field_full_name']['table'] = 'field_data_field_full_name';
  $handler->display->display_options['fields']['field_full_name']['field'] = 'field_full_name';
  $handler->display->display_options['fields']['field_full_name']['label'] = '';
  $handler->display->display_options['fields']['field_full_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_full_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_full_name']['alter']['path'] = 'job/model/[uid]/invite';
  $handler->display->display_options['fields']['field_full_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['path'] = 'models';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Models';
  $handler->display->display_options['menu']['name'] = 'main-menu';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = '[name]';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['exclude'] = TRUE;
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['image_style'] = '462_267';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Profile: Daily rate */
  $handler->display->display_options['fields']['field_daily_rate']['id'] = 'field_daily_rate';
  $handler->display->display_options['fields']['field_daily_rate']['table'] = 'field_data_field_daily_rate';
  $handler->display->display_options['fields']['field_daily_rate']['field'] = 'field_daily_rate';
  $handler->display->display_options['fields']['field_daily_rate']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_daily_rate']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_daily_rate']['group_column'] = 'entity_id';
  /* Field: Profile: Lingerie daily rate */
  $handler->display->display_options['fields']['field_lingerie_daily_rate']['id'] = 'field_lingerie_daily_rate';
  $handler->display->display_options['fields']['field_lingerie_daily_rate']['table'] = 'field_data_field_lingerie_daily_rate';
  $handler->display->display_options['fields']['field_lingerie_daily_rate']['field'] = 'field_lingerie_daily_rate';
  $handler->display->display_options['fields']['field_lingerie_daily_rate']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_lingerie_daily_rate']['label'] = '';
  $handler->display->display_options['fields']['field_lingerie_daily_rate']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_lingerie_daily_rate']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_lingerie_daily_rate']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_lingerie_daily_rate']['group_column'] = 'entity_id';
  /* Field: Profile: Age category */
  $handler->display->display_options['fields']['field_age_category']['id'] = 'field_age_category';
  $handler->display->display_options['fields']['field_age_category']['table'] = 'field_data_field_age_category';
  $handler->display->display_options['fields']['field_age_category']['field'] = 'field_age_category';
  $handler->display->display_options['fields']['field_age_category']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_age_category']['group_column'] = 'entity_id';
  /* Field: Profile: Height */
  $handler->display->display_options['fields']['field_height']['id'] = 'field_height';
  $handler->display->display_options['fields']['field_height']['table'] = 'field_data_field_height';
  $handler->display->display_options['fields']['field_height']['field'] = 'field_height';
  $handler->display->display_options['fields']['field_height']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_height']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_height']['group_column'] = 'entity_id';
  /* Field: Profile: Bust */
  $handler->display->display_options['fields']['field_chest']['id'] = 'field_chest';
  $handler->display->display_options['fields']['field_chest']['table'] = 'field_data_field_chest';
  $handler->display->display_options['fields']['field_chest']['field'] = 'field_chest';
  $handler->display->display_options['fields']['field_chest']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_chest']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_chest']['group_column'] = 'entity_id';
  /* Field: Profile: Waist */
  $handler->display->display_options['fields']['field_waist']['id'] = 'field_waist';
  $handler->display->display_options['fields']['field_waist']['table'] = 'field_data_field_waist';
  $handler->display->display_options['fields']['field_waist']['field'] = 'field_waist';
  $handler->display->display_options['fields']['field_waist']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_waist']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_waist']['group_column'] = 'entity_id';
  /* Field: Profile: Hips */
  $handler->display->display_options['fields']['field_hip']['id'] = 'field_hip';
  $handler->display->display_options['fields']['field_hip']['table'] = 'field_data_field_hip';
  $handler->display->display_options['fields']['field_hip']['field'] = 'field_hip';
  $handler->display->display_options['fields']['field_hip']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_hip']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_hip']['group_column'] = 'entity_id';
  /* Field: Profile: Shoe size */
  $handler->display->display_options['fields']['field_shoe_size']['id'] = 'field_shoe_size';
  $handler->display->display_options['fields']['field_shoe_size']['table'] = 'field_data_field_shoe_size';
  $handler->display->display_options['fields']['field_shoe_size']['field'] = 'field_shoe_size';
  $handler->display->display_options['fields']['field_shoe_size']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_shoe_size']['label'] = 'Shoes';
  $handler->display->display_options['fields']['field_shoe_size']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_shoe_size']['group_column'] = 'entity_id';
  /* Field: Profile: Hair color */
  $handler->display->display_options['fields']['field_model_hair_color']['id'] = 'field_model_hair_color';
  $handler->display->display_options['fields']['field_model_hair_color']['table'] = 'field_data_field_model_hair_color';
  $handler->display->display_options['fields']['field_model_hair_color']['field'] = 'field_model_hair_color';
  $handler->display->display_options['fields']['field_model_hair_color']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_model_hair_color']['label'] = 'Hair';
  $handler->display->display_options['fields']['field_model_hair_color']['group_column'] = 'entity_id';
  /* Field: Profile: Eye color */
  $handler->display->display_options['fields']['field_model_eye_color']['id'] = 'field_model_eye_color';
  $handler->display->display_options['fields']['field_model_eye_color']['table'] = 'field_data_field_model_eye_color';
  $handler->display->display_options['fields']['field_model_eye_color']['field'] = 'field_model_eye_color';
  $handler->display->display_options['fields']['field_model_eye_color']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_model_eye_color']['label'] = 'Eyes';
  $handler->display->display_options['fields']['field_model_eye_color']['group_column'] = 'entity_id';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
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
  /* Filter criterion: User: Model is active (field_model_is_active) */
  $handler->display->display_options['filters']['field_model_is_active_value']['id'] = 'field_model_is_active_value';
  $handler->display->display_options['filters']['field_model_is_active_value']['table'] = 'field_data_field_model_is_active';
  $handler->display->display_options['filters']['field_model_is_active_value']['field'] = 'field_model_is_active_value';
  $handler->display->display_options['filters']['field_model_is_active_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['block_description'] = 'Model Job Invite - messuirments';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'model_basic_informaiton' => 'model_basic_informaiton',
    'model_private_data' => 'model_private_data',
  );
  /* Relationship: Profile: Base city (field_c_base_city) */
  $handler->display->display_options['relationships']['field_c_base_city_value']['id'] = 'field_c_base_city_value';
  $handler->display->display_options['relationships']['field_c_base_city_value']['table'] = 'field_data_field_c_base_city';
  $handler->display->display_options['relationships']['field_c_base_city_value']['field'] = 'field_c_base_city_value';
  $handler->display->display_options['relationships']['field_c_base_city_value']['relationship'] = 'profile';
  $handler->display->display_options['relationships']['field_c_base_city_value']['label'] = 'base_city';
  $handler->display->display_options['relationships']['field_c_base_city_value']['delta'] = '-1';
  /* Relationship: Flags: casting_mark */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'users';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'casting_mark';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['text'] = 'Prepare propose.';
  $handler->display->display_options['fields']['uid']['alter']['path'] = 'job/model/[uid]/invite';
  $handler->display->display_options['fields']['uid']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['picture']['alter']['path'] = 'job/model/[uid]/invite';
  $handler->display->display_options['fields']['picture']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['picture']['alter']['preserve_tags'] = '<a> <img>';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Profile: Daily rate */
  $handler->display->display_options['fields']['field_daily_rate']['id'] = 'field_daily_rate';
  $handler->display->display_options['fields']['field_daily_rate']['table'] = 'field_data_field_daily_rate';
  $handler->display->display_options['fields']['field_daily_rate']['field'] = 'field_daily_rate';
  $handler->display->display_options['fields']['field_daily_rate']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_daily_rate']['label'] = '';
  $handler->display->display_options['fields']['field_daily_rate']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_daily_rate']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_daily_rate']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Profile: Lingerie daily rate */
  $handler->display->display_options['fields']['field_lingerie_daily_rate']['id'] = 'field_lingerie_daily_rate';
  $handler->display->display_options['fields']['field_lingerie_daily_rate']['table'] = 'field_data_field_lingerie_daily_rate';
  $handler->display->display_options['fields']['field_lingerie_daily_rate']['field'] = 'field_lingerie_daily_rate';
  $handler->display->display_options['fields']['field_lingerie_daily_rate']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_lingerie_daily_rate']['label'] = '';
  $handler->display->display_options['fields']['field_lingerie_daily_rate']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_lingerie_daily_rate']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_lingerie_daily_rate']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Profile: Age category */
  $handler->display->display_options['fields']['field_age_category']['id'] = 'field_age_category';
  $handler->display->display_options['fields']['field_age_category']['table'] = 'field_data_field_age_category';
  $handler->display->display_options['fields']['field_age_category']['field'] = 'field_age_category';
  $handler->display->display_options['fields']['field_age_category']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_age_category']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_age_category']['element_label_colon'] = FALSE;
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  /* Field: User: Full name */
  $handler->display->display_options['fields']['field_full_name']['id'] = 'field_full_name';
  $handler->display->display_options['fields']['field_full_name']['table'] = 'field_data_field_full_name';
  $handler->display->display_options['fields']['field_full_name']['field'] = 'field_full_name';
  $handler->display->display_options['fields']['field_full_name']['label'] = '';
  $handler->display->display_options['fields']['field_full_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_full_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_full_name']['alter']['path'] = 'job/model/[uid]/invite';
  $handler->display->display_options['fields']['field_full_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['path'] = 'castinglist';
  $handler->display->display_options['menu']['title'] = 'Castinglist';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Models';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['text'] = 'Prepare propose.';
  $handler->display->display_options['fields']['uid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['path'] = 'job/model/[uid]/invite';
  $handler->display->display_options['fields']['uid']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['picture']['alter']['path'] = 'job/model/[uid]/invite';
  $handler->display->display_options['fields']['picture']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['picture']['alter']['preserve_tags'] = '<a> <img>';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Profile: Daily rate */
  $handler->display->display_options['fields']['field_daily_rate']['id'] = 'field_daily_rate';
  $handler->display->display_options['fields']['field_daily_rate']['table'] = 'field_data_field_daily_rate';
  $handler->display->display_options['fields']['field_daily_rate']['field'] = 'field_daily_rate';
  $handler->display->display_options['fields']['field_daily_rate']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_daily_rate']['label'] = '';
  $handler->display->display_options['fields']['field_daily_rate']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_daily_rate']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_daily_rate']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Profile: Lingerie daily rate */
  $handler->display->display_options['fields']['field_lingerie_daily_rate']['id'] = 'field_lingerie_daily_rate';
  $handler->display->display_options['fields']['field_lingerie_daily_rate']['table'] = 'field_data_field_lingerie_daily_rate';
  $handler->display->display_options['fields']['field_lingerie_daily_rate']['field'] = 'field_lingerie_daily_rate';
  $handler->display->display_options['fields']['field_lingerie_daily_rate']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_lingerie_daily_rate']['label'] = '';
  $handler->display->display_options['fields']['field_lingerie_daily_rate']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_lingerie_daily_rate']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_lingerie_daily_rate']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Profile: Age category */
  $handler->display->display_options['fields']['field_age_category']['id'] = 'field_age_category';
  $handler->display->display_options['fields']['field_age_category']['table'] = 'field_data_field_age_category';
  $handler->display->display_options['fields']['field_age_category']['field'] = 'field_age_category';
  $handler->display->display_options['fields']['field_age_category']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_age_category']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_age_category']['element_label_colon'] = FALSE;
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  /* Field: User: Full name */
  $handler->display->display_options['fields']['field_full_name']['id'] = 'field_full_name';
  $handler->display->display_options['fields']['field_full_name']['table'] = 'field_data_field_full_name';
  $handler->display->display_options['fields']['field_full_name']['field'] = 'field_full_name';
  $handler->display->display_options['fields']['field_full_name']['label'] = '';
  $handler->display->display_options['fields']['field_full_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_full_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_full_name']['alter']['path'] = 'job/model/[uid]/invite';
  $handler->display->display_options['fields']['field_full_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['path'] = 'mine_search';
  $handler->display->display_options['menu']['title'] = 'Models';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['models'] = array(
    t('Master'),
    t('Castinglist'),
    t('more'),
    t('Search'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Details'),
    t('Yes|Lingerie'),
    t('Yes|Teeth gap'),
    t('Yes|Beautiful feet'),
    t('Yes|Beautiful hands'),
    t('Yes|Freckles'),
    t('Select any filter and click on Apply to see results'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('<div class="models_search_wrapper">
  <input id="models_search_filter" type="button" value="Filter" />
  <div id="loupe"></div>
  <input id="models_search_by_name" type="textfield"  placeholder="Search" />
  <div id="close_filter"></div>
</div>'),
    t('No active models.'),
    t('Private data'),
    t('Basic information'),
    t('Additional information'),
    t('base_city'),
    t('flag'),
    t('Age category'),
    t('Full name'),
    t('Dates'),
    t('Base city'),
    t('Eye color'),
    t('Hair color'),
    t('Daily rate'),
    t('Lingerie daily rate'),
    t('Ethnicity'),
    t('Sports'),
    t('Experience'),
    t('Driving license'),
    t('Instagram followers'),
    t('Height'),
    t('Size'),
    t('Bust'),
    t('Waist'),
    t('Hips'),
    t('Shoe size'),
    t('Page'),
    t('Models'),
    t('Prepare propose.'),
    t('Block'),
    t('[name]'),
    t('Shoes'),
    t('Hair'),
    t('Eyes'),
    t('All'),
    t('Model Job Invite - messuirments'),
    t('Profile'),
  );
  $export['models'] = $view;

  $view = new view();
  $view->name = 'my_jobs';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'My Jobs';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My Jobs';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_job_status',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: From */
  $handler->display->display_options['fields']['field_job_daily_rate_from']['id'] = 'field_job_daily_rate_from';
  $handler->display->display_options['fields']['field_job_daily_rate_from']['table'] = 'field_data_field_job_daily_rate_from';
  $handler->display->display_options['fields']['field_job_daily_rate_from']['field'] = 'field_job_daily_rate_from';
  $handler->display->display_options['fields']['field_job_daily_rate_from']['label'] = '';
  $handler->display->display_options['fields']['field_job_daily_rate_from']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_job_daily_rate_from']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_job_daily_rate_from']['alter']['text'] = 'from [field_job_daily_rate_from-value]';
  $handler->display->display_options['fields']['field_job_daily_rate_from']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_job_daily_rate_from']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: To */
  $handler->display->display_options['fields']['field_job_daily_rate_to']['id'] = 'field_job_daily_rate_to';
  $handler->display->display_options['fields']['field_job_daily_rate_to']['table'] = 'field_data_field_job_daily_rate_to';
  $handler->display->display_options['fields']['field_job_daily_rate_to']['field'] = 'field_job_daily_rate_to';
  $handler->display->display_options['fields']['field_job_daily_rate_to']['label'] = '';
  $handler->display->display_options['fields']['field_job_daily_rate_to']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_job_daily_rate_to']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_job_daily_rate_to']['alter']['text'] = ' to [field_job_daily_rate_to-value]';
  $handler->display->display_options['fields']['field_job_daily_rate_to']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_job_daily_rate_to']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['label'] = '';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = '[title]
[field_job_daily_rate_from]
[field_job_daily_rate_to]';
  $handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_2']['element_wrapper_class'] = 'cd-header';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '150',
  );
  /* Field: Content: Job status */
  $handler->display->display_options['fields']['field_job_status']['id'] = 'field_job_status';
  $handler->display->display_options['fields']['field_job_status']['table'] = 'field_data_field_job_status';
  $handler->display->display_options['fields']['field_job_status']['field'] = 'field_job_status';
  $handler->display->display_options['fields']['field_job_status']['label'] = '';
  $handler->display->display_options['fields']['field_job_status']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_job_status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_job_status']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_job_start_date']['id'] = 'field_job_start_date';
  $handler->display->display_options['fields']['field_job_start_date']['table'] = 'field_data_field_job_start_date';
  $handler->display->display_options['fields']['field_job_start_date']['field'] = 'field_job_start_date';
  $handler->display->display_options['fields']['field_job_start_date']['label'] = '';
  $handler->display->display_options['fields']['field_job_start_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_job_start_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['edit_node']['text'] = 'Edit';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Duplicate Job';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'node/[nid]/clone';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[edit_node]
[nothing]
<a href="/job/[nid]/model-search">Model search</a>';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['element_wrapper_class'] = 'actions';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'job' => 'job',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['my_jobs'] = array(
    t('Master'),
    t('My Jobs'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Nid'),
    t('from [field_job_daily_rate_from-value]'),
    t(' to [field_job_daily_rate_to-value]'),
    t('[title]
[field_job_daily_rate_from]
[field_job_daily_rate_to]'),
    t('Edit'),
    t('Duplicate Job'),
    t('[edit_node]
[nothing]
<a href="/job/[nid]/model-search">Model search</a>'),
    t('All'),
    t('Block'),
  );
  $export['my_jobs'] = $view;

  return $export;
}
