/**
 * Created by cimpleo on 07.12.16.
 */

(function ($) {

  Drupal.behaviors.mp_forms = {
    attach: function (context, settings) {
      $('input[name="profile_model_additional_info[field_lingerie][und]"').change(function() {
        if (this.checked) {
          $('.field-name-field-lingerie-daily-rate').css('display', 'block');
          $('.field-name-field-lingerie-daily-rate input').attr('required', 'required');
        }
        else {
          $('.field-name-field-lingerie-daily-rate').css('display', 'none');
          $('.field-name-field-lingerie-daily-rate input').attr('required', '');
        }
      });
    }
  };

})(jQuery);
