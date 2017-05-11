<?php
/**
 * @file
 * model_platform_quicktabs_views.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function model_platform_quicktabs_views_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'customer_dashboard_job_templates';
  $mini->category = 'Customer Dasboard';
  $mini->admin_title = 'Customer Dashboard - Job Templates';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '9c096e3e-373e-402d-921a-bd18fa05a7df';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'customer_dashboard_job_templates';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-7228f9a0-de5c-4171-bb26-db2c3aa214a8';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'views-my_job_templates-block';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '7228f9a0-de5c-4171-bb26-db2c3aa214a8';
  $display->content['new-7228f9a0-de5c-4171-bb26-db2c3aa214a8'] = $pane;
  $display->panels['middle'][0] = 'new-7228f9a0-de5c-4171-bb26-db2c3aa214a8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['customer_dashboard_job_templates'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'customer_dashboard_my_castings';
  $mini->category = 'Customer Dasboard';
  $mini->admin_title = 'Customer Dashboard - My Castings';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '9b35125e-76e2-4b41-84ec-d93dac87471e';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'customer_dashboard_my_castings';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-20b50f9b-4787-409e-8926-09b1da563fde';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'views-castinglist-block';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '20b50f9b-4787-409e-8926-09b1da563fde';
  $display->content['new-20b50f9b-4787-409e-8926-09b1da563fde'] = $pane;
  $display->panels['middle'][0] = 'new-20b50f9b-4787-409e-8926-09b1da563fde';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['customer_dashboard_my_castings'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'customer_dashboard_my_jobs';
  $mini->category = 'Customer Dasboard';
  $mini->admin_title = 'Customer Dashboard - My Jobs';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'f3b7fc0d-8b36-48af-bd7a-41ae31436192';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'customer_dashboard_my_jobs';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-a208ac58-bd47-4cb1-a71f-3f4d8fc96af7';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'views-my_jobs-block';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'a208ac58-bd47-4cb1-a71f-3f4d8fc96af7';
  $display->content['new-a208ac58-bd47-4cb1-a71f-3f4d8fc96af7'] = $pane;
  $display->panels['middle'][0] = 'new-a208ac58-bd47-4cb1-a71f-3f4d8fc96af7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-a208ac58-bd47-4cb1-a71f-3f4d8fc96af7';
  $mini->display = $display;
  $export['customer_dashboard_my_jobs'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'customer_dashboard_overview';
  $mini->category = 'Customer Dasboard';
  $mini->admin_title = 'Customer Dashboard - Overview';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '55590c2e-d2f1-4226-acc0-570972a7984d';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'customer_dashboard_overview';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-b8f2aaa7-3d90-4531-9573-c66b08c06d2e';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'views-customer_information-block';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'b8f2aaa7-3d90-4531-9573-c66b08c06d2e';
  $display->content['new-b8f2aaa7-3d90-4531-9573-c66b08c06d2e'] = $pane;
  $display->panels['middle'][0] = 'new-b8f2aaa7-3d90-4531-9573-c66b08c06d2e';
  $pane = new stdClass();
  $pane->pid = 'new-06cf6760-ec1e-484d-8524-6442d1c60b78';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'menu-menu-customer-menu';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '06cf6760-ec1e-484d-8524-6442d1c60b78';
  $display->content['new-06cf6760-ec1e-484d-8524-6442d1c60b78'] = $pane;
  $display->panels['middle'][1] = 'new-06cf6760-ec1e-484d-8524-6442d1c60b78';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-b8f2aaa7-3d90-4531-9573-c66b08c06d2e';
  $mini->display = $display;
  $export['customer_dashboard_overview'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'customer_dashboard_payments';
  $mini->category = 'Customer Dasboard';
  $mini->admin_title = 'Customer Dashboard - Payments';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '3c324dbf-114a-485b-957c-3463becedb2a';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'customer_dashboard_payments';
  $display->content = array();
  $display->panels = array();
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['customer_dashboard_payments'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'customer_dashboard_profile';
  $mini->category = 'Customer Dasboard';
  $mini->admin_title = 'Customer Dashboard - Profile';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '14fbf2b4-cfff-4eca-9a12-4885bb889062';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'customer_dashboard_profile';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-926bc202-da04-4647-ac27-d190a65b6d83';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'views-customer_information-block_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '926bc202-da04-4647-ac27-d190a65b6d83';
  $display->content['new-926bc202-da04-4647-ac27-d190a65b6d83'] = $pane;
  $display->panels['middle'][0] = 'new-926bc202-da04-4647-ac27-d190a65b6d83';
  $pane = new stdClass();
  $pane->pid = 'new-9fa794b6-d9da-4450-8b7e-241afce5feed';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'menu-menu-customer-profile-menu';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '9fa794b6-d9da-4450-8b7e-241afce5feed';
  $display->content['new-9fa794b6-d9da-4450-8b7e-241afce5feed'] = $pane;
  $display->panels['middle'][1] = 'new-9fa794b6-d9da-4450-8b7e-241afce5feed';
  $pane = new stdClass();
  $pane->pid = 'new-41d291cc-da56-44c4-8dc1-9f6aaeedfb9c';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'views-customer_information-block_2';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '41d291cc-da56-44c4-8dc1-9f6aaeedfb9c';
  $display->content['new-41d291cc-da56-44c4-8dc1-9f6aaeedfb9c'] = $pane;
  $display->panels['middle'][2] = 'new-41d291cc-da56-44c4-8dc1-9f6aaeedfb9c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['customer_dashboard_profile'] = $mini;

  return $export;
}
