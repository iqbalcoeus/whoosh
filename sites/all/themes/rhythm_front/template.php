<?php

/**
 * @file
 * Rhythm - subtheme.
 */

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
 *  Implements theme_textfield().
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
