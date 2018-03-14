var socket = io();
var jsonDataWebms;
var index, len;

// enables the mobile navigation menu
$(".button-collapse").sideNav();

$('#usersbox').submit(function(e) {
  // prevent the form from submitting
  e.preventDefault();
  socket.emit('new user', $('#set-user-name').val(), function(check) {
    if(check) {
      $('#user-name').hide();
      $('#container').show();
    } else {
      $('#errors').html('User already exists');
    }
  });

  $('#set-user-name').val('');
});
/**
  * This first method is the message sender
  * it works by using an emmitter which sends a 'chat message' "object"
  * it is sent from #m's value
  */
$('#chatbox').submit(function(e) {

  $.ajaxSetup({
  async: false
  });

  $.getJSON( "http://localhost:3000/users/wbmcollection", function( json ) {
    jsonDataWebms = json;
    // console.log( "JSON Data: " + json[ 0 ].chatkey );
  });
  // prevent the form from submitting
  e.preventDefault();
  // Here's a basic webm interaction
  for(index = 0, len = jsonDataWebms.length; index < len; ++index)
  {
      if ($('#m').val() == jsonDataWebms[index].chatkey) {
        // TODO: Figure out how to detect webm playing or not
        //socket.emit('chat message', $('#m').val());
        webmSend(jsonDataWebms[index].url);
      }
  }
  chatMessage();
  return false;
});

/**
 * Issue the message to the client
 */
function chatMessage() {
  console.log("chat message");
  if($('#m').val() != '') {
    socket.emit('chat message', $('#m').val());
  }
  $('#m').val('');
  /*
  // If it is, compile all user info into one object
      var newUser = {
          'username': $('#addUser fieldset input#inputUserName').val(),
          'email': $('#addUser fieldset input#inputUserEmail').val(),
          'fullname': $('#addUser fieldset input#inputUserFullname').val(),
          'age': $('#addUser fieldset input#inputUserAge').val(),
          'location': $('#addUser fieldset input#inputUserLocation').val(),
          'gender': $('#addUser fieldset input#inputUserGender').val()
      }
      // Use AJAX to post the object to our adduser service
      $.ajax({
          type: 'POST',
          data: newUser,
          url: '/users/adduser',
          dataType: 'JSON'
      }).done(function( response ) {
          // Check for successful (blank) response
          if (response.msg === '') {
              // Clear the form inputs
              $('#addUser fieldset input').val('');
              // Update the table
              populateTable();
          }
          else {
              // If something goes wrong, alert the error message that our service returned
              alert('Error: ' + response.msg);
          }
          */
}
/**
 * This sends the webm to the socket so we 
 * can listen in on it and take action
 */
function webmSend(webmURL) {
  socket.emit('webm', webmURL);
  $('#m').val('');
}

/**
  * This method is the listener for messages from other sockets
  */
socket.on('chat message', function(data) {
  $('#messages').append('<li><b>' + data.user + ':</b> ' + data.msg + '</li><br>');
});

socket.on('webm', function(webmURL) {
  console.log("hello");
  $.getJSON( "http://localhost:3000/users/wbmcollection", function( json ) {
    jsonDataWebms = json;
    // console.log( "JSON Data: " + json[ 0 ].chatkey );
  });
  $('#m').val('');
  $('#webm video').detach();
  $('<video width="640" height="360" frameborder="0" preload controls autoplay><source src="'+ webmURL + '" /></video>')
    // TODO: Make the addition be dynamic
    // TODO: Fill our database with generic tokens that link to webms
    .appendTo("#webm");
  $('#webm video').show();
  // TODO: we should figure out if we want to fade out or not
  $('#webm video').delay(8000).fadeOut('slow');
});

/**
 * This updates the user names to the front end so that
 * we know who is logged in
 */
socket.on('usernames', function(users) {
  var str = '';
  for(i = 0; i<users.length; i++) {
    str += '<li><b>' + users[i] + '</b></li>';
  }
  $('#users').html(str);
});