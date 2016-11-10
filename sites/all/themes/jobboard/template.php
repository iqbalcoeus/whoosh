<?php

/**
 * @file
 * template.php
 */

function jobboard_preprocess_page(&$variables) {
  if(arg(0) == 'taxonomy' && arg(1) == 'term') {
        $tid = (int)arg(2);
        $term = taxonomy_term_load($tid);
        if(is_object($term)) {
           $variables['theme_hook_suggestions'][] = 'page__taxonomy__'.$term->vocabulary_machine_name;
        }
  }
  if (isset($variables['node']->type)) {
    $variables['theme_hook_suggestions'][] = 'page__' . $variables['node']->type;
  }
}


function jobboard_form_alter(&$form, &$form_state, $form_id) {
  if (strpos($form_id, 'commerce_cart_add_to_cart_form') !== FALSE) {
    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Buy now!'),
    );
  }
  else {
    switch ($form_id) {
      case 'user_register_form':
        $form['actions']['submit']['#value'] = t('Sign up');
        $form['terms'] = array(
          '#type' => 'checkbox',
          '#title' => t('I confirm the Terms of Use'),
        );
        break;
    }
  }
}

