<?php
/**
 * @file
 * model_platform_bat_unit.features.inc
 */

/**
 * Implements hook_default_bat_type_bundle().
 */
function model_platform_bat_unit_default_bat_type_bundle() {
  $items = array();
  $items['model'] = entity_import('bat_type_bundle', '{
    "type" : "model",
    "label" : "Model",
    "weight" : "0",
    "data" : { "revision" : 0 },
    "default_event_value_field_ids" : null,
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_bat_unit_bundle().
 */
function model_platform_bat_unit_default_bat_unit_bundle() {
  $items = array();
  $items['default'] = entity_import('bat_unit_bundle', '{
    "type" : "default",
    "label" : "Default",
    "weight" : "0",
    "data" : "",
    "rdf_mapping" : []
  }');
  return $items;
}
