<?php

/**
 * @file
 * Model Platform - MangoPay payment form.
 */

function _get_month_select() {
  return '<select id="payment_month">
          <option value="01">01</option>
          <option value="02">02</option>
          <option value="03">03</option>
          <option value="04">04</option>
          <option value="05">05</option>
          <option value="06">06</option>
          <option value="07">07</option>
          <option value="08">08</option>
          <option value="09">09</option>
          <option value="10">10</option>
          <option value="11">11</option>
          <option value="12">12</option>
        </select>';
}

function _get_year_select() {
  $year_select = array();
  for($year = date('y'); $year < date('y') + 5; $year++) {
    $year_select[] = "<option value=\"$year\">$year</option>";
  }

  return '<select id="payment_year">' . implode('', $year_select) . '</select>';
}

function _get_card_type() {
  $types = array(
    'CB_VISA_MASTERCARD' => 'CB/Visa/MasterCard',
    'DINERS' => 'DINERS',
//    'MASTERPASS' => 'MASTERPASS',
    'MAESTRO' => 'MAESTRO',
//    'P24' => 'P24',
  );
  $select = array();
  foreach ($types as $key => $value) {
    $select[] = "<option value=\"$key\">$value</option>";
  }

  return '<select id="card_type">' . implode('', $select) . '</select>';
}

/**
 * Mangopay payment form.
 */
function mp_mangopay_payment_form($account, $order) {
  global $user;
  global $base_url;
  $uid = $user->uid;
  drupal_add_js(drupal_get_path('module', 'mp_mangopay') . '/js/card_form.js');

  $form = '';
  if ($order->status == 'job_invoice_status') {
    $order_wrapper = entity_metadata_wrapper('commerce_order', $order);
    $_SESSION['mangopay_data']['order_total'] = $order_wrapper->commerce_order_total->amount->value();
    $_SESSION['mangopay_data']['currency'] = 'EUR';

    $card = _mp_mangopay_card_registration($uid);
    $_SESSION['mangopay_data']['cardRegisterId'] = $card->Id;

    $returnUrl = $base_url . '/user/' . $account->uid . '/invoices/' . $order->order_id . '/payment';

    $form = '<form id="card_payment_form" action="' . $card->CardRegistrationURL . '" method="post">
    <input type="hidden" id="card_order" value="' . $order->order_id .'" />
    <input type="hidden" id="card_data" name="data" value="' . $card->PreregistrationData .'" />
    <input type="hidden" id="card_key" name="accessKeyRef" value="' . $card->AccessKey . '" />
    <input type="hidden" name="returnURL" value="' . $returnUrl . '" />

    <div>
      <div>
        <label>Card type</label>
      </div>
      <div>
        ' . _get_card_type() . '
      </div>
    </div>
    <div>
      <div>
        <label for="cardNumber">Card Number</label>
      </div>
      <div>
        <input type="text" required name="cardNumber" value="" />
      </div>
    </div>    

    <div>
      <div>
        <label for="cardExpirationDate">Expiration Date</label>
      </div>
      <div>'
        . _get_month_select()
        . '<span> / </span>'
        . _get_year_select()
        . '<input type="hidden" name="cardExpirationDate" value="" id="card_date" />
      </div>
    </div>

    <div>
      <div>
        <label for="cardCvx">CVV</label>
      </div>
      <div>
        <input type="password" required name="cardCvx" value="" />
      </div>
    </div>
    <br>
    <input type="submit" value="Pay" id="card_pay" />
</form>';
  }

  return $form;
}

/**
 * Payment callback.
 */
function mp_mangopay_payment_callback_form($account, $order) {
  $mangoPayApi = _mp_mangopay_api();

  $link = '/dashboard';

  if(isset(drupal_get_destination()['destination'])) {
      $link = explode('/payment',drupal_get_destination()['destination'])[0];
  }

  try {
    $cardRegister = $mangoPayApi->CardRegistrations->Get($_SESSION['mangopay_data']['cardRegisterId']);
    $cardRegister->RegistrationData = isset($_GET['data']) ? 'data=' . $_GET['data'] : 'errorCode=' . $_GET['errorCode'];
    $updatedCardRegister = $mangoPayApi->CardRegistrations->Update($cardRegister);

    if ($updatedCardRegister->Status != \MangoPay\CardRegistrationStatus::Validated || !isset($updatedCardRegister->CardId)){
        drupal_set_message(t('Cannot create card. Payment has not been created. Please try again later.'), 'error');
        drupal_goto($link);
    }

    // get created virtual card object
    $card = $mangoPayApi->Cards->Get($updatedCardRegister->CardId);

    // create temporary wallet for user
    $wallet = new \MangoPay\Wallet();
    $wallet->Owners = array( $updatedCardRegister->UserId );
    $wallet->Currency = 'EUR';
    $wallet->Description = 'Temporary wallet for payment demo';
    $createdWallet = $mangoPayApi->Wallets->Create($wallet);

    // create pay-in CARD DIRECT
    $payIn = new \MangoPay\PayIn();
    $payIn->CreditedWalletId = $createdWallet->Id;
    $payIn->AuthorId = $updatedCardRegister->UserId;
    $payIn->DebitedFunds = new \MangoPay\Money();
    $payIn->DebitedFunds->Amount = $_SESSION['mangopay_data']['order_total'];
    $payIn->DebitedFunds->Currency = $_SESSION['mangopay_data']['currency'];
    $payIn->Fees = new \MangoPay\Money();
    $payIn->Fees->Amount = 0;
    $payIn->Fees->Currency = $_SESSION['mangopay_data']['currency'];

    // payment type as CARD
    $payIn->PaymentDetails = new \MangoPay\PayInPaymentDetailsCard();
    $payIn->PaymentDetails->CardType = $card->CardType;
    $payIn->PaymentDetails->CardId = $card->Id;

    // execution type as DIRECT
    $payIn->ExecutionDetails = new \MangoPay\PayInExecutionDetailsDirect();
    $payIn->ExecutionDetails->SecureModeReturnURL = 'http://test.com';

    // create Pay-In
    $createdPayIn = $mangoPayApi->PayIns->Create($payIn);

    // if created Pay-in object has status SUCCEEDED it's mean that all is fine
    if ($createdPayIn->Status == \MangoPay\PayInStatus::Succeeded) {
      $order->status = 'completed';
      commerce_order_save($order);

      unset($_SESSION['mangopay_data']);

      $msg = 'Pay-In has been created successfully.<br>'
        . 'Pay-In Id = ' . $createdPayIn->Id .'<br>'
        . 'Wallet Id = ' . $createdWallet->Id ;

        drupal_set_message(t($msg));
        drupal_goto($link);

      $link = "/user/$account->uid/invoices/$order->order_id";
    }
    else {
      // if created Pay-in object has status different than SUCCEEDED
      // that occurred error and display error message
     $msg = 'Pay-In has been created with <br>'
        . 'status: ' . $createdPayIn->Status . ' <br> '
        . 'result code:'. $createdPayIn->ResultCode;

        drupal_set_message(t($msg),'error');
        drupal_goto($link);
    }
  } catch (\MangoPay\Libraries\ResponseException $e) {
      drupal_set_message(t($e->getMessage()),'error');
      drupal_goto($link);
  }
}
