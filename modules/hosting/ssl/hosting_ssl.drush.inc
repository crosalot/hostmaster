<?php

// $Id: hosting_ssl.drush.inc,v 1.2 2009/09/13 13:12:56 anarcat Exp $

/**
 */
function drush_hosting_ssl_pre_hosting_task($task) {
  $task =& drush_get_context('HOSTING_TASK');

  if ($task->ref->type == 'site') {
    $task->options['ssl'] = $task->ref->ssl;
    $task->options['ssl_redirect'] = $task->ref->ssl_redirect;
  }
}
