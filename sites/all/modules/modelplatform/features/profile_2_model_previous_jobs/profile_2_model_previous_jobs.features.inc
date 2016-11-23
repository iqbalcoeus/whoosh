<?php
/**
 * @file
 * profile_2_model_previous_jobs.features.inc
 */

/**
 * Implements hook_default_profile2_type().
 */
function profile_2_model_previous_jobs_default_profile2_type() {
  $items = array();
  $items['previous_model_jobs'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "previous_model_jobs",
    "label" : "Previous model jobs",
    "weight" : "6",
    "data" : { "registration" : 0, "revisions" : 1, "moderation" : 1, "use_page" : 0 },
    "rdf_mapping" : []
  }');
  return $items;
}
