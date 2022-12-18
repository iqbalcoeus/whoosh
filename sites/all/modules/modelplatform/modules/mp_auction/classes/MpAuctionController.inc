<?php

/**
 * The Controller for MpAuction entities
 *
 * Class MpAuctionController
 */
class MpAuctionController extends EntityAPIController {
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
   * Create a mp_auction - we first set up the values that are specific
   * to our mp_auction schema but then also go through the EntityAPIController
   * function.
   *
   * @param array $values
   *   The values of the mp_auction.
   *
   * @return object
   *   A mp_auction object with all default fields initialized.
   */
  public function create(array $values = array()) {
    global $user;
    // Add values that are specific to our MpAuction.
    $values += array(
      'mp_auction_id' => '',
      'uid'            => $user->uid,
      'is_new'         => TRUE,
      'title'          => '',
      'created'        => REQUEST_TIME,
      'changed'        => '',
    );

    $mp_auction = parent::create($values);

    return $mp_auction;
  }

  /**
   * Overriding the buildContent function to add entity specific fields.
   *
   * @param object $entity
   *   Entity.
   * @param string $view_mode
   *   View mode.
   * @param string $langcode
   *   Language code.
   * @param array $content
   *   Content.
   *
   * @return array
   *   The content built.
   */
  public function buildContent($entity, $view_mode = 'full', $langcode = NULL, $content = array()) {
    $content = parent::buildContent($entity, $view_mode, $langcode, $content);

    return $content;
  }
}
