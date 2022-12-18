<?php

/**
 * @file
 * Model Platform Booking - views plugin.
 */

/**
 * @defgroup views_mp_booking_module mp_booking.module handlers
 *
 * Includes the ability to create views of the bat_units table.
 * @{
 */

/**
 * Implements hook_views_data_alter().
 */
function mp_booking_views_data_alter(&$data) {
  $data['users']['model_status'] = array(
    'title' => t('Model Availability'),
    'help' => t('Model Availability'),
    'filter' => array(
      'handler' => 'mp_booking_handler_filter_available',
    ),
  );
}
