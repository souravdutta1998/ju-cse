import socket
import sys
import time
def createFrame(data):
	countOnes = 0
	for ch in data:
		if ch == '1':
			countOnes += 1
	data += str(countOnes%2)
	return data

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
	count = 0
	sentframes = []
	print('Initiating Sender #',senderno)
	host = '127.0.0.1'
	port = 8080
	
	mySocket = socket.socket()
	mySocket.connect((host, port))
	
	while True:
		print()
		data = input("Enter $ ")
		#prevtime = time.time()
		data = createFrame(data) + '/' + str(count) + '/'
		msg = extractMessage(data)
		print('Sending to channel :',str(msg))
		mySocket.send(data.encode())
		sentframes.append(data)
		count += 1
		
		if not msg:
			break
		if msg == 'q0':
			break
		'''rdata = mySocket.recv(1024).decode()
		print('Received from channel :',str(rdata))
		curtime = time.time()
		print('Round trip time: ',str(curtime-prevtime))
		'''
		'''
		time.sleep(0.005)
		filein = open('flag.txt',"r")
		flag = int(filein.read())
		filein.close()
		while flag == 1:
			rdata = mySocket.recv(1024).decode()
			print(rdata)
			
			cnt = extractCount(rdata)
			msg = extractMessage(sentframes[cnt])
			stat = extractStatus(rdata)
			print(msg,cnt,stat)
			print('Again Sending to channel :',str(msg))
			data = msg +'/'+cnt+'/'
			mySocket.send(data.encode())
			
			time.sleep(0.005)
			filein = open('flag.txt',"r")
			flag = int(filein.read())
			filein.close()
		
		'''
	mySocket.close()
	
if __name__ == '__main__':
	if len(sys.argv) > 1:
		senderno = int(sys.argv[1])
	else:
		senderno = 1
	Main(senderno)
	
		