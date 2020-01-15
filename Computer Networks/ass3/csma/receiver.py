import socket
import sys
import time
import random

def Main(senderno):
	print('Initiating Receiver #',senderno)
	host = '127.0.0.2'
	port = 9090
	
	mySocket = socket.socket()
	mySocket.connect((host, port))
	
	while True:
		print()
		data = mySocket.recv(1024).decode()
		if not data:
			break
		if data == 'q':
			break
		
		print('Received from channel :', str(data))
		
	mySocket.close()
	
if __name__ == '__main__':
	if len(sys.argv) > 1:
		senderno = int(sys.argv[1])
	else:
		senderno = 1
	Main(senderno)
	
		