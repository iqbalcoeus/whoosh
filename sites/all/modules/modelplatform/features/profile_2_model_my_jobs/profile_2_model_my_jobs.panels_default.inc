<?php
/**
 * @file
 * profile_2_model_my_jobs.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function profile_2_model_my_jobs_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'model_job_offers';
  $mini->category = 'Model';
  $mini->admin_title = 'Model - job offers';
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
  $display->uuid = '0c933a1d-5b3a-46a6-a818-498e51b73d03';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'model_job_offers';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-523bd6b9-be1d-4959-9e34-775affa842aa';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'views-model_job_proposes-block';
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
  $pane->uuid = '523bd6b9-be1d-4959-9e34-775affa842aa';
  $display->content['new-523bd6b9-be1d-4959-9e34-775affa842aa'] = $pane;
  $display->panels['middle'][0] = 'new-523bd6b9-be1d-4959-9e34-775affa842aa';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-523bd6b9-be1d-4959-9e34-775affa842aa';
  $mini->display = $display;
  $export['model_job_offers'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'model_past_jobs';
  $mini->category = 'Model';
  $mini->admin_title = 'Model - past jobs';
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
  $display->uuid = '37c56369-4e55-4833-86bc-eda86a7a9bbc';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'model_past_jobs';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-8b7ca411-313a-4d03-acdd-2d48606e2a8b';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'views-model_job_proposes-block_1';
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
  $pane->uuid = '8b7ca411-313a-4d03-acdd-2d48606e2a8b';
  $display->content['new-8b7ca411-313a-4d03-acdd-2d48606e2a8b'] = $pane;
  $display->panels['middle'][0] = 'new-8b7ca411-313a-4d03-acdd-2d48606e2a8b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['model_past_jobs'] = $mini;

  return $export;
}
