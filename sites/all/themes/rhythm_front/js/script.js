/**
 * Created by cimpleo on 27.02.17.
 */

(function ($) {
  $(document).ready(function() {
    $('.role-choose .role-model').click(function(){
      $('#block-views-front-page-third-block').hide();
      $('#block-views-front-page-third-block-1').hide();
      $('#block-views-front-page-third-block-2').show();

      return false;
    });

    $('.role-choose .role-customer').click(function(){
      $('#block-views-front-page-third-block').hide();
      $('#block-views-front-page-third-block-1').show();
      $('#block-views-front-page-third-block-2').hide();

      return false;
    });

  });
})(jQuery);