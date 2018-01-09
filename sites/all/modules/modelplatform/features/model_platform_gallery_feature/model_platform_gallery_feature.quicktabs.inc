<?php
/**
 * @file
 * model_platform_gallery_feature.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function model_platform_gallery_feature_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'model_gallery';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Model gallery - category';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'model_gallery',
      'display' => 'block_2',
      'args' => '',
      'title' => 'Polaroid',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'model_gallery',
      'display' => 'block_3',
      'args' => '',
      'title' => 'Book picture',
      'weight' => '-99',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Book picture');
  t('Model gallery - category');
  t('Polaroid');

  $export['model_gallery'] = $quicktabs;

  return $export;
}
