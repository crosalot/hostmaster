<?php

/**
 * Select theme
 */
function mbuild_select_theme_form(&$form_state) {
  $options = array(
    'technology' => t('Technology'),
    'kid' => t('Kid'),
    'people' => t('People'),
    'green' => t('Green'),
  );

  if (!oneclick_address_validate($_GET['address']) || !array_key_exists($_GET['category'], $options)) {
    drupal_goto();
    return;
  }
  $address = $_GET['address'];
  $category = $_GET['category'];

  $form['address'] = array(
    '#type' => 'value',
    '#value' => $address,
  );
  $form['category'] = array(
    '#type' => 'value',
    '#value' => $category,
  );


  $form['address-markup'] = array(
    '#type' => 'markup',
    '#value' => theme('mbuild_info_address', $address),
  );

  $form['oneclick_second_step'] = array(
    '#type' => 'markup',
    '#value' => '<div class="oneclick-second-step"></div><div class="oneclick-line"></div>',
  );

  $form['wrap1'] = array(
    '#type' => 'markup',
    '#value' => '<div id="second-from-wrapper">',
  );

  $packages = mbuild_get_packages();

  $options = array();
  foreach ($packages as $package) {
    $options[$package->machine_name] = theme(
      'mbuild_package_item',
      $package->drupal_path,
      $package->name,
      $package->preview_image);
  }

  $form['submit-1'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  $form['package'] = array(
    '#type' => 'radios',
    '#title' => t('Select theme'),
    '#options' => $options,
    '#prefix' => '<div id="select-theme-wrapper">',
    '#suffix' => '</div>',
    '#required' => TRUE,
  );

  $form['submit-2'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  $form['wrap2'] = array(
    '#type' => 'markup',
    '#value' => '</div>',
  );

  drupal_add_css(drupal_get_path('module', 'mbuild') .'/mbuild.css');
  drupal_add_js(drupal_get_path('module', 'mbuild') .'/mbuild.js');

  return $form;
}

/**
 * Implementation of hook_form_validate().
 */
function mbuild_select_theme_form_validate($form, &$form_state) {
  // pass
}

/**
 * Implementation of hook_form_validate().
 */
function mbuild_select_theme_form_submit($form, &$form_state) {
  global $user;
  $address = $form_state['values']['address'];
  $package = $form_state['values']['package'];
  $category = $form_state['values']['category'];
  if (user_is_logged_in()) {
    oneclick_build_all($user, array(
      'address' => $address.'.'.$_SERVER['SERVER_NAME'],
      'package' => $package,
      'category' => $category,
    ));
  }
  else {
    drupal_goto('step/3', array(
      'address' => $address,
      'package' => $package,
      'category' => $category,
    ));
  }
}
