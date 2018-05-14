<?php

/**
 * @file
 */

/**
 * Fill mp_rating row.
 */
function _mp_rating_fill_row($row) {
  db_insert('mp_rating')
    ->fields($row)
    ->execute();
}

/**
 * Remove mp_rating row.
 */
function _mp_rating_remove_row($uid, $event_id, $job_nid = NULL) {

  $query = db_delete('mp_rating')->condition('uid', $uid);
  if ($job_nid) {
    $query->condition('job_nid', $job_nid);
  }
  else {
    $query->condition('event_id', $event_id);
  }
  $query->execute();
}

/**
 * Get user rate events.
 */
function _mp_rating_get_user_rate_events($uid) {
  $event_data = db_select('mp_rating', 'mpr')
    ->distinct()
    ->condition('mpr.uid', $uid)
    ->fields('mpr', array('event_id', 'job_nid'))
    ->execute()
    ->fetchAll();

  return $event_data;
}

/**
 *
 */
function _mp_rating_is_event_ready($event_id, $field_rate_name) {
  $result = TRUE;
  if ($event_id) {
    $event = bat_event_load($event_id);
    if ($event) {
      $event_wrapper = entity_metadata_wrapper('bat_event', $event);
      $job = $event_wrapper->field_job->value();
      $unit = $event_wrapper->event_bat_unit_reference->value();
      $result = $result && isset($job->uid) && $job->uid;
      $result = $result && isset($unit->uid) && $unit->uid && ($model = user_load($unit->uid)) && isset($model->roles[5]);
      $result = $result && !$event_wrapper->{$field_rate_name}->value();
    }
  }
  else {
    $result = FALSE;
  }

  return $result;
}

/**
 * Block callback;
 */
function _mp_rating_job_rate_block() {
  global $user;

  $event_data = _mp_rating_get_user_rate_events($user->uid);

  $content = array();
  foreach($event_data as $event_info) {
    $views_arg = $event_info->event_id;
    if (_modelplatform_user_is_customer($user)) {
      $display_id = 'block_1';
      $field_rate_name = 'field_customer_rate';
    }
    else {
      $display_id = 'block';
      $field_rate_name = 'field_model_rate';
    }

    if (_mp_rating_is_event_ready($event_info->event_id, $field_rate_name)) {
      $content[] = '<div class="rating-row">'
        . views_embed_view('rate_job_event', $display_id, $views_arg)
        . '</div>';
    }
  }

  if (count($content)) {
    $result = array(
      'subject' => t('Please rate your last job.'),
      'content' => implode('', $content)
    );
    drupal_add_js(drupal_get_path('module', 'mp_rating') . '/js/mp_rating.js');
  }
  else {
    $result = array();
  }

  return $result;
}

function _mp_rating_complited_jobs_rating_ends_callback($job_info) {
  $event_id = $job_info->event_id;

  db_delete('mp_rating')
    ->condition('event_id', $event_id)
    ->execute();
}