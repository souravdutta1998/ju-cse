import socket
import sys
import time
import random

def waitRandomtime():
	x = random.randint(0,5)
	if x <= 1:
		time.sleep(2)
		
def checkError(frame):
	countOnes = 0
	for ch in frame:
		if ch == '1':
			countOnes += 1
	return countOnes%2

def extractMessage(frame):
	endidx = -1
	for i in range(len(frame)-1):
		if frame[i] == '/' and endidx == -1:
			endidx = i 
			break
	return frame[:endidx]
	
def extractCount(frame):
	startidx = -1
	endidx = -1
	for i in range(len(frame)-1):
		if frame[i] == '/':
			if startidx == -1:
				startidx = i+1
			else:
				endidx = i
	cnt = frame[startidx:endidx]
	return int(cnt)
	
def extractStatus(frame):
	count = 0
	startidx = -1
	for i in range(len(frame)-1):
		if frame[i] == '/':
			count += 1
		if count == 2 and startidx == -1:
			startidx = i+1
			break
	return frame[startidx:]
	
def Main(senderno):
	print('Initiating Receiver #',senderno)
	host = '127.0.0.2'
	port = 9090
	
	mySocket = socket.socket()
	mySocket.connect((host, port))
	
	while True:
		print()
		data = mySocket.recv(1024).decode()
		data = str(data)
		msg = extractMessage(data)
		if not msg:
			break
		if msg == 'q0':
			break
		
		print('Received from channel :', str(data))
		waitRandomtime()
		if checkError(msg) == 0:
			rdata = 'ACK'
		else:
			rdata = 'NAK'
		
		print('Sending to channel :',str(rdata))
		mySocket.send(rdata.encode())
		
		
		
	mySocket.close()
	
if __name__ == '__main__':
	if len(sys.argv) > 1:
		senderno = int(sys.argv[1])
	else:
		senderno = 1
	Main(senderno)
	
		