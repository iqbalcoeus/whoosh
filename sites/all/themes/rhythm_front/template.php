<?php

/**
 * Overrides theme_menu_local_tasks().
 */
function rhythm_menu_local_tasks(array $variables) {
  $output = '';

  if (!empty($variables['primary'])) {
    $variables['primary']['#prefix'] = '<h2 class="element-invisible">' . t('Primary tabs') . '</h2>';
    $variables['primary']['#prefix'] .= '<div class = "align-center mb-40 mb-xxs-30"><ul class="nav nav-tabs tpl-tabs">';
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