import socket
import time
import subprocess
import random
import os 

def injectRandomError(frame):
	pos = random.randint(0, len(frame)-1)
	frame = frame[:pos]+'1'+frame[pos+1:]
	return frame
	
class Channel():
	
	def __init__(self, totalsender, totalreceiver):
		self.totalsender = totalsender
		self.senderhost = '127.0.0.1'
		self.senderport = 8080
		self.senderconn = []
		
		self.totalreceiver = totalreceiver
		self.receiverhost = '127.0.0.2'
		self.receiverport = 9090
		self.receiverconn = []
		
	def initSenders(self):
		senderSocket = socket.socket()
		senderSocket.bind((self.senderhost, self.senderport))
		senderSocket.listen(self.totalsender)
		for i in range(1, self.totalsender+1):
			conn = senderSocket.accept()
			self.senderconn.append(conn)
		print('Initiated all sender connections')
		
	def closeSenders(self):
		for conn in self.senderconn:
			conn[0].close()
		print('Closed all sender connections')
		
	def initReceivers(self):
		receiverSocket = socket.socket()
		receiverSocket.bind((self.receiverhost, self.receiverport))
		receiverSocket.listen(self.totalreceiver)
		for i in range(1, self.totalreceiver+1):
			conn = receiverSocket.accept()
			self.receiverconn.append(conn)
		print('Initiated all receiver connections')
		
	def closeReceivers(self):
		for conn in self.receiverconn:
			conn[0].close()
		print('Closed all receiver connections')
			
	def processData(self):
		while True:
			for i in range(len(self.senderconn)):
				print()
				conn = self.senderconn[i]
				data = conn[0].recv(1024).decode()
				if not data:
					break
				if data == 'q0':
					break
				
				print('Received from Sender',i+1,':',str(data))
				
				recvno = random.randint(0,len(self.receiverconn)-1) 
				print('Sending to Receiver',recvno+1)
				rconn = self.receiverconn[recvno]
				data = injectRandomError(data)
				rconn[0].sendto(data.encode(), rconn[1])
				
				
				rdata = rconn[0].recv(1024).decode()
				print('Received from Receiver',recvno+1,':', str(rdata))
				
				print('Sending to Sender',i+1)
				conn[0].send(rdata.encode())
				
				time.sleep(0.002)
				filein = open('checktime.txt',"r")
				timeout = int(filein.read())
				filein.close()
				os.remove('checktime.txt')
				print(timeout)
				while timeout==1:
					print()
					data = conn[0].recv(1024).decode()
					print('Again Received from Sender',i+1,':',str(data))
					data = injectRandomError(data)
					print('Again Sending to Receiver',recvno+1)
					rconn[0].sendto(data.encode(), rconn[1])
					rdata = rconn[0].recv(1024).decode()
					print('Again Received from Receiver',recvno+1,':', str(rdata))
					print('Again Sending to Sender',i+1)
					conn[0].send(rdata.encode())
					
					time.sleep(0.002)
					filein = open('checktime.txt',"r")
					timeout = int(filein.read())
					filein.close()
					os.remove('checktime.txt')
					print(timeout)
					
				
				
			if data == 'q0':
				break
		return

if __name__ == '__main__':
	#Main()
	'''totalsen = 2
	print('Number of senders',totalsen)
	totalrecv = 2
	print('Number of receivers',totalrecv)
	
	'''
	totalsen = int(input('Enter number of senders: '))
	totalrecv = int(input('Enter number of receivers: '))
	
	
	
	ch = Channel(totalsen, totalrecv)
	ch.initSenders()
	ch.initReceivers()
	ch.processData()
	ch.closeSenders()
	ch.closeReceivers()		
'''
def Main():
	senderhost = "127.0.0.1"
	senderport = 8080
	
	
	
	
	senderSocket = socket.socket()
	senderSocket.bind((host, port))
	
	senderSocket.listen(totalsen)
	connections = []
	for i in range(1,totalsen+1):
		conn = senderSocket.accept()
		connections.append(conn)
	#conn, addr = mySocket.accept()
	
	arr = []
	
	while True:
		for conn in connections:
			print(conn[1])
			data = conn[0].recv(1024).decode()
			
			if not data:
				break
			
			print("from connected user: ", str(data))
		if data == "exit":
			break
		
	for conn in connections:
		conn[0].close()
	'''

#<socket.socket fd=572, family=AddressFamily.AF_INET, type=SocketKind.SOCK_STREAM, proto=0, laddr=('127.0.0.1', 54920), raddr=('127.0.0.1', 8080)>/q/('127.0.0.1', 54921)