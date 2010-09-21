$(document).ready(function() {
  //$('#edit-submit').attr('disabled', 'disabled');
  $('#edit-agree').click(function() {
    if (!this.checked) {
      //$('#edit-submit').attr('disabled', 'disabled');
    }
    else {
      $('#edit-submit').removeAttr('disabled');
    }
  })
  
  var oriwidth = $('#edit-address').css('width');
  
  $('#edit-address').focus(function () {
    $('#edit-address-wrapper').addClass('focus');
  }).blur(function () {
    $('#edit-address-wrapper').removeClass('focus');
  });
  
  $('#edit-address-wrapper').click(function () {
    $('#edit-address').focus();
  });
  
  $('#edit-has-domain').click(function () {
    if (this.checked) {
      $('.suffix-domain').fadeOut('fast');
      $('#edit-address').css('width', '100%');
      
    }
    else {
      $('.suffix-domain').fadeIn('fast');
      $('#edit-address').css('width', oriwidth);
      
    }
  })

});
