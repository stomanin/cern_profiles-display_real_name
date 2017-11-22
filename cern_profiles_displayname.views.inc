<?php
/**
 * @file
 * Expose cernrealname and cernccid to views.
 */

function cern_profiles_displayname_views_data() {
  $data['cernrealname'] = array(
    'table' => array(
      'group' => 'User',
      'title' => 'CERN Realname',
      'join' => array(
        'users' => array(
          'left_field' => 'uid',
          'field' => 'uid',        
         ),
      ),
    ),
    'cernrealname' => array(
      'title' => t('CERN Realname'),
      'help' => t('CERN Realname generated by the CERN Profiles Displayname module.'), // The help that appears on the UI,
      // Information for displaying the uid
    'field' => array(
      'handler' => 'views_handler_field_user', 
      'click sortable' => TRUE,
    ), 
    'sort' => array(
      'handler' => 'views_handler_sort',
    ), 
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ), 
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    /*  'field' => array(
        'handler' => 'views_handler_field_node',
        'click sortable' => TRUE,
      ),*/

    ),
  );

  $data['cernccid'] = array(
    'table' => array(
      'group' => 'User',
      'title' => 'CERN CCID',
      'join' => array(
        'users' => array(
          'left_field' => 'uid',
          'field' => 'uid',        
         ),
      ),
    ),
    'cernccid' => array(
      'title' => t('CERN CCID'),
      'help' => t('CERN CCID generated by the CERN Profiles Displayname module.'), // The help that appears on the UI,
      // Information for displaying the uid
    'field' => array(
      'handler' => 'views_handler_field_user', 
      'click sortable' => TRUE,
    ), 
    'sort' => array(
      'handler' => 'views_handler_sort',
    ), 
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ), 
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
    /*  'field' => array(
        'handler' => 'views_handler_field_node',
        'click sortable' => TRUE,
      ),*/

    ),
  );

  return $data;  
}