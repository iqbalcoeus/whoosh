/**
 * Created by cimpleo on 21.04.17.
 */

(function ($) {

  Drupal.behaviors.modelplatform_params = {
    attach: function (context, settings) {
      var selectors = Drupal.settings.modelplatform_params.selectors;
      $.each(selectors, function(i, sel) {
        var item = $(sel);
        var divideNum = 1;
        var suffix = '';
        if (Drupal.settings.modelplatform_theme.lang === 'en') {
          divideNum = 2.54;
          suffix = '';
        }
        var value = parseInt(item.html());
        value = Math.round(value / divideNum);
        item.html(value + suffix);
      });
    }
  };

})(jQuery);

