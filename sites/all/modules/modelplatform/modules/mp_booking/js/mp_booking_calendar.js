/**
 * Created by cimpleo on 02.12.16.
 */

(function ($) {
  // Calendar options structure.
  Drupal.rcOptions = Drupal.rcOptions || {};

  Drupal.rcOptions.init = function() {
    // this.schedulerLicenseKey = Drupal.settings.carCalendar.schedulerLicenseKey;
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
  };

  // Calendar structure.
  Drupal.rcCalendar = Drupal.rcCalendar || {};

  Drupal.rcCalendar.init = function() {
    this.selector = '#calendar';
    this.calendar = $(this.selector);

    Drupal.rcOptions.init();
    $(this.selector).fullCalendar(Drupal.rcOptions);
    $(this.selector).fullCalendar({
      eventSources: [Drupal.settings.basePath + Drupal.settings.mp_booking.eventsPath],
      eventRender: function(event, element) {
        element.qtip({
          content: event.description
        });
      }
    });
  };

  // Behavior.
  Drupal.behaviors.rentCarCalendar = {
    attach: function (context, settings) {
      $('body').once(function() {
        Drupal.rcCalendar.init();

        // Placeholders.
        $('input[name="bat_start_date[date]"]').attr('placeholder', 'Start date');
        $('input[name="bat_end_date[date]"]').attr('placeholder', 'End date');
        $('input[name="bat_start_date[time]"]').attr('placeholder', '10:00 AM');
        $('input[name="bat_end_date[time]"]').attr('placeholder', '10:00 AM');
      });
    }
  };

})(jQuery);
