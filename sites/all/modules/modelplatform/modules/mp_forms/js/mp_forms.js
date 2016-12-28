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
    $('#edit-user-roles input').click(function() {
      var socialBlock = $('.block-social-login-widget .social_login');
      if ($(this).val() == Drupal.settings.mp_forms.model) {
        socialBlock.addClass('model');
        $('.xing_apply_btn a').addClass('hidden');
        socialBlock.removeClass('customer');
      }
      else {
        socialBlock.addClass('customer');
        socialBlock.removeClass('model');
        $('.xing_apply_btn a').removeClass('hidden');
        $('.xing_apply_btn a').addClass('customer');
      }
    });




  });




})(jQuery);