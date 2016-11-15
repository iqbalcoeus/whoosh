<?php

$aliases['modelplatform.live'] = array(
  'uri' => 'live-modelplatform.pantheonsite.io',
  'db-url' => 'mysql://pantheon:85e9525cf27c4e48b1575c101dec38c3@dbserver.live.20919ea0-2cf3-47ab-bc15-18a63538bb6a.drush.in:16862/pantheon',
  'db-allows-remote' => TRUE,
  'remote-host' => 'appserver.live.20919ea0-2cf3-47ab-bc15-18a63538bb6a.drush.in',
  'remote-user' => 'live.20919ea0-2cf3-47ab-bc15-18a63538bb6a',
  'ssh-options' => '-p 2222 -o "AddressFamily inet"',
  'path-aliases' => array(
    '%files' => 'code/sites/default/files',
    '%drush-script' => 'drush',
  ),
);

