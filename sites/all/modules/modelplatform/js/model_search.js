(function ($) {

  function heightSlider() {
    if (Drupal.settings.better_exposed_filters.slider_options.field_height_value) {
      var heightSettings = Drupal.settings.better_exposed_filters.slider_options.field_height_value;
      var heightValue = $('.form-item-field-height-value');

      $('.form-item-field-height-value').append('<div id="height_slider_value"></div>');

      if (heightValue.length) {
        heightValue.once('add-slider', function () {
          $("#edit-field-height-value").val(parseInt(heightSettings.min));
          $("#height_slider_value").html((parseInt(heightSettings.min) / 100) + ' M');
          heightValue.prepend('<div id="romira-fixed-price-slider"></div>');
          $("#romira-fixed-price-slider").slider({
            min: parseInt(heightSettings.min),
            max: parseInt(heightSettings.max),
            step: heightSettings.step,
            slide: function(event, ui) {
              $("#edit-field-height-value").val(ui.value);
              $("#height_slider_value").html((ui.value / 100) + ' M');
            }
          });
        });
      }
    }
  };

  function prepareModelSearch() {
    // Filter button action.
    var $filters = $('.view-models .view-filters');
    var filter_button = $('#models_search_filter');
    filter_button.click(function(){
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

    $('#loupe').click(function(){
      $('.view-models form').submit();
    });
    $('#close_filter').click(function(){
      $searchField.val('');
      filter_button.removeClass('active');
      $filters.removeClass('active');
    });
    //
    $('.form-item-field-daily-rate-value-1 input').attr('placeholder', '');
    $('.form-item-field-lingerie-daily-rate-value input').attr('placeholder', '');
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
  };

  $(document).ready(function(){
    prepareModelSearch();
    heightSlider();
  });

})(jQuery);
