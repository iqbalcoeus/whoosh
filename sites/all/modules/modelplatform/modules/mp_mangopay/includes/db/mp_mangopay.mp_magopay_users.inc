<?php

/**
 * @file
 * Model Platform - Mangopay db functions for mp_mangopay_users.
 */

/**
 * Insert mangopay user short data to db.
 *
 * @param $uid
 * @param $mangopay_user_id
 *
 * @return \DatabaseStatementInterface|int
 */
function _mp_mangopay_db_mp_mangopay_users_insert($uid, $mangopay_user_id) {
  $result = db_insert('mp_mangopay_users')
    ->fields(array(
      'mangopay_user_id' => $mangopay_user_id,
      'uid' => $uid,
      'last_card_num' => 0,
    ))
    ->execute();

  return $result;
}

/**
 * Update fields for user by uid.
 *
 * @param $uid
 * @param $fields_data
 *
 * @return \DatabaseStatementInterface
 */
function _mp_mangopay_db_mp_mangopay_users_update($uid, $fields_data) {
  $result = db_update('mp_mangopay_users')
    ->fields($fields_data)
    ->condition('uid', $uid)
    ->execute();

  return $result;
}

/**
 * @param $field_key_value
 * @param $field_name
 * @param string $field_key_name
 *
 * @return mixed
 */
function _mp_mangopay_db_mp_mangopay_users_get_field_value($field_key_value, $field_name, $field_key_name = 'uid') {
  $value = _mp_mangopay_db_get_field_value('mp_mangopay_users', $field_key_name, $field_key_value, $field_name);

  return isset($value->{$field_name}) ? $value->{$field_name} : FALSE;
}

/**
 * @param $field_key_value
 * @param string $field_key_name
 *
 * @return mixed
 */
function _mp_mangopay_db_mp_mangopay_users_get_row_values($field_key_value, $field_key_name = 'uid') {
  $value = _mp_mangopay_db_get_field_value('mp_mangopay_users', $field_key_name, $field_key_value);

  return isset($value->uid) ? $value : FALSE;
}