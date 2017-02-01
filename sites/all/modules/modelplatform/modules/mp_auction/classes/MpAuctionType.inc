<?php

/**
 * The class used for mp_auction type entities
 *
 * Class MpAuctionType
 */
class MpAuctionType extends Entity {
  /**
   * @var string
   */
  public $type;

  /**
   * @var string
   */
  public $label;

  /**
   * Constructor.
   *
   * @param array $values
   *   Values.
   *
   * @throws \Exception
   */
  public function __construct($values = array()) {
    parent::__construct($values, 'mp_auction_type');
  }
}