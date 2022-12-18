<section id="<?php print $block_html_id; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php print render($title_prefix); ?>
  <?php if ($title): ?><div class="title-div">
    <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
  
  </div>
  <?php endif;?>
  <?php print render($title_suffix); ?>

 

  <div class="col-md-7 col-md-offset-1">

  	 <?php print $content ?>

  </div>
  
  <div class="col-md-3">
	<a href="user" class="btn btn-lg btn-default"><span class="glyphicon glyphicon-log-in"> </span> <?php print t('Register Now'); ?></a>
<div class="download-specs">
		<?php print t('Email verification is required'); ?></div>
</div>


</section> <!-- /.block -->
