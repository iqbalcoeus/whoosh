<?php

/**
 * @file
 * Model Platform - Block part.
 */

/**
 * Calendar form.
 */
function _mp_booking_calendar_form_block_content() {
  global $user;

  $content = '';
  drupal_add_library('system', 'ui.tooltip');

  if ($account = _mp_booking_get_calendar_account()) {

    // Generate booking form.
    if (_mp_booking_get_calendar_busy_access()) {
      $args = arg();
      if (isset($args[1]) && $args[0] === 'user' && $account->uid != $user->uid) {
        $booking_form = array();
      }
      else {
        $booking_form = drupal_get_form('mp_booking_calendar_form', $account);
      }

      $form_rendered = drupal_render($booking_form);
    }
    else {
      $form_rendered = '';
    }

    // Generate calendar.
    $calendar = '<div id="calendar" class="fixed_event_states"></div>';
    $library_path = libraries_get_path('fullcalendar');
    $unit = _mp_booking_get_unit('user', $account);

    $content['#markup'] = $calendar . $form_rendered;
    $content['#attached'] = array(
      'js' => array(
        array('data' => $library_path . '/lib/moment.min.js'),
        array('data' => $library_path . '/fullcalendar.js'),
        array('data' => drupal_get_path('module', 'mp_booking') . '/js/mp_booking_calendar.js'),
        array(
          'data' => array(
            'mp_booking' => array(
              'eventsPath' => _rcb_generate_calendar_events_path($unit),
            ),
          ),
          'type' => 'setting',
        ),
      ),
      'css' => array(
        array('data' => $library_path . '/fullcalendar.css'),
      ),
    );
  }

  return $content;
}

/**
 * Job model reciepts form.
 */
function _mp_booking_job_model_reciepts_form_block_content() {
  $content = '';

  $event = menu_get_object('bat_event', 2);
  if (isset($event->event_id) && $event->event_id) {
    $rendered_form = drupal_get_form('mp_booking_job_model_reciepts_form', $event);

    $content = $rendered_form;
  }

  return $content;
}