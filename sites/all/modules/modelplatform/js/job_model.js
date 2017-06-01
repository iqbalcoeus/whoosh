/**
 * Created by cimpleo on 26.05.17.
 */

(function ($) {

  Drupal.behaviors.modelplatform = {
    attach: function (context, settings) {
      // Masonry part.
      var $grid = $('.filtered-hired-block').masonry({
        itemSelector: '.views-row',
        fitWidth: true
      });

      // layout Masonry after each image loads
      $grid.imagesLoaded().progress( function() {
        $grid.masonry('layout');
      });
    }
  };

})(jQuery);
