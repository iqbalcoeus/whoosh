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
function _mp_booking_get_customer_jobs($customer_uid, $_fields = array('nid')) {
  $result = db_select('node', 'n')
    ->condition('type', 'job')
    ->condition('uid', $customer_uid)
    ->fields('n', $_fields)
    ->execute()
    ->fetchAllKeyed();

  return $result;
}

function _mp_booking_get_job_auction($model_uid, $customer_uid) {
  $result = NULL;

  // Auction.
  $event_query = db_select('mp_auction', 'a');

  // BAT Event.
  $event_query->innerJoin('field_data_field_auction_event', 'fae',
    'fae.entity_id = a.mp_auction_id AND fae.entity_type = \'mp_auction\'');
  $event_query->innerJoin('bat_events', 'be',
    'be.event_id = fae.field_auction_event_target_id');
  $event_query->innerJoin('field_data_field_job', 'fj', 'fj.entity_id = be.event_id AND fj.entity_type = \'bat_event\'');
  $event_query->innerJoin('node', 'n', 'n.nid = fj.field_job_target_id');
  $event_query->condition('n.uid', $customer_uid);

  // BAT Unit.
  $event_query->innerJoin('field_data_event_bat_unit_reference', 'febu',
    'febu.entity_id = be.event_id AND febu.entity_type = \'bat_event\'');
  $event_query->innerJoin('field_data_field_bat_unit', 'fbu',
    'fbu.field_bat_unit_target_id = febu.event_bat_unit_reference_target_id AND fbu.entity_type = \'user\'');
  $event_query->condition('fbu.entity_id', $model_uid);
  $event_query->addField('n', 'nid', 'job_nid');
  $event_query->addField('n', 'title', 'job_title');

  $query_result = $event_query->execute()->fetch();
  if (isset($query_result->job_nid)) {
    $result = node_load($query_result->job_nid);
  }

  return $result;
}

function _mp_booking_get_model_auctions($model_uid, $start_date, $end_date) {
  $event_query = db_select('mp_auction', 'a');

  // BAT Event.
  $event_query->innerJoin('field_data_field_auction_event', 'fae',
    'fae.entity_id = a.mp_auction_id AND fae.entity_type = \'mp_auction\'');
  $event_query->innerJoin('bat_events', 'be',
    'be.event_id = fae.field_auction_event_target_id');

  // Job.
  $event_query->innerJoin('field_data_field_job', 'fj',
    'fj.entity_id = be.event_id AND fj.entity_type = \'bat_event\'');
  $event_query->innerJoin('node', 'n', 'n.nid = fj.field_job_target_id');

  $or = db_or();

  if ($start_date) {
    // Get date values.
    $c_start_date = db_and();
    $c_start_date->condition('be.start_date', $start_date, '<=');
    $c_start_date->condition('be.end_date', $start_date, '>=');
    $or->condition($c_start_date);
  }

  if ($end_date) {
    $c_end_date = db_and();
    $c_end_date->condition('be.start_date', $end_date, '<=');
    $c_end_date->condition('be.end_date', $end_date, '>=');
    $or->condition($c_end_date);
  }

  if ($start_date && $end_date) {
    $c_into_date = db_and();
    $c_into_date->condition('be.start_date', $start_date, '>=');
    $c_into_date->condition('be.end_date', $end_date, '<=');
    $or->condition($c_into_date);
  }

  $event_query->condition($or);

  // BAT Unit.
  $event_query->innerJoin('field_data_event_bat_unit_reference', 'febu',
    'febu.entity_id = fae.field_auction_event_target_id AND febu.entity_type = \'bat_event\'');

  $event_query->innerJoin('field_data_field_bat_unit', 'fbu',
    'fbu.field_bat_unit_target_id = febu.event_bat_unit_reference_target_id AND fbu.entity_type = \'user\'');
  $event_query->condition('fbu.entity_id', $model_uid);

  $event_query->addField('n', 'nid', 'job_nid');

  $event_query->orderBy('a.created', 'ASC');

  $result = $event_query->execute()->fetchCol(0);

  return $result;
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
    'bes.id = besr.event_state_reference_state_id');
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

/**
 * Get BAT Event auction ids.
 */
function mp_booking_get_event_auction_ids($event) {
  $query = db_select('field_data_field_auction_event', 'fae');
  $query->condition('field_auction_event_target_id', $event->event_id);
  $query->condition('entity_type', 'mp_auction');
  $query->fields('fae', array('entity_id'));

  $auction_ids = $query->execute()->fetchCol(0);

  return $auction_ids;
}

/**
 * Get BAT Event auction entities.
 */
function mp_booking_get_event_auctions($event) {
  $auction_ids = mp_booking_get_event_auction_ids($event);

  $auctions = entity_load('mp_auction', $auction_ids);

  return $auctions;
}

function _mp_booking_event_create($unit_id, $state_id, $uid, $job_nid = 0, $start_date = NULL, $end_date = NULL) {
  $event_params = array(
    'type' => MP_BOOKING_MODEL_AVAILABILITY,
  );
  $event = bat_event_create($event_params);
  $event->field_job[LANGUAGE_NONE][0]['target_id'] = $job_nid;
  $event->event_bat_unit_reference[LANGUAGE_NONE][0]['target_id'] = $unit_id;
  $event->event_state_reference[LANGUAGE_NONE][0]['state_id'] = $state_id;
  if ($start_date) {
    $event->start_date = $start_date;
  }
  if ($end_date) {
    $event->end_date = $end_date;
  }
  $event->uid = $uid;

  return $event;
}

function _mp_booking_get_calendar_account() {
  global $user;

  $args = arg();

  $account = NULL;
  if (isset($args[3])
    && $args[0] === 'job'
    && $args[1] === 'model'
    && $args[3] === 'invite') {
    $account = user_load(intval($args[2]));
  }
  elseif (!isset($args[1])
    && isset($args[0])
    && $args[0] == 'user'
    && $user->uid) {
    $account = user_load($user->uid);
  }
  elseif (!isset($args[2])
    && isset($args[1])
    && intval($args[1])
    && $args[0] === 'user') {
    $account = user_load(intval($args[1]));
    if (!isset($account->roles[5])) {
      $account = NULL;
    }
  }
  elseif (isset($args[3])
    && $args[0] === 'job'
    && $args[1] === 'model'
    && $args[3] === 'auction') {
    if ($event = bat_event_load(intval($args[2]))) {
      $query = db_select('field_data_event_bat_unit_reference', 'b_unit');
      $query->condition('b_unit.entity_type', 'bat_event');
      $query->condition('b_unit.entity_id', $event->event_id);
      $query->innerJoin('field_data_field_bat_unit', 'u_unit',
        'u_unit.field_bat_unit_target_id = b_unit.event_bat_unit_reference_target_id');
      $query->condition('u_unit.entity_type', 'user');
      $query->addField('u_unit', 'entity_id', 'uid');
      $uid = $query->execute()->fetchField();

      $account = user_load($uid);
    }
  }

  return $account;
}

function _mp_booking_get_calendar_busy_access() {
  global $user;

  $args = arg();

  $access = FALSE;
  if (isset($args[3]) && $args[0] === 'job' && $args[1] === 'model' && intval($args[2]) === intval($user->uid)) {
    $access = TRUE;
  }
  elseif (isset($args[0]) && $args[0] == 'user') {
    $access = TRUE;
  }
  elseif (isset($args[3])
    && $args[0] === 'job'
    && $args[1] === 'model'
    && intval($args[2])
    && $args[3] === 'auction') {
    $access = TRUE;
  }

  return $access;
}

/**
 * Generate path for calendar events data.
 */
function _rcb_generate_calendar_events_path($unit) {
  $events_path_params = array(
    'q=bat/v2/events-calendar',
    'unit_types=' . $unit->type_id,
    'event_types=' . 'model_availability',
    'unit_ids=' . $unit->unit_id,
  );
  $events_path = '?' . implode('&', $events_path_params);

  return $events_path;
}

/**
 * Page callback.
 */
function mp_booking_model_propose($nid) {
  global $user;

  if (!isset($user->roles[5])) {
    drupal_set_message(t('Only model can send propose to the customer.'), 'warning');

    return '';
  }

  $job = node_load($nid);

  // Job dates check.
  if (isset($job->field_job_start_date[LANGUAGE_NONE][0]['value'])) {
    $start_date = $job->field_job_start_date[LANGUAGE_NONE][0]['value'];
  }
  else {
    return;
  }
  if (isset($job->field_job_start_date[LANGUAGE_NONE][0]['value2'])) {
    $end_date = $job->field_job_start_date[LANGUAGE_NONE][0]['value2'];
  }
  else {
    return;
  }

  // Get model unit.
  $model_account = user_load($user->uid);
  $unit = _mp_booking_get_unit('user', $model_account);

  // Create event.
  $event = _mp_booking_event_create($unit->unit_id, MP_BOOKING_STATE_AUCTION, $user->uid, $nid, $start_date, $end_date);
  bat_event_save($event);

  drupal_goto('job/model/' . $event->event_id . '/auction');
}