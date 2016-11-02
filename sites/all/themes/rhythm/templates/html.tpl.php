<?php if(request_uri() == '/maintenance' && strpos($_SERVER['HTTP_HOST'], 'nikadevs') !== FALSE) { include('maintenance-page.tpl.php'); exit(); } ?>

<!DOCTYPE html>
<html  lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"<?php print $rdf_namespaces; ?>>
<head>
  <?php print $head; ?>

  <title><?php print $head_title; ?></title>
  <!--[if IE]><meta http-equiv='X-UA-Compatible' content='IE=edge,chrome=1'><![endif]-->
  <meta name=viewport content="width=device-width, initial-scale=1">

  <?php print $styles; ?>
  
</head>
<body class="appear-animate <?php print $classes; ?>"<?php print $attributes; ?>>
  <div class="main-wrap">
    <?php if(theme_get_setting('loader_image')): ?>
      <!-- Page Loader -->        
      <div class="page-loader">
          <div class="loader"><?php print t('Loading...'); ?></div>
      </div>
      <!-- End Page Loader -->
    <?php endif; ?>

    <?php print $page_top; ?>
    <?php print $page; ?>
    <script type="text/javascript" src="//maps.google.com/maps/api/js?sensor=false&amp;amp;language=en&amp;1424957919"></script>
    <?php print $scripts; ?>
    <!--[if lt IE 10]><script type="text/javascript" src="<?php print base_path() . path_to_theme(); ?>/js/placeholder.js"></script><![endif]-->
    <?php print $page_bottom; ?>
  </div>
</body>
</html>