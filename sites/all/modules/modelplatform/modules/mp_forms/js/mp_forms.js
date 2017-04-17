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

            wrapper.addClass('has-ui-slider');
            wrapper.append('<div id="' + slider.name + '_cm_value" class="mp-slider-value cm-value"></div>');
            wrapper.append('<div id="' + slider.name + '_inch_value" class="mp-slider-value inch-value"></div>');

            var inchValueDiv = $('#' + slider.name + '_inch_value');
            var cmValueDiv = $('#' + slider.name + '_cm_value');

            inchValueDiv.html(Math.round(_value.val() / 2.54) + ' Inch');
            cmValueDiv.html(_value.val() + ' cm');

            wrapper.slider({
              range: false,
              min: parseInt(slider.min),
              max: parseInt(slider.max),
              value: parseInt(_value.val()),
              slide: function (event, ui) {
                _value.val(ui.value);
                inchValueDiv.html(Math.round(ui.value / 2.54) + ' Inch');
                cmValueDiv.html(ui.value + ' cm');
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
