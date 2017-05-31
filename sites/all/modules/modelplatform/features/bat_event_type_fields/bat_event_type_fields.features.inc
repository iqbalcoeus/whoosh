<?php
/**
 * @file
 * bat_event_type_fields.features.inc
 */

/**
 * Implements hook_default_bat_event_type().
 */
function bat_event_type_fields_default_bat_event_type() {
  $items = array();
  $items['model_availability'] = entity_import('bat_event_type', '{
    "type" : "model_availability",
    "label" : "Model Availability",
    "event_granularity" : "bat_hourly",
    "fixed_event_states" : "1",
    "weight" : "0",
    "default_event_value_field_ids" : null,
    "default_event_label_field_name" : "",
    "data" : "",
    "target_entity_type" : "bat_unit",
    "rdf_mapping" : [],
    "event_states" : [
      {
        "machine_name" : "available",
        "label" : "Available",
        "color" : "#54c13d",
        "calendar_label" : "Available",
        "locked" : "0",
        "blocking" : "0",
        "default_state" : "0"
      },
      {
        "machine_name" : "busy",
        "label" : "Busy",
        "color" : "#7f7f7f",
        "calendar_label" : "Busy",
        "locked" : "0",
        "blocking" : "1",
        "default_state" : "0"
      },
      {
        "machine_name" : "job_contract",
        "label" : "Job Contract",
        "color" : "#b95555",
        "calendar_label" : "Job contract",
        "locked" : "0",
        "blocking" : "1",
        "default_state" : "0"
      },
      {
        "machine_name" : "job_was_proposed",
        "label" : "Job was proposed",
        "color" : "#aeeaba",
        "calendar_label" : "Job was proposed",
        "locked" : "0",
        "blocking" : "0",
        "default_state" : "0"
      },
      {
        "machine_name" : "auction",
        "label" : "Auction",
        "color" : "#dcd9f1",
        "calendar_label" : "Auction",
        "locked" : "0",
        "blocking" : "0",
        "default_state" : "0"
      }
    ]
  }');
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function bat_event_type_fields_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}
