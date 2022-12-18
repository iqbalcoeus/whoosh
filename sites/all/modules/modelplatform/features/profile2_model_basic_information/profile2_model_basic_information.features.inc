<?php
/**
 * @file
 * profile2_model_basic_information.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function profile2_model_basic_information_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_profile2_type().
 */
function profile2_model_basic_information_default_profile2_type() {
  $items = array();
  $items['model_basic_informaiton'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "model_basic_informaiton",
    "label" : "Basic informaiton",
    "weight" : "2",
    "data" : { "registration" : 0, "revisions" : 1, "moderation" : 1, "use_page" : 0 },
    "rdf_mapping" : []
  }');
  return $items;
}
