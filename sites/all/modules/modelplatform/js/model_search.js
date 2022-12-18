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
        Drupal.ModelsSearch.setFullName($(this).val());
        Drupal.ModelsSearch.submitAction();
      }
    });
    $searchField.change(function() {
      Drupal.ModelsSearch.setFullName($(this).val());
      Drupal.ModelsSearch.startsubmitTimer();
    });
  };

  Drupal.ModelsSearch.startsubmitTimer = function() {
    if (Drupal.ModelsSearch.currentTimeoutID) {
      clearTimeout(Drupal.ModelsSearch.currentTimeoutID);
    }
    Drupal.ModelsSearch.currentTimeoutID = setTimeout(Drupal.ModelsSearch.submitAction, 500);
  };

  Drupal.ModelsSearch.setFullName = function(_fullName) {
    Drupal.ModelsSearch.fullName = _fullName;
    $('.form-control[name="field_full_name_value"]').val(_fullName);
  };

  Drupal.ModelsSearch.submitAction = function() {
    $('.view-models form').submit();
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

  Drupal.ModelsSearch.displayBEFValues = function(_name, _value, _divideNum, _suffix, _round) {
    var value = _value / _divideNum;
    if (_round) {
      value = Math.round(value);
    }
    $("#" + _name).html(value + _suffix);
  };

  Drupal.ModelsSearch.availableSliders = function(context) {
    $.each(Drupal.settings.better_exposed_filters.slider_options, function(_name, _option) {
      var className = _name.split('_').join('-');
      var wrapper = $('.form-item-' + className);
      var sliderWrapperID = 'mp-' + className;
      var suffix = '';
      var divideNum = 1;
      var defaultValue = parseInt(_option.max);
      var enteredValue = $("#edit-" + className).val();
      var round = true;

      if (_name == 'field_height_value') {
        suffix = ' M';
        divideNum = 100;
        round = false;
        defaultValue = parseInt(_option.min);
      }

      switch (_name) {
        case 'field_chest_value':
        case 'field_waist_value':
        case 'field_hip_value':
          if (Drupal.settings.modelplatform_theme.lang === 'en') {
            divideNum = 2.54;
            suffix = ' Inch';
          }
          else {
            suffix = ' cm';
          }
          break;

        default:
          // Nothing to do.
      }

      wrapper.addClass('has-ui-slider');
      wrapper.append('<div id="' + _name + '" class="mp-slider-value"></div>');

      if (wrapper.length) {
        if (enteredValue) {
          defaultValue = enteredValue;
        }
        wrapper.once('add-slider', function () {
          $("#edit-" + className).val(defaultValue);
          Drupal.ModelsSearch.displayBEFValues(_name, defaultValue, divideNum, suffix, round);
          wrapper.prepend('<div id="' + sliderWrapperID + '" class="mp-slider-wrapper"></div>');
          $("#" + sliderWrapperID).slider({
            min: parseInt(_option.min),
            max: parseInt(_option.max),
            step: parseInt(_option.step),
            value: parseInt(defaultValue),
            slide: function(event, ui) {
              $("#edit-" + className).val(ui.value);
              Drupal.ModelsSearch.displayBEFValues(_name, ui.value, divideNum, suffix, round);
              Drupal.ModelsSearch.startsubmitTimer();
            }
          });
        });
      }
    });
    $('.ui-slider-handle').draggable;
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
    Drupal.ModelsSearch.moveDateDiv();
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

  Drupal.ModelsSearch.moveDateDiv = function() {
    $('#model_availbale_dates').appendTo('#edit-secondary .bef-secondary-options');
  };

  Drupal.behaviors.modelplatform = {
    attach: function (context, settings) {
      // prepareMineSearch();
      Drupal.ModelsSearch.init(context);
      Drupal.ModelsSearch.prepareMineSearch(settings);
      Drupal.ModelsSearch.setContentHeight();

      // Masonry part.
      // var $grid = $('.view-models .view-content').masonry({
      //   itemSelector: '.views-row',
      //   //columnWidth: 283,
      //   fitWidth: true
      // });
      //
      // // layout Masonry after each image loads
      // $grid.imagesLoaded().progress( function() {
      //   $grid.masonry('layout');
      // });
    }
  };

})(jQuery);
