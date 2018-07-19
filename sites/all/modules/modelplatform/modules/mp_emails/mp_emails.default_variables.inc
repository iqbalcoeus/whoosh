<?php

/**
 * Created by PhpStorm.
 * User: cimpleo
 * Date: 22.08.17
 * Time: 17:31
 */

/**
 * Model email. Model job reminder. 2
 */
function _mp_emails_get_var_model_job_reminder_notification($language) {
  $message_text = array();
  if(!isset($language)){
    $language = 'en';
  }
  $message_text['en'] = '
    @model_salutation, @model_full_name.

    Unfortunately you have not responded to the request of our customer @customer_full_name. 
    It would be nice if you could report, so that it is clear for both sides whether a cooperation is coming. 
    This is the only chance you have a new order!

    Best regards,
    Your team of MegaOnline
  ';
  $message_text['de'] = '
    @model_salutation, @model_full_name.
    
    leider hast Du nicht noch auf die Anfrage unseres Kunden @customer_full_name reagiert. 
    Es wäre schön, wenn Du Dich melden könntest, damit für beide Seiten klar ist, ob es zu einer Zusammenarbeit kommt. 
    Nur so hast Du die Chance auf einen neuen Auftrag!
    
    Herzliche Grüße, 
    Dein Team von MegaOnline
  ';
  

  return $message_text[$language];
}

/**
 * Customer email. Customer optioned model. 3
 */
function _mp_emails_get_var_customer_job_option_notification($language) {
  $message_text = array();
  if(!isset($language)){
    $language = 'en';
  }

  $message_text['en'] = '
    @customer_salutation, @customer_full_name.     
    
    You have elected to make an offer to our model @model_full_name.  
    Your offer has been forwarded and you will have a response shortly.   
    If you do not have a response within 24 hours, or if you have any questions whatsoever, please do not hesitate to contact our friendly team on (phone number).
    
    Best regards,
    Your team of MegaOnline
  ';
  $message_text['de'] = '
    @customer_salutation, @customer_full_name.
    
    Sie haben eine Option für unser Model @model_full_name gewählt. 
    Wir haben Ihre Anfrage an unser Model weitergeleitet. 
    Sollten Sie innerhalb der nächsten 24 Stunden keine Nachricht von dem gewünschten Model bekommen oder noch Fragen haben, melden Sie sich gerne telefonisch bei uns.
     
    Herzliche Grüße, 
    Ihr Team von MegaOnline
  ';

  return $message_text[$language];
}

/**
 * Model email. Model was optioned. 1
 */
function _mp_emails_get_var_model_job_option_notification($language) {
  $message_text = array();
  if(!isset($language)){
    $language = 'en';
  }

  $message_text['en'] = '
    @model_salutation, @model_full_name.
    
    Our customer @customer_full_name has chosen an option for a project with you. 
    To accept or reject this request, if you are not currently available, just click on this link: @url
    Here you also have the possibility to check whether the customer\'s suggested day rate matches your expectations or whether you would like to make a new proposal.      
    
    Here are the details, which are important for you:

    Customer: @customer_full_name
    Job description: !job_description
    Date: @job_date
    Daily rate: @job_daily_rate
    
    Best regards,
    Your team of MegaOnline
  ';
  $message_text['de'] = '
    @model_salutation, @model_full_name.
    
    unser Kunde @customer_full_name hat eine Option für ein Projekt mit Dir gewählt. 
    Um diese Anfrage anzunehmen oder abzulehnen, wenn Du gerade nicht zur Verfügung stehst, musst Du nur noch auf diesen Link klicken: @url. 
    Hier hast Du auch die Möglichkeit zu prüfen, ob der vom Kunden vorgeschlagene Tagessatz Deinen Vorstellungen entspricht oder ob Du einen neuen Vorschlag machen möchtest.
    
    Kunde: @customer_full_name
    Jobbeschreibung: !job_description
    Datum: @job_date
    Tagessatz: @job_daily_rate
     
    Herzliche Grüße, 
    Dein Team von MegaOnline
  ';

  return $message_text[$language];
}

/**
 * Customer email. Model confirmed option. 4
 */
function _mp_emails_get_var_customer_job_option_model_confirm($language) {
  $message_text = array();
  if(!isset($language)){
    $language = 'en';
  }

  $message_text['en'] = '
    @customer_salutation, @customer_full_name.     
    
    We are pleased to inform you that @model_full_name has accepted your offer.
    
    Best regards,
    Your team of MegaOnline
  ';
  $message_text['de'] = '
    @customer_salutation, @customer_full_name.
      
    das von Ihnen angefragte @model_full_name hat Ihre Option bestätigt.
    
    Herzliche Grüße, 
    Ihr Team von MegaOnline
  ';

  return $message_text[$language];
}

/**
 * Customer. Auction email. 5
 */
function _mp_emails_get_var_customer_job_auction($language) {
  $message_text = array();
  if(!isset($language)){
    $language = 'en';
  }

  $message_text['en'] = '
    @customer_salutation, @customer_full_name.

    We are pleased to inform you that your chosen @model_full_name has accepted your offer.  
    You now must close the deal by confirming the job booking.   
    If you are happy with the job as it stands, please click here:  @url

    We will immediately notify the model that the job is set.
    
    Good luck with the cooperation and cordial greetings,
    Your team of MegaOnline
  ';
  $message_text['de'] = '
    @customer_salutation, @customer_full_name.
    
    Sie haben eine Option für unser @model_full_name gewählt. Das freut uns natürlich. 
    Nun müssen Sie sich entscheiden: Wenn Sie aus der Option eine Festbuchung machen möchten, dann klicken Sie bitte hier: @url. 
    Wir informieren dann umgehend das von Ihnen gewählte Model.
    
    Viel Erfolg bei der Zusammenarbeit und herzliche Grüße, 
    Ihr Team von MegaOnline
  ';

  return $message_text[$language];
}

/**
 * Model. Job confirmed. 6
 */
function _mp_emails_get_var_model_job_confirmed($language) {
  $message_text = array();
  if(!isset($language)){
    $language = 'en';
  }

  $message_text['en'] = '
    @model_salutation, @model_full_name.
    
    Your job with @customer_full_name has been accepted and booked.
    Congratulations.  We wish you a fun and successful shoot.
    
    Best regards,
    Your team of MegaOnline
  ';

  $message_text['de'] = '
    @model_salutation, @model_full_name.
    
    Deine Option durch @customer_full_name ist nun eine Festbuchung geworden. 
    Herzlichen Glückwunsch – wir wünschen eine erfolgreiche Zusammenarbeit!
    
    Herzliche Grüße, 
    Dein Team von MegaOnline
  ';

  return $message_text[$language];
}

/**
 * Model. Calendar. 7
 */
function _mp_emails_get_var_model_calendar($language) {
  $message_text = array();
  if(!isset($language)){
    $language = 'en';
  }
  
  $message_text['en'] = '
    @model_salutation, @model_full_name.
    
    You must be a very busy person!  
    In fact, it seems like you haven’t even had time to respond to some of the requests we have sent you.     
    If this is indeed the case, would you please take a moment to update your calendar with us?   
    All you need to do is update which dates you are or are not available.  
    This way we will know which dates offers can still be made to you.  
    Thank you so much for your cooperation.  
    We hope this helps us both towards more efficient booking.
    
    Best regards,
    Your team of MegaOnline
  ';
  $message_text['de'] = '
    @model_salutation, @model_full_name.
    
    offensichtlich hast du gerade keine Zeit, um neue Anfragen anzunehmen. 
    In diesem Fall wäre es schön, wenn Du Deinen Kalender aktualisieren könntest. 
    Dafür musst Du einfach die Tage markieren, an denen Du nicht gebucht werden kannst. 
    So wissen Deine Auftraggeber, dass sie gerade ohne Dich planen müssen. 
    Vielen Dank für Dein Verständnis!
    
    Herzliche Grüße, 
    Dein Team von MegaOnline
  ';

  return $message_text[$language];
}