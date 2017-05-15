<?php
/**
 * @file
 * model_platform_gallery_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function model_platform_gallery_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access add type service'.
  $permissions['access add type service'] = array(
    'name' => 'access add type service',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_api',
  );

  // Exported permission: 'access add unit service'.
  $permissions['access add unit service'] = array(
    'name' => 'access add unit service',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_api',
  );

  // Exported permission: 'access edit event service'.
  $permissions['access edit event service'] = array(
    'name' => 'access edit event service',
    'roles' => array(
      'Customer' => 'Customer',
      'Model' => 'Model',
      'administrator' => 'administrator',
    ),
    'module' => 'bat_api',
  );

  // Exported permission: 'access edit type service'.
  $permissions['access edit type service'] = array(
    'name' => 'access edit type service',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_api',
  );

  // Exported permission: 'access edit unit service'.
  $permissions['access edit unit service'] = array(
    'name' => 'access edit unit service',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_api',
  );

  // Exported permission: 'access events calendar index service'.
  $permissions['access events calendar index service'] = array(
    'name' => 'access events calendar index service',
    'roles' => array(
      'Customer' => 'Customer',
      'Model' => 'Model',
      'administrator' => 'administrator',
    ),
    'module' => 'bat_api',
  );

  // Exported permission: 'access events index service'.
  $permissions['access events index service'] = array(
    'name' => 'access events index service',
    'roles' => array(
      'Customer' => 'Customer',
      'Model' => 'Model',
      'administrator' => 'administrator',
    ),
    'module' => 'bat_api',
  );

  // Exported permission: 'access matching units calendar index service'.
  $permissions['access matching units calendar index service'] = array(
    'name' => 'access matching units calendar index service',
    'roles' => array(
      'Customer' => 'Customer',
      'Model' => 'Model',
      'administrator' => 'administrator',
    ),
    'module' => 'bat_api',
  );

  // Exported permission: 'access types index service'.
  $permissions['access types index service'] = array(
    'name' => 'access types index service',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_api',
  );

  // Exported permission: 'access units calendar index service'.
  $permissions['access units calendar index service'] = array(
    'name' => 'access units calendar index service',
    'roles' => array(
      'Customer' => 'Customer',
      'Model' => 'Model',
      'administrator' => 'administrator',
    ),
    'module' => 'bat_api',
  );

  // Exported permission: 'access units index service'.
  $permissions['access units index service'] = array(
    'name' => 'access units index service',
    'roles' => array(
      'Customer' => 'Customer',
      'Model' => 'Model',
      'administrator' => 'administrator',
    ),
    'module' => 'bat_api',
  );

  // Exported permission: 'administer bat_event_type entities'.
  $permissions['administer bat_event_type entities'] = array(
    'name' => 'administer bat_event_type entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_event',
  );

  // Exported permission: 'administer bat_type_bundle entities'.
  $permissions['administer bat_type_bundle entities'] = array(
    'name' => 'administer bat_type_bundle entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_unit',
  );

  // Exported permission: 'administer bat_unit_bundle entities'.
  $permissions['administer bat_unit_bundle entities'] = array(
    'name' => 'administer bat_unit_bundle entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_unit',
  );

  // Exported permission: 'administer calendar events'.
  $permissions['administer calendar events'] = array(
    'name' => 'administer calendar events',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_fullcalendar',
  );

  // Exported permission: 'administer mp_auction types'.
  $permissions['administer mp_auction types'] = array(
    'name' => 'administer mp_auction types',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'mp_auction',
  );

  // Exported permission: 'administer mp_auctions'.
  $permissions['administer mp_auctions'] = array(
    'name' => 'administer mp_auctions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'mp_auction',
  );

  // Exported permission: 'bypass bat_event entities access'.
  $permissions['bypass bat_event entities access'] = array(
    'name' => 'bypass bat_event entities access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_event',
  );

  // Exported permission: 'bypass bat_type entities access'.
  $permissions['bypass bat_type entities access'] = array(
    'name' => 'bypass bat_type entities access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_unit',
  );

  // Exported permission: 'bypass bat_unit entities access'.
  $permissions['bypass bat_unit entities access'] = array(
    'name' => 'bypass bat_unit entities access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_unit',
  );

  // Exported permission: 'configure bat settings'.
  $permissions['configure bat settings'] = array(
    'name' => 'configure bat settings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat',
  );

  // Exported permission: 'create bat_event entities'.
  $permissions['create bat_event entities'] = array(
    'name' => 'create bat_event entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_event',
  );

  // Exported permission: 'create bat_event entities of bundle model_availability'.
  $permissions['create bat_event entities of bundle model_availability'] = array(
    'name' => 'create bat_event entities of bundle model_availability',
    'roles' => array(
      'Model' => 'Model',
      'administrator' => 'administrator',
    ),
    'module' => 'bat_event',
  );

  // Exported permission: 'create bat_type entities'.
  $permissions['create bat_type entities'] = array(
    'name' => 'create bat_type entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_unit',
  );

  // Exported permission: 'create bat_type entities of bundle model'.
  $permissions['create bat_type entities of bundle model'] = array(
    'name' => 'create bat_type entities of bundle model',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_unit',
  );

  // Exported permission: 'create bat_unit entities'.
  $permissions['create bat_unit entities'] = array(
    'name' => 'create bat_unit entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_unit',
  );

  // Exported permission: 'create bat_unit entities of bundle default'.
  $permissions['create bat_unit entities of bundle default'] = array(
    'name' => 'create bat_unit entities of bundle default',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_unit',
  );

  // Exported permission: 'create job content'.
  $permissions['create job content'] = array(
    'name' => 'create job content',
    'roles' => array(
      'Customer' => 'Customer',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create node_gallery_gallery content'.
  $permissions['create node_gallery_gallery content'] = array(
    'name' => 'create node_gallery_gallery content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create node_gallery_item content'.
  $permissions['create node_gallery_item content'] = array(
    'name' => 'create node_gallery_item content',
    'roles' => array(
      'Model' => 'Model',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any bat_event entity'.
  $permissions['delete any bat_event entity'] = array(
    'name' => 'delete any bat_event entity',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_event',
  );

  // Exported permission: 'delete any bat_event entity of bundle model_availability'.
  $permissions['delete any bat_event entity of bundle model_availability'] = array(
    'name' => 'delete any bat_event entity of bundle model_availability',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_event',
  );

  // Exported permission: 'delete any bat_type entity'.
  $permissions['delete any bat_type entity'] = array(
    'name' => 'delete any bat_type entity',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_unit',
  );

  // Exported permission: 'delete any bat_type entity of bundle model'.
  $permissions['delete any bat_type entity of bundle model'] = array(
    'name' => 'delete any bat_type entity of bundle model',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_unit',
  );

  // Exported permission: 'delete any bat_unit entity'.
  $permissions['delete any bat_unit entity'] = array(
    'name' => 'delete any bat_unit entity',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_unit',
  );

  // Exported permission: 'delete any bat_unit entity of bundle default'.
  $permissions['delete any bat_unit entity of bundle default'] = array(
    'name' => 'delete any bat_unit entity of bundle default',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_unit',
  );

  // Exported permission: 'delete any job content'.
  $permissions['delete any job content'] = array(
    'name' => 'delete any job content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any node_gallery_gallery content'.
  $permissions['delete any node_gallery_gallery content'] = array(
    'name' => 'delete any node_gallery_gallery content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any node_gallery_item content'.
  $permissions['delete any node_gallery_item content'] = array(
    'name' => 'delete any node_gallery_item content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete bat_type revisions'.
  $permissions['delete bat_type revisions'] = array(
    'name' => 'delete bat_type revisions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_unit',
  );

  // Exported permission: 'delete own auction mp_auction'.
  $permissions['delete own auction mp_auction'] = array(
    'name' => 'delete own auction mp_auction',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'mp_auction',
  );

  // Exported permission: 'delete own bat_event entities'.
  $permissions['delete own bat_event entities'] = array(
    'name' => 'delete own bat_event entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_event',
  );

  // Exported permission: 'delete own bat_event entities of bundle model_availability'.
  $permissions['delete own bat_event entities of bundle model_availability'] = array(
    'name' => 'delete own bat_event entities of bundle model_availability',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_event',
  );

  // Exported permission: 'delete own bat_type entities'.
  $permissions['delete own bat_type entities'] = array(
    'name' => 'delete own bat_type entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_unit',
  );

  // Exported permission: 'delete own bat_type entities of bundle model'.
  $permissions['delete own bat_type entities of bundle model'] = array(
    'name' => 'delete own bat_type entities of bundle model',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_unit',
  );

  // Exported permission: 'delete own bat_unit entities'.
  $permissions['delete own bat_unit entities'] = array(
    'name' => 'delete own bat_unit entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_unit',
  );

  // Exported permission: 'delete own bat_unit entities of bundle default'.
  $permissions['delete own bat_unit entities of bundle default'] = array(
    'name' => 'delete own bat_unit entities of bundle default',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_unit',
  );

  // Exported permission: 'delete own job content'.
  $permissions['delete own job content'] = array(
    'name' => 'delete own job content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own node_gallery_gallery content'.
  $permissions['delete own node_gallery_gallery content'] = array(
    'name' => 'delete own node_gallery_gallery content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own node_gallery_item content'.
  $permissions['delete own node_gallery_item content'] = array(
    'name' => 'delete own node_gallery_item content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any auction mp_auction'.
  $permissions['edit any auction mp_auction'] = array(
    'name' => 'edit any auction mp_auction',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'mp_auction',
  );

  // Exported permission: 'edit any job content'.
  $permissions['edit any job content'] = array(
    'name' => 'edit any job content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any node_gallery_gallery content'.
  $permissions['edit any node_gallery_gallery content'] = array(
    'name' => 'edit any node_gallery_gallery content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any node_gallery_item content'.
  $permissions['edit any node_gallery_item content'] = array(
    'name' => 'edit any node_gallery_item content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own auction mp_auction'.
  $permissions['edit own auction mp_auction'] = array(
    'name' => 'edit own auction mp_auction',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'mp_auction',
  );

  // Exported permission: 'edit own job content'.
  $permissions['edit own job content'] = array(
    'name' => 'edit own job content',
    'roles' => array(
      'Customer' => 'Customer',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own node_gallery_gallery content'.
  $permissions['edit own node_gallery_gallery content'] = array(
    'name' => 'edit own node_gallery_gallery content',
    'roles' => array(
      'Model' => 'Model',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own node_gallery_item content'.
  $permissions['edit own node_gallery_item content'] = array(
    'name' => 'edit own node_gallery_item content',
    'roles' => array(
      'Model' => 'Model',
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'job model propose'.
  $permissions['job model propose'] = array(
    'name' => 'job model propose',
    'roles' => array(
      'Customer' => 'Customer',
      'Model' => 'Model',
      'administrator' => 'administrator',
    ),
    'module' => 'mp_booking',
  );

  // Exported permission: 'modelplatform administer models'.
  $permissions['modelplatform administer models'] = array(
    'name' => 'modelplatform administer models',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'modelplatform',
  );

  // Exported permission: 'modelplatform dashboard access'.
  $permissions['modelplatform dashboard access'] = array(
    'name' => 'modelplatform dashboard access',
    'roles' => array(
      'Customer' => 'Customer',
      'Model' => 'Model',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'mp_dashboard',
  );

  // Exported permission: 'moderate modelplatform documents'.
  $permissions['moderate modelplatform documents'] = array(
    'name' => 'moderate modelplatform documents',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'modelplatform',
  );

  // Exported permission: 'reject profile revisions'.
  $permissions['reject profile revisions'] = array(
    'name' => 'reject profile revisions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'mp_profile2_moderation',
  );

  // Exported permission: 'revert bat_type revisions'.
  $permissions['revert bat_type revisions'] = array(
    'name' => 'revert bat_type revisions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_unit',
  );

  // Exported permission: 'update any bat_event entity'.
  $permissions['update any bat_event entity'] = array(
    'name' => 'update any bat_event entity',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_event',
  );

  // Exported permission: 'update any bat_event entity of bundle model_availability'.
  $permissions['update any bat_event entity of bundle model_availability'] = array(
    'name' => 'update any bat_event entity of bundle model_availability',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_event',
  );

  // Exported permission: 'update any bat_type entity'.
  $permissions['update any bat_type entity'] = array(
    'name' => 'update any bat_type entity',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_unit',
  );

  // Exported permission: 'update any bat_type entity of bundle model'.
  $permissions['update any bat_type entity of bundle model'] = array(
    'name' => 'update any bat_type entity of bundle model',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_unit',
  );

  // Exported permission: 'update any bat_unit entity'.
  $permissions['update any bat_unit entity'] = array(
    'name' => 'update any bat_unit entity',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_unit',
  );

  // Exported permission: 'update any bat_unit entity of bundle default'.
  $permissions['update any bat_unit entity of bundle default'] = array(
    'name' => 'update any bat_unit entity of bundle default',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_unit',
  );

  // Exported permission: 'update own bat_event entities'.
  $permissions['update own bat_event entities'] = array(
    'name' => 'update own bat_event entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_event',
  );

  // Exported permission: 'update own bat_event entities of bundle model_availability'.
  $permissions['update own bat_event entities of bundle model_availability'] = array(
    'name' => 'update own bat_event entities of bundle model_availability',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_event',
  );

  // Exported permission: 'update own bat_type entities'.
  $permissions['update own bat_type entities'] = array(
    'name' => 'update own bat_type entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_unit',
  );

  // Exported permission: 'update own bat_type entities of bundle model'.
  $permissions['update own bat_type entities of bundle model'] = array(
    'name' => 'update own bat_type entities of bundle model',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_unit',
  );

  // Exported permission: 'update own bat_unit entities'.
  $permissions['update own bat_unit entities'] = array(
    'name' => 'update own bat_unit entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_unit',
  );

  // Exported permission: 'update own bat_unit entities of bundle default'.
  $permissions['update own bat_unit entities of bundle default'] = array(
    'name' => 'update own bat_unit entities of bundle default',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_unit',
  );

  // Exported permission: 'view any auction mp_auction'.
  $permissions['view any auction mp_auction'] = array(
    'name' => 'view any auction mp_auction',
    'roles' => array(
      'Customer' => 'Customer',
      'Model' => 'Model',
      'administrator' => 'administrator',
    ),
    'module' => 'mp_auction',
  );

  // Exported permission: 'view any bat_event entity'.
  $permissions['view any bat_event entity'] = array(
    'name' => 'view any bat_event entity',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bat_event',
  );

  // Exported permission: 'view any bat_event entity of bundle model_availability'.
  $permissions['view any bat_event entity of bundle model_availability'] = array(
    'name' => 'view any bat_event entity of bundle model_availability',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_event',
  );

  // Exported permission: 'view any bat_type entity'.
  $permissions['view any bat_type entity'] = array(
    'name' => 'view any bat_type entity',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_unit',
  );

  // Exported permission: 'view any bat_type entity of bundle model'.
  $permissions['view any bat_type entity of bundle model'] = array(
    'name' => 'view any bat_type entity of bundle model',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_unit',
  );

  // Exported permission: 'view any bat_type unpublished entity'.
  $permissions['view any bat_type unpublished entity'] = array(
    'name' => 'view any bat_type unpublished entity',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_unit',
  );

  // Exported permission: 'view any bat_unit entity'.
  $permissions['view any bat_unit entity'] = array(
    'name' => 'view any bat_unit entity',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_unit',
  );

  // Exported permission: 'view any bat_unit entity of bundle default'.
  $permissions['view any bat_unit entity of bundle default'] = array(
    'name' => 'view any bat_unit entity of bundle default',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_unit',
  );

  // Exported permission: 'view any bat_unit unpublished entity'.
  $permissions['view any bat_unit unpublished entity'] = array(
    'name' => 'view any bat_unit unpublished entity',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_unit',
  );

  // Exported permission: 'view bat_type revisions'.
  $permissions['view bat_type revisions'] = array(
    'name' => 'view bat_type revisions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_unit',
  );

  // Exported permission: 'view calendar data for any model_availability event'.
  $permissions['view calendar data for any model_availability event'] = array(
    'name' => 'view calendar data for any model_availability event',
    'roles' => array(
      'Customer' => 'Customer',
      'Model' => 'Model',
      'administrator' => 'administrator',
    ),
    'module' => 'bat_event',
  );

  // Exported permission: 'view own auction mp_auction'.
  $permissions['view own auction mp_auction'] = array(
    'name' => 'view own auction mp_auction',
    'roles' => array(
      'Customer' => 'Customer',
      'Model' => 'Model',
      'administrator' => 'administrator',
    ),
    'module' => 'mp_auction',
  );

  // Exported permission: 'view own bat_event entities'.
  $permissions['view own bat_event entities'] = array(
    'name' => 'view own bat_event entities',
    'roles' => array(
      'Customer' => 'Customer',
      'Model' => 'Model',
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bat_event',
  );

  // Exported permission: 'view own bat_event entities of bundle model_availability'.
  $permissions['view own bat_event entities of bundle model_availability'] = array(
    'name' => 'view own bat_event entities of bundle model_availability',
    'roles' => array(
      'Model' => 'Model',
      'administrator' => 'administrator',
    ),
    'module' => 'bat_event',
  );

  // Exported permission: 'view own bat_type entities'.
  $permissions['view own bat_type entities'] = array(
    'name' => 'view own bat_type entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_unit',
  );

  // Exported permission: 'view own bat_type entities of bundle model'.
  $permissions['view own bat_type entities of bundle model'] = array(
    'name' => 'view own bat_type entities of bundle model',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_unit',
  );

  // Exported permission: 'view own bat_type unpublished entities'.
  $permissions['view own bat_type unpublished entities'] = array(
    'name' => 'view own bat_type unpublished entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_unit',
  );

  // Exported permission: 'view own bat_unit entities'.
  $permissions['view own bat_unit entities'] = array(
    'name' => 'view own bat_unit entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_unit',
  );

  // Exported permission: 'view own bat_unit entities of bundle default'.
  $permissions['view own bat_unit entities of bundle default'] = array(
    'name' => 'view own bat_unit entities of bundle default',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_unit',
  );

  // Exported permission: 'view own bat_unit unpublished entities'.
  $permissions['view own bat_unit unpublished entities'] = array(
    'name' => 'view own bat_unit unpublished entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'bat_unit',
  );

  // Exported permission: 'view past event information'.
  $permissions['view past event information'] = array(
    'name' => 'view past event information',
    'roles' => array(
      'Customer' => 'Customer',
      'Model' => 'Model',
      'administrator' => 'administrator',
    ),
    'module' => 'bat_fullcalendar',
  );

  return $permissions;
}
