var express = require('express');
var router = express.Router();

/* GET home page.
router.get('/', function(req, res, next) {
  res.render('index', { title: 'Express' });
});
*/
//router.use(express.static('C:\\node\\wbmchat\\public\\html\\index.html'));

var path = require('path');

router.use(express.static(path.resolve() + '/public/html/index.html' ));


router.get('/', function(req, res) {
  res.sendFile(path.resolve() + '/public/html/index.html');
});

module.exports = router;
