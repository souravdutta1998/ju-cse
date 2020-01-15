import socket
import time
import subprocess
import random
import os 

	
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
		fileout = open('status.txt',"w")
		fileout.write(str(0))
		fileout.close()
		while True:
			for i in range(len(self.senderconn)):
				print()
				conn = self.senderconn[i]
				fileout = open('status.txt',"w")
				fileout.write(str(0))
				fileout.close()
				data = conn[0].recv(1024).decode()
				fileout = open('status.txt',"w")
				fileout.write(str(1))
				fileout.close()
				
				if not data:
					break
				if data == 'q0':
					break
				
				print('Received from Sender',i+1,':',str(data))
				
				recvno = random.randint(0,len(self.receiverconn)-1) 
				print('Sending to Receiver',recvno+1)
				rconn = self.receiverconn[recvno]
				rconn[0].sendto(data.encode(), rconn[1])
				
				
			if data == 'q0':
				break
		return

if __name__ == '__main__':
	totalsen = int(input('Enter number of senders: '))
	totalrecv = int(input('Enter number of receivers: '))
	
	ch = Channel(totalsen, totalrecv)
	ch.initSenders()
	ch.initReceivers()
	ch.processData()
	ch.closeSenders()
	ch.closeReceivers()		
