<?php
/**
 * @file
 * profile_2_model_my_jobs.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function profile_2_model_my_jobs_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'edit any my_jobs profile'.
  $permissions['edit any my_jobs profile'] = array(
    'name' => 'edit any my_jobs profile',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'edit own my_jobs profile'.
  $permissions['edit own my_jobs profile'] = array(
    'name' => 'edit own my_jobs profile',
    'roles' => array(
      'Model' => 'Model',
      'administrator' => 'administrator',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'view any my_jobs profile'.
  $permissions['view any my_jobs profile'] = array(
    'name' => 'view any my_jobs profile',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'view own my_jobs profile'.
  $permissions['view own my_jobs profile'] = array(
    'name' => 'view own my_jobs profile',
    'roles' => array(
      'Model' => 'Model',
      'administrator' => 'administrator',
    ),
    'module' => 'profile2',
  );

  return $permissions;
}
