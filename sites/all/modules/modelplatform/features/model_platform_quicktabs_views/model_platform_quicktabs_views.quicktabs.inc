<?php
/**
 * @file
 * model_platform_quicktabs_views.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function model_platform_quicktabs_views_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'customer_dashboard';
  $quicktabs->ajax = 1;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Customer Dashboard';
  $quicktabs->tabs = array(
    0 => array(
      'bid' => 'panels_mini_delta_customer_dashboard_overview',
      'hide_title' => 1,
      'title' => 'Overview',
      'weight' => '-100',
      'type' => 'block',
    ),
    1 => array(
      'bid' => 'panels_mini_delta_customer_dashboard_profile',
      'hide_title' => 1,
      'title' => 'Profile',
      'weight' => '-99',
      'type' => 'block',
    ),
    2 => array(
      'bid' => 'panels_mini_delta_customer_dashboard_job_templates',
      'hide_title' => 1,
      'title' => 'Job templates',
      'weight' => '-98',
      'type' => 'block',
    ),
    3 => array(
      'bid' => 'panels_mini_delta_customer_dashboard_my_jobs',
      'hide_title' => 1,
      'title' => 'My jobs',
      'weight' => '-97',
      'type' => 'block',
    ),
    4 => array(
      'bid' => 'panels_mini_delta_customer_dashboard_my_castings',
      'hide_title' => 1,
      'title' => 'My castings',
      'weight' => '-96',
      'type' => 'block',
    ),
    5 => array(
      'bid' => 'panels_mini_delta_customer_dashboard_payments',
      'hide_title' => 1,
      'title' => 'Payments',
      'weight' => '-95',
      'type' => 'block',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'default';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Customer Dashboard');
  t('Job templates');
  t('My castings');
  t('My jobs');
  t('Overview');
  t('Payments');
  t('Profile');

  $export['customer_dashboard'] = $quicktabs;

  return $export;
}
