import socket
import sys
import time
import random
	
def Main(senderno):
	print('Initiating Station #',senderno)
	host = '127.0.0.1'
	port = 8080
	
	mySocket = socket.socket()
	mySocket.connect((host, port))
	
	data = input('Enter $ ')
	mySocket.send(data.encode())
	
	while True:
		data = mySocket.recv(1024).decode()
		if not data:
			break
		print('Received bit value from channel:',str(data))
		data = int(data)
		if data == -1:
			val = 0
		elif data == 1:
			val = 1
		else:
			val = "silent"
		print('VALUE OF RECEIVED BIT IS :',str(val))
	
	mySocket.close()
	
if __name__ == '__main__':
	if len(sys.argv) > 1:
		senderno = int(sys.argv[1])
	else:
		senderno = 1
	Main(senderno)