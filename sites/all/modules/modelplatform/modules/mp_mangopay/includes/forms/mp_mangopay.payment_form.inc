<?php

/**
 * @file
 * Model Platform - MangoPay payment form.
 */

/**
 * Mangopay payment form.
 */
function mp_mangopay_payment_form($account, $order) {
  global $user;
  global $base_url;
  $uid = $user->uid;


  $form = '';
  if ($order->status == 'job_invoice_status') {
    $order_wrapper = entity_metadata_wrapper('commerce_order', $order);
    $_SESSION['mangopay_data']['order_total'] = $order_wrapper->commerce_order_total->amount->value() / 100;
    $_SESSION['mangopay_data']['currency'] = 'EUR';

    $card = _mp_mangopay_card_registration($uid);
    $_SESSION['mangopay_data']['cardRegisterId'] = $card->Id;

    $returnUrl = $base_url . '/user/' . $account->uid . '/invoices/' . $order->order_id . '/payment';

    $form = '<form action="' . $card->CardRegistrationURL . '" method="post">
    <input type="hidden" name="data" value="' . $card->PreregistrationData .'" />
    <input type="hidden" name="accessKeyRef" value="' . $card->AccessKey . '" />
    <input type="hidden" name="returnURL" value="' . $returnUrl . '" />

    <div>
      <div>
        <label for="cardNumber">Card Number</label>
      </div>
      <div>
        <input type="text" name="cardNumber" value="" />
      </div>
    </div>    

    <div>
      <div>
        <label for="cardExpirationDate">Expiration Date</label>
      </div>
      <div>
        <input type="text" name="cardExpirationDate" value="" />
      </div>
    </div>

    <div>
      <div>
        <label for="cardCvx">CVV</label>
      </div>
      <div>
        <input type="text" name="cardCvx" value="" />
      </div>
    </div>

    <input type="submit" value="Pay" />
</form>';
  }

  return $form;
}

/**
 * Payment callback.
 */
function mp_mangopay_payment_callback_form($account, $order) {
  $mangoPayApi = _mp_mangopay_api();

  $cardRegister = $mangoPayApi->CardRegistrations->Get($_SESSION['cardRegisterId']);
  $cardRegister->RegistrationData = isset($_GET['data']) ? 'data=' . $_GET['data'] : 'errorCode=' . $_GET['errorCode'];
  $updatedCardRegister = $mangoPayApi->CardRegistrations->Update($cardRegister);

  if ($updatedCardRegister->Status != \MangoPay\CardRegistrationStatus::Validated || !isset($updatedCardRegister->CardId))
    die('<div style="color:red;">Cannot create card. Payment has not been created. Please try again later.<div>');

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

    return '<div style="color:green;">'.
      'Pay-In has been created successfully. '
      .'Pay-In Id = ' . $createdPayIn->Id
      . ', Wallet Id = ' . $createdWallet->Id
      . '</div>';

    $link = "/user/$account->uid/invoices/$order->order_id";
  }
  else {
    // if created Pay-in object has status different than SUCCEEDED
    // that occurred error and display error message
    return '<div style="color:red;">'.
      'Pay-In has been created with status: '
      . $createdPayIn->Status . ' (result code: '
      . $createdPayIn->ResultCode . ')'
      . '</div>';
  }
}