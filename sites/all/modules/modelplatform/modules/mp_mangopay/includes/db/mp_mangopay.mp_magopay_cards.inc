<?php

/**
 * @file
 * Model Platform - Mangopay db functions for mp_mangopay_users.
 */

/**
 * @param $uid
 * @param $mangopay_user_id
 * @param $card_id
 * @param $card_number
 *
 * @return \DatabaseStatementInterface|int
 */
function _mp_mangopay_db_mp_mangopay_cards_insert($uid, $mangopay_user_id, $card_id, $card_number) {
  $result = db_insert('mp_mangopay_cards')
    ->fields(array(
      'uid' => $uid,
      'mangopay_user_id' => $mangopay_user_id,
      'card_id' => $card_id,
      'card_number' => $card_number,
    ))
    ->execute();

  return $result;
}

/**
 * @param $mangopay_user_id
 * @param $fields_data
 *
 * @return \DatabaseStatementInterface
 */
function _mp_mangopay_db_mp_mangopay_cards_update($card_id, $fields_data) {
  $result = db_update('mp_mangopay_cards')
    ->fields($fields_data)
    ->condition('card_id', $card_id)
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
function _mp_mangopay_db_mp_mangopay_cards_get_field_value($field_key_value, $field_name, $field_key_name = 'card_id') {
  $value = _mp_mangopay_db_get_values('mp_mangopay_cards', $field_key_name, $field_key_value, $field_name);

  return isset($value->{$field_name}) ? $value->{$field_name} : FALSE;
}

/**
 * @param $field_key_value
 * @param string $field_key_name
 *
 * @return mixed
 */
function _mp_mangopay_db_mp_mangopay_cards_get_row_values($field_key_value, $field_key_name = 'card_id') {
  $value = _mp_mangopay_db_get_values('mp_mangopay_cards', $field_key_name, $field_key_value);

  return isset($value->mangopay_user_id) ? $value : FALSE;
}