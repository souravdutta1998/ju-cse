import socket

	
if __name__ == '__main__':
	host = '127.0.0.1'
	port = 8080
	
	sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
	sock.bind((host,port))
	
	while True:
		print('--------------------------------------')
		data, ip = sock.recvfrom(1024)
		data = data.decode()
		if data == 'q':
			break
		print('Received domain name:',data)
		print('Searching the domain name...')
		
		sendmsg = 'not found'
		try:
			fi = open('domains.txt',"r")
			domname = fi.readline().split(' ')
			flag = 0
			while domname[0]:
				
				#print(domname)
				if data == domname[0]:
					sendmsg = domname[1]
					flag = 1
					break
				domname = fi.readline().split(' ')
			if flag == 0:
				print('Domain not found!')
			else:
				print('Domain found! Sending its corresponding IP address')
		except IOError:
			print('File does not exist!')
		
		sock.sendto(sendmsg.encode(),ip)
		
		#break