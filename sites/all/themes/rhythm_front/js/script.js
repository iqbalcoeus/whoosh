/**
 * Created by cimpleo on 27.02.17.
 */

(function ($) {

  $(document).ready(function() {

    if ($('body').hasClass('page-page-404')) {
      $('body').css('background-image', 'url(' + Drupal.settings.rhythm_front.body_images.p404 + ')');
    }

    $('#edit-blog-search').attr('placeholder', Drupal.t('Search'));

    var hashElement = $(window.location.hash.replace('#_', '#'));
    if (hashElement.length) {
      $('html,body').animate({
        scrollTop: hashElement.offset().top - 120
      }, 500);
    }
    $('a').click(function(){
      if (this.hash !== "") {
        $('html,body').animate({
          scrollTop: $(this.hash.replace('#_', '#')).offset().top - 120
        }, 500);
      }
    });

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

  $(function() {
    $('a[href*="#"]:not([href="#"])').click(function() {
      if (location.pathname.replace(/^\//,'') == this.pathname.replace(/^\//,'') && location.hostname == this.hostname) {
        var target = $(this.hash);
        target = target.length ? target : $('[name=' + this.hash.slice(1) +']');
        if (target.length) {
          $('html, body').animate({
            scrollTop: target.offset().top
          }, 1000);
          return false;
        }
      }
    });
  });


})(jQuery);