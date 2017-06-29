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