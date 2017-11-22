<?php
// $Id$
/**
 * @file
 * Builds placeholder replacement tokens for realname.
 */

/**
 * Implements hook_token_info().
 */
function cern_profiles_displayname_token_info() {
  $info['tokens']['user']['name-raw'] = array(
    'name' => t('Raw name'),
    'description' => t('The raw login name of the user account, unprocessed by the CERN Profiles Displayname module.'),
  );
  $info['tokens']['user']['cern-ccid'] = array(
    'name' => t('CERN CCID'),
    'description' => t('The CERN CCID of the user account, retrieved from LDAP by the CERN Profiles Displayname module.'),
  );

  return $info;
}

/**
 * Implements hook_token_info_alter().
 */
function cern_profiles_displayname_token_info_alter(&$info) {
  // Since the [user:name] token uses format_username(), its meta-data should
  // be altered to reflect that it will be the real name.
  $info['tokens']['user']['name']['name'] = t('CERN Real name');
  $info['tokens']['user']['name']['description'] = t('The real name of the user account.');
}

/**
 * Implements hook_tokens().
 */
function cern_profiles_displayname_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();
  $sanitize = !empty($options['sanitize']);

  if ($type == 'user' && !empty($data['user'])) {
    $account = $data['user'];

    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'name-raw':
          $replacements[$original] = $sanitize ? check_plain($account->name) : $account->name;
          break;
        case 'cern-ccid':
          $replacements[$original] = $sanitize ? check_plain($account->cernccid) : $account->cernccid;
          break;
      }
    }
  }

  return $replacements;
}
