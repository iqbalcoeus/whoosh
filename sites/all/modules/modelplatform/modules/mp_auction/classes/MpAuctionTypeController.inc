<?php

/**
 * The Controller for MpAuction entities.
 *
 * Class MpAuctionTypeController
 */
class MpAuctionTypeController extends EntityAPIControllerExportable {
  /**
   * Constructor.
   *
   * @param string $entity_type
   *   Entity type.
   */
  public function __construct($entity_type) {
    parent::__construct($entity_type);
  }

  /**
   * Create a mp_auction type - we first set up the values that are specific
   * to our mp_auction type schema but then also go through
   * the EntityAPIController function.
   *
   * @param array $values
   *   The values of the mp_auction.
   *
   * @return bool
   *   A mp_auction type object with all default fields initialized.
   */
  public function create(array $values = array()) {
    // Add values that are specific to our MpAuction.
    $values += array(
      'id'     => '',
      'is_new' => TRUE,
    );
    $mp_auction_type = parent::create($values);

    return $mp_auction_type;
  }
}
