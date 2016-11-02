
  jQuery(document).ready(function(){  

	/* Message to Employer */
  
    var job = jQuery("h1").html();

    var loc =  window.location.href;

    var jobName = job.replace(jQuery(job).html(), "");
  
	var message = "I'm interested on the '" + jobName.replace("<span></span>", "") + "' job posted at (" + loc + ").";
	
	jQuery("#block-webform-client-block-15  .form-textarea").val(message);

	jQuery("#block-multiblock-1 .form-textarea").val(message);
	
	
  });
