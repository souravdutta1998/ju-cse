var server = require('ws').Server;
var s = new server({ port : 8080 });
var dict = {};
var auth = {};
s.on('connection', function(ws){
	ws.on('message', function(message) {
		message = JSON.parse(message);
		
		if(message.type == "clientId") {
			ws.clientId = message.data;
			if(auth[ws.clientId] == "guest" || auth[ws.clientId] == "manager") {
				console.log("ERROR: DUPLICATE CLIENT ID!");
				//ws.send("DUPLICATE-CLIENT");
				ws.clientId = "duplicateuser";
				ws.send(JSON.stringify({
					type: "errormsg",
					data: "DUPLICATE-CLIENT"
				}));
				ws.close();
				return;
			}
			auth[ws.clientId] = "guest";
			dict[ws.clientId] = {};
			console.log("Client with clientId "+ws.clientId+" connected!");
			//return;
		}
		else if(message.type == "PUT") {
			console.log("PUT REQUEST:");
			dict[ws.clientId][message.key] = message.value;
			console.log("The value of '"+message.key+"' as '"+message.value+"' is inserted in "+ws.clientId+"'s key-store");
		}
		else if(message.type == "GET") {
			console.log("GET REQUEST:");
			if(auth[ws.clientId] == "guest") {
				var val = dict[ws.clientId][message.key];
				if(typeof val == "undefined") {
					//ws.send("blank");
					ws.send(JSON.stringify({
						type: "message",
						data: "blank"
					}));
					console.log(message.key+" could not be found in "+ws.clientId+"'s key-store!");
					console.log("Sending the value of '"+message.key+"' as "+"<blank>");
				} else {
					//ws.send(val);
					ws.send(JSON.stringify({
						type: "message",
						data: val
					}));
					console.log("Sending the value of '"+message.key+"' as '"+val+"' from "+ws.clientId+"'s key-store");
				}			
			}
			else if(auth[ws.clientId] == "manager") {
				console.log(message.key+" could not be found in "+ws.clientId+"'s key-store!");
				console.log("Since the client is a manager, Searching for the value in other client's key-stores");
				var val = dict[ws.clientId][message.key];
				if(typeof val == "undefined") {
					var found = 0;
					s.clients.forEach(function(client){
						var val = dict[client.clientId][message.key];
						if(typeof val != "undefined") {
							found = 1;
							//ws.send(val);
							ws.send(JSON.stringify({
								type: "message",
								data: val
							}));
							console.log("Sending the value of '"+message.key+"' as '"+val+"' from "+client.clientId+"'s key-store");
							//break;
						}
					});
					if(found == 0) {
						//ws.send("blank");
						ws.send(JSON.stringify({
							type: "message",
							data: "blank"
						}));
						console.log("Sending the value of '"+message.key+"' as "+"<blank>");
					}
					
				} else {
					//ws.send(val);
					ws.send(JSON.stringify({
						type: "message",
						data: val
					}));
					console.log("Sending the value of '"+message.key+"' as '"+val+"' from "+ws.clientId+"'s key-store");
					s.clients.forEach(function(client){
						var val = dict[client.clientId][message.key];
						if(client != ws && typeof val != "undefined") {
							//ws.send(val);
							ws.send(JSON.stringify({
								type: "message",
								data: val
							}));
							console.log("Sending the value of '"+message.key+"' as '"+val+"' from "+client.clientId+"'s key-store");
							//break;
						}
					});
				}	
			}
						
		}
		else if(message.type == "UPGRADE") {
			if(auth[ws.clientId] == "manager") {
				console.log(ws.clientId+" is already a manager!");
			} else {
				auth[ws.clientId] = "manager";
				console.log(ws.clientId+" is now a manager!");
			}			
		}
		else if(message.type == "DOWNGRADE") {
			if(auth[ws.clientId] == "guest") {
				console.log(ws.clientId+" is already a guest!");
			} else {
				auth[ws.clientId] = "guest";
				console.log(ws.clientId+" is now a guest!");
			}			
		}
		
	});
	
	ws.on('close', function() {
		auth[ws.clientId] = "";
		dict[ws.clientId] = {};
	});
});