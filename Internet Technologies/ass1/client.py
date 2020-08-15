import socket
import sys
import time

class Client():
	def __init__(self):
		self.serverhost = '127.0.0.1'
		self.serverport = 8080
		
	def process_query(self, args):
		if args[2] != self.serverhost or int(args[3]) != self.serverport:
			print('ERROR: Invalid server host or port number entered!')
			return
		sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
		sock.connect((args[2],int(args[3])))
		for x in args:
			time.sleep(.0005)
			sock.send(x.encode())
		sock.send("end".encode())
		data = sock.recv(1024).decode()
		while data:
			if data == 'end':
				break
			print(data)
			data = sock.recv(1024).decode()
			
		sock.close()
		
if __name__ == '__main__':
	c = Client()
	num_args = len(sys.argv)
	if num_args < 4:
		print("ERROR: Invalid arguments provided!")
		exit()
	client_no = int(sys.argv[1])
	if client_no < 1 or client_no > 100:
		print("ERROR: Invalid client number provided!")
		exit()
	#print(num_args)
	#print(sys.argv)
	c.process_query(sys.argv)
