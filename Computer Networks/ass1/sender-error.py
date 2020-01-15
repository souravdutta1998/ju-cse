class Sender:
	#Initialize all the data members of class
	def __init__(self, size):
		self.codeword = []
		self.dataSize = size
		self.parity = ""
		self.checksum = ""
	
	#Function to generate codewords to be sent
	def createFrames(self, filename, type, poly=""):
		fileinput = open(filename, "r")
		packet = fileinput.readline()
		fileinput.close()
		tempword = ""
		if type == 1:
			for i in range(len(packet)):
				if i>0 and i%self.dataSize==0:
					self.codeword.append(tempword)
					tempword = ""
				tempword += packet[i]
			self.codeword.append(tempword)	
			self.rowEvenParityGenerator()
		elif type == 2:
			for i in range(len(packet)):
				if i>0 and i%self.dataSize==0:
					self.codeword.append(tempword)
					tempword = ""
				tempword += packet[i]
			self.codeword.append(tempword)	
			self.columnEvenParityGenerator()
		elif type == 3:
			for i in range(len(packet)):
				if i>0 and i%self.dataSize==0:
					self.codeword.append(tempword)
					tempword = ""
				tempword += packet[i]
			self.codeword.append(tempword)
			
			summ = self.calculateSum()
			for i in range(len(summ)):
				if summ[i]=='0':
					self.checksum += '1'
				else:
					self.checksum += '0'
		elif type == 4:
			tempsize = self.dataSize #- (len(poly)-1)
			for i in range(len(packet)):
				if i>0 and i%tempsize==0:
					tempword += '0'*(len(poly)-1)
					remainder = self.divide(tempword, poly)
					remainder = remainder[len(remainder)-(len(poly)-1):]
					tempword = tempword[:tempsize]
					tempword += remainder
					self.codeword.append(tempword)
					tempword = ""
				tempword += packet[i]
				
			tempword += '0'*(len(poly)-1)
			remainder = self.divide(tempword, poly)
			remainder = remainder[len(remainder)-(len(poly)-1):]
			tempword = tempword[:tempsize]
			tempword += remainder
			self.codeword.append(tempword)	

	#Function to display the sent codewords
	def displayFrames(self, type):
		datawords = []
		for x in self.codeword:
			datawords.append(x[:self.dataSize])
		print("Datawords to be sent:")
		print(datawords)
		print("Codewords sent by sender:")
		print(self.codeword)
		if type == 2:
			print(self.parity, " - parity")
		elif type == 3:
			print(self.checksum, " - checksum")
		print("\n")
	
	#Helper function for VRC Even Parity generator
	def rowEvenParityGenerator(self):
		for i in range(len(self.codeword)):
			countOnes = 0
			for j in range(len(self.codeword[i])):
				if self.codeword[i][j] == '1':
					countOnes += 1
			if countOnes%2==1:
				self.codeword[i] += '1'
			else:
				self.codeword[i] += '0'
	
	#Helper function for LRC Even Parity generator
	def columnEvenParityGenerator(self):
		i=0
		while i<self.dataSize:
			countOnes = 0
			j=0
			while j<len(self.codeword):
				if self.codeword[j][i] == '1':
					countOnes += 1
				j+=1
			if countOnes%2==1:
				self.parity += '1'
			else:
				self.parity += '0'
			i+=1
	
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