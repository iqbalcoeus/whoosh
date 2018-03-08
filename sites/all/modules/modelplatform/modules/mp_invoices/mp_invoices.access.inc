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
  $access = $access && ($order->uid == $user->uid || $user->roles[3] || $user->roles[5]);

  return $access;
}