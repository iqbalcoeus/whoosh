/**
 * Created by cimpleo on 07.07.16.
 */

(function ($) {

  $(document).ready(function() {
    $('#payment_month, #payment_year').change(function(){
      $('#card_date').val($('#payment_month').val() + $('#payment_year').val());
    });

    $('#card_type').change(function() {
      $.ajax({
        url: '/mangopay/ajax/' + $('#card_order').val() + '/' + $(this).val(),
        success: function(data) {
          $('#card_payment_form').attr('action', data.url);
          $('#card_data').val(data.data);
          $('#card_key').val(data.key);
        }
      });
    });
  });

})(jQuery);
