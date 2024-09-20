var mysql = require('mysql');
var con = mysql.createConnection({
    host: 'localhost',
    user: 'root',    // 'user' instead of 'username'
    password: '',    // root's password (empty string here)
    port: 3308,
    database: 'myapp'
});
con.connect(function(error){
    if(error!=null)
        console.log(error);
    else 
        console.log('connection created successfully');
});
module.exports.con = con;