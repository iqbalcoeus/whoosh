<?php
/**
 * @file
 * profile_2_model_galleries_and_videos.features.inc
 */

/**
 * Implements hook_default_profile2_type().
 */
function profile_2_model_galleries_and_videos_default_profile2_type() {
  $items = array();
  $items['galleries'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "galleries",
    "label" : "Image section",
    "weight" : "8",
    "data" : { "registration" : 0, "revisions" : 1, "moderation" : 1, "use_page" : 0 },
    "rdf_mapping" : []
  }');
  $items['model_videos'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "model_videos",
    "label" : "Video section",
    "weight" : "10",
    "data" : { "registration" : 0, "revisions" : 1, "moderation" : 1, "use_page" : 0 },
    "rdf_mapping" : []
  }');

  t('Image section');
  t('Video section');

  return $items;
}
