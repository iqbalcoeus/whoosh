<?php

/**
 * @file
 * Model Platform - Invoices access functions.
 */

/**
 * Access function.
 */
function mp_invoices_access_own_invoices($account, $order) {
  global $user;

  $access = TRUE;
  $access = $access && user_access('view own model platform invoices');
  $access = $access && ($account->uid == $user->uid || $user->roles[3]);
  $access = $access && ($order->uid == $account->uid || $user->roles[3]);

  return $access;
}