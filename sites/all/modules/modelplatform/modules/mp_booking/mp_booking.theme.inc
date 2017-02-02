<?php

/**
 * @file
 * Model Platform Booking themes.
 */

function theme_mp_booking_event_auctions_table($variables) {
  $output = '';

  if (isset($variables['auctions'])) {
    $auctions = $variables['auctions'];

    $rows = array();
    foreach ($auctions as $auction) {
      $row = array();

      $row[] = $auction->field_auction_cost_propose[LANGUAGE_NONE][0]['amount'];
      $row[] = $auction->field_auction_decision[LANGUAGE_NONE][0]['value'];

      $rows[] = $row;
    }

    $header = array(
      t('Propose'),
      t('Decision'),
    );

    $table_variables = array(
      'header' => $header,
      'rows' => $rows,
    );

    $output .= theme('table', $table_variables);
  }

  return $output;
}
