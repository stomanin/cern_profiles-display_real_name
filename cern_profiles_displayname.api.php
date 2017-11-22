<?php

/**
 * @file
 * Hooks provided by the cern_profiles_displayname module.
 */


/**
 * Alter a user's real name before it is saved to the database.
 *
 * @param $realname
 *   The user's generated real name.
 * @param $account
 *   A user account object.
 *
 * @see cern_profiles_displayname_update()
 *
 * @ingroup cern_profiles_displayname
 */
function hook_cern_profiles_displayname_alter(&$realname, $account) {

}

/**
 * Respond to updates to an account's real name.
 *
 * @see cern_profiles_displayname_update()
 *
 * @ingroup cern_profiles_displayname
 */
function hook_cern_profiles_displayname_update($realname, $account) {

}

/**
 * @} End of "addtogroup hooks".
 */