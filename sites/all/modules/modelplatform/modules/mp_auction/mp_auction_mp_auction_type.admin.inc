<?php

/**
 * @file
 * MpAuction type editing UI.
 */

/**
 * UI controller.
 */
class MpAuctionTypeUIController extends EntityDefaultUIController {

  /**
   * Overrides hook_menu() defaults.
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    $items[$this->path]['description'] = 'Manage MP Auction entity types, including adding
		and removing fields and the display of fields.';

    return $items;
  }
}

/**
 * Generates the mp_auction type editing form.
 */
function mp_auction_type_form($form, &$form_state, $mp_auction_type, $op = 'edit') {

  if ($op == 'clone') {
    $mp_auction_type->label .= ' (cloned)';
    $mp_auction_type->type = '';
  }

  $form['label'] = array(
    '#title'         => t('Label'),
    '#type'          => 'textfield',
    '#default_value' => $mp_auction_type->label,
    '#description'   => t('The human-readable name of this MP Auction type.'),
    '#required'      => TRUE,
    '#size'          => 30,
  );
  // Machine-readable type name.
  $form['type'] = array(
    '#type'          => 'machine_name',
    '#default_value' => isset($mp_auction_type->type) ? $mp_auction_type->type : '',
    '#maxlength'     => 32,
    '#machine_name'  => array(
      'exists' => 'mp_auction_get_types',
      'source' => array('label'),
    ),
    '#description'   => t(
      'A unique machine-readable name for this MP Auction type. It must only contain lowercase letters, numbers, and underscores.'
    ),
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type'   => 'submit',
    '#value'  => t('Save MP Auction type'),
    '#weight' => 40,
  );

  return $form;
}

/**
 * Form API submit callback for the type form.
 */
function mp_auction_type_form_submit(&$form, &$form_state) {
  $mp_auction_type = entity_ui_form_submit_build_entity($form, $form_state);
  $mp_auction_type->save();
  $form_state['redirect'] = 'admin/structure/mp_auction_types';
}

/**
 * Form API submit callback for the delete button.
 */
function mp_auction_type_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/structure/mp_auction_types/manage/' . $form_state['mp_auction_type']->type . '/delete';
}
