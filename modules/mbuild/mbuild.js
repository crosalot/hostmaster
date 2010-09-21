$(document).ready(function () {
  $('.form-radios > .form-item').click(function () {
    $('.form-radios > .form-item').removeClass('selected');
    $(this).addClass('selected');
  });
});