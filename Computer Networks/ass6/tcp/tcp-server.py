import socket
def getextension(str):
	idx = -1
	for i in range(len(str)-1):
		if str[i] == '.':
			idx = i 
			break
	return str[idx+1:]

if __name__ == '__main__':
	host = '127.0.0.1'
	port = 8080
	totalclient = int(input('Enter number of clients: '))
	
	sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	sock.bind((host,port))
	sock.listen(totalclient)
	connections = []
	print('Initiating clients')
	for i in range(totalclient):
		conn = sock.accept()
		connections.append(conn)
		print('Connected with client',i+1)
	#print('Connected with all clients')
	fileno = 0
	idx = 0
	for conn in connections:
		idx += 1
		data = conn[0].recv(1024).decode()
		if not data:
			continue
		ex = getextension
		filename = 'output'+str(fileno)+'.txt'
		fileno += 1
		fo = open(filename, "w")
		
		while data:
			if data == "exit":
				break
			fo.write(data)
			data = conn[0].recv(1024).decode()
		print()
		print('Receiving file from client',idx)
		print()
		print('Received successfully! New filename is:',filename)
		fo.close()

	for conn in connections:
		conn[0].close()