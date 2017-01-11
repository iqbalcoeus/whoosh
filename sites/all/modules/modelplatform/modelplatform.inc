<?php
/**
 * Created by PhpStorm.
 * User: cimpleo
 * Date: 21.11.16
 * Time: 17:03
 */

/**
 * Get date diff.
 */
function _modelplatform_get_date_diff($date_string, $diff_name) {
  $datetime1 = date_create($date_string);
  $datetime2 = date_create('now');
  $interval = date_diff($datetime1, $datetime2);

  return $interval->{$diff_name};
}

/**
 * Change models age category.
 */
function _modelplatform_update_model_age_category($account) {
  // Stop if account has no model role.
  if (!in_array(MODELPLATFORM_MODEL_ROLE_NAME, $account->roles)) {
    return;
  }
  // Profile type name.
  $profile_type_name = 'model_basic_informaiton';
  // Get profile by type name.
  $profile = profile2_load_by_user($account, $profile_type_name);
  // Stop if has no birthday.
  if (!isset($profile->field_birthday[LANGUAGE_NONE][0]['value'])) {
    return;
  }
  $birthday = $profile->field_birthday[LANGUAGE_NONE][0]['value'];
  // Calculate years old - age.
  $age = _modelplatform_get_date_diff($birthday, 'y');
  // Load vocabulary and its terms..
  $vocabulary = taxonomy_vocabulary_machine_name_load(MODELPLATFORM_VOCABULARY_AGE_CATEGORY);
  $terms = taxonomy_get_tree($vocabulary->vid);
  // Check each terms.
  foreach ($terms as $term) {
    $term_item = taxonomy_term_load($term->tid);
    $field_min = field_get_items('taxonomy_term', $term_item, 'field_min_age');
    $field_max = field_get_items('taxonomy_term', $term_item, 'field_max_age');
    $min = isset($field_min[0]['value']) ? $field_min[0]['value'] : 100;
    $max = isset($field_max[0]['value']) ? $field_max[0]['value'] : 100;
    if ($min <= $age && $max >= $age) {
      $profile->age_category[LANGUAGE_NONE][0]['tid'] = $term->tid;
      break;
    }
  }
  // Save profile.
  profile2_save($profile);
}

/**
 * Job node form submit action to redirect on the model search page.
 */
function modelplatform_job_node_form_submit($form, &$form_state) {
  $query = array();
  if (isset($form_state['values']['field_job_daily_rate_from'][LANGUAGE_NONE][0]['value'])) {
    $query['daily_rate[min]'] = $form_state['values']['field_job_daily_rate_from'][LANGUAGE_NONE][0]['value'];
  }
  if (isset($form_state['values']['field_job_daily_rate_to'][LANGUAGE_NONE][0]['value'])) {
    $query['daily_rate[max]'] = $form_state['values']['field_job_daily_rate_to'][LANGUAGE_NONE][0]['value'];
  }
  $form_state['redirect'] = array(
    'models',
    array(
      'query' => $query,
    ),
  );
}