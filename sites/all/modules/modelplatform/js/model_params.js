/**
 * Created by cimpleo on 21.04.17.
 */

(function ($) {

  Drupal.behaviors.modelplatform_params = {
    attach: function (context, settings) {
      if (Drupal.settings.modelplatform_theme) {
        $('body').once(function() {
          var selectors = Drupal.settings.modelplatform_params.selectors;
          $.each(selectors, function (i, sel) {
            var item = $(sel);
            var divideNum = 1;
            var suffix = '';
            if (Drupal.settings.modelplatform_theme.lang === 'en') {
              divideNum = 2.54;
              suffix = '';
            }
            var value = parseInt(item.html());
            value = Math.round(value / divideNum);
            item.html(value + suffix);
          });
        });
      }
    }
  };

})(jQuery);

// Download images feature
jQuery( document ).ready(function() {

  var imgUrls = jQuery('#quicktabs-container-model_gallery').find('img').map(function() { return this.src; }).get();

  if(imgUrls.length>0){
    jQuery("#quicktabs-model_gallery").append('<div class="form-actions form-wrapper"><input class="btn-medium btn btn-mod btn-round form-submit" type="button" id="download-images" name="op" value="Download"></div>');

    jQuery("#download-images").click(function() {

      var zip = new JSZip();
      var count = 0;
      var zipFilename = "model_images.zip";

      var imgTitle = 1;
      imgUrls.forEach(function(url){

        var filename = "img_"+imgTitle+".png";

        imgTitle = imgTitle+1;

        // loading a file and add it in a zip file
        JSZipUtils.getBinaryContent(url, function (err, data) {
         if(err) {
              throw err; // or handle the error
              console.log(err);
            }

            zip.file(filename, data, {binary:true});
            count++;

            if (count == imgUrls.length) {
             var zipFile = zip.generate({type: "blob"});
             saveAs(zipFile, zipFilename);
           }
         });
      });

    });
  }
});