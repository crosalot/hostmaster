<?php
// $Id: hosting_package.drush.inc,v 1.3 2009/05/20 19:36:24 adrian Exp $

function drush_hosting_package_pre_hosting_task() {
  $task =& drush_get_context('HOSTING_TASK');
  if ($task->ref->type == 'site') {
    $profile = node_load($task->ref->profile);
    if ($task->task_type != 'import') {
      $task->options['profile'] = $profile->short_name;
    }
  }
}

