<?php

/**
 * @file
 * MpAuction editing UI.
 *
 * We make very little use of the EntityAPI interface for this - preferring
 * instead to use views. That offers more flexibility to change a UI that
 * will, more often than not, be end-user facing.
 */

/**
 * UI controller.
 */
class MpAuctionUIController extends EntityDefaultUIController {

  /**
   * Overrides hook_menu() defaults. Main reason for doing this is that
   * parent class hook_menu() is optimized for entity type administration.
   */
  public function hook_menu() {

    $items = array();
    $id_count = count(explode('/', $this->path));
    $wildcard = isset($this->entityInfo['admin ui']['menu wildcard']) ? $this->entityInfo['admin ui']['menu wildcard'] : '%' . $this->entityType;

    $items[$this->path] = array(
      'title'            => 'Auction',
      'description'      => 'Add edit and update Auction.',
      'page callback'    => 'system_admin_menu_block_page',
      'access arguments' => array('access administration pages'),
      'file path'        => drupal_get_path('module', 'system'),
      'file'             => 'system.admin.inc',
    );

    // Change the overview menu type for the list of mp_auctions.
    $items[$this->path]['type'] = MENU_LOCAL_TASK;

    // Change the add page menu to multiple types of entities.
    $items[$this->path . '/add'] = array(
      'title'            => 'Add a MP Auction',
      'description'      => 'Add a new MP Auction',
      'page callback'    => 'mp_auction_add_page',
      'access callback'  => 'mp_auction_access',
      'access arguments' => array('edit'),
      'type'             => MENU_NORMAL_ITEM,
      'weight'           => 20,
      'file'             => 'mp_auction_mp_auction.admin.inc',
      'file path'        => drupal_get_path('module', $this->entityInfo['module']),
    );

    // Add menu items to add each different type of entity.
    foreach (mp_auction_get_types() as $type) {
      $items[$this->path . '/add/' . $type->type] = array(
        'title'            => 'Add ' . $type->label,
        'page callback'    => 'mp_auction_form_wrapper',
        'page arguments'   => array(mp_auction_create(array('type' => $type->type))),
        'access callback'  => 'mp_auction_access',
        'access arguments' => array('edit', 'edit ' . $type->type),
        'file'             => 'mp_auction_mp_auction.admin.inc',
        'file path'        => drupal_get_path('module', $this->entityInfo['module']),
      );
    }

    // Loading and editing mp_auction entities.
    $items[$this->path . '/mp_auction/' . $wildcard] = array(
      'page callback'    => 'mp_auction_form_wrapper',
      'page arguments'   => array($id_count + 1),
      'access callback'  => 'mp_auction_access',
      'access arguments' => array('edit', $id_count + 1),
      'weight'           => 0,
      'context'          => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
      'file'             => 'mp_auction_mp_auction.admin.inc',
      'file path'        => drupal_get_path('module', $this->entityInfo['module']),
    );
    $items[$this->path . '/mp_auction/' . $wildcard . '/edit'] = array(
      'title'   => 'Edit',
      'type'    => MENU_DEFAULT_LOCAL_TASK,
      'weight'  => -10,
      'context' => MENU_CONTEXT_PAGE | MENU_CONTEXT_INLINE,
    );

    $items[$this->path . '/mp_auction/' . $wildcard . '/delete'] = array(
      'title'            => 'Delete',
      'page callback'    => 'mp_auction_delete_form_wrapper',
      'page arguments'   => array($id_count + 1),
      'access callback'  => 'mp_auction_access',
      'access arguments' => array('edit', $id_count + 1),
      'type'             => MENU_LOCAL_TASK,
      'context'          => MENU_CONTEXT_INLINE,
      'weight'           => 10,
      'file'             => 'mp_auction_mp_auction.admin.inc',
      'file path'        => drupal_get_path('module', $this->entityInfo['module']),
    );

    // Menu item for viewing mp_auctions.
    $items['mp_auction/' . $wildcard] = array(
      // 'title' => 'Title',
      'title callback'   => 'mp_auction_page_title',
      'title arguments'  => array(1),
      'page callback'    => 'mp_auction_page_view',
      'page arguments'   => array(1),
      'access callback'  => 'mp_auction_access',
      'access arguments' => array('view', 1),
      'type'             => MENU_CALLBACK,
    );

    return $items;
  }

  /**
   * Create the markup for the add MpAuction Entities page within the class
   * so it can easily be extended/overriden.
   */
  public function addPage() {
    $item = menu_get_item();
    $content = system_admin_menu_block($item);

    if (count($content) == 1) {
      $item = array_shift($content);
      drupal_goto($item['href']);
    }

    return theme('mp_auction_add_list', array('content' => $content));
  }
}

/**
 * Form callback wrapper: create or edit a mp_auction.
 *
 * @param object $mp_auction
 *   The mp_auction object being edited by this form.
 *
 * @return array
 *   Form.
 *
 * @see mp_auction_edit_form()
 */
function mp_auction_form_wrapper($mp_auction) {
  // Add the breadcrumb for the form's location.
  mp_auction_set_breadcrumb();

  return drupal_get_form('mp_auction_edit_form', $mp_auction);
}

/**
 * Form callback wrapper: delete a mp_auction.
 *
 * @param object $mp_auction
 *   The mp_auction object being edited by this form.
 *
 * @return array
 *   Form.
 *
 * @see mp_auction_edit_form()
 */
function mp_auction_delete_form_wrapper($mp_auction) {
  // Add the breadcrumb for the form's location.
  // mp_auction_set_breadcrumb();
  return drupal_get_form('mp_auction_delete_form', $mp_auction);
}

/**
 * Form callback: create or edit a mp_auction.
 *
 * @param object $mp_auction
 *   The mp_auction object to edit or for a create form an empty
 *     mp_auction object with only a mp_auction type defined.
 */
function mp_auction_edit_form($form, &$form_state, $mp_auction) {
  // Add the default field elements.
  $form['name'] = array(
    '#type'          => 'textfield',
    '#title'         => t('MP Auction Name'),
    '#default_value' => isset($mp_auction->name) ? $mp_auction->name : '',
    '#maxlength'     => 255,
    '#required'      => TRUE,
    '#weight'        => -5,
  );

  // Add the field related form elements.
  $form_state['mp_auction'] = $mp_auction;
  field_attach_form('mp_auction', $mp_auction, $form, $form_state);

  $form['actions'] = array(
    '#type'       => 'container',
    '#attributes' => array('class' => array('form-actions')),
    '#weight'     => 400,
  );

  // We add the form's #submit array to this button along with the actual submit
  // handler to preserve any submit handlers added by a form callback_wrapper.
  $submit = array();

  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions']['submit'] = array(
    '#type'   => 'submit',
    '#value'  => t('Save'),
    '#submit' => $submit + array('mp_auction_edit_form_submit'),
  );

  if (!empty($mp_auction->name)) {
    $form['actions']['delete'] = array(
      '#type'   => 'submit',
      '#value'  => t('Delete'),
      '#suffix' => l(t('Cancel'), 'admin/content/mp_auctions'),
      '#submit' => $submit + array('mp_auction_form_submit_delete'),
      '#weight' => 45,
    );
  }

  // We append the validate handler to #validate in case a form callback_wrapper
  // is used to add validate handlers earlier.
  $form['#validate'][] = 'mp_auction_edit_form_validate';

  return $form;
}

/**
 * Implements hook_form_validate().
 */
function mp_auction_edit_form_validate(&$form, &$form_state) {
  $mp_auction = $form_state['mp_auction'];

  // Notify field widgets to validate their data.
  field_attach_form_validate('mp_auction', $mp_auction, $form, $form_state);
}

/**
 * Implements hook_form_submit().
 *
 * @todo remove hard-coded link
 */
function mp_auction_edit_form_submit(&$form, &$form_state) {

  $mp_auction = entity_ui_controller('mp_auction')->entityFormSubmitBuildEntity($form, $form_state);
  // Save the mp_auction and go back to the list of mp_auctions.

  // Add in created and changed times.
  if ($mp_auction->is_new = isset($mp_auction->is_new) ? $mp_auction->is_new : 0) {
    $mp_auction->created = REQUEST_TIME;
  }

  $mp_auction->changed = REQUEST_TIME;

  $mp_auction->save();
  $form_state['redirect'] = 'admin/content/mp_auctions';
}

/**
 * Form API submit callback for the delete button.
 * @todo Remove hard-coded path
 *
 * @param array $form
 *   Form.
 * @param array $form_state
 *   Form state.
 */
function mp_auction_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/content/mp_auctions/mp_auction/' . $form_state['mp_auction']->mp_auction_id . '/delete';
}

/**
 * Form callback: confirmation form for deleting a mp_auction.
 *
 * @param object $mp_auction
 *   The mp_auction to delete
 *
 * @return array
 *   Form.
 *
 * @see confirm_form()
 */
function mp_auction_delete_form($form, &$form_state, $mp_auction) {
  $form_state['mp_auction'] = $mp_auction;

  $form['#submit'][] = 'mp_auction_delete_form_submit';

  $form = confirm_form(
    $form,
    t('Are you sure you want to delete MP Auction %name?', array('%name' => $mp_auction->name)),
    'admin/content/mp_auctions/mp_auction',
    '<p>' . t('This action cannot be undone.') . '</p>',
    t('Delete'),
    t('Cancel'),
    'confirm'
  );

  return $form;
}

/**
 * Implements hook_form_submit().
 */
function mp_auction_delete_form_submit($form, &$form_state) {
  $mp_auction = $form_state['mp_auction'];

  mp_auction_delete($mp_auction);

  drupal_set_message(t('The MP Auction %name has been deleted.', array('%name' => $mp_auction->name)));
  watchdog('mp_auction', 'Deleted MP Auction %name.', array('%name' => $mp_auction->name));

  $form_state['redirect'] = 'admin/content/mp_auctions';
}


/**
 * Page to add MpAuction Entities.
 * @todo Pass this through a proper theme function
 *
 * @return mixed
 *   Page.
 */
function mp_auction_add_page() {
  $controller = entity_ui_controller('mp_auction');

  return $controller->addPage();
}


/**
 * Displays the list of available mp_auction types for mp_auction creation.
 *
 * @ingroup themeable
 */
function theme_mp_auction_add_list($variables) {
  $content = $variables['content'];

  if ($content) {
    $output = '<dl class="mp_auction-type-list">';

    foreach ($content as $item) {
      $output .= '<dt>' . l($item['title'], $item['href']) . '</dt>';
      $output .= '<dd>' . filter_xss_admin($item['description']) . '</dd>';
    }
    $output .= '</dl>';
  }
  else {
    if (user_access('administer mp_auction types')) {
      $output = '<p>' . t(
          'MP Auction Entities cannot be added because you have not created any MP Auction types yet. Go to the <a href="@create-mp_auction-type">MP Auction type creation page</a> to add a new MP Auction type.',
          array('@create-mp_auction-type' => url('admin/structure/mp_auction_types/add'))
        ) . '</p>';
    }
    else {
      $output = '<p>' . t('No MP Auction types have been created yet for you to use.') . '</p>';
    }
  }

  return $output;
}

/**
 * Sets the breadcrumb for administrative mp_auction pages.
 */
function mp_auction_set_breadcrumb() {
  $breadcrumb = array(
    l(t('Home'), '<front>'),
    l(t('Administration'), 'admin'),
    l(t('Content'), 'admin/content'),
    l(t('MpAuctions'), 'admin/content/mp_auctions'),
  );

  drupal_set_breadcrumb($breadcrumb);
}
