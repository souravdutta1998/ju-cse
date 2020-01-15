import socket
import time
import subprocess
import random
import os 

def multiplyTuples(t1, t2):
	tup = []
	for i in range(len(t1)):
		tup.append(t1[i] * t2[i])
	return tup 
	
def multiplyScalar(t1, x):
	tup = []
	for i in range(len(t1)):
		tup.append(t1[i] * x)
	return tup
	
def addTuples(t1, t2):
	tup = []
	for i in range(len(t1)):
		tup.append(t1[i]+t2[i])
	return tup 		
	
class Channel():
	
	def __init__(self, totalstations):
		self.totalstation = totalstations
		self.stationhost = '127.0.0.1'
		self.stationport = 8080
		self.stationconn = []
		self.walshtable = [ [] ]
		
	def initStations(self):
		stationSocket = socket.socket()
		stationSocket.bind((self.stationhost, self.stationport))
		stationSocket.listen(self.totalstation)
		for i in range(1, self.totalstation+1):
			conn = stationSocket.accept()
			self.stationconn.append(conn)
		print('Initiated all station connections')
		
	def closeStations(self):
		for conn in self.stationconn:
			conn[0].close()
		print('Closed all station connections')
	
	def generateWalshTable(self):
		print('Generating Walsh table ...')
		n = self.totalstation
		p = 1
		prevtable = [ [1] ]
		while p < n:
			p *= 2
			curtable = []
			for i in range(p):
				tup = []
				for j in range(p):
					tup.append(0)
				curtable.append(tup)
			for i in range(0,p//2):
				for j in range(0,p//2):
					curtable[i][j] = prevtable[i][j]
					curtable[i+p//2][j] = prevtable[i][j]
					curtable[i][j+p//2] = prevtable[i][j]
					curtable[i+p//2][j+p//2] = -1*prevtable[i][j]	
			prevtable = curtable
			
		self.walshtable = prevtable
		print('Printing Walsh table :')
		for i in range(p):
			for j in range(p):
				if self.walshtable[i][j] == 1:
					print(end=' ')
				print(self.walshtable[i][j],end=' ')
			print()
	
	def process(self):
		'''data = []
		data.append('1001')
		data.append('011')
		data.append('11011')
		data.append('0000')
		for i in range(self.totalstation):
			print('Station',i+1,'will send data:',end=' ')
			print(data[i])
		'''
		data = []
		for i in range(self.totalstation):
			conn = self.stationconn[i]
			d = conn[0].recv(1024).decode()
			data.append(d)
			
		for i in range(self.totalstation):
			print('Station',i+1,'will send data:',end=' ')
			print(data[i])
		maxlen = 0
		for i in data:
			maxlen = max(maxlen,len(i))
		datavalue = []
		for d in data:
			tup = []
			for j in range(maxlen):
				if j < len(d):
					if d[j] == '0':
						tup.append(-1)
					elif d[j] == '1':
						tup.append(1)
				else:
					tup.append(0)
			datavalue.append(tup)
			
		for i in range(maxlen):	
			print('---------------------------------------------')
			print('Sending bit',i+1,'of each station\'s data')
			finaldata = []			
			d = []
			c = []
			n = len(self.walshtable)
			for j in range(n):
				if j < self.totalstation:
					d.append(datavalue[j][i])
				else:
					d.append(1)
				c.append(self.walshtable[j])
				finaldata.append(0)
				
			for j in range(n):
				temp = multiplyScalar(c[j], d[j])
				finaldata = addTuples(finaldata,temp)
			print('Bit',i+1,'of each station is:',end=' ')	
			print(d)
			print()
			print('After multiplying data bit with code bits of corresponding stations, and adding them all,')
			print('Final data is:',end=' ')
			print(finaldata)
			print()
			
			choice = input('Does any station want to receive data ? (y/n) ')
			while choice == 'y':
				stnum,renum = input('Enter the sender and receiver station number: ').split()
				stnum = int(stnum)
				renum = int(renum)
				if stnum > self.totalstation or stnum <= 0 or renum > self.totalstation or renum <= 0:
					print('Invalid station number')
				else:
					temp = multiplyTuples(finaldata, c[stnum-1])
					print('Multiplying final data with Code bits of sender station',stnum)
					print('The result is :',end=' ')
					print(temp)
					summ = sum(temp)
					print('the sum of result is:',summ)
					databit = str(summ//n)
					print('THE DATA BIT OF STATION',stnum,'is:',databit)
					conn = self.stationconn[renum-1]
					conn[0].sendto(databit.encode(), conn[1])
					print('Data bit sent to receiver',renum,'successfully!')
					print()
					choice = input('Does any station want to receive data ? (y/n) ')
		

if __name__ == '__main__':
	totalstations = int(input('Enter number of stations: '))
	
	ch = Channel(totalstations)
	ch.generateWalshTable()
	ch.initStations()
	ch.process()
	ch.closeStations()