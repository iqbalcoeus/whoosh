<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying deletes links
 * as fields.
 */

/**
 * Class mp_auction_handler_delete_link_field.
 */
class mp_auction_handler_delete_link_field extends mp_auction_handler_link_field {
  /**
   * Constructor.
   */
  public function construct() {
    parent::construct();
    $this->additional_fields['type'] = 'type';
  }

  /**
   * Render link.
   *
   * @param array $values
   *   Values.
   *
   * @return string
   *   Link.
   */
  public function render($values) {
    $type = $values->{$this->aliases['type']};

    // Creating a dummy mp_auction to check access against.
    $dummy_mp_auction = (object) array('type' => $type);
    if (!mp_auction_access('edit', $dummy_mp_auction)) {
      return;
    }

    $text = !empty($this->options['text']) ? $this->options['text'] : t('delete');
    $mp_auction_id = $values->{$this->aliases['mp_auction_id']};

    return l($text, 'admin/content/mp_auctions/mp_auction/' . $mp_auction_id . '/delete');
  }
}
