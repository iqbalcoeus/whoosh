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

    // Filter button action.
    $('#models_search_filter').click(function(){
      var $filters = $('.view-models .view-filters');
      if ($filters.hasClass('active')) {
        $(this).removeClass('active');
        $filters.removeClass('active');
      }
      else {
        $(this).addClass('active');
        $filters.addClass('active');
      }
    });

    // Search.
    var $searchField = $('#models_search_by_name');
    $searchField.val($('.form-control[name="field_full_name_value"]').val());
    $searchField.keypress(function (e) {
      if (e.which == 13) {
        $('.form-control[name="field_full_name_value"]').val($(this).val());
        $('.view-models form').submit();
      }
    });

    // collapsed.
    $('.view-filters label').click(function(){
      var $parent = $(this).parent();

      if ($parent.hasClass('active')) {
        $parent.removeClass('active')
      }
      else {
        $parent.addClass('active');
      }
    });

    //
    if ($('#edit-field-lingerie-value-1:checked').length) {
      $('.form-item-field-daily-rate-value-1').hide();
      $('.form-item-field-lingerie-daily-rate-value').show();
    }
    $('.form-item-field-lingerie-value input').change(function(){
      if (this.checked) {
        $('.form-item-field-daily-rate-value-1').hide();
        $('.form-item-field-lingerie-daily-rate-value').show();
      }
      else {
        $('.form-item-field-lingerie-daily-rate-value').hide();
        $('.form-item-field-daily-rate-value-1').show();
      }
    });

    var $grid = $('.view-models .view-content').masonry({
      itemSelector: '.views-row',
      //columnWidth: 283,
      fitWidth: true
    });
    // layout Masonry after each image loads
    $grid.imagesLoaded().progress( function() {
      $grid.masonry('layout');
    });

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