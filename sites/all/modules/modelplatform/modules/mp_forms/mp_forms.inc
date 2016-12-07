<?php

define('MP_FORMS_COUNTRY_SELECTOR', '.country[name="profile_model_private_data[field_complete_address][und][0][country]"]');
define('MP_FORMS_COUNTRY_CODE', 'DE');

/**
 * Hide/display fields on the model private data profile form.
 */
function _mp_forms_model_private_data_form(&$form, &$form_state, $profile_id) {
  $active_field_names = _mp_forms_get_changed_fields();

  foreach ($active_field_names as $field_name) {
    $form[$profile_id][$field_name]['#states'] = array(
      'visible' => array(
        array(
          MP_FORMS_COUNTRY_SELECTOR => array(
            '!value' => MP_FORMS_COUNTRY_CODE,
          ),
        ),
      ),
      'invisible' => array(
        array(
          MP_FORMS_COUNTRY_SELECTOR => array(
            'value' => MP_FORMS_COUNTRY_CODE,
          ),
        ),
      ),
      'required' => array(
        array(
          MP_FORMS_COUNTRY_SELECTOR => array(
            '!value' => MP_FORMS_COUNTRY_CODE,
          ),
        ),
      ),
      'unrequired' => array(
        array(
          MP_FORMS_COUNTRY_SELECTOR => array(
            'value' => MP_FORMS_COUNTRY_CODE,
          ),
        ),
      ),
    );
  }

  $form['#validate'][] = '_mp_forms_model_private_data_form_validate';
}

/**
 * Validation.
 *
 * @see _mp_forms_model_private_data_form()
 */
function _mp_forms_model_private_data_form_validate($form, &$form_state) {
  $active_field_names = _mp_forms_get_changed_fields();
  $profile_id = 'profile_' . $form_state['build_info']['args'][1];

  $values = &$form_state['values'][$profile_id];
  $country = $values['field_complete_address'][LANGUAGE_NONE][0]['country'];
  if ($country !== MP_FORMS_COUNTRY_CODE) {
    foreach ($active_field_names as $field_name) {
      if (!$values[$field_name][LANGUAGE_NONE][0]['fid']) {
        $title = $form[$profile_id][$field_name]['und'][0]['#title'];
        $message = t('Please upload @title', array('@title' => $title));
        form_set_error($field_name, $message);
      }
    }
  }

  $model_agency_terms = $values['field_model_agensy_terms_of_use'][LANGUAGE_NONE][0]['value'];
  $model_agency = $values['field_model_agency'][LANGUAGE_NONE][0]['value'];
  if ($model_agency) {
    if (!$model_agency_terms) {
      $title = $form[$profile_id]['field_model_agensy_terms_of_use'][LANGUAGE_NONE]['#title'];
      $message = t('You should accept !title', array('!title' => $title));
      form_set_error('field_model_agensy_terms_of_use', $message);
    }
  }
  else {
    $values['field_model_agensy_terms_of_use'][LANGUAGE_NONE][0]['value'] = $model_agency;
  }
}

/**
 * Get required documents for non german citizens.
 */
function _mp_forms_get_changed_fields() {
  return array(
    'field_local_registration_documen',
    'field_travel_passport',
  );
}

/**
 * Customization of model basic information profile form.
 */
function _mp_forms_model_basic_informaiton_form(&$form, &$form_state, $profile_id) {
  drupal_add_library('system', 'ui.widget');
  drupal_add_library('system', 'ui.mouse');
  drupal_add_library('system', 'ui.slider');
  $form['#attached']['js'] = array(
    drupal_get_path('module', 'mp_forms') . '/js/mp_forms.js',
  );

  // Sliders fields.
  $slider_fields = array(
    'field_height',
    'field_waist',
    'field_chest',
    'field_hip',
  );

  // Prepare sliders
  $sliders = array();
  foreach ($slider_fields as $field_name) {
    $field_instance = field_info_instance('profile2', $field_name, $form['#user_category']);
    $field_settings = $field_instance['settings'];
    $selector = '#'
      . str_replace('_', '-', 'edit-' . $profile_id . '-' . $field_name)
      . ' .rhythm-input';
    $sliders[$field_name] = array(
      'selector' => $selector,
      'min' => $field_settings['min'],
      'max' => $field_settings['max'],
    );
  }
  drupal_add_js(array('mp_forms' => array('sliders' => $sliders)), 'setting');

  $form[$profile_id]['field_verification_status']['#disabled'] = TRUE;
  $form[$profile_id]['field_age_category']['#access'] = FALSE;
  $form['#submit'][] = '_mp_forms_model_basic_informaiton_form_submit';
}

/**
 * .
 */
function _mp_forms_model_basic_informaiton_form_submit($form, &$form_state) {
  _modelplatform_update_model_age_category($form['#user']);
}