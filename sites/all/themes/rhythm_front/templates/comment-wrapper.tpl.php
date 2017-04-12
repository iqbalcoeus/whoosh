<?php

/**
 * @file
 * Default theme implementation to provide an HTML container for comments.
 *
 * Available variables:
 * - $content: The array of content-related elements for the node. Use
 *   render($content) to print them all, or
 *   print a subset such as render($content['comment_form']).
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default value has the following:
 *   - comment-wrapper: The current template type, i.e., "theming hook".
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * The following variables are provided for contextual information.
 * - $node: Node object the comments are attached to.
 * The constants below the variables show the possible values and should be
 * used for comparison.
 * - $display_mode
 *   - COMMENT_MODE_FLAT
 *   - COMMENT_MODE_THREADED
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess_comment_wrapper()
 *
 * @ingroup themeable
 */
$result_comments = array();
$tree_comments = array();
foreach($content['comments'] as $i => $comment) {
  if (is_numeric($i)) {
    if ($pid = $comment['#comment']->pid) {
      $_pid = $pid;
      while (!isset($result_comments[$_pid])) {
        $_pid = $tree_comments[$_pid]['comment']['#comment']->pid;
      }
      $tree_comments[$_pid]['children'][$comment['#comment']->cid] = $comment;
    }
    else {
      $result_comments[$comment['#comment']->cid] = $comment;
    }
    $tree_comments[$comment['#comment']->cid]['comment'] = $comment;
  }
}
$content['comments'] = $result_comments;

$comments_array = array_filter($content['comments'], '_count_comments');
foreach($content['comments'] as $i => $comment) {
  if (is_numeric($i)) {
    $close_tag = strip_tags(str_replace('</div>', '</li></ul>', $content['comments'][$i]['#prefix']), '<ul><li></ul></li>');
    $content['comments'][$i]['#prefix'] = $close_tag . '<li class = "media comment-item">' . str_replace(array('</div>', '<div class="indented">'), array('', '<ul><li class = "media comment-item">'), $content['comments'][$i]['#prefix']);
    if (isset($tree_comments[$comment['#comment']->cid]['children'])) {
      $content['comments'][$i]['#suffix'] = '<ul>' . render($tree_comments[$comment['#comment']->cid]['children']) . '</ul></li>';
    }
    else {
      $content['comments'][$i]['#suffix'] = '</li>';
    }
  }
}
?>

<?php if($comments_array): ?>
  <div class="mb-60 mb-xs-30">
    <?php print render($title_prefix); ?>
    <h3 class="title slim"><?php print t('Comments'); ?></h3>
    <?php print render($title_suffix); ?>
    <ul class="media-list text comment-list clearlist">
      <?php print render($content['comments']); ?>
    </ul>
  </div>
<?php endif; ?>

<?php if ($content['comment_form']): ?>
  <div>
    <h4 class="blog-page-title font-alt"><?php print t('Leave a Comment'); ?></h4>
  </div>
  <?php
    $content['comment_form']['actions']['submit']['#value'] = t('Send Comment');
    print render($content['comment_form']);
  ?>
<?php endif; ?>