<?php
/**
 * @file
 * profile_2_model_my_jobs.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function profile_2_model_my_jobs_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "panels_mini" && $api == "panels_default") {
    return array("version" => "1");
  }
  if ($module == "quicktabs" && $api == "quicktabs") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function profile_2_model_my_jobs_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_profile2_type().
 */
function profile_2_model_my_jobs_default_profile2_type() {
  $items = array();
  $items['my_jobs'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "my_jobs",
    "label" : "My Jobs",
    "weight" : "10",
    "data" : { "registration" : 0, "revisions" : 0, "moderation" : 0, "use_page" : 0 },
    "rdf_mapping" : []
  }');
  return $items;
}
