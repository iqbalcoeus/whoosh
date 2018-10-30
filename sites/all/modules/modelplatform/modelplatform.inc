<?php

/**
 * @file
 * Model platform none hook functions.
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
function _modelplatform_update_model_age_category($profile) {
  $latest_revision = profile2_moderation_get_latest_revision($profile);
  $last_profile = profile2_load(NULL, $latest_revision->vid);

  // Stop if has no birthday.
  if (!isset($last_profile->field_birthday[LANGUAGE_NONE][0]['value'])) {
    return;
  }
  $birthday = $last_profile->field_birthday[LANGUAGE_NONE][0]['value'];

  // Calculate years old - age.
  $age = _modelplatform_get_date_diff($birthday, 'y');

  // Load vocabulary and its terms..
  $vocabulary = taxonomy_vocabulary_machine_name_load(MODELPLATFORM_VOCABULARY_AGE_CATEGORY);
  $terms = taxonomy_get_tree($vocabulary->vid);

  // Check each terms.
  foreach ($terms as $term) {
    $term_item = taxonomy_term_load($term->tid);
    $field_min = field_get_items('taxonomy_term', $term_item, 'field_min_age');
    $field_max = field_get_items('taxonomy_term', $term_item, 'field_age_to');
    $min = isset($field_min[0]['value']) ? $field_min[0]['value'] : 100;
    $max = isset($field_max[0]['value']) ? $field_max[0]['value'] : 100;
    if ($min <= $age && $max >= $age) {
      $last_profile->field_age_category[LANGUAGE_NONE][0]['tid'] = $term->tid;
      break;
    }
  }

  // Save profile.
  profile2_save($last_profile);
}

/**
 * Change models age category.
 */
function _modelplatform_get_model_age_category($profile) {
  $latest_revision = profile2_moderation_get_latest_revision($profile);
  $last_profile = profile2_load(NULL, $latest_revision->vid);

  // Stop if has no birthday.
  if (!isset($last_profile->field_birthday[LANGUAGE_NONE][0]['value'])) {
    return NULL;
  }
  $birthday = $last_profile->field_birthday[LANGUAGE_NONE][0]['value'];

  // Calculate years old - age.
  $age = _modelplatform_get_date_diff($birthday, 'y');

  // Load vocabulary and its terms..
  $vocabulary = taxonomy_vocabulary_machine_name_load(MODELPLATFORM_VOCABULARY_AGE_CATEGORY);
  $terms = taxonomy_get_tree($vocabulary->vid);

  // Check each terms.
  foreach ($terms as $term) {
    $term_item = taxonomy_term_load($term->tid);
    $field_min = field_get_items('taxonomy_term', $term_item, 'field_min_age');
    $field_max = field_get_items('taxonomy_term', $term_item, 'field_age_to');
    $min = isset($field_min[0]['value']) ? $field_min[0]['value'] : 100;
    $max = isset($field_max[0]['value']) ? $field_max[0]['value'] : 100;
    if ($min <= $age && $max >= $age) {
      return $term->tid;
    }
  }

  return NULL;
}

/**
 * Job node form submit action to redirect on the model search page.
 *
 * @see modelplatform_form_alter()
 */
function modelplatform_job_node_form_submit($form, &$form_state) {
  $query = array();

  if (isset($form_state['values']['field_job_daily_rate_to'][LANGUAGE_NONE][0]['value'])) {
    $query['field_daily_rate_value_1'] = $form_state['values']['field_job_daily_rate_to'][LANGUAGE_NONE][0]['value'];
  }
  if (isset($form_state['values']['field_job_start_date'][LANGUAGE_NONE][0]['value'])) {
    $date_part = explode(' ', $form_state['values']['field_job_start_date'][LANGUAGE_NONE][0]['value']);
    $query['start_date']['date'] = $date_part[0];
  }
  if (isset($form_state['values']['field_job_start_date'][LANGUAGE_NONE][0]['value2'])) {
    $date_part = explode(' ', $form_state['values']['field_job_start_date'][LANGUAGE_NONE][0]['value2']);
    $query['end_date']['date'] = $date_part[0];
  }

  $form_state['redirect'] = array(
    'models',
    array(
      'query' => $query,
    ),
  );
}

/**
 * Job node form validation..
 *
 * @see modelplatform_form_alter()
 */
function modelplatform_job_node_form_validate($form, &$form_state) {
  $min = $max = 0;
  if (isset($form_state['values']['field_job_daily_rate_from'][LANGUAGE_NONE][0]['value'])) {
    $min = $form_state['values']['field_job_daily_rate_from'][LANGUAGE_NONE][0]['value'];
  }
  if (isset($form_state['values']['field_job_daily_rate_to'][LANGUAGE_NONE][0]['value'])) {
    $max = $form_state['values']['field_job_daily_rate_to'][LANGUAGE_NONE][0]['value'];
  }
  if ($min > $max) {
    form_set_error('field_job_daily_rate_to', t('Daily payment rate to should be more then Daily payment rate from'));
  }
}

/**
 * Clone model job.
 */
function modelplatform_job_clone($node) {
  $job = new stdClass();
  $job->type = 'job';
  $job->created = REQUEST_TIME;
  $job->changed = REQUEST_TIME;
  $job->title = $node->title;
  $job->body = $node->body;
  $job->field_job_daily_rate_from = $node->field_job_daily_rate_from;
  $job->field_job_daily_rate_to = $node->field_job_daily_rate_to;
  $job->field_job_start_date = $node->field_job_start_date;
  $job->field_job_additional_documents = $node->field_job_additional_documents;
  $job->field_job_travel_budget = $node->field_job_travel_budget;

  return $job;
}

/**
 * Save job as template.
 *
 * @see pppmodelplatform_form_alter()
 */
function modelplatform_job_node_form_template($form, &$form_state) {
  $job = $form['#node'];
  $job->type = 'job_template';
  $job->created = REQUEST_TIME;
  $job->changed = REQUEST_TIME;
  $job->nid = $job->vid = NULL;

  $job_template_wrapper = entity_metadata_wrapper('node', $job);
//  $term = taxonomy_term_load(MODELPLATFORM_JOB_STATUS_CREATED);
  $job_template_wrapper->field_job_status = MODELPLATFORM_JOB_STATUS_CREATED;
  $job_template_wrapper->save();

  drupal_set_message(t('Job template was created.'));
}

/**
 * Job node clone action.
 *
 * @see modelplatform_form_alter()
 */
function modelplatform_job_node_form_clone($form, &$form_state) {
  if (isset($form['#node']->nid)) {
    $form_state['redirect'] = array(
      'node/add/job',
      array(
        'query' => array(
          'parent_job' => $form['#node']->nid,
        ),
      ),
    );
  }
}

/**
 * Callback function.
 */
function modelplatform_job_clone_callback($node) {
  if ($node->type === 'job' || $node->type === 'job_template') {
    drupal_goto('node/add/job', array(
      'query' => array(
        'parent_job' => $node->nid,
      ),
    ));
  }
}

/**
 * Create full name.
 */
function modelplatform_create_full_name($account) {
  $old_full_name = $first_name = $last_name = '';

  $old_full_name_field = field_get_items('user', $account, 'field_full_name');
  if (isset($old_full_name_field[0]['value'])) {
    $old_full_name = $old_full_name_field[0]['value'];
  }

  $first_name_field = field_get_items('user', $account, 'field_first_name');
  if (isset($first_name_field[0]['value'])) {
    $first_name = $first_name_field[0]['value'];
  }

  $last_name_field = field_get_items('user', $account, 'field_last_name');
  if (isset($last_name_field[0]['value'])) {
    $last_name = $last_name_field[0]['value'];
  }

  $full_name = $first_name . ' ' . $last_name;
  if ($full_name != $old_full_name) {
    $account->field_full_name[LANGUAGE_NONE][0]['value'] = $full_name;
    user_save($account);
  }
}

/**
 * Additional submit action for views exposed form.
 *
 * @see modelplatform_form_alter()
 */
function modelplatform_views_exposed_form_submit($form, &$form_state) {
  if (in_array($form['#id'], array('views-exposed-form-models-page', 'views-exposed-form-models-page-1')) ) {
    $mine_search = drupal_get_query_parameters();
    if (count($mine_search)) {
      $_SESSION['mine_search'] = $mine_search;
    }
  }
}

/**
 * Creates get_string.
 */
function modelplatform_mine_search_url($mine_search) {
  $get_string = '';

  if (is_array($mine_search)) {
    $get = array();
    foreach ($mine_search as $key => $value) {
      if (is_array($value)) {
        foreach ($value as $_key => $_value) {
          $get[] = $key . '[' . $_key . ']=' . $_value;
        }
      }
      else {
        $get[] = $key . '=' . $value;
      }
    }
    $get_string = implode('&', $get);
  }

  return $get_string;
}

function _modelplatform_user_is_model($user) {
  return isset($user->roles[MODELPLATFORM_ROLE_MODEL]);
}

function _modelplatform_user_is_customer($user) {
  return isset($user->roles[MODELPLATFORM_ROLE_CUSTOMER]);
}

/**
 * Return TRUE if job confirmed.
 */
function _modelplatform_job_is_confirmed($nid) {
  $query = db_select('bat_events', 'be');
  $query->innerJoin('field_data_event_state_reference', 'esr',
    'esr.entity_type = \'bat_event\' AND esr.entity_id = be.event_id');
  $query->innerJoin('bat_event_state', 'bes',
    'bes.id = esr.event_state_reference_state_id AND bes.blocking = 1');

  $query->innerJoin('field_data_field_job', 'fj',
    'fj.entity_id = be.event_id AND fj.entity_type = \'bat_event\'');
  $query->condition('fj.field_job_target_id', $nid);
  $query->addField('be', 'event_id', 'event_id');
  $query->addField('fj', 'field_job_target_id', 'nid');
  $result = $query->execute()->fetchCol(0);

  return count($result) > 0;
}

/**
 *
 */
function modelplatform_complited_jobs_callback($job_info) {
  $job = node_load($job_info->job_nid);
  if(!empty($job)) {
    $job_wrapper = entity_metadata_wrapper('node', $job);
    
    $job_wrapper->field_job_status->set(98);
    $job_wrapper->save();
    module_invoke_all('modelplatform_job_complete', $job_info->job_nid, $job_info->event_id);
  }
}

function _modelplatform_job_creation_access($customer) {
  $mandatory_fields = array(
    'field_tax_number',
    'field_vat_id',
    'field_commercial_registry_number',
  );
  $profile = profile2_load_by_user($customer->uid);
  $access = isset($profile['customer_private_data']);
  if ($access) {
    $profile_wrapper = entity_metadata_wrapper('profile2', $profile['customer_private_data']);
    foreach ($mandatory_fields as $field_name) {
      $access = $access && $profile_wrapper->{$field_name}->value();
    }
  }

  return $access;
}