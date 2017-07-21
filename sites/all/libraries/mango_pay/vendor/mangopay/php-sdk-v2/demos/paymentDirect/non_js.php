<?php

// include MangoPay SDK
require_once '../../../../autoload.php';
require_once 'config.php';

// sample payment data
$_SESSION['amount'] = 10;
$_SESSION['currency'] = 'EUR';
$_SESSION['cardType'] = 'CB_VISA_MASTERCARD';//or alternatively MAESTRO or DINERS etc

// create instance of MangoPayApi SDK
$mangoPayApi = new \MangoPay\MangoPayApi();
$mangoPayApi->Config->ClientId = MangoPayDemo_ClientId;
$mangoPayApi->Config->ClientPassword = MangoPayDemo_ClientPassword;
$mangoPayApi->Config->TemporaryFolder = '/tmp';

// create user for payment
$user = new MangoPay\UserNatural();
$user->FirstName = 'John';
$user->LastName = 'Smith';
$user->Email = 'newemail@domain.com';
$user->Birthday = time();
$user->Nationality = 'FR';
$user->CountryOfResidence = 'FR';
$user->Occupation = "programmer";
$user->IncomeRange = 3;
$createdUser = $mangoPayApi->Users->Create($user);
var_dump($createdUser);

// register card
$cardRegister = new \MangoPay\CardRegistration();
$cardRegister->UserId = $createdUser->Id;
$cardRegister->Currency = $_SESSION['currency'];
$cardRegister->CardType = $_SESSION['cardType'];
$createdCardRegister = $mangoPayApi->CardRegistrations->Create($cardRegister);
$_SESSION['cardRegisterId'] = $createdCardRegister->Id;
var_dump($createdCardRegister);
var_dump($mangoPayApi->CardRegistrations->Get($_SESSION['cardRegisterId']));

// build the return URL to capture token response
$returnUrl = 'http' . ( isset($_SERVER['HTTPS']) ? 's' : '' ) . '://' . $_SERVER['HTTP_HOST'];
$returnUrl .= substr($_SERVER['REQUEST_URI'], 0, strripos($_SERVER['REQUEST_URI'], '/') + 1);
$returnUrl .= 'payment.php';
var_dump($createdCardRegister->CardRegistrationURL);
?>

<p>
  <i>
    Shows how to register the card without using JavaScript <br />
    and process payments with page reload.
  </i>
</p>

<label>Full Name</label>
<label><?php print $createdUser->FirstName . ' ' . $createdUser->LastName; ?></label>
<div class="clear"></div>

<label>Amount</label>
<label><?php print $_SESSION['amount'] . ' ' . $_SESSION['currency']; ?></label>
<div class="clear"></div>

<form action="<?php print $createdCardRegister->CardRegistrationURL; ?>" method="post">
    <input type="hidden" name="data" value="<?php print $createdCardRegister->PreregistrationData; ?>" />
    <input type="hidden" name="accessKeyRef" value="<?php print $createdCardRegister->AccessKey; ?>" />
    <input type="hidden" name="returnURL" value="<?php print $returnUrl; ?>" />

    <label for="cardNumber">Card Number</label>
    <input type="text" name="cardNumber" value="" />
    <div class="clear"></div>

    <label for="cardExpirationDate">Expiration Date</label>
    <input type="text" name="cardExpirationDate" value="" />
    <div class="clear"></div>

    <label for="cardCvx">CVV</label>
    <input type="text" name="cardCvx" value="" />
    <div class="clear"></div>

    <input type="submit" value="Pay" />
</form>
