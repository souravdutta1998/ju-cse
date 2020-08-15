var server = require('ws').Server;
var s = new server({ port : 8080 });
var present = {};
s.on('connection', function(ws) {
	ws.on('message', function(message) {
		message = JSON.parse(message);
		
		if(message.type == "username") {
			ws.username = message.data;	
			if(present[ws.username] == 1) {	
				ws.username = "duplicateuser";
				present[ws.username] = 0;
				ws.send(JSON.stringify({
					type: "errormsg",
					data: "DUPLICATE-CLIENT"
				}));
				ws.close();
			}
			else {
				present[ws.username] = 1;
				s.clients.forEach(function(client){
					client.send(JSON.stringify({
						type: "username",
						data: ws.username
					}));
				});
				console.log(ws.username+" joined the chatroom");
			}
		}
		else if(message.type == "message") {
			console.log("Received from "+ws.username+": "+message.data);
			s.clients.forEach(function(client){
				if(client != ws) {
					client.send(JSON.stringify({
						type: "message",
						data: "<b>"+ws.username+":</b> "+message.data
					}));
				}
				
			});
		}
	});
	
	ws.on('close', function() {
		if(present[ws.username] == 1) {
			present[ws.username] = 0;
			console.log(ws.username+" left the chatroom");
			s.clients.forEach(function(client){
				client.send(JSON.stringify({
					type: "message",
					data: ws.username+" left the chatroom"
				}));
			});
		}		
	});
});