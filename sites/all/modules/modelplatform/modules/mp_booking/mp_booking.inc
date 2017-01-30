<?php

/**
 * @file
 * Model Platform Booking - Helper functions.
 */

/**
 * Create new BAT Unit.
 */
function _mp_booking_unit_create($name, $uid) {
  $unit = bat_unit_create(array(
    'type' => MP_BOOKING_UNIT_TYPE,
  ));
  $unit->created = REQUEST_TIME;
  $unit->type_id = MP_BOOKING_UNIT_TYPE_ID;
  $unit->default_state = 1;
  $unit->name = $name;
  $unit->uid = $uid;
  $unit->save();

  return $unit;
}

/**
 * Update BAT Unit.
 */
function _mp_booking_unit_update($unit, $name, $uid) {
  $unit->name = $name;
  $unit->uid = $uid;
  $unit->save();

  return $unit;
}

/**
 * Get Entity BAT Unit.
 */
function _mp_booking_get_unit($entity_type, $entity) {
  $wrapper = entity_metadata_wrapper($entity_type, $entity);
  $unit = $wrapper->{MP_BOOKING_UNIT_FIELD_NAME}->value();

  return $unit;
}

/**
 * Set BAT Unit to the Entity.
 */
function _mp_booking_set_unit($entity_type, $entity, $unit) {
  $wrapper = entity_metadata_wrapper($entity_type, $entity);
  $wrapper->{MP_BOOKING_UNIT_FIELD_NAME}->set($unit);
  $wrapper->save();
}

/**
 * Get customer Jobs.
 */
function _mp_booking_get_customer_jobs($customer_uid) {
  $nids = db_select('node', 'n')
    ->condition('type', 'job')
    ->condition('uid', $customer_uid)
    ->fields('n', array('nid'))
    ->execute()
    ->fetchCol(0);

  return $nids;
}

/**
 * Get BAT Events of the BAT Unit.
 */
function _mp_booking_get_unit_events($unit, $start_date = NULL, $end_date = NULL, $blocking = NULL, $return_events = TRUE) {
  $or = db_or();

  $flag = FALSE;
  if ($start_date) {
    // Get date values.
    $c_start_date = db_and();
    $c_start_date->condition('be.start_date', $start_date, '<=');
    $c_start_date->condition('be.end_date', $start_date, '>=');
    $or->condition($c_start_date);
    $flag = TRUE;
  }

  if ($end_date) {
    $c_end_date = db_and();
    $c_end_date->condition('be.start_date', $end_date, '<=');
    $c_end_date->condition('be.end_date', $end_date, '>=');
    $or->condition($c_end_date);
    $flag = TRUE;
  }

  if ($start_date && $end_date) {
    $c_into_date = db_and();
    $c_into_date->condition('be.start_date', $start_date, '>=');
    $c_into_date->condition('be.end_date', $end_date, '<=');
    $or->condition($c_into_date);
    $flag = TRUE;
  }

  // Get blocking events.
  $event_query = db_select('bat_events', 'be');
  if ($flag) {
    $event_query->condition($or);
  }
  $event_query->innerJoin('field_data_event_state_reference', 'besr',
    'besr.entity_id = be.event_id AND besr.entity_type = \'bat_event\'');
  $event_query->innerJoin('field_data_event_bat_unit_reference', 'beur',
    'beur.entity_id = be.event_id '
    . ' AND beur.entity_type = \'bat_event\''
    . ' AND beur.event_bat_unit_reference_target_id = ' . $unit->unit_id );
  $event_query->innerJoin('bat_event_state', 'bes',
    'bes.id = besr.event_state_reference_state_id AND bes.blocking = 1');
  if (isset($blocking)) {
    $event_query->condition('bes.blocking', $blocking);
  }
  $event_query->addField('be', 'event_id', 'event_id');
  $event_ids = $event_query->execute()->fetchCol(0);

  if ($return_events) {
    $result = entity_load('bat_event', $event_ids);
  }
  else {
    $result = $event_ids;
  }

  return $result;
}
