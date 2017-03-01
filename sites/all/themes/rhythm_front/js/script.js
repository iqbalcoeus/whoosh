/**
 * Created by cimpleo on 27.02.17.
 */

(function ($) {
  $(document).ready(function() {
    var title = Drupal.settings.modelplatform_theme.register_title.und;
    if (Drupal.settings.modelplatform_theme.lang == 'de') {
      title = Drupal.settings.modelplatform_theme.register_title.DE;
    }
    var aelement = '<a class="register-link" href="/user/register">'+title+'</a>';
    $('.role-choose .role-model a').click(function(){
      $('#block-views-front-page-third-block').hide();
      $('#block-views-front-page-third-block-1').hide();
      $('#block-views-front-page-third-block-2').show();
      $('#block-views-front-page-third-block-2').append(aelement);

      return false;
    });

    $('.role-choose .role-customer a').click(function(){
      $('#block-views-front-page-third-block').hide();
      $('#block-views-front-page-third-block-1').show();
      $('#block-views-front-page-third-block-2').hide();
      $('#block-views-front-page-third-block-1').append(aelement);

      return false;
    });
    $('.front-page-sixth-block .block-content').append('<a href="/user" class="login-free"></a>');
  });

  $(window).scroll(function(){
    if ($(window).scrollTop() > 10) {
      $("#Header .region-top").addClass("sticky");
    }
    else {
      $("#Header .region-top").removeClass("sticky");
    }
  });

})(jQuery);