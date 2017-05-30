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
            var suffix = ' cm';
            var divideNum = 1;
            var divideNum2 = 1;
            var value = _value.val() ? _value.val() : slider.min;

            wrapper.addClass('has-ui-slider');
            wrapper.append('<div id="' + slider.name + '_value" class="mp-slider-value"></div>');

            var valueDiv = $('#' + slider.name + '_value');

            if (Drupal.settings.modelplatform_theme.lang === 'en') {
              suffix = ' Inch';
              divideNum = 2.54;
              divideNum2 = 1;
            }

            if (slider.name == 'field_height') {
              suffix = ' M';
              divideNum = 100;
              divideNum2 = 100;
            }

            valueDiv.html(Math.round(value * divideNum2 / divideNum) / divideNum2 + suffix);

            wrapper.slider({
              range: false,
              min: parseInt(slider.min),
              max: parseInt(slider.max),
              value: parseInt(value),
              slide: function (event, ui) {
                _value.val(ui.value);
                valueDiv.html(Math.round(ui.value * divideNum2 / divideNum) / divideNum2 + suffix);
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
    if ($('input[name="user_roles"]:checked').val() == Drupal.settings.mp_forms.customer) {
      $('#edit-user-roles-' + Drupal.settings.mp_forms.customer).click();
    }
    else {
      $('#edit-user-roles-' + Drupal.settings.mp_forms.model).click();
    }
  });

})(jQuery);
