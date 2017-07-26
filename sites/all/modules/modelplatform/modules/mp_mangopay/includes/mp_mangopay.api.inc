<?php

/**
 * @file
 * Model Platform - MangoPay API functions.
 */

/**
 * Get MagoPay API object.
 */
function _mp_mangopay_api() {
  require_once libraries_get_path('mango_pay') . '/vendor/autoload.php';

  $api = new MangoPay\MangoPayApi();
  $api->Config->ClientId = variable_get('mp_mangopay_client_id', '');
  $api->Config->ClientPassword = variable_get('mp_mangopay_client_pass', '');
  $api->Config->TemporaryFolder = variable_get('mp_mangopay_tmp_folder', '/tmp');
  $api->Config->DebugMode = FALSE;

  return $api;
}

/**
 * Create MangoPay natural user.
 */
function _mp_mangopay_create_natural_user($customer_uid) {
  $api = _mp_mangopay_api();

  $customer = user_load($customer_uid);
  $customer_wrapper = entity_metadata_wrapper('user', $customer);
  $customer_private_data = profile2_load_by_user($customer, 'customer_private_data');
  $customer_private_data_wrapper = entity_metadata_wrapper('profile2', $customer_private_data);

  $UserNatural = new \MangoPay\UserNatural();
  $UserNatural->Tag = "Customer #$customer_uid";
  $UserNatural->FirstName = $customer_wrapper->field_first_name->value();
  $UserNatural->LastName = $customer_wrapper->field_last_name->value();

  $UserNatural->Address = new \MangoPay\Address();
  $UserNatural->Address->AddressLine1 = $customer_private_data_wrapper->field_model_street->value() . ' '
    . $customer_private_data_wrapper->field_model_house->value() . ', '
    . $customer_private_data_wrapper->field_model_apartment->value();
  $UserNatural->Address->City = $customer_private_data_wrapper->field_complete_address->locality->value();
  $UserNatural->Address->PostalCode = $customer_private_data_wrapper->field_model_postal_code->value();
  $UserNatural->Address->Country = $customer_private_data_wrapper->field_complete_address->country->value();
  $UserNatural->Address->Region = $customer_private_data_wrapper->field_complete_address->administrative_area->value();

  $UserNatural->Birthday = 1163496101;
  $UserNatural->Nationality = $UserNatural->Address->Country;
  $UserNatural->CountryOfResidence = $UserNatural->Address->Country;
  $UserNatural->Occupation = "Model Platform Customer";
  $UserNatural->IncomeRange = 2;
  $UserNatural->Email = $customer->mail;

  try {
    $new_user_natural = $api->Users->Create($UserNatural);
    _mp_mangopay_db_mp_mangopay_users_insert($customer_uid, $new_user_natural->Id);
  } catch(MangoPay\Libraries\ResponseException $e) {
    watchdog('error', '<div style="color: red;">'
      .'\MangoPay\ResponseException: Code: '
      . $e->getCode() . '<br/>Message: ' . $e->getMessage()
      .'<br/><br/>Details: ' . '<pre>' . print_r($e->GetErrorDetails()) . '</pre>'
    .'</div>');
  } catch(MangoPay\Libraries\Exception $e) {

  }

  return $new_user_natural;
}

/**
 * MangoPay card registration.
 */
function _mp_mangopay_card_registration($uid) {
  $api = _mp_mangopay_api();

  _mp_mangopay_include_db_mp_mangopay_users();
  $mangopay_user_data = _mp_mangopay_db_mp_mangopay_users_get_row_values($uid, 'uid');
  if (!$mangopay_user_data) {
    _mp_mangopay_create_natural_user($uid);
    $mangopay_user_data = _mp_mangopay_db_mp_mangopay_users_get_row_values($uid, 'uid');
  }
  $new_card_number = $mangopay_user_data->last_card_num + 1;
  $mangopay_user_id = $mangopay_user_data->mangopay_user_id;

  $CardRegistration = new \MangoPay\CardRegistration();
  $CardRegistration->Tag = "Customer #$uid - Card #$new_card_number";
  $CardRegistration->UserId = $mangopay_user_id;
  $CardRegistration->Currency = "EUR";
  $CardRegistration->CardType = "CB_VISA_MASTERCARD";

  $new_card = $api->CardRegistrations->Create($CardRegistration);
  _mp_mangopay_db_mp_mangopay_users_update($uid, array('last_card_num' => $new_card_number));

  _mp_mangopay_include_db_mp_mangopay_cards();
  _mp_mangopay_db_mp_mangopay_cards_insert($uid, $mangopay_user_id, $new_card->Id, $new_card_number);

  return $new_card;
}
