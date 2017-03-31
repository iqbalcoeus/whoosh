(function ($) {

  function heightSlider() {
    if (Drupal.settings.better_exposed_filters.slider_options.field_height_value) {
      var heightSettings = Drupal.settings.better_exposed_filters.slider_options.field_height_value;
      var heightValue = $('.form-item-field-height-value');

      if (heightValue.length) {
        heightValue.once('add-slider', function () {
          $("#edit-field-height-value").val(parseInt(heightSettings.min));
          heightValue.prepend('<div id="romira-fixed-price-slider"></div>');
          $("#romira-fixed-price-slider").slider({
            min: parseInt(heightSettings.min),
            max: parseInt(heightSettings.max),
            step: heightSettings.step,
            slide: function(event, ui) {
              $("#edit-field-height-value").val(ui.value);
            }
          });
        });
      }
    }
  };

  $(document).ready(function(){
    heightSlider();
  });


})(jQuery);
