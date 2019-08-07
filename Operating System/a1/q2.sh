#!/bin/sh
echo												

echo "Number of files in Current Directory : $(find . -type f | wc -l)"			#Check number of files in current directory 


for directory in $(ls -p | grep /)							#Iterate over all subdirectories
do
	echo "Number of files in ./$directory : $(find $directory -type f | wc -l)"	#Display number of files in that directory
done

echo												

echo "In Directory . :"
for file in $(find . -maxdepth 1 -atime -2 -type f)					#Get files accessed within two days in current directory
do
	echo -n "    "										
	echo $file									#Print files
done
echo

for directory in $(ls -p | grep /)							#Iterate over all subdirectories
do 
	if find $directory -maxdepth 0 -empty | read v					#Check if directory is empty
        	then echo "./$directory is empty"
	else
		echo "In Directory $directory :"
		for file in $(find $directory -maxdepth 1 -atime -2 -type f)		#Get files accessed within 2 days
		do
		        echo -n "    ./"
		        echo $file							#Print files
		done
	fi
	echo
done
