<?php

/**
 * @file
 * Model Platform - MangoPay payment form.
 */

/**
 * Mangopay payment form.
 */
function mp_mangopay_payment_form(&$form, &$form_state, $account, $order) {
  dsm($order);

  global $user;
  $uid = $user->uid;
  $card = _mp_mangopay_card_registration($uid);

  $_SESSION['cardRegisterId'] = $card->Id;

  $returnUrl = 'user/' . $account->uid . '/invoices/' . $order->order_id . '/payment_result';

  $form['#action'] = $card->CardRegistrationURL;
  $form['data'] = array(
    '#type' => 'hidden',
    '#value' => $card->PreregistrationData,
  );
  $form['accessKeyRef'] = array(
    '#type' => 'hidden',
    '#value' => $card->AccessKey,
  );
  $form['returnURL'] = array(
    '#type' => 'hidden',
    '#value' => $returnUrl,
  );

  $form['cardNumber'] = array(
    '#type' => 'textfield',
    '#title' => 'Card number',
  );
  $form['cardExpirationDate'] = array(
    '#type' => 'textfield',
    '#title' => 'Expiration Date',
  );
  $form['cardCvx'] = array(
    '#type' => 'textfield',
    '#title' => 'CVV',
  );

  $form['cardCvx'] = array(
    '#type' => 'submit',
    '#value' => 'Pay',
  );

  return $form;
}

/**
 * Payment callback.
 */
function mp_mangopay_payment_callback_form(&$form, &$form_state, $account, $order) {

  $cardRegister = $mangoPayApi->CardRegistrations->Get($_SESSION['cardRegisterId']);
  var_dump($cardRegister);
  $cardRegister->RegistrationData = isset($_GET['data']) ? 'data=' . $_GET['data'] : 'errorCode=' . $_GET['errorCode'];
  var_dump($cardRegister);
  $updatedCardRegister = $mangoPayApi->CardRegistrations->Update($cardRegister);
  var_dump($updatedCardRegister);

  if ($updatedCardRegister->Status != \MangoPay\CardRegistrationStatus::Validated || !isset($updatedCardRegister->CardId))
    die('<div style="color:red;">Cannot create card. Payment has not been created.<div>');

  // get created virtual card object
  $card = $mangoPayApi->Cards->Get($updatedCardRegister->CardId);

  // create temporary wallet for user
  $wallet = new \MangoPay\Wallet();
  $wallet->Owners = array( $updatedCardRegister->UserId );
  $wallet->Currency = $_SESSION['currency'];
  $wallet->Description = 'Temporary wallet for payment demo';
  $createdWallet = $mangoPayApi->Wallets->Create($wallet);
  var_dump($createdWallet);

  // create pay-in CARD DIRECT
  $payIn = new \MangoPay\PayIn();
  $payIn->CreditedWalletId = $createdWallet->Id;
  $payIn->AuthorId = $updatedCardRegister->UserId;
  $payIn->DebitedFunds = new \MangoPay\Money();
  $payIn->DebitedFunds->Amount = $_SESSION['amount'];
  $payIn->DebitedFunds->Currency = $_SESSION['currency'];
  $payIn->Fees = new \MangoPay\Money();
  $payIn->Fees->Amount = 0;
  $payIn->Fees->Currency = $_SESSION['currency'];

  // payment type as CARD
  $payIn->PaymentDetails = new \MangoPay\PayInPaymentDetailsCard();
  $payIn->PaymentDetails->CardType = $card->CardType;
  $payIn->PaymentDetails->CardId = $card->Id;

  // execution type as DIRECT
  $payIn->ExecutionDetails = new \MangoPay\PayInExecutionDetailsDirect();
  $payIn->ExecutionDetails->SecureModeReturnURL = 'http://test.com';

  // create Pay-In
  $createdPayIn = $mangoPayApi->PayIns->Create($payIn);
  var_dump($createdPayIn);
  // if created Pay-in object has status SUCCEEDED it's mean that all is fine
  if ($createdPayIn->Status == \MangoPay\PayInStatus::Succeeded) {
    print '<div style="color:green;">'.
      'Pay-In has been created successfully. '
      .'Pay-In Id = ' . $createdPayIn->Id
      . ', Wallet Id = ' . $createdWallet->Id
      . '</div>';
  }
  else {
    // if created Pay-in object has status different than SUCCEEDED
    // that occurred error and display error message
    print '<div style="color:red;">'.
      'Pay-In has been created with status: '
      . $createdPayIn->Status . ' (result code: '
      . $createdPayIn->ResultCode . ')'
      .'</div>';
  }

  /*
   *
   */
  $result = 'success';

  $form['label'] = array(
    '#type' => 'markup',
    '#markup' => '<div class="payment result">' . $result . '</div>',
  );

  return $form;
}