<?php

define('MP_FORMS_COUNTRY_SELECTOR', '.country[name="profile_model_private_data[field_complete_address][und][0][country]"]');
define('MP_FORMS_COUNTRY_CODE', 'DE');

/**
 * Hide/display fields on the model private data profile form.
 */
function _mp_forms_model_private_data_form(&$form, &$form_state, $profile_id) {
  $active_field_names = _mp_forms_get_changed_fields();

  foreach ($active_field_names['model'] as $field_name) {
    if (!isset($form[$profile_id][$field_name])) {
      continue;
    }
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

  $title_suffix = "";
  if ($fid = variable_get('parental_approval_for_minors', '')) {
    $file = file_load($fid);
    if (isset($file->uri)) {
      $url = file_create_url($file->uri);
      $title_suffix = ' (' . l(t('Example'), $url) . ')';
    }
  }
  $form[$profile_id]['field_parental_approval_for_mino'][LANGUAGE_NONE][0]['#title'] .= $title_suffix;
  $form['#validate'][] = '_mp_forms_model_private_data_form_validate';
  $form['#submit'][] = '_mp_forms_model_private_data_form_submit';
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
    foreach ($active_field_names['model'] as $field_name) {
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

  if (isset($values['field_income_tax_id'][LANGUAGE_NONE][0]['value']) && $values['field_income_tax_id'][LANGUAGE_NONE][0]['value']) {
    if (!is_numeric($values['field_income_tax_id'][LANGUAGE_NONE][0]['value'])) {
      $title = $form[$profile_id]['field_income_tax_id'][LANGUAGE_NONE]['#title'];
      $message = t('!title must be numeric', array('!title' => $title));
      form_set_error('field_income_tax_id', $message);
    }
  }
}

/**
 * Form submit.
 *
 * @see _mp_forms_model_private_data_form()
 */
function _mp_forms_model_private_data_form_submit($form, $form_state) {
  if (isset($form['#user']->uid)) {
    $profile = profile2_load_by_user($form['#user']);

    if (isset($profile['model_private_data'])) {
      foreach ($form_state['values']['profile_model_private_data'] as $field_name => $value) {
        if (isset($value[LANGUAGE_NONE][0]['fid']) && $value[LANGUAGE_NONE][0]['fid']) {
          $fid = $value[LANGUAGE_NONE][0]['fid'];
          if ($file = file_load($fid)) {
            $file->status = FILE_STATUS_PERMANENT;
            $file->display = 1;
            $file->description = '';
            file_save($file);
            $profile['model_private_data']->{$field_name}[LANGUAGE_NONE][0] = (array) $file;
          }
        }
        elseif ($field_name === 'field_c_base_city') {
          $profile['model_private_data']->{$field_name} = $value;
        }
      }
      profile2_save($profile['model_private_data']);
    }
  }
}

/**
 * Get required documents for non german citizens.
 */
function _mp_forms_get_changed_fields() {
  return array(
    'model' => array(
      'field_local_registration_documen',
      'field_travel_passport',
    ),
    'customer' => array(
      'field_tax_number',
      'field_vat_id',
      'field_commercial_registry_number',
    )
  );
}

/**
 * Customization of model basic information profile form.
 */
function _mp_forms_model_basic_informaiton_form(&$form, &$form_state, $profile_id) {
  global $user;

  drupal_add_library('system', 'ui.widget');
  drupal_add_library('system', 'ui.mouse');
  drupal_add_library('system', 'ui.slider');

  drupal_add_js(drupal_get_path('module', 'mp_forms') . '/js/mp_forms.js');

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
      'name' => $field_name,
      'min' => $field_settings['min'],
      'max' => $field_settings['max'],
    );
  }
  drupal_add_js(array(
    'mp_forms' => array(
      'sliders' => $sliders
    ),
  ), 'setting');

  $form[$profile_id]['field_verification_status']['#disabled'] = !isset($user->roles[3]);
  $form[$profile_id]['field_age_category']['#access'] = FALSE;
}

/**
 * Get required fields for customer private data.
 */
function _mp_forms_customer_private_data_form(&$form, &$form_state, $profile_id) {
  global $user;

  $active_field_names = _mp_forms_get_changed_fields();

  foreach ($active_field_names['customer'] as $field_name) {
    if (!isset($form[$profile_id][$field_name])) {
      continue;
    }
    $selector = '.country[name="profile_customer_private_data[field_complete_address][und][0][country]"]';
    $form[$profile_id][$field_name]['#states'] = array(
      'required' => array(
        array(
          $selector => array(
            'value' => MP_FORMS_COUNTRY_CODE,
          ),
        ),
      ),
      'unrequired' => array(
        array(
          $selector => array(
            '!value' => MP_FORMS_COUNTRY_CODE,
          ),
        ),
      ),
    );
  }

  $disabled = FALSE;
  if (isset($form['#user']->uid)) {
    $disabled = !($user->uid == $form['#user']->uid);
  }

  $form[$profile_id]['field_commercial_registry_number']['#disabled'] = $disabled;
  $form[$profile_id]['field_payment_method_credit_card']['#disabled'] = $disabled;
  $form[$profile_id]['field_vat_id']['#disabled'] = $disabled;

  $form['#validate'][] = '_mp_forms_customer_private_data_form_validate';
}

/**
 * Validation.
 *
 * @see _mp_forms_customer_private_data_form()
 */
function _mp_forms_customer_private_data_form_validate(&$form, &$form_state) {
  $active_field_names = _mp_forms_get_changed_fields();
  $profile_id = 'profile_' . $form_state['build_info']['args'][1];

  $values = $form_state['values'][$profile_id];
  $country = $values['field_complete_address'][LANGUAGE_NONE][0]['country'];
  if ($country == MP_FORMS_COUNTRY_CODE) {
    foreach ($active_field_names['customer'] as $field_name) {
      if (!isset($form[$profile_id][$field_name])) {
        continue;
      }
      if (!isset($values[$field_name][LANGUAGE_NONE][0]['value'])
      || !$values[$field_name][LANGUAGE_NONE][0]['value']) {
        if (isset($form[$profile_id][$field_name][LANGUAGE_NONE]['#title'])) {
          $title = $form[$profile_id][$field_name][LANGUAGE_NONE]['#title'];
        }
        else {
          $title = $form[$profile_id][$field_name]['#title'];
        }
        $message = t('Please enter @title', array('@title' => $title));
        $field_error = $profile_id . '][' . $field_name;
        form_set_error($field_error, $message);
      }
    }
  }
}

/**
 * Change user_profile_form.
 */
function _mp_forms_user_profile_form($form) {
  global $user;

  if (isset($form['field_model_is_active'])) {
    $access = in_array(MODELPLATFORM_MODEL_ROLE_NAME, $form['#user']->roles);
    $access = $access && user_access('modelplatform administer models');
    $form['field_model_is_active']['#access'] = $access;
    $form['field_bat_unit']['#access'] = $access && ($user->uid == 1);
    $form['field_front_page']['#access'] = $access;
    $form['field_front_page_image']['#access'] = $access;
    $form['field_front_page_logo']['#access'] = $access;
    $form['field_front_page_text']['#access'] = $access;
    $form['field_front_page_slider']['#access'] = $access;
    $form['field_full_name']['#access'] = $access;
    $form['field_rating']['#access'] = FALSE;
    $form['field_company_name']['#access'] = FALSE;

    $is_model = in_array(MODELPLATFORM_MODEL_ROLE_NAME, $form['#user']->roles);
    $form['field_small_business']['#access'] = $is_model;
    $form['picture']['#access'] = !$is_model || ($access);
  }
  if (isset($form['#user']->roles[MODELPLATFORM_ROLE_CUSTOMER])) {
//    $form['picture']['#title'] = t('Logo');
    $form['field_company_name']['#access'] = TRUE;
    $form['picture']['picture_upload']['#description'] = t('Your virtual face or logo. Pictures larger than @dimensions pixels will be scaled down.', array('@dimensions' => variable_get('user_picture_dimensions', '85x85'))) . ' ' . filter_xss_admin(variable_get('user_picture_guidelines', ''));
  }

  return $form;
}

/**
 * Change user_pass_reset form.
 */
function _mp_forms_user_pass_reset_form($form) {
  if (isset($form['message']['#markup'])) {
    drupal_set_title(t('One-time login'));
    $message = t('<p>Click on this button to log in to the site.</p>');
    $form['message']['#markup'] = $message;
  }

  return $form;
}

function _mp_forms_job_node_form($form) {
  global $user;

  if (!_modelplatform_job_creation_access($user)) {
    // drupal_set_message(t('Please enter mandatory data before creating a job.'), 'warning');
    drupal_set_message(t('Tax number, VAT ID and Commercial registry number fields required to create a job.'), 'warning');
    drupal_goto("user/$user->uid/edit/customer_private_data");
  }
  $get_params = drupal_get_query_parameters();

  if (isset($get_params['parent_job'])) {
    $parent_job = node_load($get_params['parent_job']);
    if (isset($parent_job->nid)
      && ($parent_job->type == 'job' || $parent_job->type == 'job_template')
      && ($parent_job->uid == $user->uid)) {
      $new_job = modelplatform_job_clone($parent_job);

      $fields = array(
        'body',
        'field_job_daily_rate_from',
        'field_job_daily_rate_to',
        'field_job_start_date',
        'field_job_travel_budget',
        'field_job_additional_documents',
      );
      $form['#node'] = $new_job;
      $form['title']['#default_value'] = $parent_job->title;

      foreach ($fields as $field_name) {
        foreach (array('und', 'en', 'de') as $lang) {
          foreach ($parent_job->{$field_name}[$lang] as $key => $item) {
            switch ($field_name) {
              case 'field_job_daily_rate_from':
              case 'field_job_daily_rate_to':
              case 'field_job_travel_budget':
                $form[$field_name][LANGUAGE_NONE][$key]['amount']['#default_value'] = $item['amount'] / 100;
                break;

              case 'body':
                $form[$field_name][LANGUAGE_NONE][$key]['#default_value'] = $item['value'];
                break;

              case 'field_job_start_date':
                $form[$field_name][LANGUAGE_NONE][$key]['#default_value'] = $item;
                break;

              default:
                // Nothing to do.
            }
          }
        }
      }
    }
  }

  $job = $form['#node'];
  if (isset($job->nid)
    && ($user->uid === $job->uid || user_access('edit any job content'))) {
    $field_job_status = field_get_items('node', $job, 'field_job_status');
    if (isset($field_job_status[0]['tid'])
      && $field_job_status[0]['tid'] == MODELPLATFORM_JOB_STATUS_DRAFTED) {
      $form['actions']['template'] = array(
        '#type' => 'submit',
        '#value' => t('Save as Job template'),
        '#submit' => array(
          '_mp_forms_job_node_form_template',
        ),
      );
    }
  }
  $disabled = _modelplatform_job_is_confirmed($job->nid);
  if ($disabled) {
    drupal_set_message(t('Model was confirmed for this job. Some fields are disabled.'), 'info');
  }

  $form['field_job_start_date']['#disabled'] = $disabled;
  $form['field_job_status']['#disabled'] = $disabled;
  $form['field_job_daily_rate_from']['#disabled'] = $disabled;
  $form['field_job_daily_rate_to']['#disabled'] = $disabled;
  $form['actions']['delete']['#access'] = !$disabled;

  $form['actions']['submit']['#submit'][] = '_mp_forms_job_node_form_submit';
  $form['#validate'][] = '_mp_forms_job_node_form_validate';

  return $form;
}

function _mp_forms_job_template_node_form($form) {
  global $user;

  if (isset($form['#node']->nid)
    && ($user->uid === $form['#node']->uid || user_access('edit any job content'))) {
    $form['actions']['clone'] = array(
      '#type' => 'submit',
      '#value' => t('Duplicate Job'),
      '#submit' => array(
        '_mp_forms_job_node_form_clone',
      ),
    );
  }

  return $form;
}

function _mp_forms_user_login_form($form) {
  if (variable_get("autoassignrole_user_active", 0)
    && !user_access('administer users')
    && !autoassignrole_get_active_path_rid()) {

    // Get a list of valid roles that can be selected.
    $roles = array_intersect_key(user_roles(TRUE), array_filter(variable_get('autoassignrole_user_roles', array())));

    if ($roles) {
      $form['autoassignrole_user'] = array(
        '#type' => 'fieldset',
        '#title' => filter_xss(variable_get('autoassignrole_user_fieldset_title', t('User Roles'))),
        '#collapsible' => FALSE,
        '#collapsed' => FALSE,
      );

      // Sort the roles.
      if (variable_get('autoassignrole_user_sort', 'SORT_ASC') == 'SORT_ASC') {
        asort($roles);
      }
      elseif (variable_get('autoassignrole_user_sort', 'SORT_DESC') == 'SORT_DESC') {
        arsort($roles);
      }
      else {
        drupal_sort_weight($roles, $roles);
      }

      $multiple = variable_get('autoassignrole_user_multiple', 0);
      $user_selection = variable_get('autoassignrole_user_selection', AUTOASSIGNROLE_ELEMENT_RADIO_CHECKBOX);

      $type = 'select';
      if ($user_selection == AUTOASSIGNROLE_ELEMENT_RADIO_CHECKBOX) {
        $type = $user_selection == AUTOASSIGNROLE_ELEMENT_RADIO_CHECKBOX && !$multiple ? 'radios' : 'checkboxes';
      }

      // If not multiple + not required + select box, need a none selection.
      if (!$multiple && !variable_get('autoassignrole_user_required', 0) && $type == 'select') {
        $roles = array(0 => t('None')) + $roles;
      }

      // Set the user description filter format.
      $autoassignrole_user_description = _autoassignrole_get_user_description();

      // Add in the element.
      $form['autoassignrole_user']['user_roles'] = array(
        '#type' => $type,
        '#title' => filter_xss(variable_get('autoassignrole_user_title', t('Role'))),
        '#options' => $roles,
        '#description' => filter_xss_admin($autoassignrole_user_description['value']),
        '#required' => variable_get('autoassignrole_user_required', 0),
        '#multiple' => $multiple,
      );
    }
  }

  $form['#attached']['js'] = array(
    array(
      'data' => array(
        'mp_forms' => array(
          'model' => 5,
          'customer' => 4,
        ),
      ),
      'type' => 'setting',
    ),
    array(
      'data' => drupal_get_path('module', 'mp_forms') . '/js/mp_forms.js',
    ),
  );
   $form['autoassignrole_user']['#weight'] = -1;

  return $form;
}

function _mp_forms_job_node_form_clone($form, &$form_state) {
  if (isset($form['#node']->nid)) {
    $form_state['redirect'] = array(
      'node/add/job',
      array(
        'query' => array(
          'parent_job' => $form['#node']->nid,
        ),
      ),
    );
  }
}

function _mp_forms_job_node_form_validate($form, &$form_state) {
  $min = $max = 0;
  if (isset($form_state['values']['field_job_daily_rate_from'][LANGUAGE_NONE][0]['value'])) {
    $min = $form_state['values']['field_job_daily_rate_from'][LANGUAGE_NONE][0]['value'];
  }
  if (isset($form_state['values']['field_job_daily_rate_to'][LANGUAGE_NONE][0]['value'])) {
    $max = $form_state['values']['field_job_daily_rate_to'][LANGUAGE_NONE][0]['value'];
  }
  if ($min > $max) {
    form_set_error('field_job_daily_rate_to', t('Daily payment rate to should be more then Daily payment rate from'));
  }
}

function _mp_forms_job_node_form_submit($form, &$form_state) {
  // @TODO remove it has no custom submit action.
}

function _mp_forms_job_node_form_template($form, &$form_state) {
  $job = $form['#node'];
  $job->type = 'job_template';
  $job->created = REQUEST_TIME;
  $job->changed = REQUEST_TIME;
  $job->nid = $job->vid = NULL;

  $job_template_wrapper = entity_metadata_wrapper('node', $job);
  $job_template_wrapper->field_job_status = MODELPLATFORM_JOB_STATUS_CREATED;
  $job_template_wrapper->save();
}

function _mp_forms_model_additional_informaiton_form(&$form, &$form_state, $profile_id) {
  drupal_add_js(drupal_get_path('module', 'mp_forms') . '/js/additional_info.js');
}
