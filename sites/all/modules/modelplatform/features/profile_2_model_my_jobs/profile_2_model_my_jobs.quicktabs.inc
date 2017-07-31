<?php
/**
 * @file
 * profile_2_model_my_jobs.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function profile_2_model_my_jobs_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'model_my_jobs';
  $quicktabs->ajax = 1;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'My Jobs';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'model_job_proposes',
      'display' => 'block',
      'args' => '',
      'title' => 'Job offers',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'model_job_proposes',
      'display' => 'block_1',
      'args' => '',
      'title' => 'Past jobs',
      'weight' => '-99',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Job offers');
  t('My Jobs');
  t('Past jobs');

  $export['model_my_jobs'] = $quicktabs;

  return $export;
}
