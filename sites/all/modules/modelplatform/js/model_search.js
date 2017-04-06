(function ($) {

  Drupal.ModelsSearch = {
    currentTimeoutID: 0,
    fullName: '',
  };

  Drupal.ModelsSearch.initFilterButton = function(context) {
    // Filter button action.
    var $filters = $(context).find('.view-filters');
    var filter_button = $(context).find('#models_search_filter');
    filter_button.once(function(){
      $(this).click(function(){
        if ($filters.hasClass('active')) {
          $(this).removeClass('active');
          $filters.removeClass('active');
        }
        else {
          $(this).addClass('active');
          $filters.addClass('active');
        }
        Drupal.ModelsSearch.setContentHeight();
      });
    });
  };

  Drupal.ModelsSearch.initSearchField = function(context) {
    // Search.
    var $searchField = $(context).find('#models_search_by_name');
    $searchField.val($(context).find('.form-control[name="field_full_name_value"]').val());
    $searchField.keypress(function(e) {
      if (e.which == 13) {
        $(context).find('.form-control[name="field_full_name_value"]').val($(this).val());
        $(context).find('.view-models form').submit();
      }
    });
    $searchField.change(function() {
      if (Drupal.ModelsSearch.currentTimeoutID) {
        clearTimeout(Drupal.ModelsSearch.currentTimeoutID);
      }
      Drupal.ModelsSearch.fullName = $(this).val();
      Drupal.ModelsSearch.currentTimeoutID = setTimeout(setFullNameField, 500);
    });
  };

  Drupal.ModelsSearch.initColapsedItems = function(context) {
    // collapsed.
    $(context).find('.view-filters label').on('click', function() {
      var $parent = $(this).parent();

      if ($parent.hasClass('active')) {
        $parent.removeClass('active');
      }
      else {
        $parent.addClass('active');
      }
      Drupal.ModelsSearch.setContentHeight();
    });
    $(context).find('.bef-secondary-options').click(function(e){
      console.log(e.target);
    });
  };

  Drupal.ModelsSearch.initSearchIcons = function(context) {
    // Search icons parts.
    $(context).find('#loupe').click(function() {
      $(context).find('.view-models form').submit();
    });
    $(context).find('#close_filter').click(function() {
      $(context).find('#models_search_by_name').val('');
      $(context).find('#models_search_filter').removeClass('active');
      $(context).find('.view-models .view-filters').removeClass('active');
      Drupal.ModelsSearch.setContentHeight();
    });
  };

  Drupal.ModelsSearch.initDailyRatePart = function(context) {
    // Daily rate part.
    $(context).find('.form-item-field-daily-rate-value-1 input').attr('placeholder', '');
    $(context).find('.form-item-field-lingerie-daily-rate-value input').attr('placeholder', '');
    if ($(context).find('#edit-field-lingerie-value-1:checked').length) {
      $(context).find('.form-item-field-daily-rate-value-1').hide();
      $(context).find('.form-item-field-lingerie-daily-rate-value').show();
    }
    $(context).find('.form-item-field-lingerie-value input').change(function(){
      if (this.checked) {
        $(context).find('.form-item-field-daily-rate-value-1').hide();
        $(context).find('.form-item-field-lingerie-daily-rate-value').show();
      }
      else {
        $(context).find('.form-item-field-lingerie-daily-rate-value').hide();
        $(context).find('.form-item-field-daily-rate-value-1').show();
      }
    });
  };

  Drupal.ModelsSearch.availableSliders = function(context) {
    $.each(Drupal.settings.better_exposed_filters.slider_options, function(_name, _option) {
      var className = _name.split('_').join('-');
      var wrapper = $('.form-item-' + className);
      var sliderWrapperID = 'mp-' + className;
      var suffix = '';
      var divideNum = 1;

      if (_name == 'field_height_value') {
        suffix = ' M';
        divideNum = 100;
      }
      wrapper.addClass('has-ui-slider');
      wrapper.append('<div id="' + _name + '" class="mp-slider-value"></div>');

      if (wrapper.length) {
        wrapper.once('add-slider', function () {
          $("#edit-" + className).val(parseInt(_option.min));
          $("#" + _name).html((parseInt(_option.min) / divideNum) + suffix);
          wrapper.prepend('<div id="' + sliderWrapperID + '" class="mp-slider-wrapper"></div>');
          $("#" + sliderWrapperID).slider({
            min: parseInt(_option.min),
            max: parseInt(_option.max),
            step: parseInt(_option.step),
            slide: function(event, ui) {
              $("#edit-" + className).val(ui.value);
              $("#" + _name).html((ui.value / divideNum) + suffix);
              setTimeout(setFullNameField, 500);
            }
          });
        });
      }
    });
    $('.ui-slider-handle').draggable;
  };

  function setFullNameField() {
    $('.form-control[name="field_full_name_value"]').val(Drupal.ModelsSearch.fullName);
    $('.view-models form').submit();
  };

  Drupal.ModelsSearch.prepareMineSearch = function(_settings) {
    $('#mine_search').attr('href', '/' + _settings.modelplatform.pathname + '?' + _settings.modelplatform.search);
  };

  Drupal.ModelsSearch.init = function(context){
    Drupal.ModelsSearch.initFilterButton(context);
    Drupal.ModelsSearch.initColapsedItems(context);
    Drupal.ModelsSearch.initSearchField(context);
    Drupal.ModelsSearch.initSearchIcons(context);
    Drupal.ModelsSearch.initDailyRatePart(context);
    Drupal.ModelsSearch.availableSliders();
  };

  Drupal.ModelsSearch.setContentHeight = function() {
    var _filter = $('.view-models .view-filters');
    var _height = _filter.height();
    var _viewsContent = $('.view-models .view-content');
    var _viewsEmpty = $('.view-models  .view-empty');
    if (_filter.hasClass('active') && _height >= 830) {
      _viewsContent.css('min-height', parseInt(_height) + 'px');
      _viewsEmpty.css('min-height', parseInt(_height) + 'px');
    }
    else if (_filter.hasClass('active')) {
      _viewsContent.css('min-height', '760px');
      _viewsEmpty.css('min-height', '760px');
    }
    else {
      _viewsContent.css('min-height', '0px');
      _viewsEmpty.css('min-height', '0px');
    }
  };

  Drupal.behaviors.modelplatform = {
    attach: function (context, settings) {
      // prepareMineSearch();
      Drupal.ModelsSearch.init(context);
      Drupal.ModelsSearch.prepareMineSearch(settings);
      Drupal.ModelsSearch.setContentHeight();

      // Masonry part.
      var $grid = $('.view-models .view-content').masonry({
        itemSelector: '.views-row',
        //columnWidth: 283,
        fitWidth: true
      });

      // layout Masonry after each image loads
      $grid.imagesLoaded().progress( function() {
        $grid.masonry('layout');
      });
    }
  };

})(jQuery);
