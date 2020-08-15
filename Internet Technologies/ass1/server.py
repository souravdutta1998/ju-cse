import socket
import time

class Server():
	def __init__(self):
		self.serverhost = '127.0.0.1'
		self.serverport = 8080
		self.max_client = 100
		self.auth_dict = {}
		self.key_store = {}
		
	def init_authorization(self):
		for i in range(1,self.max_client+1):
			self.auth_dict[i] = "guest"
			self.key_store[i] = {}
		#self.auth_dict[1] = 'manager'
		#print(self.auth_dict)
		#self.key_store[2]["city"] = "kolkata"
		#self.key_store[2]["institute"] = "ju"
		#print(self.key_store)
		
	def process_query(self):
		
		while True:
			res = input('Want to close the server (y/n)? ')
			if res == 'y':
				return
			
			while True:
				res = input('Want to change the authorization to any client (y/n)? ')
				if res == 'y':
					client_no, auth = input('Enter client number and role (manager/guest): ').split()
					if auth == 'manager' or auth == 'guest':
						self.auth_dict[int(client_no)] = auth
						print('Client-'+client_no+' is now a \''+auth+'\' !!')
				elif res == 'n':
					break
				else:
					print('Invalid response! Please enter again')
			sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
			sock.bind((self.serverhost,self.serverport))
			sock.listen(1)
			conn = sock.accept()
			
			query = []
			response = []
			data = conn[0].recv(1024).decode()
			while data:				
				if data == 'end':
					break
				query.append(data)
				#print(data, end=',')
				data = conn[0].recv(1024).decode()
			
			#print(query)
			qlen = len(query)
			client_no = int(query[1])
			print('-'*70)
			print('\t\tConnected with client '+query[1])
			print('-'*70)
			#for i in range(4,qlen):
			i = 4
			while i < qlen:
				if query[i] == 'get':
					if i+1 < qlen:
						if query[i+1] in self.key_store[client_no]:
							response.append(self.key_store[client_no][query[i+1]])
							print('GET REQUEST: Sending the Value of \''+query[i+1]+'\' as \''+self.key_store[client_no][query[i+1]]+'\' to client-'+str(client_no))
						else:
							if self.auth_dict[client_no] == 'manager':
								print(query[i+1],'could not be found in self key-value store')
								print('Since the client is a manager, Finding it in other\'s key-value store')
								found = 0
								for j in range(1,self.max_client+1):
									if query[i+1] in self.key_store[j]:
										found = 1
										response.append(self.key_store[j][query[i+1]])
										print('GET REQUEST: Sending the Value of \''+query[i+1]+'\' as \''+self.key_store[j][query[i+1]]+'\' to client-'+str(client_no))
										break
								if found == 0:
									response.append("<blank>")
									print('GET REQUEST: Sending the Value of \''+query[i+1]+'\' as \''+'<blank>'+'\' to client-'+str(client_no))
							else:
								response.append("<blank>")
								print('GET REQUEST: Sending the Value of \''+query[i+1]+'\' as \''+'<blank>'+'\' to client-'+str(client_no))
						i = i+2
					else:
						print('INVALID GET REQUEST!')
						break
				elif query[i] == 'put':
					if i+2 < qlen:
						key = query[i+1]
						value = query[i+2]
						i = i+3
						while i < qlen:
							if query[i] == 'put' or query[i] == 'get':
								break
							value += " "+query[i]
							i = i+1
						self.key_store[client_no][key] = value
						print('PUT REQUEST: Value of \''+key+'\' as \''+value+'\' added to client-'+str(client_no)+'\'s key-value store')
					else:
						print('INVALID PUT REQUEST!')
						break
				else:
					print('INVALID REQUEST FOUND!')
			response.append("end")
			
			for x in response:
				time.sleep(.0005)
				conn[0].send(x.encode())
			conn[0].close()
			print('-'*70)
			print(end='\n\n')
		
if __name__ == '__main__':
	s = Server()
	s.init_authorization()
	s.process_query()