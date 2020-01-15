import socket

if __name__ == '__main__':
	host = '127.0.0.1'
	port = 8080
	
	sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
	
	while True:
		print('-----------------------------------')
		domain = input('Enter domain name: ')
		
		sock.sendto(domain.encode(),(host,port))
		if domain == 'q':
			break
		
		recvmsg,ip = sock.recvfrom(1024)
		recvmsg = recvmsg.decode()
		print()
		if recvmsg == 'not found':
			print('The domain could not be found!!')
		else:
			print('IP address of domain',domain,'is:',recvmsg)
		