<?php
/**
 * @file
 * profile2_model_private_data.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function profile2_model_private_data_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_profile2_type().
 */
function profile2_model_private_data_default_profile2_type() {
  $items = array();
  $items['model_private_data'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "model_private_data",
    "label" : "Model Private Data",
    "weight" : "0",
    "data" : { "registration" : 0, "use_page" : 0 },
    "rdf_mapping" : []
  }');
  return $items;
}
