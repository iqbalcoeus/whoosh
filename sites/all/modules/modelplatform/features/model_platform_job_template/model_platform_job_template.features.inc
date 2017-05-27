<?php
/**
 * @file
 * model_platform_job_template.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function model_platform_job_template_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function model_platform_job_template_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function model_platform_job_template_node_info() {
  $items = array(
    'job' => array(
      'name' => t('Job'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Job title'),
      'help' => '',
    ),
    'job_template' => array(
      'name' => t('Job template'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Job title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
