/**
 * Created by cimpleo on 07.12.16.
 */

(function ($) {

  Drupal.behaviors.mp_forms = {
    attach: function (context, settings) {
      $('body').once(function() {
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
      });
    }
  };

})(jQuery);