class WPBakeryShortCode_{base} extends WPBakeryShortCode {


protected function content($atts, $content = null) {
extract(shortcode_atts(array(
'el_class' => '',
'limit' => '',
'formatter' => 'default_formatter',
), $atts));
$el_class .= ' wpb_{base}_wrapper';
$output = '<div class="' . $el_class . '">';    
    if(isset($atts['entity_type']) && isset($atts['entity_id'])) {
    $entity = array_pop(entity_load($atts['entity_type'], array($atts['entity_id'])));
    $entity->_field_view_prepared = false;
    $formatter_settings = array();
    foreach($atts as $key => $value) {
    $pos = strpos($key, 'formatter_settings_');
    if ($pos !== false) {
    $key = str_replace('formatter_settings_', '', $key);
    $key = explode('__', $key);    
    if(count($key) == 1) {
    $formatter_settings[$key[0]] = $value;
    }
    if(count($key) == 2) {
    $formatter_settings[$key[0]] = array($key[1] => $value);
    }
    }

    }    
    if(isset($atts['field_label']) && $atts['field_label']!= '') {
        $output .= '<label>'. t($atts['field_label']) .': </label>';
    }
    foreach($entity->{field} as $language => $items) {
        if(empty($atts['limit']))
            $entity->{field}[$language] = $items;
        else
            $entity->{field}[$language] = array_slice($items, 0, $atts['limit']);
    }    
    $field_view = field_view_field($atts['entity_type'], $entity, '{field}', array('label' => 'hidden', 'type' => $formatter, 'settings' => $formatter_settings));
    $output .= render($field_view) . ' ';
    }
    $output .= '</div>';
return $output;
}

}
