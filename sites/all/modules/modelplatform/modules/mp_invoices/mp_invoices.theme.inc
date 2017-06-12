<?php

/**
 * @file
 * Model Platform - Invoices theme functions.
 */

/**
 * Generate invoice page.
 */
function theme_mp_invoices_page($page_variables) {
  global $base_url;

  // Header.
  $header_variables = $page_variables['header'];

  $header_img = theme('image', array('path' => $header_variables['img']));
  $header_div_img = '<div class="mpi-image">' . $header_img . '</div>';

  $header_text_column1 = '<div class="mpi-text-column mpi-text-column-1">';
  $header_text_column1 .= $header_variables['text']['column1'];
  $header_text_column1 .= '</div>';

  $header_text_column2 = '<div class="mpi-text-column mpi-text-column-2">';;
  $header_text_column2 .= $header_variables['text']['column2'];
  $header_text_column2 .= '</div>';

  $header_text = '<div class="mpi-text">';
  $header_text .= $header_text_column1;
  $header_text .= $header_text_column2;
  $header_text .= '</div>';

  $header = '<div class="mpi-header">';
  $header .= $header_div_img;
  $header .= $header_text;
  $header .= '</div>';

  // Content.
  // Content - Address.
  $address_variables = $page_variables['content']['address'];

  $customer_address_variables = $address_variables['customer'];

  $customer_prefix = '<div class="mpi-customer-prefix">' . $customer_address_variables['prefix'] . '</div>';
  $customer_company_name = '<div class="mpi-customer-company-name">' . $customer_address_variables['company_name'] . '</div>';
  $customer_name = '<div class="mpi-customer-name">' . $customer_address_variables['name'] . '</div>';
  $customer_street = '<div class="mpi-customer-street">' . $customer_address_variables['street'] . '</div>';
  $customer_house = '<div class="mpi-customer-house">' . $customer_address_variables['house'] . '</div>';
  $customer_postal_code = '<div class="mpi-customer-postal-code">' . $customer_address_variables['postal_code'] . '</div>';
  $customer_city = '<div class="mpi-customer-city">' . $customer_address_variables['city'] . '</div>';

  $customer_address = '<div class="mpi-customer-address">';
  $customer_address .= $customer_prefix;
  $customer_address .= $customer_company_name;
  $customer_address .= $customer_name;
  $customer_address .= $customer_street;
  $customer_address .= $customer_house;
  $customer_address .= $customer_postal_code;
  $customer_address .= $customer_city;
  $customer_address .= '</div>';

  $model_address_variables = $address_variables['model'];

  $model_name = '<div class="mpi-model-name">' . $model_address_variables['name'] . '</div>';
  $model_street = '<div class="mpi-model-street">' . $model_address_variables['street'] . '</div>';
  $model_house = '<div class="mpi-model-house">' . $model_address_variables['house'] . '</div>';
  $model_postal_code = '<div class="mpi-model-postal-code">' . $model_address_variables['postal_code'] . '</div>';
  $model_city = '<div class="mpi-model-city">' . $model_address_variables['city'] . '</div>';
  $model_appartment = '<div class="mpi-model-appartment">' . $model_address_variables['city'] . '</div>';
  $model_tax_id = '<div class="mpi-model-tax-id">' . $model_address_variables['tax_id'] . '</div>';

  $model_address = '<div class="mpi-model-address">';
  $model_address .= $model_name;
  $model_address .= $model_street;
  $model_address .= $model_house;
  $model_address .= $model_postal_code;
  $model_address .= $model_city;
  $model_address .= $model_appartment;
  $model_address .= $model_tax_id;
  $model_address .= '</div>';

  $address_prefix = '<div class="mpi-address-prefix">' . $address_variables['prefix'] . '</div>';
  $address_content = '<div class="mpi-address-content">' . $customer_address . $model_address . '</div>';
  $address_suffix = '<div class="mpi-address-suffix">' . $address_variables['suffix'] . '</div>';

  $address = '<div class="mpi-address">';
  $address .= $address_prefix;
  $address .= $address_content;
  $address .= $address_suffix;
  $address .= '</div>';

  // Content - Job.
  $job_variables = $page_variables['content']['job'];

  $start_date = $job_variables['job_dates']['start_date'];
  $end_date = $job_variables['job_dates']['end_date'];

  $job_start_date = '<div class="mpi-job-start-date">' . $start_date->format('Y-m-d') . '</div>';
  $job_start_time = '<div class="mpi-job-start-time">' . $start_date->format('G:i A') . '</div>';

  $job_end_date = '<div class="mpi-job-end-date">' . $end_date->format('Y-m-d') . '</div>';
  $job_end_time = '<div class="mpi-job-end-time">' . $end_date->format('G:i A') . '</div>';

  $job_dates = '<div class="mpi-job-dates">';
  $job_dates .= $job_start_date;
  $job_dates .= $job_start_time;
  $job_dates .= '<span class="mpi-dates-separator"></span>';
  $job_dates .= $job_end_date;
  $job_dates .= $job_end_time;
  $job_dates .= '</div>';

  $job_company_name = '<div class="mpi-customer-compamny-name">';
  $job_company_name .= $job_variables['company'];
  $job_company_name .= '</div>';

  $job_details = '<div class="mpi-job-details">';
  $job_details .= $job_variables['details'];
  $job_details .= '</div>';

  $job = '<div class="mpi-job">';
  $job .= $job_dates;
  $job .= $job_company_name;
  $job .= $job_details;
  $job .= '</div>';

  // Content - Bills.
  $bills_variables = $page_variables['content']['bills'];

  // Content - main lines.
  $main_lines_prefix = '<div class="mpi-main-prefix mpi-prefix">'
    . $bills_variables['main']['prefix'] . '</div>';
  $main_lines_suffix = '<div class="mpi-main-prefix mpi-suffix">'
    . $bills_variables['main']['suffix'] . '</div>';

  $lines = array();
  foreach ($bills_variables['main']['lines'] as $key => $line) {
    $label = $line['label'];
    if ($key == 0) {
      $qty = '<div class="mpi-qty-num">' . floor($line['quantity']) . '</div><div class="mpi-number-of-days">' . t('(Number of days)') . '</div>';
      $netto = commerce_currency_format($line['amount'], $line['currency_code']);
    }
    else {
      $qty = $netto = '&nbsp;';
    }
    $total = commerce_currency_format($line['amount'], $line['currency_code']);

    $bill_line = '<div class="mpi-main-bill-line">';
    $bill_line .= '<div class="mpi-label">' . $label . '</div>';
    $bill_line .= '<div class="mpi-qty">' . $qty . '</div>';
    $bill_line .= '<div class="mpi-netto">' . $netto . '</div>';
    $bill_line .= '<div class="mpi-brutto mpi-total">' . $total . '</div>';
    $bill_line .= '</div>';

    $lines[] = $bill_line;
  }
  $main_lines_content = '<div class="mpi-main-bills-content">' . implode('', $lines) . '</div>';

  $title_line = '<div class="mpi-main-bill-line">';
  $title_line .= '<div class="mpi-label">&nbsp;</div>';
  $title_line .= '<div class="mpi-qty">&nbsp;</div>';
  $title_line .= '<div class="mpi-netto">' . t('netto') . '</div>';
  $title_line .= '<div class="mpi-brutto mpi-total">' . t('brutto') . '</div>';
  $title_line .= '</div>';

  $main_lines = '<div class="mpi-main-bills">';
  $main_lines .= $main_lines_prefix;
  $main_lines .= $title_line;
  $main_lines .= $main_lines_content;
  $main_lines .= $main_lines_suffix;
  $main_lines .= '</div>';

  // Content - TAX lines.
  $tax_lines_prefix = '<div class="mpi-tax-prefix mpi-prefix">' . $bills_variables['tax']['prefix'] . '</div>';
  $tax_lines_suffix = '<div class="mpi-tax-suffix mpi-suffix">' . $bills_variables['tax']['suffix'] . '</div>';

  $lines = array();
  foreach ($bills_variables['tax']['lines'] as $key => $line) {
    $label = $line['label'];
    $qty = $netto = '&nbsp;';
    $total = commerce_currency_format($line['amount'], $line['currency_code']);

    $bill_line = '<div class="mpi-main-bill-line">';
    $bill_line .= '<div class="mpi-label">' . $label . '</div>';
    $bill_line .= '<div class="mpi-qty">' . $qty . '</div>';
    $bill_line .= '<div class="mpi-netto">' . $netto . '</div>';
    $bill_line .= '<div class="mpi-brutto mpi-total">' . $total . '</div>';
    $bill_line .= '</div>';

    $lines[] = $bill_line;
  }
  $tax_lines_content = '<div class="mpi-main-bills-content">' . implode('', $lines) . '</div>';

  $tax_lines = '<div class="mpi-tax-bills">';
  $tax_lines .= $tax_lines_prefix;
  $tax_lines .= $tax_lines_content;
  $tax_lines .= $tax_lines_suffix;
  $tax_lines .= '</div>';

  // Content - Additional lines.
  $additional_lines_prefix = '<div class="mpi-additional-prefix mpi-prefix">' . $bills_variables['additional']['prefix'] . '</div>';
  $additional_lines_suffix = '<div class="mpi-additional-suffix mpi-suffix">' . $bills_variables['additional']['suffix'] . '</div>';

  $lines = array();
  foreach ($bills_variables['additional']['lines'] as $key => $line) {
    $label = $line['label'];
    $qty = $netto = '&nbsp;';
    $total = commerce_currency_format($line['amount'], $line['currency_code']);

    $bill_line = '<div class="mpi-main-bill-line">';
    $bill_line .= '<div class="mpi-label">' . $label . '</div>';
    $bill_line .= '<div class="mpi-qty">' . $qty . '</div>';
    $bill_line .= '<div class="mpi-netto">' . $netto . '</div>';
    $bill_line .= '<div class="mpi-brutto mpi-total">' . $total . '</div>';
    $bill_line .= '</div>';

    $lines[] = $bill_line;
  }
  $additional_lines_content = '<div class="mpi-main-bills-content">' . implode('', $lines) . '</div>';

  $additional_lines = '<div class="mpi-additional-bills">';
  $additional_lines .= $additional_lines_prefix;
  $additional_lines .= $additional_lines_content;
  $additional_lines .= $additional_lines_suffix;
  $additional_lines .= '</div>';

  // Content - total part.
  $total_variables = $bills_variables['total'];

  $total_label = '<div class="mpi-total-invoice-label">';
  $total_label .= $total_variables['label'];
  $total_label .= '</div>';

  $total_value = '<div class="mpi-total-invoice-value">';
  $total_value .= commerce_currency_format($total_variables['amount'], $total_variables['currency_code']);
  $total_value .= '</div>';

  $total = '<div class="mpi-total-invoice">';
  $total .= $total_label;
  $total .= $total_value;
  $total .= '</div>';

  $content = '<div class="mpi-content">';
  $content .= $address;
  $content .= $job;
  $content .= $main_lines;
  $content .= $tax_lines;
  $content .= $additional_lines;
  $content .= $total;
  $content .= '</div>';

  // Footer.
  $footer_variables = $page_variables['footer'];
  $footer_part_1 = '<div class="mpi-footer-part mpi-footer-part-1">' . $footer_variables['part_1'] . '</div>';
  $footer_part_2 = '<div class="mpi-footer-part mpi-footer-part-2">' . $footer_variables['part_2'] . '</div>';

  $footer = '<div class="mpi-footer">';
  $footer .= $footer_part_1;
  $footer .= $footer_part_2;
  $footer .= '</div>';

  $output = '<div class="mpi-invoice">';
  $output .= $header;
  $output .= $content;
  $output .= $footer;
  $output .= '</div>';

  return $output;
}
