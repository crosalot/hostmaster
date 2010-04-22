<?php
// $Id: hosting_alias.drush.inc,v 1.5 2009/10/15 10:32:24 mig5 Exp $

function drush_hosting_alias_pre_hosting_task() {
  if (module_exists('hosting_alias')) {
    $task =& drush_get_context('HOSTING_TASK');
    if (($task->ref->type == 'site') && (in_array($task->task_type, array('install', 'verify', 'migrate', 'enable')))) {
      $task->options['aliases'] = implode(",", hosting_alias_get_aliases($task->ref));
      $task->options['redirection'] = db_result(db_query("SELECT redirection FROM {hosting_site_alias} WHERE vid=%d", $task->ref->vid));
    }
  }
}
