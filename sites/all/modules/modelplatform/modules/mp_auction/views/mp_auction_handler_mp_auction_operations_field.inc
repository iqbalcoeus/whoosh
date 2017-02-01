<?php

/**
 * @file
 * This field handler aggregates operations that can be done on a mp_auction
 * under a single field providing a more flexible way to present them in a view
 */

/**
 * Class mp_auction_handler_mp_auction_operations_field.
 */
class mp_auction_handler_mp_auction_operations_field extends views_handler_field {
  /**
   * Constructor.
   */
  public function construct() {
    parent::construct();

    $this->additional_fields['mp_auction_id'] = 'mp_auction_id';
  }

  /**
   * Update query.
   */
  public function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  /**
   * Build link.
   *
   * @param array $values
   *   Values.
   *
   * @return string
   *   Link.
   *
   * @throws \Exception
   */
  public function render($values) {
    $links = menu_contextual_links(
      'mp_auction',
      'admin/content/mp_auctions/mp_auction',
      array($this->get_value($values, 'mp_auction_id'))
    );

    if (!empty($links)) {
      return theme(
        'links',
        array(
          'links' => $links,
          'attributes' => array(
            'class' => array('links', 'inline', 'operations'),
          ),
        )
      );
    }
  }
}
