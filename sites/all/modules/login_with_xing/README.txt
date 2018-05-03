-------------------------------------------------------------------------------
XING CONNECT MODULE for Drupal 7.x
  by Ajay Nimbolkar - ajaynimbolkar (at) gmail (dot) com
-------------------------------------------------------------------------------

DESCRIPTION:
------------
What does this module do?
* Allow users to register with Xing, their usename, email, profile pic can be
synced to their Drupal account.
* Allow users to login with Xing.

How it works
User can click on the "login with XING" link on the user login page/ User login
block

When the user click the "login with XING" link, it automatically takes
user to Xing and asks for his permission. Once granted the module checks
the users email. If the email address is found on the Drupal Site, he is logged
in automatically. Otherwise a new user account is created with the email address
and the user is logged in.
-------------------------------------------------------------------------------

INSTALLATION:
-------------
* Put the module in your Drupal modules directory and enable it in
  admin/modules.
* Using Drush :: drush pm-enable login_with_xing
-------------------------------------------------------------------------------

CONFIGURATION:
-------------
1) Create a new plugin in dev.xing.com
This will give you an App ID/API Key and an App Secret
2)Open Configuration form such as admin/config/people/login_with_xing
3) Enter your plugin consumer key
