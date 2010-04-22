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
});
