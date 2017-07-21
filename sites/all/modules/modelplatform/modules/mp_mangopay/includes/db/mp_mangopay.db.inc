<?php

/**
 * @file
 * Model Platform - MangoPay DB helper functions.
 */

/**
 * Get field values.
 */
function _mp_mangopay_db_get_values($table_name, $field_key_name, $field_key_value, $field_name = '') {
  $query = db_select($table_name, 'ta');
  $query->condition($field_key_name, $field_key_value);
  if ($field_name) {
    $query->fields('ta', array($field_key_name, $field_name));
  }
  else {
    $query->fields('ta');
  }
  $data = $query->execute()->fetch();

  return $data;
}