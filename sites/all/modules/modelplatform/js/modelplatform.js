(function ($) {

  function resizeAction() {
    var w = Drupal.settings.modelplatform.videoWidth;
    var h = Drupal.settings.modelplatform.videoHeight;
    var el = $('#front_page_video');
    var elHeader = $('#Header .region-top');
    var hrth = elHeader.height() + parseInt(elHeader.css('padding-top')) + parseInt(elHeader.css('padding-bottom'));
    var elBlock = $('.front-page-video-block');
    el.css('top', hrth + 'px');
    var wh = $(window).height() - hrth;
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

  $(document).ready(function(){
    resizeAction();
    var tag = document.createElement('script');
    tag.src = "https://www.youtube.com/player_api";
    var firstScriptTag = document.getElementsByTagName('script')[0];
    firstScriptTag.parentNode.insertBefore(tag, firstScriptTag);

    Drupal.youtube_player = null || Drupal.youtube_player;
  });
  $(window).resize(resizeAction);

})(jQuery);

function onPlayerStateChange(newState) {
  if (Drupal.youtubeFlag) {
    Drupal.youtubeFlag = false;
    Drupal.youtube_player.pauseVideo();
  }
  if (newState.data == 1) {
    jQuery('.front-page-video-block').addClass('playing');
  }
  else {
    jQuery('.front-page-video-block').removeClass('playing');
  }
}

function onYouTubePlayerAPIReady() {
  Drupal.youtube_player = new YT.Player('ytplayer', {
      width: '100%',
      height: '100%',
      videoId: Drupal.settings.modelplatform.videoID,
      playerVars: {
        controls: 0,
        disablekb: 0,
        showinfo: 0,
        autoplay: 1,
        playlist: Drupal.settings.modelplatform.videoID,
        loop: 1,
      },
      events: {
        'onStateChange': onPlayerStateChange
      },
      suggestedQuality: 'hq720',
    });

  Drupal.youtubeFlag = true;

  var _play = '<div id="play-button"></div>';
  var _pause = '<div id="pause-button"></div>';

  jQuery('.front-page-video-block').append(_play).append(_pause);

  var playButton = document.getElementById("play-button");
  playButton.addEventListener("click", function() {
    Drupal.youtube_player.playVideo();
  });

  var pauseButton = document.getElementById("pause-button");
  pauseButton.addEventListener("click", function() {
    Drupal.youtube_player.pauseVideo();
  });
}
