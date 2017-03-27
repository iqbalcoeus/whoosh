<?php

/**
 * @file
 * Views handler for availability.
 */

/**
 * Field handler to provide simple renderer that allows linking to a file.
 *
 * @ingroup views_handler_filter
 */
class mp_booking_handler_filter_available extends views_handler_filter_boolean_operator {

  function get_value_options() {
    // Provide a fallback if the above didn't set anything.
    if (!isset($this->value_options)) {
      $this->value_options = array(1 => t('Available'), 0 => t('Reserved'));
    }
  }

  function value_form(&$form, &$form_state) {
    if (empty($this->value_options)) {
      // Initialize the array of possible values for this filter.
      $this->get_value_options();
    }
    if (!empty($form_state['exposed'])) {
      // Exposed filter: use a select box to save space.
      $filter_form_type = 'select';
    }
    else {
      // Configuring a filter: use radios for clarity.
      $filter_form_type = 'radios';
    }
    $form['value'] = array(
      '#type' => $filter_form_type,
      '#title' => t('Choose date interval'),
      '#options' => $this->value_options,
      '#default_value' => 1,
      '#access' => FALSE,
    );
    $format = 'Y-m-d';
    $form['start_date'] = array(
      '#type' => 'date_popup',
      '#title' => t('Start date'),
      '#date_format' => $format,
      '#default_value' => isset($this->view->exposed_raw_input['start_date'])
        ? $this->view->exposed_raw_input['start_date'] : NULL,
    );
    $form['end_date'] = array(
      '#type' => 'date_popup',
      '#title' => t('End date'),
      '#date_format' => $format,
      '#default_value' => isset($this->view->exposed_raw_input['end_date'])
        ? $this->view->exposed_raw_input['end_date'] : NULL,
    );
    if (!empty($this->options['exposed'])) {
      $identifier = $this->options['expose']['identifier'];
      if (!empty($form_state['exposed']) && !isset($form_state['input'][$identifier])) {
        $form_state['input'][$identifier] = $this->value;
      }
      // If we're configuring an exposed filter, add an <Any> option.
      if (empty($form_state['exposed']) || empty($this->options['expose']['required'])) {
        $any_label = variable_get('views_exposed_filter_any_label', 'new_any') == 'old_any' ? '<Any>' : t('- Any -');
        if ($form['value']['#type'] != 'select') {
          $any_label = check_plain($any_label);
        }
        $form['value']['#options'] = array('All' => $any_label) + $form['value']['#options'];
      }
    }
  }

  function query() {
    if ($this->value) {
      // Prepare filter.
      $or = db_or();

      $start_date = $end_date = NULL;

      // Get date values.
      if (isset($this->view->exposed_raw_input['start_date'])) {
        $start_date = $this->view->exposed_raw_input['start_date'];

        $c_start_date = db_and();
        $c_start_date->condition('be.start_date', $start_date, '<=');
        $c_start_date->condition('be.end_date', $start_date, '>=');

        $or->condition($c_start_date);
      }

      if (isset($this->view->exposed_raw_input['end_date'])) {
        $end_date = $this->view->exposed_raw_input['end_date'];

        $c_end_date = db_and();
        $c_end_date->condition('be.start_date', $end_date, '<=');
        $c_end_date->condition('be.end_date', $end_date, '>=');

        $or->condition($c_end_date);
      }

      if ($start_date && $end_date) {
        $c_into_date = db_and();
        $c_into_date->condition('be.start_date', $start_date, '>=');
        $c_into_date->condition('be.end_date', $end_date, '<=');
        $or->condition($c_into_date);
      }

      if ($start_date || $end_date) {
        // Get reserved nodes.
        $not_uids_query = db_select('bat_events', 'be');
        $not_uids_query->condition($or);

        // State
        $not_uids_query->innerJoin('field_data_event_state_reference', 'es', 'es.entity_id = be.event_id');
        $not_uids_query->innerJoin('bat_event_state', 'bes', 'bes.id = es.event_state_reference_state_id');
        $not_uids_query->condition('bes.blocking', 1);

        // BAT Unit
        $not_uids_query->innerJoin('field_data_event_bat_unit_reference', 'ebu', 'ebu.entity_id = be.event_id');

        // User
        $not_uids_query->innerJoin('field_data_field_bat_unit', 'fbu', 'fbu.field_bat_unit_target_id = ebu.event_bat_unit_reference_target_id');
        $not_uids_query->addField('fbu', 'entity_id', 'uid');
        $not_uids_query->groupBy('fbu.uid');

        $not_uids = $not_uids_query->execute()->fetchCol(0);

        if (count($not_uids)) {
          // Exclude reserved nodes from the results.
          $not_uids_str = implode(',', $not_uids);
          $this->query->add_where_expression($this->options['group'], "user.uid NOT IN ($not_uids_str)");
        }
      }
    }
  }

}
