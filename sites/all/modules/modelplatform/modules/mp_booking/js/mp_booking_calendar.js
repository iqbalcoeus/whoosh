/**
 * Created by cimpleo on 02.12.16.
 */

(function ($) {
  // Calendar options structure.
  Drupal.rcOptions = Drupal.rcOptions || {};

  Drupal.rcOptions.init = function() {
    // this.schedulerLicenseKey = Drupal.settings.carCalendar.schedulerLicenseKey;
    this.header = {
      left: 'prev,next today',
      center: 'title',
      right: 'month,agendaWeek,agendaDay,listWeek'
    };
    this.slotWidth = 30;
    this.height = 460;
    this.editable = false;
    this.selectable = false;
    this.displayEventTime = true;
    this.eventStartEditable = false;
    this.dayNamesShort = [
      Drupal.t('Sun'),
      Drupal.t('Mon'),
      Drupal.t('Tue'),
      Drupal.t('Wed'),
      Drupal.t('Thu'),
      Drupal.t('Fri'),
      Drupal.t('Sat')
    ],
    this.monthNames = [
      Drupal.t('January'),
      Drupal.t('February'),
      Drupal.t('March'),
      Drupal.t('April'),
      Drupal.t('May'),
      Drupal.t('June'),
      Drupal.t('July'),
      Drupal.t('August'),
      Drupal.t('September'),
      Drupal.t('October'),
      Drupal.t('November'),
      Drupal.t('December')
    ];
    this.events = Drupal.settings.basePath + Drupal.settings.mp_booking.eventsPath;
    this.eventRender = function(event, element) {
      $(element[0]).attr('title', event.tooltip);
    };
    //limit the calender start date
    this.viewRender= function(currentView){
        //start of the year
        var minDate = moment().startOf('year');
        // Past
        if (minDate >= currentView.start && minDate <= currentView.end) {
            $(".fc-prev-button").prop('disabled', true);
            $(".fc-prev-button").addClass('fc-state-disabled');
        }
        else {
            $(".fc-prev-button").removeClass('fc-state-disabled');
            $(".fc-prev-button").prop('disabled', false);
        }
    }
  };

  // Calendar structure.
  Drupal.rcCalendar = Drupal.rcCalendar || {};

  Drupal.rcCalendar.init = function() {
    this.selector = '#calendar';
    this.calendar = $(this.selector);

    Drupal.rcOptions.init();
    $(this.selector).fullCalendar(Drupal.rcOptions);
  };

  // Behavior.
  Drupal.behaviors.rentCarCalendar = {
    attach: function (context, settings) {
      $('body').once(function() {
        Drupal.rcCalendar.init();

        // Placeholders.
        $('input[name="bat_start_date[date]"]').attr('placeholder', 'Start date');
        $('input[name="bat_end_date[date]"]').attr('placeholder', 'End date');
        $('input[name="bat_start_date[time]"]').attr('placeholder', '16:00');
        $('input[name="bat_end_date[time]"]').attr('placeholder', '16:00');

        $('#model-gallery-next').appendTo('body');
        $('#model-gallery-prev').appendTo('body');

        $('#model-gallery-next').click(function() {
          $.colorbox.next();
        });
        $('#model-gallery-prev').click(function() {
          $.colorbox.prev();
        });
        $(document).bind('cbox_open', function() {
          $('#model-gallery-next').addClass('active');
          $('#model-gallery-prev').addClass('active');
        });
        $(document).bind('cbox_closed', function() {
          $('#model-gallery-next').removeClass('active');
          $('#model-gallery-prev').removeClass('active');
        });
      });
    }
  };

})(jQuery);
