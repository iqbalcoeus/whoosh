(function ($) {

  function resizeAction() {
    var w = Drupal.settings.modelplatform.video_width;
    var h = Drupal.settings.modelplatform.video_height;
    var el = $('#front_page_video');
    var elBlock = $('.front-page-video-block');
    el.height(el.width() * h / w);
    elBlock.height(el.width() * h / w);
  };

  $(document).ready(resizeAction);
  $(window).resize(resizeAction);

})(jQuery);