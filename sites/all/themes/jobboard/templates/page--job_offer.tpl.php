<?php
/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template in this directory.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['header']: Items for the header region.
 * - $page['footer']: Items for the footer region.
 *
 * @see bootstrap_preprocess_page()
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see bootstrap_process_page()
 * @see template_process()
 * @see html.tpl.php
 *
 * @ingroup themeable
 */
?>

<div class="header-top">
  
  <div class="container">

    <div class="row">
      
      <?php if (!empty($page['headertopleft'])): ?>
        <div class="headertopleft col-sm-8"><?php print render($page['headertopleft']); ?></div>
      <?php endif; ?>

      <?php if (!empty($page['headertopright'])): ?>
        <div class="headertopright col-sm-4"><?php print render($page['headertopright']); ?></div>
      <?php endif; ?>

    </div>

  </div>

</div>

<header id="navbar" role="banner" class="<?php print $navbar_classes; ?>">
  <div class="container">
    <div class="navbar-header">
      <?php if ($logo): ?>
      <a class="logo navbar-btn pull-left" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
        <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />

      </a>
      <a class="logo navbar-btn pull-left" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo-mobile"><img src="<?php print $base_path; ?><?php print $directory; ?>/logo-mobile.png" alt="<?php print t('Home'); ?>" /></a>
      <?php endif; ?>

      <?php if (!empty($site_name)): ?>
      <a class="name navbar-brand" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>"><?php print $site_name; ?></a>
      <?php endif; ?>

      <!-- .btn-navbar is used as the toggle for collapsed navbar content -->
      <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-collapse">
        <span class="sr-only">Toggle navigation</span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
      </button>
    </div>

    <?php
    global $user;
    $check = array_intersect(array('Employer', 'administrator'), array_values($user->roles));
        if (empty($check) ? FALSE : TRUE) {
        // is admin
        } else {
        // is not admin
        }
    ?>

     <?php if (empty($check) ? FALSE : TRUE): ?>

      <div class="post-job" > 
     <?php 

        $account = $GLOBALS['user'];


        $uid = user_load($account->uid);
        $profile_main = profile2_load_by_user($uid, 'employer');

        

      ?>

      <ul class="nav navbar-nav navbar-right">
  <li class="dropdown">
    <a data-toggle="dropdown" class="dropdown-toggle btn btn-primary" href="#">
     <span><i class="fa fa-users"></i>  <?php print t('My Account'); ?></span>
    </a>
    <div class="dropdown-menu">
      <div class="view-empty">
      <ul>
        <li> <img src="<?php print image_style_url('employer_logo', $profile_main->field_company_logo['und'][0]['uri']); ?>" /></li>
        <li><i class="fa fa-user"></i>  <span> <?php print t('Logged in as'); ?> <a href="<?php print $base_path; ?>user" class="y"><?php print $account->name; ?></a></span></li>
        <li><i class="fa fa-align-justify"></i>  <span><?php print userpoints_get_current_points($user->uid); ?> <?php print t('Available Submissions.'); ?></span></li>
        <li><a href="<?php print $base_path; ?>new-job-offer" ><i class="fa fa-plus"></i> <?php print t('Post a new Job'); ?></a></li>
        <li><a href="<?php print $base_path; ?>my-submissions" ><i class="fa fa-briefcase"></i> <?php print t('See my Submissions'); ?></a></li>
        <li><a href="<?php print $base_path; ?>purchase-submissions" class="y"><i class="fa fa-shopping-cart"></i> <?php print t('Purchase Submissions'); ?></a></li>
        <li class="last"><a href="<?php print $base_path; ?>user/logout" class="y"><i class="fa fa-sign-out"></i> <?php print t('Logout'); ?></a></li>
        
      </li>
      </div>
    </div> 
  </li>
 </ul>

     
    </div>
     
      <?php endif; ?>


      <?php if (!empty($check) ? FALSE : TRUE): ?>

      <div class="post-job" > 
      
 <ul class="nav navbar-nav navbar-right">
  <li class="dropdown">
    <a href="<?php print $base_path; ?>user/login" class="btn dropdown-toggle  btn-primary"><i class="fa fa-sign-in"></i> <?php print t('Sign in'); ?></a>
    <span class="new-account"><?php print t('or'); ?> <a href="<?php print $base_path; ?>user/register" ><?php print t('Create a new account'); ?></a></span>
  </li>
  
 </ul>
    </div>
     
      <?php endif; ?>

    <?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])): ?>
      <div class="navbar-collapse collapse">
        <nav role="navigation">
          <?php if (!empty($primary_nav)): ?>
            <?php print render($primary_nav); ?>
          <?php endif; ?>
          <?php if (!empty($secondary_nav)): ?>
            <?php print render($secondary_nav); ?>
          <?php endif; ?>
          <?php if (!empty($page['navigation'])): ?>
            <?php print render($page['navigation']); ?>
          <?php endif; ?>
          <?php print render($page['cart']); ?>
        </nav>
      </div>
    <?php endif; ?>
    
  </div>
</header>



<?php if (!empty($page['highlighted'])): ?>
        <div class="highlighted"><?php print render($page['highlighted']); ?></div>
      <?php endif; ?>


<div class="title-container">
  <div class="container">
  <?php if (!empty($breadcrumb)): print $breadcrumb; endif;?>
  <?php print render($title_prefix); ?>
      <?php if (!empty($title)): ?>

      <?php  $loc = $node->field_location['und'][0]['taxonomy_term']->name; ?>
      
      <?php if(!empty($node->field_location)): ?>

        <h1 class="page-header"><?php print $title; ?><span> <?php print t('in'); ?> <?php print $loc;?></span></h1>

      <?php endif;?>


      <?php if(empty($node->field_location)): ?>

        <h1 class="page-header"><?php print $title; ?></h1>

      <?php endif;?>

      <?php endif; ?>
      <?php print render($title_suffix); ?>
  </div>
</div>

<div class="main-container container">

  <header role="banner" id="page-header">
    <?php if (!empty($site_slogan)): ?>
      <p class="lead"><?php print $site_slogan; ?></p>
    <?php endif; ?>

    <?php print render($page['header']); ?>
  </header> <!-- /#page-header -->

  <div class="row content-area-container">

    <?php if (!empty($page['sidebar_first'])): ?>
      <aside class="col-sm-3" role="complementary">
        <?php print render($page['sidebar_first']); ?>
      </aside>  <!-- /#sidebar-first -->
    <?php endif; ?>

    <section class="col-sm-9 page-container" >

      <div class="content-area">
      
      
      <a id="main-content"></a>
      
      <?php print $messages; ?>
      <?php if (!empty($tabs)): ?>
        <?php print render($tabs); ?>
      <?php endif; ?>
      <?php if (!empty($page['help'])): ?>
        <?php print render($page['help']); ?>
      <?php endif; ?>
      <?php if (!empty($action_links)): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>
      <?php print render($page['content']); ?>


      </div>

      <div class="related-area">

      <?php if (!empty($page['related'])): ?>
      <?php print render($page['related']); ?></div>
      <?php endif; ?>

      </div>

    </section>

    <?php if (!empty($page['sidebar_second'])): ?>
      <aside class="col-sm-3" role="complementary">
        <?php print render($page['sidebar_second']); ?>
      </aside>  <!-- /#sidebar-second -->
    <?php endif; ?>

  </div>
</div>
<div class="footer-head-container">
<footer class="container">
  <?php print render($page['footer_head']); ?>
</footer>
</div>

<div class="footer-container">
<footer class="footer container">
  <div class="row">
  <?php print render($page['footer']); ?>
  <?php print render($page['closure']); ?>
  </div>
</footer>
</div>