<?php
/**
 * @file
 * model_platform_model_job_auction.features.inc
 */

/**
 * Implements hook_views_api().
 */
function model_platform_model_job_auction_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function model_platform_model_job_auction_image_default_styles() {
  $styles = array();

  // Exported image style: 1400x600.
  $styles['1400x600'] = array(
    'label' => '1400x600',
    'effects' => array(
      13 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1400,
          'height' => 600,
          'retinafy' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 187x101.
  $styles['187x101'] = array(
    'label' => '187x101',
    'effects' => array(
      10 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 187,
          'height' => 101,
          'retinafy' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 293x159_news.
  $styles['293x159_news'] = array(
    'label' => '293x159 news',
    'effects' => array(
      14 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 293,
          'height' => 159,
          'retinafy' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: 462_267.
  $styles['462_267'] = array(
    'label' => '462х267',
    'effects' => array(
      15 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 462,
          'height' => 267,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: 512_512.
  $styles['512_512'] = array(
    'label' => '512х512',
    'effects' => array(
      16 => array(
        'name' => 'focal_point_scale_and_crop',
        'data' => array(
          'width' => 512,
          'height' => 512,
          'focal_point_advanced' => array(
            'shift_x' => '',
            'shift_y' => '',
          ),
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: blog.
  $styles['blog'] = array(
    'label' => 'blog',
    'effects' => array(
      9 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 848,
          'height' => 281,
          'retinafy' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: employer_logo.
  $styles['employer_logo'] = array(
    'label' => 'employer_logo',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 220,
          'height' => '',
          'upscale' => 0,
          'retinafy' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: news_home.
  $styles['news_home'] = array(
    'label' => 'news_home',
    'effects' => array(
      8 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 360,
          'height' => 200,
          'retinafy' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: sidebar_jobs_employers.
  $styles['sidebar_jobs_employers'] = array(
    'label' => 'sidebar jobs employers',
    'effects' => array(
      4 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 120,
          'height' => '',
          'upscale' => 0,
          'retinafy' => 0,
        ),
        'weight' => -10,
      ),
      6 => array(
        'name' => 'canvasactions_definecanvas',
        'data' => array(
          'RGB' => array(
            'HEX' => 'ffffff',
          ),
          'under' => 1,
          'exact' => array(
            'width' => 120,
            'height' => 120,
            'xpos' => 'center',
            'ypos' => 'center',
          ),
          'relative' => array(
            'leftdiff' => '',
            'rightdiff' => '',
            'topdiff' => '',
            'bottomdiff' => '',
          ),
        ),
        'weight' => 3,
      ),
      7 => array(
        'name' => 'image_resize',
        'data' => array(
          'width' => 60,
          'height' => 60,
          'retinafy' => 1,
        ),
        'weight' => 3,
      ),
    ),
  );

  return $styles;
}
