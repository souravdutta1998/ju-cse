class Receiver:
	#Initialize all the data members of class
	def __init__(self, s):
		self.codeword = s.codeword
		self.dataSize = s.dataSize
		self.sentparity = s.parity
		self.receivedparity = ""
		self.sentchecksum = s.checksum
		self.sum = ""
		self.addchecksum = ""
		self.complement = ""
	
	#Function to decode and check for error in codewords
	def checkError(self, type, poly=""):
		if type == 1:
			for i in range(len(self.codeword)):
				countOnes = 0
				for j in range(len(self.codeword[i])):
					if self.codeword[i][j]=='1':
						countOnes += 1
				if countOnes%2==0:
					print("Parity is even.", end=' ')
					print("NO ERROR DETECTED")
				else:
					print("Parity is odd.", end=' ')
					print("ERROR DETECTED")
		elif type == 2:
			error = False
			i=0
			while i<self.dataSize:
				countOnes = 0
				j=0
				while j<len(self.codeword):
					if self.codeword[j][i] == '1':
						countOnes += 1
					j+=1
				if countOnes%2==1:
					ch = '1'
				else:
					ch = '0'
				self.receivedparity += ch	
				if ch != self.sentparity[i]:
					error = True
				i+=1
			if error:
				print("Parity did not match.",end=' ')
				print("ERROR DETECTED")
			else:
				print("Parity matched.",end=' ')
				print("NO ERROR DETECTED")
		elif type == 3:
			self.sum = self.calculateSum()
			result = self.add(self.sum, self.sentchecksum)
			while len(result) > self.dataSize:
				t1 = result[:len(result)-self.dataSize]
				t2 = result[len(result)-self.dataSize:]
				result = self.add(t1, t2)
			self.addchecksum = result
			
			#finding complement and checking error
			error = False
			for ch in self.addchecksum:
				if ch == '0':
					self.complement += '1'
					error = True
				else:
					self.complement += '0'
			if error:
				print("Complement is not zero.",end=' ')
				print("ERROR DETECTED")
			else:
				print("Complement is zero.",end=' ')
				print("NO ERROR DETECTED")
		elif type == 4:
			for i in range(len(self.codeword)):
				remainder = self.divide(self.codeword[i], poly)
				error = False
				for j in range(len(remainder)):
					if remainder[j] == '1':
						error = True
				print("Remainder:",remainder,end=' ')
				if error:
					print("ERROR DETECTED")
				else:
					print("NO ERROR DETECTED")
		print()
			
	#Function to display the received codewords
	def displayFrames(self, type):
		print("Codewords received by receiver:")
		print(self.codeword)
		if type == 2:
			print(self.receivedparity, " - parity")
		elif type == 3:
			print(self.sum, " - sum")
			print(self.addchecksum, " - sum+checksum")
			print(self.complement, " - complement")	
		for i in range(len(self.codeword)):
			self.codeword[i] = self.codeword[i][:self.dataSize]
		print("Extracting datawords from codewords:")
		print(self.codeword)
		print()
	
	#Helper function to add two binary sequence
	def add(self, a, b):
		result = ""
		s = 0
		i = len(a)-1
		j = len(b)-1
		while i>=0 or j>=0 or s==1:
			if i>=0:
				s+=int(a[i])
			if j>=0:
				s+=int(b[j])
			result = str(s%2) + result
			s //= 2 
			i-=1
			j-=1
		return result
	
	#Helper function to calculate sum of all codewords
	def calculateSum(self):
		result = self.codeword[0]
		for i in range(1,len(self.codeword)):
			result = self.add(result, self.codeword[i])
			while len(result) > self.dataSize:
				t1 = result[:len(result)-self.dataSize]
				t2 = result[len(result)-self.dataSize:]
				result = self.add(t1, t2)
		return result
		
	#Helper function to XOR two binary sequence
	def xor(self, a, b):
		result = ""
		for i in range(1, len(b)):
			if a[i]==b[i]:
				result += '0'
			else:
				result += '1'
		return result

	#Helper function to divide two binary sequence
	def divide(self, dividend, divisor):
		xorlen = len(divisor)
		temp = dividend[:xorlen]
		while len(dividend) > xorlen:
			if temp[0]=='1':
				temp=self.xor(divisor,temp)+dividend[xorlen]
			else:
				temp=self.xor('0'*xorlen,temp)+dividend[xorlen]
			xorlen += 1
		if temp[0]=='1':
			temp=self.xor(divisor,temp)
		else:
			temp=self.xor('0'*xorlen,temp)
		return temp
		