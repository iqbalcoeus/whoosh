<?php
/**
 * @file
 * model_platform_quicktabs_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function model_platform_quicktabs_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'castinglist';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Castinglist';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Castinglist';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Flags: casting_mark */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'users';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'casting_mark';
  /* Relationship: Basic informaiton */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['ui_name'] = 'Basic informaiton';
  $handler->display->display_options['relationships']['profile']['label'] = 'Basic informaiton';
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'model_basic_informaiton' => 'model_basic_informaiton',
  );
  /* Relationship: Private Data */
  $handler->display->display_options['relationships']['profile_1']['id'] = 'profile_1';
  $handler->display->display_options['relationships']['profile_1']['table'] = 'users';
  $handler->display->display_options['relationships']['profile_1']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile_1']['ui_name'] = 'Private Data';
  $handler->display->display_options['relationships']['profile_1']['label'] = 'Private Data';
  $handler->display->display_options['relationships']['profile_1']['bundle_types'] = array(
    'model_private_data' => 'model_private_data',
  );
  /* Relationship: Additional informaiton */
  $handler->display->display_options['relationships']['profile_2']['id'] = 'profile_2';
  $handler->display->display_options['relationships']['profile_2']['table'] = 'users';
  $handler->display->display_options['relationships']['profile_2']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile_2']['ui_name'] = 'Additional informaiton';
  $handler->display->display_options['relationships']['profile_2']['label'] = 'Additional informaiton';
  $handler->display->display_options['relationships']['profile_2']['bundle_types'] = array(
    'model_additional_info' => 'model_additional_info',
  );
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['picture']['alter']['path'] = 'job/model/[uid]/invite';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'users';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['label'] = '';
  $handler->display->display_options['fields']['name_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = FALSE;
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['exclude'] = TRUE;
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  /* Field: Flags: Flagged */
  $handler->display->display_options['fields']['flagged']['id'] = 'flagged';
  $handler->display->display_options['fields']['flagged']['table'] = 'flagging';
  $handler->display->display_options['fields']['flagged']['field'] = 'flagged';
  $handler->display->display_options['fields']['flagged']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['flagged']['label'] = '';
  $handler->display->display_options['fields']['flagged']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['flagged']['not'] = 0;
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

  /* Display: Castinglist block */
  $handler = $view->new_display('block', 'Castinglist block', 'block');
  $translatables['castinglist'] = array(
    t('Master'),
    t('Castinglist'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('flag'),
    t('Basic informaiton'),
    t('Private Data'),
    t('Additional informaiton'),
    t('Castinglist block'),
  );
  $export['castinglist'] = $view;

  $view = new view();
  $view->name = 'customer_information';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Customer information';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Private data';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Customer Private Data */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['ui_name'] = 'Customer Private Data';
  $handler->display->display_options['relationships']['profile']['label'] = 'Customer Private Data';
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'customer_private_data' => 'customer_private_data',
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['image_style'] = 'node_gallery_thumbnail';
  /* Field: User: Rating */
  $handler->display->display_options['fields']['field_rating']['id'] = 'field_rating';
  $handler->display->display_options['fields']['field_rating']['table'] = 'field_data_field_rating';
  $handler->display->display_options['fields']['field_rating']['field'] = 'field_rating';
  $handler->display->display_options['fields']['field_rating']['label'] = '';
  $handler->display->display_options['fields']['field_rating']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_rating']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_rating']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_rating']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_rating']['click_sort_column'] = 'rating';
  $handler->display->display_options['fields']['field_rating']['settings'] = array(
    'widget' => array(
      'fivestar_widget' => 'sites/all/modules/fivestar/widgets/oxygen/oxygen.css',
    ),
    'expose' => 0,
    'style' => 'average',
    'text' => 'none',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Models';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'models';
  $handler->display->display_options['fields']['nothing']['alter']['path_case'] = 'upper';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
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

  /* Display: Customer - short info */
  $handler = $view->new_display('block', 'Customer - short info', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Profile';
  $handler->display->display_options['block_description'] = 'Customer information';

  /* Display: Customer - User info */
  $handler = $view->new_display('block', 'Customer - User info', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'User information';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = FALSE;
  $handler->display->display_options['fields']['picture']['image_style'] = 'node_gallery_thumbnail';
  /* Field: User: Rating */
  $handler->display->display_options['fields']['field_rating']['id'] = 'field_rating';
  $handler->display->display_options['fields']['field_rating']['table'] = 'field_data_field_rating';
  $handler->display->display_options['fields']['field_rating']['field'] = 'field_rating';
  $handler->display->display_options['fields']['field_rating']['label'] = '';
  $handler->display->display_options['fields']['field_rating']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_rating']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_rating']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_rating']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_rating']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_rating']['click_sort_column'] = 'rating';
  $handler->display->display_options['fields']['field_rating']['settings'] = array(
    'widget' => array(
      'fivestar_widget' => 'sites/all/modules/fivestar/widgets/oxygen/oxygen.css',
    ),
    'expose' => 0,
    'style' => 'average',
    'text' => 'none',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Models';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'models';
  $handler->display->display_options['fields']['nothing']['alter']['path_case'] = 'upper';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: User: Full name */
  $handler->display->display_options['fields']['field_full_name']['id'] = 'field_full_name';
  $handler->display->display_options['fields']['field_full_name']['table'] = 'field_data_field_full_name';
  $handler->display->display_options['fields']['field_full_name']['field'] = 'field_full_name';
  $handler->display->display_options['fields']['field_full_name']['label'] = '';
  $handler->display->display_options['fields']['field_full_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['block_description'] = 'Customer - User info';

  /* Display: Customer - Private data */
  $handler = $view->new_display('block', 'Customer - Private data', 'block_2');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: Complete Address */
  $handler->display->display_options['fields']['field_complete_address']['id'] = 'field_complete_address';
  $handler->display->display_options['fields']['field_complete_address']['table'] = 'field_data_field_complete_address';
  $handler->display->display_options['fields']['field_complete_address']['field'] = 'field_complete_address';
  $handler->display->display_options['fields']['field_complete_address']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_complete_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_complete_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Profile: Postal code */
  $handler->display->display_options['fields']['field_model_postal_code']['id'] = 'field_model_postal_code';
  $handler->display->display_options['fields']['field_model_postal_code']['table'] = 'field_data_field_model_postal_code';
  $handler->display->display_options['fields']['field_model_postal_code']['field'] = 'field_model_postal_code';
  $handler->display->display_options['fields']['field_model_postal_code']['relationship'] = 'profile';
  /* Field: Profile: Street */
  $handler->display->display_options['fields']['field_model_street']['id'] = 'field_model_street';
  $handler->display->display_options['fields']['field_model_street']['table'] = 'field_data_field_model_street';
  $handler->display->display_options['fields']['field_model_street']['field'] = 'field_model_street';
  $handler->display->display_options['fields']['field_model_street']['relationship'] = 'profile';
  /* Field: Profile: House No */
  $handler->display->display_options['fields']['field_model_house']['id'] = 'field_model_house';
  $handler->display->display_options['fields']['field_model_house']['table'] = 'field_data_field_model_house';
  $handler->display->display_options['fields']['field_model_house']['field'] = 'field_model_house';
  $handler->display->display_options['fields']['field_model_house']['relationship'] = 'profile';
  /* Field: Profile: Apartment No */
  $handler->display->display_options['fields']['field_model_apartment']['id'] = 'field_model_apartment';
  $handler->display->display_options['fields']['field_model_apartment']['table'] = 'field_data_field_model_apartment';
  $handler->display->display_options['fields']['field_model_apartment']['field'] = 'field_model_apartment';
  $handler->display->display_options['fields']['field_model_apartment']['relationship'] = 'profile';
  /* Field: Profile: Tax number */
  $handler->display->display_options['fields']['field_tax_number']['id'] = 'field_tax_number';
  $handler->display->display_options['fields']['field_tax_number']['table'] = 'field_data_field_tax_number';
  $handler->display->display_options['fields']['field_tax_number']['field'] = 'field_tax_number';
  $handler->display->display_options['fields']['field_tax_number']['relationship'] = 'profile';
  /* Field: Profile: VAT ID */
  $handler->display->display_options['fields']['field_vat_id']['id'] = 'field_vat_id';
  $handler->display->display_options['fields']['field_vat_id']['table'] = 'field_data_field_vat_id';
  $handler->display->display_options['fields']['field_vat_id']['field'] = 'field_vat_id';
  $handler->display->display_options['fields']['field_vat_id']['relationship'] = 'profile';
  /* Field: Profile: Commercial registry number */
  $handler->display->display_options['fields']['field_commercial_registry_number']['id'] = 'field_commercial_registry_number';
  $handler->display->display_options['fields']['field_commercial_registry_number']['table'] = 'field_data_field_commercial_registry_number';
  $handler->display->display_options['fields']['field_commercial_registry_number']['field'] = 'field_commercial_registry_number';
  $handler->display->display_options['fields']['field_commercial_registry_number']['relationship'] = 'profile';
  /* Field: Profile: Phone number */
  $handler->display->display_options['fields']['field_phone_number']['id'] = 'field_phone_number';
  $handler->display->display_options['fields']['field_phone_number']['table'] = 'field_data_field_phone_number';
  $handler->display->display_options['fields']['field_phone_number']['field'] = 'field_phone_number';
  $handler->display->display_options['fields']['field_phone_number']['relationship'] = 'profile';
  /* Field: Profile: Website */
  $handler->display->display_options['fields']['field_website']['id'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['table'] = 'field_data_field_website';
  $handler->display->display_options['fields']['field_website']['field'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_website']['click_sort_column'] = 'url';
  /* Field: Profile: Payment method (credit card) */
  $handler->display->display_options['fields']['field_payment_method_credit_card']['id'] = 'field_payment_method_credit_card';
  $handler->display->display_options['fields']['field_payment_method_credit_card']['table'] = 'field_data_field_payment_method_credit_card';
  $handler->display->display_options['fields']['field_payment_method_credit_card']['field'] = 'field_payment_method_credit_card';
  $handler->display->display_options['fields']['field_payment_method_credit_card']['relationship'] = 'profile';
  $handler->display->display_options['block_description'] = 'Customer - Private data';
  $translatables['customer_information'] = array(
    t('Master'),
    t('Private data'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Customer Private Data'),
    t('Models'),
    t('All'),
    t('Customer - short info'),
    t('Profile'),
    t('Customer information'),
    t('Customer - User info'),
    t('User information'),
    t('Customer - Private data'),
    t('Complete Address'),
    t('Postal code'),
    t('Street'),
    t('House No'),
    t('Apartment No'),
    t('Tax number'),
    t('VAT ID'),
    t('Commercial registry number'),
    t('Phone number'),
    t('Website'),
    t('Payment method (credit card)'),
  );
  $export['customer_information'] = $view;

  $view = new view();
  $view->name = 'my_job_templates';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'My job templates';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My job templates';
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
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Create job';
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
';
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
    'job_template' => 'job_template',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['my_job_templates'] = array(
    t('Master'),
    t('My job templates'),
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
    t('Create job'),
    t('[edit_node]
[nothing]
'),
    t('All'),
    t('Block'),
  );
  $export['my_job_templates'] = $view;

  return $export;
}
