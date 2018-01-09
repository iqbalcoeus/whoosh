<?php
/**
 * @file
 * model_platform_gallery_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function model_platform_gallery_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "quicktabs" && $api == "quicktabs") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function model_platform_gallery_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function model_platform_gallery_feature_image_default_styles() {
  $styles = array();

  // Exported image style: 150x225_gallery.
  $styles['150x225_gallery'] = array(
    'label' => '150x225 gallery',
    'effects' => array(
      17 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 150,
          'height' => 255,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 485x728_model_main_photo.
  $styles['485x728_model_main_photo'] = array(
    'label' => '485x728 model main photo',
    'effects' => array(
      18 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 485,
          'height' => 728,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 556x913_colorbox_open.
  $styles['556x913_colorbox_open'] = array(
    'label' => '556x913 colorbox open',
    'effects' => array(
      19 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 556,
          'height' => 913,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
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
