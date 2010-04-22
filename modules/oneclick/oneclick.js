/*
$(document).ready(function() {
  var domain = Drupal.settings.domain;
  var site_id = Drupal.settings.site_id;
  var root_site= Drupal.settings.root_site;
  var checksite = setInterval(function() {
    // TODO: Build url in client site and return waiting = false
    $.getJSON('/oneclick/site/' + site_id + '/success', function(resp1) {
      if(resp1.success){
        clearInterval(checksite);
        setTimeout(function() {
          window.location.href = 'http://' + domain;
        }, 10*1000);
      }
    });
  }, 10*1000);
});
*/

/**
 * Attaches the batch behavior to progress bars.
 */
Drupal.behaviors.oneclick = function(context) {
  $('#oneclick-progress').each(function () {
    var holder = this;
    var uri = Drupal.settings.oneclick.uri;

    var updateCallback = function (progress, status, pb) {
      if (progress == 100) {
        pb.stopMonitoring();
        window.location = 'http://' + Drupal.settings.oneclick.domain;
      }
    };

    var progress = new Drupal.progressBar('oneclick', updateCallback, "POST");
    $(holder).append(progress.element);
    progress.startMonitoring(uri, 1000);
  });
};

