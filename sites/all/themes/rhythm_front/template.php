<?php

/**
 * @file
 * Rhythm - subtheme.
 */

/**
 * Implements hook_preprocess_page().
 */
function rhythm_front_preprocess_page(&$vars) {
  global $language;

  $image = variable_get('modelplatform_body_image_404_url', '');
  drupal_add_js(array(
    'rhythm_front' => array(
      'body_images' => array(
        'p404' => $image,
      ),
    ),
  ), 'setting');

  // @TODO Should be fixed in the feature.
  if ($vars['front_page']) {
    drupal_add_js(array(
      'modelplatform_theme' => array(
        'register_title' => array(
          'und' => 'To <br> register',
          'EN' => 'To <br> register',
          'DE' => 'Gleich <br> registrieren',
        ),
        'lang' => $language->language,
      )
    ), 'setting');
  }
}

/**
 * Implements hook_node_view().
 */
function rhythm_front_node_view($node, $view_mode, $langcode) {
  if ($view_mode === 'full') {
    switch ($node->type) {
      case 'news':
        $node_type_name = node_type_get_name($node->type);
        drupal_set_title($node_type_name);
        break;

      default:
        // Do nothing.
    }
  }
}

/**
 * Overrides theme_menu_local_tasks().
 */
function rhythm_front_menu_local_tasks(array $variables) {
  $output = '';

  if (!empty($variables['primary'])) {
    $variables['primary']['#prefix'] = '<h2 class="element-invisible">' . t('Primary tabs') . '</h2>';
    $variables['primary']['#prefix'] .= '<div class = "align-center mb-40 mb-xxs-30"><ul class="nav nav-tabs tpl-minimal-tabs">';
    $variables['primary']['#suffix'] = '</ul></div>';
    $output .= drupal_render($variables['primary']);
  }
  if (!empty($variables['secondary'])) {
    $variables['secondary']['#prefix'] = '<h2 class="element-invisible">' . t('Secondary tabs') . '</h2>';
    $variables['secondary']['#prefix'] .= '<div class = "align-center mb-40 mb-xxs-30"><ul class="nav nav-tabs tpl-tabs">';
    $variables['secondary']['#suffix'] = '</ul></div>';
    $output .= drupal_render($variables['secondary']);
  }

  return $output;
}

/**
 *  Overrides theme_textfield().
 */
function rhythm_front_textfield($variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = isset($element['#attributes']['type']) ? $element['#attributes']['type'] : 'text';

  element_set_attributes($element, array(
    'id',
    'name',
    'value',
    'size',
    'maxlength',
  ));
  $required = !empty($element['#required']) ? theme('form_required_marker', $variables) : '';
  $output = '<label>' . t('!title !required', array('!title' => $element['#title'], '!required' => $required)) . "</label>";
  $output .= '<div class="rhythm-input"><input' . drupal_attributes($element['#attributes']) . ' /></div>';
  $extra = '';
  if ($element['#autocomplete_path'] && drupal_valid_path($element['#autocomplete_path'])) {
    drupal_add_library('system', 'drupal.autocomplete');
    $element['#attributes']['class'][] = 'form-autocomplete';
    $attributes = array();
    $attributes['type'] = 'hidden';
    $attributes['id'] = $element['#attributes']['id'] . '-autocomplete';
    $attributes['value'] = url($element['#autocomplete_path'], array('absolute' => TRUE));
    $attributes['disabled'] = 'disabled';
    $attributes['class'][] = 'autocomplete';
    $output = '<div class="input-group">' . $output . '<span class="input-group-addon"><i class = "fa fa-refresh"></i></span></div>';
    $extra = '<input' . drupal_attributes($attributes) . ' />';
  }
  $output .= $extra;
  if(isset($element['#nd_icon'])) {
    $size_class = in_array('input-lg', $element['#attributes']['class']) ? ' pi-input-with-icon-lg' : '';
    $size_class .= in_array('input-sm', $element['#attributes']['class']) ? ' pi-input-with-icon-sm' : '';
    $output = '<div class="pi-input-with-icon' . $size_class .'"><div class="pi-input-icon"><i class="' . $element['#nd_icon'] . '"></i></div>' . $output .  '</div>';
  }
  return $output;
}

/**
 * Theme function for 'default' fivestar field formatter.
 */
function rhythm_front_fivestar_formatter_default($variables) {
  $element = $variables['element'];
  if (empty($element['#instance_settings']['stars'])) {
    $element['#instance_settings']['stars'] = 5;
  }

  // Add CSS and JS
  $path = drupal_get_path('module', 'fivestar');
  drupal_add_js($path . '/js/fivestar.js');
  drupal_add_css($path . '/css/fivestar.css');

  $variables = array(
    'rating' => $element['#rating'],
    'stars' => $element['#instance_settings']['stars'],
    'widget' => $element['#widget'],
  );

  $star_display = theme('fivestar_static', $variables);

  return $element['#rating']
    ? theme('fivestar_static_element', array('description' => $element['#description'], 'star_display' => $star_display))
    : '';
}

/**
 * Theme function to render an email component.
 */
function rhythm_front_webform_email($variables) {
  global $language ;
  $element = $variables['element'];

  // @TODO Should be fixed in the feature.
  $lang_name = $language->language;
  t($element['#attributes']['placeholder']);
  $title = $element['#attributes']['placeholder'];
  $query = db_select('locales_source', 'ls');
  $query->condition('ls.source', $title);
  $query->innerJoin('locales_target', 'lt', 'lt.lid = ls.lid');
  $query->condition('lt.language', $lang_name);
  $query->fields('lt', array('translation'));

  $new_title = $query->execute()->fetchfield();
  if (!$new_title) {
    $query = db_select('locales_target', 'lt');
    $query->condition('lt.translation', $title);
    $query->condition('lt.language', $lang_name, '!=');
    $query->innerJoin('locales_source', 'ls', 'lt.lid = ls.lid');
    $query->fields('ls', array('source'));

    $new_title = $query->execute()->fetchfield();
  }
  if ($new_title) {
    $element['#attributes']['placeholder'] = $new_title;
  }

  // This IF statement is mostly in place to allow our tests to set type="text"
  // because SimpleTest does not support type="email".
  if (!isset($element['#attributes']['type'])) {
    $element['#attributes']['type'] = 'email';
  }

  // Convert properties to attributes on the element if set.
  foreach (array('id', 'name', 'value', 'size') as $property) {
    if (isset($element['#' . $property]) && $element['#' . $property] !== '') {
      $element['#attributes'][$property] = $element['#' . $property];
    }
  }
  _form_set_class($element, array('form-text', 'form-email'));

  return '<input' . drupal_attributes($element['#attributes']) . ' />';
}

function rhythm_front_form_alter(&$form, $form_state, $form_id) {
  if ($form_id == 'views_exposed_form' && $form_state['view']->name == 'models') {
    drupal_add_js(drupal_get_path('theme', 'rhythm_front') . '/js/jquery.ui.touch-punch.min.js', 'file');
    drupal_add_js(drupal_get_path('module', 'modelplatform') . '/js/model_search.js', 'file');
    drupal_add_js(array(
      'modelplatform' => array(
        'pathname' => 'mine_search',
        'search' => modelplatform_mine_search_url($_SESSION['mine_search']),
      ),
    ), 'setting');

    $info = $form['#info'];
    $form['#info'] = array(
      'basics_title' => array(
        'value' => '<div class="basics-title">' . t('Basics') . '</div>',
        'label' => t('Basics'),
      )
    );
    $form['#info'] += $info;
    array_unshift($form['#submit'], 'modelplatform_views_exposed_form_submit');
  }
}