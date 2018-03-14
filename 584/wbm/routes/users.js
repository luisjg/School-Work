var express = require('express');
var router = express.Router();

/*
 * GET userlist.
 */
router.get('/wbmcollection', function(req, res) {
    var db = req.db;
    var collection = db.get('wbmcollection');
    collection.find({},{},function(e,docs){
        res.json(docs);
    });
});

/*
 * POST to adduser.
 */
router.post('/addchatmsg', function(req, res) {
    var db = req.db;
    var collection = db.get('chatmsghistory');
    collection.insert(req.body, function(err, result){
        res.send(
            (err === null) ? { msg: 'blow me' } : { msg: err }
        );
    });
});

router.get('/getchatmsg', function(req, res) {
    var db = req.db;
    var collection = db.get('chatmsghistory');
    collection.find({},{},function(e,docs){
        res.json(docs);
    });
});

module.exports = router;
