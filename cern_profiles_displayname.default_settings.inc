<?php
  // $Id$  
 
 /**
 * @file: Set default values for configuration variables.
 */
  
  define('DEFAULT_LDAP_SERVER', ''); 	//LDAP server address ie. ldap.example.com
  define('DEFAULT_LDAP_PORT', '389');	// default LDAP port
  define('DEFAULT_LDAP_BASE_DN', ''); 	// LDAP Base DN ex. ou=orgunit,dc=example,dc=com
  define('DEFAULT_LDAP_USER_BIND', ''); 
  define('DEFAULT_LDAP_PASS_BIND', ''); 
  define('DEFAULT_ATTRIBUTE', 'displayname');
  
  define('DEFAULT_SHOW_ACCOUNT_NAME', FALSE);

  define('DEFAULT_ENABLE_REDIRECT', TRUE);
  define('DEFAULT_PROFILES_SITE', 'http://profiles.web.cern.ch/');
  define('DEFAULT_UNVERIFIED_ACCOUNT_PATH', 'unverified_account');
  define('DEFAULT_SERVICES_ACCOUNT_PATH', 'service_account');
  
  define('DEFAULT_REDIRECT_EDIT', TRUE);
  define('DEFAULT_REDIRECT_CONTACT', TRUE);
  define('DEFAULT_REDIRECT_DEVEL', FALSE);
  
