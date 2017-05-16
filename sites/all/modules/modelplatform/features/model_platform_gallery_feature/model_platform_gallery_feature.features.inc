<?php
/**
 * @file
 * model_platform_gallery_feature.features.inc
 */

/**
 * Implements hook_views_api().
 */
function model_platform_gallery_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_mp_auction_type().
 */
function model_platform_gallery_feature_default_mp_auction_type() {
  $items = array();
  $items['auction'] = entity_import('mp_auction_type', '{
    "type" : "auction",
    "label" : "Auction",
    "weight" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_node_info().
 */
function model_platform_gallery_feature_node_info() {
  $items = array(
    'node_gallery_item' => array(
      'name' => t('Gallery Item'),
      'base' => 'node_content',
      'description' => t('A gallery node item.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
