<?php

/**
 * @file
 * Providing extra functionality for the MpAuction UI via views.
 */

/**
 * Implements hook_views_data().
 */
function mp_auction_views_data_alter(&$data) {

  $data['mp_auction']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field'      => 'uid',
    ),
  );

  $data['mp_auction']['uid'] = array(
    'title'        => t('User ID'),
    'help'         => t('The author ID'),
    'relationship' => array(
      // The name of the table to join with.
      'base'       => 'users',
      // The name of the field on the joined table.
      'base field' => 'uid',
      'handler'    => 'views_handler_relationship',
      'label'      => t('Author ID of the mp_auction (relationship)'),
      'title'      => t('Author ID'),
      'help'       => t('Author of the mp_auction (relationship)'),
    ),
    'field'        => array('handler' => 'views_handler_field_numeric', 'click sortable' => TRUE),
    'filter'       => array('handler' => 'views_handler_filter_numeric'),
    'sort'         => array('handler' => 'views_handler_sort'),
    'argument'     => array('handler' => 'views_handler_argument_numeric'),
  );

  $data['mp_auction']['link_mp_auction'] = array(
    'field' => array(
      'title'   => t('Link'),
      'help'    => t('Provide a link to the mp_auction.'),
      'handler' => 'mp_auction_handler_link_field',
    ),
  );
  $data['mp_auction']['edit_mp_auction'] = array(
    'field' => array(
      'title'   => t('Edit Link'),
      'help'    => t('Provide a link to the edit form for the mp_auction.'),
      'handler' => 'mp_auction_handler_edit_link_field',
    ),
  );
  $data['mp_auction']['delete_mp_auction'] = array(
    'field' => array(
      'title'   => t('Delete Link'),
      'help'    => t('Provide a link to delete the mp_auction.'),
      'handler' => 'mp_auction_handler_delete_link_field',
    ),
  );

  // This content of this field are decided based on the menu structure that
  // follows mp_auctions/mp_auction/%mp_auction_id/op
  $data['mp_auction']['operations'] = array(
    'field' => array(
      'title'   => t('Operations links'),
      'help'    => t('Display all operations available for this mp_auction.'),
      'handler' => 'mp_auction_handler_mp_auction_operations_field',
    ),
  );

  $data['mp_auction']['created'] = array(
    'title'  => t('Created'),
    'help'   => t('Creation date'),
    'field'  => array(
      'handler'        => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort'   => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  $data['mp_auction']['changed'] = array(
    'title'  => t('Changed'),
    'help'   => t('Last modification date'),
    'field'  => array(
      'handler'        => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort'   => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );
}

/**
 * Implements hook_views_default_views().
 */
function mp_auction_views_default_views() {
  static $views;

  if (isset($views)) {
    return $views;
  }

  $files = file_scan_directory(drupal_get_path('module', 'mp_auction') . '/views', '/\.view$/');

  foreach ($files as $filepath => $file) {
    include $filepath;
    if (isset($view)) {
      $views[$view->name] = $view;
    }
  }

  return $views;
}
