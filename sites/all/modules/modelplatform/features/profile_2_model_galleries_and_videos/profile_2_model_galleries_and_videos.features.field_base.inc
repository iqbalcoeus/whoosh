<?php
/**
 * @file
 * profile_2_model_galleries_and_videos.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function profile_2_model_galleries_and_videos_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_main_image'.
  $field_bases['field_main_image'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_main_image',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'profile2_private' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  // Exported field_base: 'field_videos'.
  $field_bases['field_videos'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_videos',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'video_embed_field',
    'settings' => array(
      'profile2_private' => 0,
    ),
    'translatable' => 0,
    'type' => 'video_embed_field',
  );

  return $field_bases;
}
