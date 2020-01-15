from sender import *
from receiver import *
import random
import sys

#function to inject errors in random positions
def injectRandomError(frames):
	for i in range(len(frames)):
		pos = random.randint(0, len(frames[i])-1)
		frames[i] = frames[i][:pos]+'1'+frames[i][pos+1:]
	return frames

#function to inject errors in specific positions
def injectSpecificError(frames, zeropos, onepos):
	for i in range(len(zeropos)):
		for j in range(len(zeropos[i])):
			pos = zeropos[i][j]
			frames[i] = frames[i][:pos]+'0'+frames[i][pos+1:]
	for i in range(len(onepos)):
		for j in range(len(onepos[i])):
			pos = onepos[i][j]
			frames[i] = frames[i][:pos]+'1'+frames[i][pos+1:]
	return frames
	
#function to generate random sequence of 0,1 and store it in a file
def generateRandomInput(length, filename):
	fileout = open(filename, "w")
	for i in range(length):
		fileout.write(str(random.randint(0,1)))
	fileout.close()

#function to execute Case 1	
def case1(size, filename):
	puterror = True
	print("--------------------------- CASE 1 -------------------------")
	print("Error is detected by all four schemes.")
	print("-------------- Vertical Redundancy Check -------------------")
	type = 1
	s = Sender(size)
	s.createFrames(filename,type)
	s.displayFrames(type)
	if puterror:
		s.codeword = injectRandomError(s.codeword)
	r = Receiver(s)
	r.checkError(type)
	r.displayFrames(type)
	print("-------------- Longitudinal Redundancy Check ---------------")
	type = 2
	s = Sender(size)
	s.createFrames(filename,type)
	s.displayFrames(type)
	if puterror:
		s.codeword = injectRandomError(s.codeword)
	r = Receiver(s)
	r.checkError(type)
	r.displayFrames(type)
	print("-------------- Checksum ------------------------------------")
	type = 3
	s = Sender(size)
	s.createFrames(filename,type)
	s.displayFrames(type)
	if puterror:
		s.codeword = injectRandomError(s.codeword)
	r = Receiver(s)
	r.checkError(type)
	r.displayFrames(type)
	print("-------------- Cyclic Redundancy Check ---------------------")
	type = 4
	#poly = "1001"
	#print("Generator polynomial:",poly)
	poly = input("Enter Generator Polynomial: ")
	s = Sender(size)
	s.createFrames(filename,type,poly)
	s.displayFrames(type)
	if puterror:
		s.codeword = injectRandomError(s.codeword)
	r = Receiver(s)
	r.checkError(type,poly)
	r.displayFrames(type)
	print("------------------------------------------------------------\n")

#function to execute Case 2
def case2(size, filename):
	print("--------------------------- CASE 2 -------------------------")
	print("Error is detected by checksum but not by CRC.")
	print("-------------- Checksum ------------------------------------")
	type = 3
	s = Sender(size)
	s.createFrames(filename,type)
	s.displayFrames(type)
	zeropos = []
	onepos = [[5]]
	s.codeword = injectSpecificError(s.codeword,zeropos,onepos)
	r = Receiver(s)
	r.checkError(type)
	r.displayFrames(type)
	print("-------------- Cyclic Redundancy Check ---------------------")
	type = 4
	poly = "1000"
	print("Generator Polynomial:",poly)
	s = Sender(size)
	s.createFrames(filename,type,poly)
	s.displayFrames(type)
	s.codeword = injectSpecificError(s.codeword,zeropos,onepos)
	r = Receiver(s)
	r.checkError(type,poly)
	r.displayFrames(type)
	print("------------------------------------------------------------\n")

#function to execute Case 3
def case3(size, filename):
	print("--------------------------- CASE 3 -------------------------")
	print("Error is detected by VRC but not by CRC.")
	print("-------------- Vertical Redundancy Check -------------------")
	type = 1
	s = Sender(size)
	s.createFrames(filename,type)
	s.displayFrames(type)
	zeropos = []
	onepos = [[5]]
	s.codeword = injectSpecificError(s.codeword,zeropos,onepos)
	r = Receiver(s)
	r.checkError(type)
	r.displayFrames(type)
	print("-------------- Cyclic Redundancy Check ---------------------")
	type = 4
	poly = "100"
	print("Generator Polynomial:",poly)
	s = Sender(size)
	s.createFrames(filename,type,poly)
	s.displayFrames(type)
	s.codeword = injectSpecificError(s.codeword,zeropos,onepos)
	r = Receiver(s)
	r.checkError(type,poly)
	r.displayFrames(type)
	print("------------------------------------------------------------\n")

#driver function to run the error detection module
if __name__ == "__main__":
	print("------------------------------------------------------------")
	print("1. Error is detected by all four schemes.")
	print("2. Error is detected by checksum but not by CRC.")
	print("3. Error is detected by VRC but not by CRC.")
	case = int(input("Enter Case Number : "))
	if case == 1:
		size = int(input("Enter length of the dataword: "))
		generateRandomInput(size*4, sys.argv[1])
		case1(size, sys.argv[1])
	elif case == 2:
		size = 8
		case2(size, sys.argv[1])
	elif case == 3:
		size = 6
		case3(size, sys.argv[1])
	else:
		print("You entered invalid choice.")
