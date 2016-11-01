class WPBakeryShortCode_{base} extends WPBakeryShortCode {



protected function content($atts, $content = null) {
extract(shortcode_atts(array(
'el_class' => '',
), $atts));
$el_class .= ' wpb_{base}_wrapper';
$output = '<div class="' . $el_class . '">';
    $output .= visual_composer_get_view('{name}', '{display}', $atts);
    $output .= '</div>';
return $output;
}

}