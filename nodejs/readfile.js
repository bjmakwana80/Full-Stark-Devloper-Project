var http = require('http');
var fs = require('fs');
var server = http.createServer(function(request,response){
    var url = request.url;
    console.log(url);
    var filename = url.substring(1);
    fs.readFile(filename,function(error,content){
        if(error){
            response.writeHead(404,{'content-type':'text/html'});
            response.write('no search page exists');
            return response.end();
        }
        else{
            response.writeHead(200,{'content-type':'text/html'});
            response.write(content);
            return response.end();
        }
    })

})
server.listen(8076);
console.log('ready to accept reqeust....');