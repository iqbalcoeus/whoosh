<?php
/**
 * @file
 * profile2_model_additional_information.features.inc
 */

/**
 * Implements hook_default_profile2_type().
 */
function profile2_model_additional_information_default_profile2_type() {
  $items = array();
  $items['model_additional_info'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "model_additional_info",
    "label" : "Additional informaiton",
    "weight" : "4",
    "data" : { "registration" : 0, "revisions" : 1, "moderation" : 1, "use_page" : 0 },
    "rdf_mapping" : []
  }');
  return $items;
}
