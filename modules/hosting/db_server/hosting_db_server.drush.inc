<?php
// $Id: hosting_db_server.drush.inc,v 1.2 2009/05/07 22:04:10 adrian Exp $

function drush_hosting_db_server_pre_hosting_task($task) {
  $task =& drush_get_context('HOSTING_TASK');
  if ($task->ref->type == 'platform' && $task->task_type == 'verify') {
    $task->options['master_db'] = hosting_db_server_as_url(HOSTING_DEFAULT_DB_SERVER);
  }
  if ($task->ref->type == 'site') {
    $task->options['db_id'] = $task->ref->db_server;
  }
}

