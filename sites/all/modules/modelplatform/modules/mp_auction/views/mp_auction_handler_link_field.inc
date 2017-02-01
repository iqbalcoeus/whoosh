<?php

/**
 * @file
 * Contains a Views field handler to take care of displaying links to entities
 * as fields.
 */

/**
 * Class mp_auction_handler_link_field
 */
class mp_auction_handler_link_field extends views_handler_field {
  /**
   * Constructor.
   */
  public function construct() {
    parent::construct();

    $this->additional_fields['mp_auction_id'] = 'mp_auction_id';
    $this->additional_fields['type'] = 'type';
  }

  /**
   * Get option definition.
   *
   * @return array
   *   Definition.
   */
  public function option_definition() {
    $options = parent::option_definition();

    $options['text'] = array('default' => '', 'translatable' => TRUE);

    return $options;
  }

  /**
   * Update form field.
   *
   * @param array $form
   *   Form.
   * @param array $form_state
   *   Form state.
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $form['text'] = array(
      '#type'          => 'textfield',
      '#title'         => t('Text to display'),
      '#default_value' => $this->options['text'],
    );
  }

  /**
   * Update query.
   */
  public function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
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
    $text = !empty($this->options['text']) ? $this->options['text'] : t('view');
    $mp_auction_id = $values->{$this->aliases['mp_auction_id']};

    return l($text, 'mp_auction/' . $mp_auction_id);
  }
}
