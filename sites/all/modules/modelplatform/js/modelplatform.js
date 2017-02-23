(function ($) {

  function resizeAction() {
    var w = Drupal.settings.modelplatform.video_width;
    var h = Drupal.settings.modelplatform.video_height;
    var el = $('#front_page_video');
    el.height(el.width() * h / w);
  };

  $(document).ready(resizeAction);
  $(window).resize(resizeAction);

})(jQuery);