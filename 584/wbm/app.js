//start mongodb as follows:mongod --dbpath c:\projectpath\data
var express = require('express');
var path = require('path');
var favicon = require('serve-favicon');
var logger = require('morgan');
var cookieParser = require('cookie-parser');
var bodyParser = require('body-parser');


// Database
var mongo = require('mongodb');
var monk = require('monk');
var db = monk('localhost:27017/wbmcollection');

var routes = require('./routes/index');
var users = require('./routes/users');
//var socket = require('./routes/socket.io');

var app = express();
var http = require('http').Server(app);
var io = require('socket.io')(http);

var usernames = [];
// view engine setup
app.set('views', path.join(__dirname, 'views'));
app.set('view engine', 'jade');

// uncomment after placing your favicon in /public
//app.use(favicon(path.join(__dirname, 'public', 'favicon.ico')));
app.use(logger('dev'));
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

// Make our db accessible to our router
app.use(function(req,res,next){
    req.db = db;
    next();
});

app.use('/', routes);
app.use('/users', users);
//app.use('/socket.io', socket);


// catch 404 and forward to error handler
app.use(function(req, res, next) {
  var err = new Error('Not Found');
  err.status = 404;
  next(err);
});

// error handlers

// development error handler
// will print stacktrace
if (app.get('env') === 'development') {
  app.use(function(err, req, res, next) {
    res.status(err.status || 500);
    res.render('error', {
      message: err.message,
      error: err
    });
  });
}

// production error handler
// no stacktraces leaked to user
app.use(function(err, req, res, next) {
  res.status(err.status || 500);
  res.render('error', {
    message: err.message,
    error: {}
  });
});

/**
  * This is the socket server
  * 'connection' is basically a listener (which listens to http server) for
  * incoming socket events
  */
io.on('connection', function(socket) {
  //let's create and check for user uniqueness
  socket.on('new user', function(data, callback) {
    if(usernames.indexOf(data) != -1) {
      callback(false);
    } else {
      callback(true);
      socket.nickname = data;
      usernames.push(socket.nickname);
      updateUsernames();
    }
  });
  //you can make custom events such as this 'chat message'
  socket.on('chat message', function(data) {
    io.emit('chat message', {msg: data , user: socket.nickname});
  });

  //the wbm socket
  socket.on('webm', function(url) {
    io.emit('webm', url);
  });

/**
 * This handles the usernames when a user exits the application
 * 'disconnect' is a built in listener that listens in on when
 * a disconnect occurs
 */
  socket.on('disconnect', function() {
    if(!socket.nickname) return;
    usernames.splice(usernames.indexOf(socket.usernames), 1);
    updateUsernames();
  });
  // TODO: Figure out if we want webm to be integrated in the chat or apart
  // TODO: Listener for new users
  // TODO: Listener for new message (connect to db)
});

/**
 * Updates the usernames lis
 */
function updateUsernames() {
    io.emit('usernames', usernames);
}

// Set server port and run it
http.listen(3000, function() {
  console.log('server is running on http://localhost:3000');
});

module.exports = app;
