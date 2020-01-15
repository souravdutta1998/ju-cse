import socket
import time
import subprocess
import random
import os 

def injectRandomError(frame):
	pos = random.randint(0, len(frame)-1)
	frame = frame[:pos]+'1'+frame[pos+1:]
	return frame

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
	
class Channel():
	
	def __init__(self, totalsender, totalreceiver, windowsize):
		self.totalsender = totalsender
		self.senderhost = '127.0.0.1'
		self.senderport = 8080
		self.senderconn = []
		
		self.totalreceiver = totalreceiver
		self.receiverhost = '127.0.0.2'
		self.receiverport = 9090
		self.receiverconn = []
		
		self.windowsize = windowsize
		self.slidingwindow = []
		self.currentcount = 0
		#self.statuswindow = []
		
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
		'''fileout = open('flag.txt', "w")
		fileout.write(str(0))
		fileout.close()'''
		while True:
			for i in range(len(self.senderconn)):
				print()
				
				conn = self.senderconn[i]
				data = conn[0].recv(1024).decode()
				prevtime = time.time()
				data = str(data)
				origmsg = extractMessage(data)
				if not origmsg:
					break
				if origmsg == 'q0':
					break
				print('Received from Sender',i+1,':',str(data))
				
				
				recvno = random.randint(0,len(self.receiverconn)-1) 
				print('Sending to Receiver',recvno+1)
				rconn = self.receiverconn[recvno]
				cnt = extractCount(data)
				msg = injectRandomError(origmsg)
				newdata = msg + '/' + str(cnt) + '/'
				rconn[0].sendto(newdata.encode(), rconn[1])
				
				#received from receiver
				rdata = rconn[0].recv(1024).decode()
				rdata = str(rdata)
				time.sleep(0.5)
				curtime = time.time()
				if curtime-prevtime > 2:
					timeout = 1
					newdata += 'TIMEOUT'
				else:
					timeout = 0
					newdata += rdata
				
				self.slidingwindow.append([data, newdata, i, recvno])
				
				
				msg = extractMessage(newdata)
				cnt = extractCount(newdata)
				status = extractStatus(newdata)
				print(msg,str(cnt),status)
				print('Round trip time: ',str(curtime-prevtime))
				print('Current frame no:',str((self.currentcount % windowsize)+1))
				if (self.currentcount % windowsize)+1 == self.windowsize:
					idx = 0
					flag = 1
					
					while flag == 1:
						idx = 0
						flag = 0
						while idx < self.windowsize:
							currframe = self.slidingwindow[idx][1]
							msg = extractMessage(currframe)
							cnt = extractCount(currframe)
							status = extractStatus(currframe)
							
							if status == 'NAK' or status == 'TIMEOUT':
								flag = 1
								break
							idx += 1
						print(' ------------------------------ ')	
						if flag==1:
							print('RESEND FROM FRAME NO:',str(idx+1))
						else:
							print('BLOCK OF WINDOW SIZE',self.windowsize,'SUCCESSFULLY SENT')
						print(' ------------------------------ ')	
						'''fileout = open('flag.txt', "w")
						fileout.write(str(flag))
						fileout.close()'''
						
						while flag == 1 and idx < self.windowsize:
							print()
							prevtime = time.time()
							prevframe = self.slidingwindow[idx][0]
							currframe = self.slidingwindow[idx][1]
							sendno = self.slidingwindow[idx][2]
							recvno = self.slidingwindow[idx][3]
							conn = self.senderconn[sendno]
							rconn = self.receiverconn[recvno]
							
							#sending all frames to its sender from first NAK 							
							#conn[0].send(currframe.encode())
							
							#data = conn[0].recv(1024).decode()
							print('Current frame no:',str(idx+1))
							print('Again Sending to Receiver',recvno+1)
							
							msg = extractMessage(prevframe)
							msg = injectRandomError(msg)
							data = msg + '/' + str(cnt) + '/'
							rconn[0].sendto(data.encode(), rconn[1])
							
							# receiving ACK or NAK from receiver 
							rdata = rconn[0].recv(1024).decode()
							rdata = str(rdata)
							data += rdata
							
							msg = extractMessage(data)
							cnt = extractCount(data)
							stat = extractStatus(data)
							curtime = time.time()
							print(msg,str(cnt),stat)
							print('Round trip time: ',str(curtime-prevtime))
							self.slidingwindow[idx][1] = data 
							idx += 1
										
							
						'''fileout = open('flag.txt', "w")
						fileout.write(str(0))
						fileout.close()	'''
						
				
				self.currentcount += 1
			if origmsg == 'q0':
				break
		return

if __name__ == '__main__':
	#Main()
	'''totalsen = 2
	print('Number of senders',totalsen)
	totalrecv = 2
	print('Number of receivers',totalrecv)
	windowsize = 4
	print('Window size:',windowsize)
	'''
	totalsen = int(input('Enter number of senders: '))
	totalrecv = int(input('Enter number of receivers: '))
	windowsize =int(input('Enter window size: '))
	
	ch = Channel(totalsen, totalrecv, windowsize)
	ch.initSenders()
	ch.initReceivers()
	ch.processData()
	ch.closeSenders()
	ch.closeReceivers()		
