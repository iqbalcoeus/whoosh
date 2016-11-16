<?php

define('MP_FORMS_COUNTRY_SELECTOR', '.country[name="profile_model_private_data[field_complete_address][und][0][country]"]');
define('MP_FORMS_COUNTRY_CODE', 'DE');

function _mp_forms_model_private_data_form(&$form, &$form_state, $profile_id) {
  $hide_fields = array(
    'field_local_registration_documen',
    'field_travel_passport',
  );

  foreach ($hide_fields as $field_name) {
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