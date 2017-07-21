<?php

/**
 * @file
 * Model Platform - MangoPay DB helper functions.
 */

/**
 * Get field values.
 */
function _mp_mangopay_db_get_field_value($table_name, $field_key_name, $field_key_value, $field_name) {
  $mp_mangopay_users = db_select($table_name, 'table_alias')
    ->condition('table_alias.' . $field_key_name, $field_key_value)
    ->fields('table_alias', array($field_key_name, $field_name))
    ->execute()->fetch();

  return $mp_mangopay_users;
}