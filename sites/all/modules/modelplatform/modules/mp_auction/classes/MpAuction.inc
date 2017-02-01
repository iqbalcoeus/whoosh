<?php

/**
 * The class used for mp_auction entities
 *
 * Class MpAuction
 */
class MpAuction extends Entity {
  /**
   * Constructor.
   *
   * @param array $values
   *   Values.
   *
   * @throws \Exception
   */
  public function __construct($values = array()) {
    parent::__construct($values, 'mp_auction');
  }

  /**
   * Return mp_auction label.
   *
   * @return string
   *   Label.
   */
  protected function defaultLabel() {
    return $this->name;
  }

  /**
   * Return mp_auction URI.
   *
   * @return array
   *   Uri.
   */
  protected function defaultUri() {
    return array('path' => 'mp_auction/' . $this->mp_auction_id);
  }
}