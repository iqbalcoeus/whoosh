(function ($) {

  function resizeAction() {
    var w = Drupal.settings.modelplatform.video_width;
    var h = Drupal.settings.modelplatform.video_height;
    var el = $('#front_page_video');
    var elBlock = $('.front-page-video-block');
    var wh = $(window).height();
    var ww = $(window).width();
    var newHeight = el.width() * h / w;
    elBlock.height(newHeight);
    if (wh > newHeight) {
      var newWidth = wh * w / h;
      el.height(wh);
      el.width(newWidth);
      el.css('margin-left', '-' + ((newWidth - ww) / 2) + 'px');
    }
    else {
      el.height(newHeight);
    }
  };

  $(document).ready(resizeAction);
  $(window).resize(resizeAction);

})(jQuery);