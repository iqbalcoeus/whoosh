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
function _mp_rating_remove_row($uid, $event_id) {
  db_delete('mp_rating')
    ->condition('uid', $uid)
    ->condition('event_id', $event_id)
    ->execute();
}

/**
 * Get user rate events.
 */
function _mp_rating_get_user_rate_events($uid) {
  $event_data = db_select('mp_rating', 'mpr')
    ->condition('mpr.uid', $uid)
    ->fields('mpr', array('event_id', 'job_nid'))
    ->execute()
    ->fetchAll();

  return $event_data;
}

/**
 * Block callback;
 */
function _mp_rating_job_rate_block() {
  global $user;

  $event_data = _mp_rating_get_user_rate_events($user->uid);

  $content = array();
  foreach($event_data as $event_info) {
    $display_id = 'block';
    $views_arg = $event_info->event_id;
    if (_modelplatform_user_is_customer($user)) {
      $display_id = 'block_1';
      $views_arg = $event_info->job_nid;
    }

    $content[] = '<div class="rating-row">'
      . views_embed_view('rate_job_event', $display_id, $views_arg)
      . '</div>';
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

  db_delete('mp_rating', 'mpr')
    ->condition('event_id', $event_id)
    ->execute();
}