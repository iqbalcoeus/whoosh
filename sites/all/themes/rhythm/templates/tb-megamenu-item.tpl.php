<?php
  $a_classes[] = $submenu ? ' mn-has-sub' : '';
  $angle_class = $item['link']['depth'] == 1 ? 'down' : 'right right';
  $href = strpos($item['link']['href'], "_anchor_") !== false ? str_replace("http://_anchor_", '#', $item['link']['href']) : url($item['link']['href'], $item['link']['options']);
  
  $classes .= strpos($item['link']['href'], "_anchor_") !== false ? ' local-scroll' : '';
  $classes .= $item_config['alignsub'] ? ' align-menu-' . $item_config['alignsub'] : '';
?>
<li class="<?php print trim($classes); ?>" <?php print $attributes;?>>
  <?php if(!empty($item_config['caption'])) : ?>
    <a class="mn-group-title" style="height: 97px; line-height: 75px;"><?php print t($item_config['caption']);?></a>
  <?php endif;?>
  <a href="<?php print in_array($item['link']['href'], array('<nolink>')) ? "#" : $href; ?>" class="<?php print implode(" ", $a_classes);?>">
    <?php if(!empty($item_config['xicon'])) : ?>
      <i class="<?php print $item_config['xicon'];?> fa-sm"></i> 
    <?php endif;?>    
    <?php print t($item['link']['link_title']);?>
    <?php print $submenu ? '<i class="fa fa-angle-' . $angle_class . '"></i>' : ''; ?>  
  </a>
  <?php print $submenu ? $submenu : ''; ?>
</li>
