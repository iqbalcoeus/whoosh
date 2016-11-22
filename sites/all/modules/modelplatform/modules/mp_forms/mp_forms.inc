<?php

define('MP_FORMS_COUNTRY_SELECTOR', '.country[name="profile_model_private_data[field_complete_address][und][0][country]"]');
define('MP_FORMS_COUNTRY_CODE', 'DE');

/**
 * Hide/display fields on the model private data profile form.
 */
function _mp_forms_model_private_data_form(&$form, &$form_state, $profile_id) {
  $active_field_names = array(
    'field_local_registration_documen',
    'field_travel_passport',
  );

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
}

/**
 * Customization of model basic information profile form.
 */
function _mp_forms_model_basic_informaiton_form(&$form, &$form_state, $profile_id) {
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