<?php
/**
 * @file
 * model_platform_quicktabs_views.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function model_platform_quicktabs_views_ctools_plugin_api($module = NULL, $api = NULL) {
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
function model_platform_quicktabs_views_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
