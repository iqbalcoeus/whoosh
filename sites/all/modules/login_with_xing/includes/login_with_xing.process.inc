<?php
/**
 * Saves the user information
 * 
 * @throws Exception
 */
function login_with_xing_process_save() {
//    $parameters = $_POST;
      $parameters = drupal_get_query_parameters();

    if (!empty($parameters)) {
        $xing_candidate_info = $parameters;

        if (!empty($xing_candidate_info['id'] &&!empty($xing_candidate_info['active_email'] ))) {
            if (!try_drupal_login($xing_candidate_info['active_email'])) {
                if (variable_get('login_with_xing_login')) {
                    // Create the drupal user.
                    // This will generate a random password, you could set your own here.
                    $xing_username = (isset($xing_candidate_info['display_name']) ? $xing_candidate_info['display_name'] : $xing_candidate_info['first_name']);
                    $drupal_username_generated = login_with_xing_connect_unique_user_name($xing_username);
                    $password = user_password(8);
                    // Set up the user fields.
                    $fields = array(
                        'name' => $drupal_username_generated,
                        'mail' => $xing_candidate_info['active_email'],
                        'pass' => $password,
                        'status' => 1,
                        'init' => 'email address',
                        'roles' => array(
                            DRUPAL_AUTHENTICATED_RID => 'authenticated user',
                        ),
                    );

                    if (variable_get('user_pictures', 0)) {
                        $picture_directory = file_default_scheme() . '://' . variable_get('user_picture_path', 'pictures/');
                        file_prepare_directory($picture_directory, FILE_CREATE_DIRECTORY);
                        $file = system_retrieve_file($xing_candidate_info['photo_urls']['size_1024x1024'], $picture_directory . '/' . $xing_candidate_info['display_name'] . '.jpg', TRUE, FILE_EXISTS_RENAME);
                        if (is_object($file)) {
                            $fields['picture'] = $file->fid;
                        } else{
                            $fields['picture'] = $xing_candidate_info['img_url'];
                        }

                    }
                    drupal_alter("xing_connect_register", $fields, $xing_candidate_info);

                    // The first parameter is left blank so a new user is created.
                    $account = user_save('', $fields);
                    // If you want to send the welcome email, use the following code.
                    // Manually set the password so it appears in the e-mail.
                    $account->password = $fields['pass'];
                    // Send the e-mail through the user module.
                    drupal_mail('user', 'register_no_approval_required', $account->mail, NULL, array('account' => $account), variable_get('site_mail', 'admin@drupalsite.com'));
                    drupal_set_message(t('You have been registered with the username @username', array('@username' => $account->name)));
                    try_drupal_login($fields['mail']);
                } else {
                    drupal_set_message(t('There was no account with the email addresse @email found. Please register before trying to login.', array('@email' => $xing_candidate_info['active_email'])), 'error');
                }
            }
        } else {
            drupal_set_message(t("Though you have authorised the Xing app to access your profile, you don't have the permission to access email address. Please contact site administrator of xing."), "error");
        }
    } else {
        drupal_set_message(t('An error occurred while fetching information from Xing.'), 'error');
    }
    drupal_goto('user/login');
}

/**
 * Generates a unique username for drupal site based on XING username.
 */
function login_with_xing_connect_unique_user_name($xing_name, $i = 0) {
    $trimmed_name = '';
    $user_to_load = '';
    if ($i == 0) {
        $trimmed_name = strtolower(trim(str_replace(' ', '_', $xing_name)));
        $user_to_load = $trimmed_name;
    }
    else {
        $trimmed_name = $xing_name;
        $user_to_load = $trimmed_name . "_" . $i;
    }

    // Check if user exists by loading userbyname.
    if (is_object(user_load_by_name($user_to_load))) {
        $i++;
        return (login_with_xing_connect_unique_user_name($trimmed_name, $i));
    }
    else {
        return $user_to_load;
    }
}

/**
 * Tries to login
 *
 * @param $email
 * @return bool
 */
function try_drupal_login($email){
    $account = user_load_by_mail($email);
    if($account) {
        if ($account->status) {
            $form_state = array();
            $form_state['uid'] = $account->uid;
            user_login_submit(array(), $form_state);
            drupal_set_message(t('Welcome !!! You have been logged in with the username @username', array('@username' => $account->name)));
            drupal_goto('dashboard');
        } else {
            drupal_set_message(t('You could not be logged in as your account is blocked. Contact site administrator to activate your account.'), 'error');
            drupal_goto('user/login');
        }

        return true;
    }
    return false;
}