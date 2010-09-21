<?php

function mbuild_registration() {
  if (!user_is_logged_in()) {
    $output .= drupal_get_form('mbuild_login_form') .
               '<div id="second-from-wrapper">'.
                 drupal_get_form('user_register') .
                 drupal_get_form('user_login') .
               '</div>';

    return $output;
  }
  else {
    return;
  }
}

/**
* Login
*/
function mbuild_login_form(&$form_state) {
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

  $packages = mbuild_get_packages();
  $package = $packages[$_GET['package']];
  if (!$package) {
    drupal_set_message('You have selected invalid package.', 'error');
    drupal_goto();
    return;
  }

  $options = array();
  foreach ($packages as $package) {
    $options[$package->machine_name] = theme(
      'mbuild_package_item',
      $package->drupal_path,
      $package->name,
      $package->preview_image);
  }

  // Reset $package variable.
  $package = $packages[$_GET['package']];
  $form['package'] = array(
    '#type' => 'radios',
    '#options' => $options,
    '#default_value' => $_GET['package'],
    '#required' => TRUE,
    '#access' => FALSE,
  );

  $form['package-markup'] = array(
    '#type' => 'markup',
    '#value' => theme(
      'mbuild_info_package',
      $package->drupal_path,
      $package->name,
      $package->preview_image),
  );

  $form['oneclick_second_step'] = array(
    '#type' => 'markup',
    '#value' => '<div class="oneclick-third-step"></div><div class="oneclick-line"></div>',
  );

  drupal_add_css(drupal_get_path('module', 'mbuild') .'/mbuild.css');

  return $form;
}
