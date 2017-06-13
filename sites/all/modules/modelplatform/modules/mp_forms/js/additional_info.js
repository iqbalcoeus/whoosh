/**
 * Created by cimpleo on 07.12.16.
 */

(function ($) {

  function checkLingerie() {
    if ($('input[name="profile_model_additional_info[field_lingerie][und]"').is(":checked")) {
      $('.field-name-field-lingerie-daily-rate').css('display', 'block');
      $('.field-name-field-lingerie-daily-rate input').attr('required', 'required');
    }
    else {
      $('.field-name-field-lingerie-daily-rate').css('display', 'none');
      $('.field-name-field-lingerie-daily-rate input').attr('required', '');
    }
  }
  Drupal.behaviors.mp_forms = {
    attach: function (context, settings) {
      checkLingerie();
      $('input[name="profile_model_additional_info[field_lingerie][und]"]').change(checkLingerie);
    }
  };

})(jQuery);
