/**
 * Created by cimpleo on 27.02.17.
 */

(function ($) {

  Drupal.behaviors.mp_rating = {
    attach: function (context, settings) {
      $('.past-job-rating h5').css('margin-top', ($('.past-job-rating').height() * 0.3) + 'px');
      $('.past-job-rating').click(function(event){
        if ($(event.target).hasClass('past-job-rating') ||
          $(event.target).parent().hasClass('star')) {
          $('.past-job-rating').hide();
        }
      });
    }
  };

})(jQuery);

