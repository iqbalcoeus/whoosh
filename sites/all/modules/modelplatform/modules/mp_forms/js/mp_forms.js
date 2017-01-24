/**
 * Created by cimpleo on 07.12.16.
 */

(function ($) {

  Drupal.behaviors.mp_forms = {
    attach: function (context, settings) {
      // Sliders.
      $('body').once(function() {
        if (settings.mp_forms.sliders !== undefined) {
          var _sliders = settings.mp_forms.sliders;
          $.each(_sliders, function (i, slider) {
            var _value = $(slider.selector + " input");
            var wrapper = $(slider.selector);
            wrapper.slider({
              range: false,
              min: parseInt(slider.min),
              max: parseInt(slider.max),
              value: _value.val(),
              slide: function (event, ui) {
                _value.val(ui.value);
              }
            });
          });
        }
      });
    }
  };

  $(document).ready(function() {
    var socialBlock = $('.block-social-login-widget .social_login');
    $('#edit-user-roles input').click(function() {
      if ($(this).val() == Drupal.settings.mp_forms.model) {
        socialBlock.addClass('model');
        $('.xing_apply_btn a').addClass('hidden');
        socialBlock.removeClass('customer');
      }
      else {
        socialBlock.addClass('customer');
        socialBlock.removeClass('model');
        $('.xing_apply_btn a').removeClass('hidden');
        // @TODO Fix it.
        $('.xing_apply_btn a').addClass('customer');
      }
    });
    if (socialBlock.hasClass('customer')) {
      $('#edit-user-roles-' + Drupal.settings.mp_forms.customer).click();
    }
    else {
      $('#edit-user-roles-' + Drupal.settings.mp_forms.model).click();
    }
  });

})(jQuery);
