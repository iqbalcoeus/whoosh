<?php if(request_uri() == '/maintenance' && strpos($_SERVER['HTTP_HOST'], 'nikadevs') !== FALSE) { include('maintenance-page.tpl.php'); exit(); } ?>

<!DOCTYPE html>
<html  lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>"<?php print $rdf_namespaces; ?>>
<head>
  <?php print $head; ?>

  <?php 
    if(drupal_is_front_page()) {
      $head_title .= '24H MODELBOOKING | '.t('With the Support of Modeling Agency');
    }
   ?>
  <title><?php print $head_title; ?></title>
  <!--[if IE]><meta http-equiv='X-UA-Compatible' content='IE=edge,chrome=1'><![endif]-->
  <meta name=viewport content="width=device-width, initial-scale=1">
  <meta name="google-site-verification" content="nnBavD6zsRTGSw0HaUNftl6IBWxh7SzUkVIn0lTB3tY" />
  <meta name="description" content="<?php echo t('A very well known Modeling Agency in Hamburg provides the experience and support behind myfabmodels.') ?>">

  <?php print $styles; ?>
  <?php 
      global $user;
      if(isset($user))
      {
        if (in_array('Model', $user->roles)) {
          $classes .= ' model-user';
        }
      }
  ?>
  <script type="application/ld+json">
    {
      "@context": "http://schema.org",
      "@type": "LocalBusiness",
      "name": "MyFab Models",
      "description": "A very well known Modeling Agency in Hamburg provides the experience and support behind myfabmodels.",
      "logo": "https://www.myfabmodels.com/sites/default/files/MegaOnlineButtonBlack_100mm_trimmed_90px.png",
      "image": "https://www.myfabmodels.com/sites/default/files/styles/462_267/public/DSC_8094_0.jpg?itok=2bCSuSgV",
      "url": "https://www.myfabmodels.com",
      "telephone": "+49 40 30036613",
      "email": "hello@myfabmodels.com",
      "address": {
        "@type": "PostalAddress",
        "streetAddress": "Kanalstr. 28",
        "addressLocality": "Hamburg",
        "postalCode": "22085",
        "addressCountry": "DE"
      },
      "sameAs": [
        "https://www.facebook.com/myfabmodels/",
        "https://www.instagram.com/myfabmodels/"
      ]
    }
</script>
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
<!--    <script type="text/javascript" src="//maps.google.com/maps/api/js?sensor=false&amp;amp;language=en&amp;1424957919"></script>-->
    <?php print $scripts; ?>
    <!--[if lt IE 10]><script type="text/javascript" src="<?php print base_path() . path_to_theme(); ?>/js/placeholder.js"></script><![endif]-->
    <?php print $page_bottom; ?>
  </div>
  
</body>
</html>