import socket

if __name__ == '__main__':
	host = '127.0.0.1'
	port = 8080
	
	sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	sock.connect((host, port))
	
	while True:
		filename = input('Input filename you want to send: ')
		try:
			fi = open(filename,"r")
			data = fi.read()
			if not data:
				break
			while data:
				sock.send(data.encode())
				data = fi.read()
			data = "exit"
			sock.send(data.encode())
			fi.close()
		except IOError:
			print('You entered an invalid filename! Please enter a valid name')
		