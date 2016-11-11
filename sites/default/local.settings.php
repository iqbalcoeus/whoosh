<?php

// Fast 404 pages.
$conf['404_fast_paths_exclude'] = '/\/(?:styles)\//';
$conf['404_fast_paths'] = '/\.(?:txt|png|gif|jpe?g|css|js|ico|swf|flv|cgi|bat|pl|dll|exe|asp)$/i';
$conf['404_fast_html'] = '<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML+RDFa 1.0//EN" "http://www.w3.org/MarkUp/DTD/xhtml-rdfa-1.dtd"><html xmlns="http://www.w3.org/1999/xhtml"><head><title>404 Not Found</title></head><body><h1>Not Found</h1><p>The requested URL "@path" was not found on this server.</p></body></html>';

$databases['default']['default'] = array(
  'driver' => 'mysql',
  'database' => 'modelplatform_backup',
  'username' => 'root',
  'password' => 'cImp8yoga',
  'host' => 'localhost',
  'prefix' => '',
);
$update_free_access = FALSE;