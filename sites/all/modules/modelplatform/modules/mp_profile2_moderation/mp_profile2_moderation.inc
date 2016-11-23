<?php
/**
 * Created by PhpStorm.
 * User: cimpleo
 * Date: 22.11.16
 * Time: 16:19
 */

/**
 * Get field label.
 */
function _mp_get_field_label($field_name, $entity_type, $bundle) {
  $query = db_select('field_config_instance', 'f');
  $query->condition('field_name', $field_name);
  $query->condition('entity_type', $entity_type);
  $query->condition('bundle', $bundle);
  $query->fields('f');
  $query = $query->execute()->fetch();
  $result = unserialize($query->data);

  return $result['label'];
}

/**
 * Get Profile2 revision diff.
 */
function _mp_profile2_moderation_get_revisions_diff($profile1, $profile2) {
  $value_handlers = array(
    'value' => '_profile2_moderation_get_value',
    'fid' => '_profile2_moderation_get_file_uri',
    'tid' => '_profile2_moderation_get_term_name',
  );
  $properties = get_object_vars($profile1);
  $result = array();
  foreach ($properties as $key => $value) {
    if ($profile2->{$key} != $value) {
      $_key = _mp_get_field_label($key, 'profile2', $profile1->type);
      foreach ($value_handlers as $value_name => $function) {
        // Just fields please.
        if (isset($value[LANGUAGE_NONE][0][$value_name]) || isset($profile2->{$key}[LANGUAGE_NONE][0][$value_name])) {
          $result[$_key] = array();

          if (isset($value[LANGUAGE_NONE][0][$value_name])) {
            $_value = $value[LANGUAGE_NONE][0][$value_name];
            $result[$_key][] = $function($_value);
          }
          else {
            $result[$_key][] = "'" . t('Empty') . "'";
          }

          if (isset($profile2->{$key}[LANGUAGE_NONE][0][$value_name])) {
            $_value = $profile2->{$key}[LANGUAGE_NONE][0][$value_name];
            $result[$_key][] = $function($_value);
          }
          else {
            $result[$_key][] = "'" . t('Empty') . "'";
          }
        }
      }
    }
  }

  return $result;
}

/**
 * Profile2 moderation page.
 */
function _mp_profile2_moderation_page() {
  $header = array(
    array('data' => t('User'), 'width'=> '10%'),
    array('data' => t('Current revision'), 'width'=> '5%'),
    array('data' => t('Latest revision to moderate'), 'width'=> '5%'),
    array('data' => t('Difference'), 'width'=> '60%'),
    array('data' => t('Operations'), 'colspan' => 2, 'width' => '20%'),
  );
  $revisions = _mp_profile2_moderation_unmoderate_revision_list();
  $rows = array();

  $reject_permission = FALSE;
  if ((user_access('reject profile revisions') || user_access('administer profiles')) ) {
    $reject_permission = TRUE;
  }

  foreach ($revisions as $revision) {
    $row = array();
    $operations = array();

    $row[] = $revision->username;
    $row[] = $revision->current_vid;
    $row[] = $revision->vid;

    $current_profile = profile2_load($revision->pid);
    $latest_profile = profile2_load($revision->pid, $revision->vid);

    $diff = _mp_profile2_moderation_get_revisions_diff($current_profile, $latest_profile);

    $diff_header = array(
      array('data' => t('Field'), 'width'=> '30%'),
      array('data' => t('Current'), 'width'=> '35%'),
      array('data' => t('Latest'), 'width'=> '35%')
    );
    $diff_rows = array();
    foreach ($diff as $key => $value) {
      $diff_row = array();
      $diff_row[] = '<em>' . $key . '</em>: ';
      $diff_row[] = '<span><b>' . $value[0] . '</b></span>';
      $diff_row[] = '<span>' . $value[1] . '</span>';
      $diff_rows[] = $diff_row;
    }

    $row[] = theme_table(array(
      'header' => $diff_header,
      'rows' => $diff_rows,
      'attributes' => array(),
      'caption' => NULL,
      'colgroups' => NULL,
      'sticky' => FALSE,
      'empty' => FALSE,
    ));

    // Moderate link.
    $operations[] = l(t('Apply latest'), "admin/profile/$revision->pid/revisions/$revision->vid/moderate");

    // Reject link.
    if ($reject_permission) {
      $operations[] = l(t('Reject'), "admin/profile/$revision->pid/revisions/$revision->vid/reject");
    } else {
      $operations[] = '-';
    }

    $rows[] = array_merge($row, $operations);
  }

  $build = array();
  if (count($rows) > 0) {
    $build['profile2_moderation_revisions_moderation_table'] = array(
      '#theme' => 'table',
      '#rows' => $rows,
      '#header' => $header,
    );
  } else {
    $build['profile2_moderation_no_revisions_found'] = array(
      '#markup' => '<p>' . t('No revisions to moderate.') . '</p>',
    );
  }

  return $build;
}

/**
 * Return a list of all the existing revision numbers for active models.
 */
function _mp_profile2_moderation_unmoderate_revision_list() {
  $revisions = array();

  $qrejected = db_select('pfile2_field_rejects', 'rj');
  $qrejected->fields('rj', array('pid', 'vid'));
  $rejected = $qrejected->execute()->fetchAll();

  $qrev = db_select('profile_revision', 'pr');
  $qrev->condition('pr.status', 0);
  $qrev->innerJoin('profile', 'p', 'p.pid = pr.pid AND p.vid < pr.vid');
  $qrev->innerJoin('users', 'u', 'u.uid = p.uid');
  $qrev->innerJoin('field_data_field_model_is_active', 'ma', 'ma.field_model_is_active_value = 1 AND ma.entity_id = u.uid AND ma.entity_type = \'user\'');
  $qrev->groupBy('p.pid');
  $qrev->groupBy('p.vid');
  $qrev->groupBy('u.name');
  $qrev->addField('p', 'pid', 'pid');
  $qrev->addExpression('MAX(pr.vid)', 'vid');
  $qrev->addField('p', 'vid', 'current_vid');
  $qrev->addField('u', 'name', 'username');
  $qrev->orderBy('pr.vid', 'DESC');
  $result = $qrev->execute()->fetchAll();

  // Ignore rejected rows.
  foreach ($result as $revision) {
    $flag = TRUE;
    foreach ($rejected as $reject) {
      if ($reject->pid == $revision->pid && $reject->vid == $revision->vid) {
        $flag = FALSE;
      }
    }
    if ($flag) {
      $revisions[$revision->vid] = $revision;
    }
  }

  return $revisions;
}

/**
 * Reject confirmation page.
 */
function profile2_moderation_revision_reject_confirm($form, $form_state, $profile_revision) {
  $form['#profile_revision'] = $profile_revision;
  return confirm_form($form, t('Are you sure you want to reject the revision?'), 'admin/profile/moderation', t('This action cannot be undone.'), t('Apply'), t('Cancel'));
}

/**
 * Reject confirmation form submit.
 */
function profile2_moderation_revision_reject_confirm_submit($form, &$form_state) {
  global $user;

  // Save rejected revision.
  $profile_revision = $form['#profile_revision'];
  db_merge('pfile2_field_rejects')
    ->key(array(
      'pid' => $profile_revision->pid,
    ))
    ->fields(array(
      'pid' => $profile_revision->pid,
      'vid' => $profile_revision->vid,
      'uid' => $user->uid,
    ))
    ->execute();

  // Add redirect to the profile revision moderation page.
  $form_state['redirect'] = 'admin/people/profiles/moderation';
}