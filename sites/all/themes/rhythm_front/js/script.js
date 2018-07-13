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
      android.openMenuData(JSON.stringify(Drupal.settings.rhythm_front.user.role_class));
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

jQuery(document).ready(function(){
  jQuery('.filtered-views-block .views-field-picture a[href]').each(function(){ 
      var oldUrl = jQuery(this).attr("href"); // Get current url
      var newUrl = oldUrl + '?node=' + jQuery('.node-id').text(); // Create new url
      jQuery(this).attr("href", newUrl); // Set herf value
  });

    var imgUrls = jQuery('.hired-views-block .view-id-job_models.view-display-id-block_1').find('img').map(function() {
    var image = new Image(); 
    image.src = this.src;
    if (image.width > 0) {
      return this.src;
    }
  }).get();
 jQuery(".hired-views-block .view-id-job_models.view-display-id-block_1").append('<div class="form-actions form-wrapper"><input class="btn-medium btn btn-mod btn-round form-submit" type="button" id="download-shortlisted-pictures" name="op" value="Download Pictures"></div>');
  if(imgUrls.length>0){
    jQuery("#download-shortlisted-pictures").click(function() {

      var zip = new JSZip();
      var count = 0;
      var zipFilename = "Shortlist-"+jQuery('#page-title').text()+".zip";

      var imgTitle = 1;
      imgUrls.forEach(function(url){

        var filename = "img_"+imgTitle+(url.match(/.gif|.png|.jpg|.jpeg|.tiff|.bmp|.ppm|.svg/));

        imgTitle = imgTitle+1;

            // loading a file and add it in a zip file
            JSZipUtils.getBinaryContent(url, function (err, data) {
              if(!err) {
                zip.file(filename, data, {binary:true});
                count++;

                if (count == imgUrls.length) {
                  var zipFile = zip.generate({type: "blob"});
                  saveAs(zipFile, zipFilename);
                }
              }
            });
        });

    });
  }else{
        jQuery("#download-shortlisted-pictures").hide();
  }
});