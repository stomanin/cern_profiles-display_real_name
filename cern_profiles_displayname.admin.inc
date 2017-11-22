<?php

// $Id$


/**
 * @file: Form builder; display the cern_Profiles_displayname settings form.
 *
 * @see cern_profiles_displayname_settings_form_submit()
 */
function cern_profiles_displayname_settings_form($form, &$form_state) {

  //LDAP configurations
  $form['LDAP'] = array('#type' => 'fieldset', '#title' => t('LDAP configurations'));

  $form['LDAP']['LDAP_server'] = array(
    '#type' => 'textfield',
    '#title' => t('LDAP server'),
    '#description' => t('LDAP server to connect to in order to retrieve user\'s name to diplay.'),
    '#default_value' => variable_get('LDAP_server', DEFAULT_LDAP_SERVER),
    '#required' => TRUE,
  );
  $form['LDAP']['LDAP_port'] = array(
    '#type' => 'textfield',
    '#title' => t('LDAP port'),
    '#description' => t('LDAP port for the server to connect to in order to retrieve user\'s name to diplay.'),
    '#default_value' => variable_get('LDAP_port', DEFAULT_LDAP_PORT),
    '#required' => TRUE,
  );
  $form['LDAP']['LDAP_base_dn'] = array(
    '#type' => 'textarea',
    '#title' => t('LDAP Base dn'),
    '#description' => t('Base DN: Distinguished Name to perform your queries on.'),
    '#default_value' => variable_get('LDAP_base_dn', DEFAULT_LDAP_BASE_DN),
    '#required' => TRUE,
  );
  
  $form['LDAP']['LDAP_user_bind'] = array(
    '#type' => 'textfield',
    '#title' => t('LDAP Binding username'),
    '#description' => t('Some servers don\'t allow anonymous queries. Here goes the username for binding to the server or leave it empy for anonymous binding.<br>Required expression: <em>"cn= %username, %baseDN</em>'),
    '#default_value' => variable_get('LDAP_user_bind', DEFAULT_LDAP_USER_BIND),
    '#required' => FALSE,
  );
  $form['LDAP']['LDAP_pass_bind'] = array(
    '#type' => 'password',
    '#title' => t('LDAP Binding password'),
    '#description' => t('Some servers don\'t allow anonymous queries. Here goes the password for the username for binding to the server or leave it empy for anonymous binding.'),    
    '#default_value' => variable_get('LDAP_pass_bind', DEFAULT_LDAP_PASS_BIND),
    '#required' => FALSE,
  );
  
  
  $form['LDAP']['attribute'] = array(
    '#type' => 'textfield',
    '#title' => t('LDAP Attribute'),
    '#description' => t('LDAP attribute to display instead of the login name.'),    
    '#default_value' => variable_get('attribute', DEFAULT_ATTRIBUTE),
    '#required' => TRUE,
  );
  
  

  // Displayname configurations
  $form['Displayname_configurations'] = array('#type' => 'fieldset', '#title' => t('Real name configurations'));

  $form['Displayname_configurations']['show_account_name'] = array(
  '#type' => 'checkbox',
  '#title' => t('Show account name (useful to recognize secondary accounts or services)'),
  '#description' => t('If option is disabled: <em>Silvia Tomanin</em> <br>If option is enabled: <em>Silvia Tomanin (stomanin)</em>'),    
  '#default_value' => variable_get('show_account_name', DEFAULT_SHOW_ACCOUNT_NAME),
  );



  
  //Redirect to Profiles site configuration
  $form['redirect'] = array('#type' => 'fieldset', '#title' => t('Configure redirect to CERN Profiles site'));
  
  $form['redirect']['enable_redirect'] = array(
  '#type' => 'checkbox',
  '#title' => t('Rewrite URLs'),
  '#description' => t('CERN users\' profiles are stored at the Profiles site: select this option to enable URL rewriting to point to the Profiles site instead of the local user profile. <br> NB: The path /user/&#60uid&#62 and all his subdirectories (ie. /user/&#60uid&#62/edit, /user/&#60uid&#62/devel) will be redirected.'),    
  '#default_value' => variable_get('enable_redirect', DEFAULT_ENABLE_REDIRECT),
  );
  
  $form['redirect']['profiles_site'] = array( 
    '#type' => 'textfield', 
    '#title' => t('Path to the default CERN Profiles site'),
    '#description' => t('Edit this path to point to this site clicking on the name for a user. NB! Trailing slash at the end of the URL needed.'),
    '#default_value' => variable_get('profiles_site', DEFAULT_PROFILES_SITE),
    '#required' => TRUE,
  );
  
  
  
  $form['redirect']['enable_redirect_pages'] = array(
  '#type' => 'checkboxes',
  '#title' => t('Check the user/subdirectory path you want to be redirected to the Profiles site'),
  '#description' => t('For example, if you check <em>edit</em> the subdirectory <em>/user/&#60uid&#62/edit</em> will be redirected to the profile for that user at the Profiles site.<br>This could be useful for development purposes.'),    
  '#options' => array(
        'edit' => t('edit/*'), 
        'contact' => t('contact/*'),
        'devel' => t('devel/*'), 
      ),
  '#default_value' => variable_get('enable_redirect_pages', array(DEFAULT_REDIRECT_EDIT, DEFAULT_REDIRECT_CONTACT, DEFAULT_REDIRECT_DEVEL)),
  '#states' => array(
    // Only make visible these checkboxes when the url rewrite option is enabled.
    'visible' => array(
      ':input[name="enable_redirect"]' => array('checked' => TRUE),
    ),
   ),
 );
  
  
  
  
  
  $form['#submit'][] = 'cern_profiles_displayname_settings_form_submit';
  return system_settings_form($form);
}

/**
 * Form submit handler for the cern_profiles_displayname settings form.
 *
 * @see cern_profiles_displayname_settings_form().
 */
function cern_profiles_displayname_settings_form_submit($form, $form_state) {
  // Clear the cern_profiles_displayname cache every time configurations are saved.
  cern_profiles_displayname_delete_all();
  //drupal_flush_all_caches();
  
}

/**
 * Form validate handler for the cern_profiles_displayname settings form.
 *
 * @see cern_profiles_displayname_settings_form().
 */

function cern_profiles_displayname_settings_form_validate($form, &$form_state) {
  $value = &$form_state['values']['profiles_site'];
  if (!valid_url($value, TRUE)) {
    form_error($form, t('The redirect path %value is not valid. The path must be absolute.', array('%value' => $value)));
  }
  if (!($value[strlen($value)-1] == '/')) {
    form_error($form, t('Trailing slash at the end of the path needed.'));
  }
}


