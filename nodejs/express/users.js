var express = require('express');
var connection = require('./connection');
var cors = require('cors');
var pwd = require('./password_hash');
const USER_ROUTE = "/users";
var app = express();

//required to access input submitted via post,put, delete method 
app.use(express.urlencoded({ extended: true }));
app.use(express.json()); // New line added
app.use(cors());

//purpose : used to register new user
//method : post
// url : http://localhost:8076/users/register
// input : email,mobile,password (all required)
app.post(USER_ROUTE + "/register", function (request, response) {


    var { email, password, mobile } = request.body;
    if (email === undefined || password === undefined || mobile === undefined) {
        response.json([{ 'error': 'input is missing' }]);
    }
    else {
        pwd.HashPassword(password).then((hash) => {
            let data = [email, hash, mobile];
            var sql = "insert into users (email,password,mobile) values (?,?,?)";
            //? means placeholders (now create an array which 3  value)
            connection.con.query(sql, data, function (error, result) {
                if (error) {
                    if (error.code === 'ER_DUP_ENTRY')
                        response.json([{ 'error': 'Email/Mobile is already registered with us' }])
                    else
                        response.json([{ 'error': 'error occured' }])
                    console.log(error);
                }
                else {
                    response.json([{ 'error': 'no' }, { 'message': 'register sucessfully' }]);
                }
            });
        })
    }
});
//purpose : used to login as user
//method : post
// url : http://localhost:8076/users/login
// input : email,password (all required)
app.post(USER_ROUTE + "/login", function (request, response) {
    var { email, password } = request.body;
    if (email === undefined || password === undefined) {
        response.json([{ 'error': 'input is missing' }]);
    }
    else {
        //fetch passsword of those row whose email matches with inputed email
        var sql = "select id,password from users where email=?";
        var data = [email];
        connection.con.query(sql, data, function (error, result) {
            if (error) {
                response.json([{ 'error': 'error occured' }]);
                console.log(error);
            }
            else {
                if (result.length === 0)
                    response.json([{ 'error': 'no' }, { 'success': 'no' }, { 'message': 'invalid login' }]);
                else {
                    //fetch hashed password into hashed_password variable
                    var hashed_password = result[0]['password'];
                    var id = result[0]['id'];

                    //match hashed password with original password
                    pwd.MatchPassword(hashed_password, password).then((result) => {
                        if (result === true)
                            response.json([{ 'error': 'no' }, { 'success': 'yes' }, { 'message': 'login successfull' }, { 'id': id }]);
                        else
                            response.json([{ 'error': 'no' }, { 'success': 'no' }, { 'message': 'invalid login' }]);
                    });

                }
            }
        })
    }
});


//change password 
//purpose : used to change password
//method : post
// url : http://localhost:8076/users/change-password
// input : id,password,newpassword (all required)
app.post(USER_ROUTE + "/change-password", function (request, response) {
    var { id, password, newpassword } = request.body;
    if (id === undefined || password === undefined || newpassword === undefined)
        response.json([{ 'error': 'input is missing' }]);
    else {
        //fetch hashed_password from table whose id matched with inputed id 
        let sql = "select password from users where id=?";
        let data = [id];
        connection.con.query(sql, data, function (error, result) {
            if (error) {
                response.json([{ 'error': 'error occured' }]);
                console.log(error);
            }
            else {
                if (result.length === 0)
                    response.json([{ 'error': 'no' }, { 'success': 'no' }, { 'message': 'authorization failed' }]);
                else {
                    //fetch hashed password into hashed_password variable
                    var hashed_password = result[0]['password'];

                    //now match hashed password with inputed password
                    pwd.MatchPassword(hashed_password, password).then((result) => {
                        if (result === true) {
                            //generate new hash password 
                            pwd.HashPassword(newpassword).then((hash) => {

                                //now update password with new hashed password 
                                var sql = "update users set password=? where id=?";
                                let data = [hash, id];
                                //? means placeholders (now create an array which 3  value)
                                connection.con.query(sql, data, function (error, result) {
                                    if (error)
                                        response.json([{ 'error': 'password could not updated' }])
                                    else
                                        response.json([{ 'error': 'no' }, { 'success': 'yes' }, { 'message': 'password changed' }]);
                                });
                            });
                        }
                        else
                            response.json([{ 'error': 'no' }, { 'success': 'no' }, { 'message': 'authorization failed' }]);
                    });
                }
            }
        });
    }
});

//forgot password 
//purpose : used to generate new password and send it as email when user use forgot password
//method : post
// url : http://localhost:8076/users/forgot-password
// input : id,password,newpassword (all required)

app.post(USER_ROUTE + "/forgot-password", function (request, response) {
    var email = request.body.email;

    if (email === undefined) {
        return response.json([{ 'error': 'Input is missing' }]);
    }

    var sql = "SELECT password FROM users WHERE email = ?";
    var data = [email];

    // Query the database for the email
    connection.con.query(sql, data, function (error, result) {
        if (error) {
            console.log("Database error:", error);
            return response.json([{ 'error': 'An error occurred while querying the database' }]);
        }

        // Check if the email exists in the database
        if (result.length === 0) {
            return response.json([{ 'error': 'no' }, { 'success': 'no' }, { 'message': 'Authorization failed' }]);
        }

        // Email found, generate a new password
        var generator = require("./mypassword");
        var new_random_password = generator.getRandomPassword(12);

        // Hash the new password
        pwd.HashPassword(new_random_password).then((hash) => {
            sql = "UPDATE users SET password = ? WHERE email = ?";
            data = [hash, email];

            // Update the user's password in the database
            connection.con.query(sql, data, function (error, result) {
                if (error) {
                    console.log("Database update error:", error);
                    return response.json([{ 'error': 'An error occurred while updating the password' }]);
                }

                // Send email to the user with the new password
                var g = require('./gmail');
                var mailer = new g.gmail();  // Renamed from 'email' to 'mailer' to avoid conflict with user email variable
                var subject = 'Password Recovery Email';
                var message = `We have recovered your password. \nYour new password is: ${new_random_password}`;

                // Send the recovery email
                console.log('Attempting to send email...');
                mailer.send(email, subject, message, function (err, info) {
                    if (err) {
                        console.log("Error sending email:", err);
                        return response.json([{ 'error': 'Failed to send recovery email', 'details': err.message }]);
                    } else {
                        console.log('Email sent successfully:', info.response);
                        return response.json([{ 'error': 'no' }, { 'success': 'yes' }, { 'message': 'We have sent your new password to your registered email address' }]);
                    }
                });
            });
        }).catch((err) => {
            console.log("Password hashing error:", err);
            return response.json([{ 'error': 'Failed to hash the password' }]);
        });
    });
});

app.listen(8076);
console.log('ready to accept request');