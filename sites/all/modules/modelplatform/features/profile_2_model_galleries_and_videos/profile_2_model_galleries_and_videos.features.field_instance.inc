<?php
/**
 * @file
 * profile_2_model_galleries_and_videos.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function profile_2_model_galleries_and_videos_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'profile2-galleries-field_main_image'.
  $field_instances['profile2-galleries-field_main_image'] = array(
    'bundle' => 'galleries',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'profile2',
    'field_name' => 'field_main_image',
    'label' => 'Main image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'profile2-model_videos-field_videos'.
  $field_instances['profile2-model_videos-field_videos'] = array(
    'bundle' => 'model_videos',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'video_embed_field',
        'settings' => array(
          'description' => 1,
          'description_position' => 'bottom',
          'video_style' => 'normal',
        ),
        'type' => 'video_embed_field',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'profile2',
    'field_name' => 'field_videos',
    'label' => 'Videos',
    'required' => 0,
    'settings' => array(
      'allowed_providers' => array(
        'vimeo' => 'vimeo',
        'youtube' => 'youtube',
      ),
      'description_field' => 0,
      'description_length' => 128,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'video_embed_field',
      'settings' => array(),
      'type' => 'video_embed_field_video',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Main image');
  t('Videos');

  return $field_instances;
}
