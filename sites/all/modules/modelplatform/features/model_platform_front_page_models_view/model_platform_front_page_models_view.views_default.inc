<?php
/**
 * @file
 * model_platform_front_page_models_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function model_platform_front_page_models_view_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'front_page_models_1';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Front page - models 1';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Front page - models 1';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div class="mb-24h">24H MODELBOOKING</div>
<div class="header-title"><img src="/sites/all/themes/rhythm_front/css/images/Logo_MegaOnline_Black.jpg"/></div>
<a href="user/register" class="sign-up">Join us</a>
';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
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
  $handler->display->display_options['fields']['picture']['image_style'] = '462_267';
  /* Field: User: Front page logo */
  $handler->display->display_options['fields']['field_front_page_logo']['id'] = 'field_front_page_logo';
  $handler->display->display_options['fields']['field_front_page_logo']['table'] = 'field_data_field_front_page_logo';
  $handler->display->display_options['fields']['field_front_page_logo']['field'] = 'field_front_page_logo';
  $handler->display->display_options['fields']['field_front_page_logo']['label'] = '';
  $handler->display->display_options['fields']['field_front_page_logo']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_front_page_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_front_page_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_front_page_logo']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: User: Front page text */
  $handler->display->display_options['fields']['field_front_page_text']['id'] = 'field_front_page_text';
  $handler->display->display_options['fields']['field_front_page_text']['table'] = 'field_data_field_front_page_text';
  $handler->display->display_options['fields']['field_front_page_text']['field'] = 'field_front_page_text';
  $handler->display->display_options['fields']['field_front_page_text']['label'] = '';
  $handler->display->display_options['fields']['field_front_page_text']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_front_page_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_front_page_text']['type'] = 'text_plain';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="front-page-logo-and-text">
 <div class="logo-image">
  [field_front_page_logo]
 </div>
 <div class="logo-text">
  [field_front_page_text]
 </div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: User: Front page image */
  $handler->display->display_options['fields']['field_front_page_image']['id'] = 'field_front_page_image';
  $handler->display->display_options['fields']['field_front_page_image']['table'] = 'field_data_field_front_page_image';
  $handler->display->display_options['fields']['field_front_page_image']['field'] = 'field_front_page_image';
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

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<a href="#footer" class="link-to-bottom">Bottom</a>';
  $handler->display->display_options['footer']['area']['format'] = 'php_code';
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
  /* Field: User: Front page image */
  $handler->display->display_options['fields']['field_front_page_image']['id'] = 'field_front_page_image';
  $handler->display->display_options['fields']['field_front_page_image']['table'] = 'field_data_field_front_page_image';
  $handler->display->display_options['fields']['field_front_page_image']['field'] = 'field_front_page_image';
  $handler->display->display_options['fields']['field_front_page_image']['label'] = '';
  $handler->display->display_options['fields']['field_front_page_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_front_page_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_front_page_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_front_page_image']['settings'] = array(
    'image_style' => '462_267',
    'image_link' => '',
  );
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['picture']['alter']['text'] = '[field_front_page_image]';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = FALSE;
  $handler->display->display_options['fields']['picture']['image_style'] = '462_267';
  /* Field: User: Front page logo */
  $handler->display->display_options['fields']['field_front_page_logo']['id'] = 'field_front_page_logo';
  $handler->display->display_options['fields']['field_front_page_logo']['table'] = 'field_data_field_front_page_logo';
  $handler->display->display_options['fields']['field_front_page_logo']['field'] = 'field_front_page_logo';
  $handler->display->display_options['fields']['field_front_page_logo']['label'] = '';
  $handler->display->display_options['fields']['field_front_page_logo']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_front_page_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_front_page_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_front_page_logo']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: User: Front page text */
  $handler->display->display_options['fields']['field_front_page_text']['id'] = 'field_front_page_text';
  $handler->display->display_options['fields']['field_front_page_text']['table'] = 'field_data_field_front_page_text';
  $handler->display->display_options['fields']['field_front_page_text']['field'] = 'field_front_page_text';
  $handler->display->display_options['fields']['field_front_page_text']['label'] = '';
  $handler->display->display_options['fields']['field_front_page_text']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_front_page_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_front_page_text']['type'] = 'text_plain';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="front-page-logo-and-text">
 <div class="logo-image">
  [field_front_page_logo]
 </div>
 <div class="logo-text">
  [field_front_page_text]
 </div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Place to front page (field_front_page) */
  $handler->display->display_options['filters']['field_front_page_value']['id'] = 'field_front_page_value';
  $handler->display->display_options['filters']['field_front_page_value']['table'] = 'field_data_field_front_page';
  $handler->display->display_options['filters']['field_front_page_value']['field'] = 'field_front_page_value';
  $handler->display->display_options['filters']['field_front_page_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['block_description'] = 'Front page - First block';

  /* Display: Authorized Block */
  $handler = $view->new_display('block', 'Authorized Block', 'block_1');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'flexslider';
  $handler->display->display_options['style_options']['optionset'] = 'models';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<a href="/models">Models search</a>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = FALSE;
  $handler->display->display_options['fields']['picture']['image_style'] = '512_512';
  /* Field: User: Front page logo */
  $handler->display->display_options['fields']['field_front_page_logo']['id'] = 'field_front_page_logo';
  $handler->display->display_options['fields']['field_front_page_logo']['table'] = 'field_data_field_front_page_logo';
  $handler->display->display_options['fields']['field_front_page_logo']['field'] = 'field_front_page_logo';
  $handler->display->display_options['fields']['field_front_page_logo']['label'] = '';
  $handler->display->display_options['fields']['field_front_page_logo']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_front_page_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_front_page_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_front_page_logo']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: User: Front page text */
  $handler->display->display_options['fields']['field_front_page_text']['id'] = 'field_front_page_text';
  $handler->display->display_options['fields']['field_front_page_text']['table'] = 'field_data_field_front_page_text';
  $handler->display->display_options['fields']['field_front_page_text']['field'] = 'field_front_page_text';
  $handler->display->display_options['fields']['field_front_page_text']['label'] = '';
  $handler->display->display_options['fields']['field_front_page_text']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_front_page_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_front_page_text']['type'] = 'text_plain';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[name]';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = 'job/model/[uid]/invite';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Place to front page slider (field_front_page_slider) */
  $handler->display->display_options['filters']['field_front_page_slider_value']['id'] = 'field_front_page_slider_value';
  $handler->display->display_options['filters']['field_front_page_slider_value']['table'] = 'field_data_field_front_page_slider';
  $handler->display->display_options['filters']['field_front_page_slider_value']['field'] = 'field_front_page_slider_value';
  $handler->display->display_options['filters']['field_front_page_slider_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['block_description'] = 'Front page - Second block (Authorized)';

  /* Display: Anonimous block */
  $handler = $view->new_display('block', 'Anonimous block', 'block_2');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    1 => '1',
  );
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'flexslider';
  $handler->display->display_options['style_options']['optionset'] = 'models';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<a href="/user/register">Models search</a>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['path'] = '/user/login';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = FALSE;
  $handler->display->display_options['fields']['picture']['image_style'] = '512_512';
  /* Field: User: Front page logo */
  $handler->display->display_options['fields']['field_front_page_logo']['id'] = 'field_front_page_logo';
  $handler->display->display_options['fields']['field_front_page_logo']['table'] = 'field_data_field_front_page_logo';
  $handler->display->display_options['fields']['field_front_page_logo']['field'] = 'field_front_page_logo';
  $handler->display->display_options['fields']['field_front_page_logo']['label'] = '';
  $handler->display->display_options['fields']['field_front_page_logo']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_front_page_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_front_page_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_front_page_logo']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: User: Front page text */
  $handler->display->display_options['fields']['field_front_page_text']['id'] = 'field_front_page_text';
  $handler->display->display_options['fields']['field_front_page_text']['table'] = 'field_data_field_front_page_text';
  $handler->display->display_options['fields']['field_front_page_text']['field'] = 'field_front_page_text';
  $handler->display->display_options['fields']['field_front_page_text']['label'] = '';
  $handler->display->display_options['fields']['field_front_page_text']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_front_page_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_front_page_text']['type'] = 'text_plain';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[name]';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['path'] = '/user/login';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Place to front page slider (field_front_page_slider) */
  $handler->display->display_options['filters']['field_front_page_slider_value']['id'] = 'field_front_page_slider_value';
  $handler->display->display_options['filters']['field_front_page_slider_value']['table'] = 'field_data_field_front_page_slider';
  $handler->display->display_options['filters']['field_front_page_slider_value']['field'] = 'field_front_page_slider_value';
  $handler->display->display_options['filters']['field_front_page_slider_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['block_description'] = 'Front page - Second block (Anonimous)';
  $translatables['front_page_models_1'] = array(
    t('Master'),
    t('Front page - models 1'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<div class="mb-24h">24H MODELBOOKING</div>
<div class="header-title"><img src="/sites/all/themes/rhythm_front/css/images/Logo_MegaOnline_Black.jpg"/></div>
<a href="user/register" class="sign-up">Join us</a>
'),
    t('<div class="front-page-logo-and-text">
 <div class="logo-image">
  [field_front_page_logo]
 </div>
 <div class="logo-text">
  [field_front_page_text]
 </div>
</div>'),
    t('Front page image'),
    t('Block'),
    t('<a href="#footer" class="link-to-bottom">Bottom</a>'),
    t('[field_front_page_image]'),
    t('Front page - First block'),
    t('Authorized Block'),
    t('<a href="/models">Models search</a>'),
    t('[name]'),
    t('Front page - Second block (Authorized)'),
    t('Anonimous block'),
    t('<a href="/user/register">Models search</a>'),
    t('Front page - Second block (Anonimous)'),
  );
  $export['front_page_models_1'] = $view;

  return $export;
}
