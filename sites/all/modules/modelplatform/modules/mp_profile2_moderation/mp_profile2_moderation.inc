<?php
/**
 * Created by PhpStorm.
 * User: cimpleo
 * Date: 22.11.16
 * Time: 16:19
 */

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

    $diff = profile2_moderation_get_revisions_diff($current_profile, $latest_profile);

    $diff_header = array(
      array('data' => t('Field'), 'width'=> '30%'),
      array('data' => t('Current'), 'width'=> '35%'),
      array('data' => t('Latest'), 'width'=> '35%')
    );
    $diff_rows = array();
    foreach ($diff as $key => $value) {
      $diff_row = array();
      $diff_row[] = '<em>' . $key . '</em>: ';
      $diff_row[] = '<span style="color:#f00">' . $value[0] . '</span>';
      $diff_row[] = '<span style="color:#0f0">' . $value[1] . '</span>';
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
  $result = db_query('
    SELECT 
      p.pid,
      MAX(r.vid) AS vid, 
      p.vid AS current_vid, 
      u.name AS username
    FROM {profile_revision} r 
    LEFT JOIN {profile} p ON p.pid = r.pid 
    INNER JOIN {users} u ON u.uid = p.uid 
    INNER JOIN {field_data_field_model_is_active} ua ON ua.field_model_is_active_value = 1 AND ua.entity_id = u.uid
    WHERE r.status = 0 AND r.vid > p.vid
    GROUP BY p.pid, p.vid, u.name
    ORDER BY r.vid DESC
    ', array());

  foreach ($result as $revision) {
    $revisions[$revision->vid] = $revision;
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
  $profile_revision = $form['#profile_revision'];
  // @TODO Save rejected vid and tid.
  $form_state['redirect'] = 'admin/people/profiles/moderation';
}