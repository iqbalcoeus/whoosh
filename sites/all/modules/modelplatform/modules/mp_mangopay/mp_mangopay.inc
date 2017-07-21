<?php

/**
 * @file
 * Model Platform - MangoPay helper functions.
 */

function _mp_mangopay_test() {
  $api = _mp_mangopay_api();

  // get some user by id
  try {
    dsm($api);
    $john = $api->Users->Get(29635616);
    dsm($john);
  } catch(MangoPay\Libraries\ResponseException $e) {

  } catch(MangoPay\Libraries\Exception $e) {

  }
}

// DB functions.

/**
 * Include db mp_mangopay_users.
 */
function _mp_mangopay_include_db_mp_mangopay_users() {
  require_once 'includes/db/mp_mangopay.mp_magopay_users.inc';
}

/**
 * Include db mp_mangopay_cards.
 */
function _mp_mangopay_include_db_mp_mangopay_cards() {
  require_once 'includes/db/mp_mangopay.mp_magopay_cards.inc';
}

function _mp_mangopay_get_user_by_uid($uid) {
  _mp_mangopay_include_db_mp_mangopay_users();
  $mangopay_user_id = _mp_mangopay_db_mp_mangopay_users_get_field_value($uid, 'mangopay_user_id', 'uid');

  return $mangopay_user_id;
}