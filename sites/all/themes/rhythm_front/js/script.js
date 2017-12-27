/**
 * Created by cimpleo on 27.02.17.
 */

(function ($) {

  function moveToHashElement(_hash) {
    var hashElement = $(_hash.replace('#_', '#'));
    if (hashElement.length) {
      $('html,body').animate({
        scrollTop: hashElement.offset().top - 120
      }, 500);
    }
  }

  $(document).ready(function() {
    $('#block-views-model-gallery-block').hide();
    $('#block-quicktabs-model-gallery .quicktabs-tabpage').addClass('block-views').addClass('gallery');
    $('#superfish-1-toggle').on('click', callNativeApp);

    if ($('body').hasClass('page-page-404')) {
      $('body').css('background-image', 'url(' + Drupal.settings.rhythm_front.body_images.p404 + ')');
    }

    $('#edit-blog-search').attr('placeholder', Drupal.t('Search'));

    moveToHashElement(window.location.hash);
    $('a').click(function(){
      moveToHashElement(this.hash);
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

  function validateOS() {
    var userAgent = navigator.userAgent || navigator.vendor || window.opera;

    // Windows Phone must come first because its UA also contains "Android"
    if (/windows phone/i.test(userAgent)) {
      return "Windows Phone";
    }

    if (/android/i.test(userAgent)) {
      return "Android";
    }

    // iOS detection from: http://stackoverflow.com/a/9039885/177710
    if (/iPad|iPhone|iPod/.test(userAgent) && !window.MSStream) {
      return "iOS";
    }

    return "unknown";
  }

  function callNativeApp () {
    var osInfo = validateOS();

    if (osInfo == "Android") {
      android.openMenu("openMenu");
      android.openMenu(Drupal.settings.rhythm_front.user.role_class);
    }
    else if (osInfo == "iOS") {
      try {
        webkit.messageHandlers.callbackHandler.postMessage("openMenu");
        webkit.messageHandlers.callbackHandler.postMessage(Drupal.settings.rhythm_front.user.role_class);
      }
      catch(err) {
        console.log('The native context does not exist yet');
      }
    }
  }

  Drupal.behaviors.rhythm_front = {
    attach: function (context, settings) {

    }
  };

})(jQuery);
