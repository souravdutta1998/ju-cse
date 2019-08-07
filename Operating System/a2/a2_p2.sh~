#! /bin/bash

FILE="$1"
if test -e $FILE 
then
	echo "File exists"
else
	echo "File does-not exist"
	exit
fi
echo "End of Script"

if test -b $FILE
then
	echo "File is block special"
fi
if test -c $FILE
then
	echo "File is character special"
fi
if test -p $FILE
then
	echo "File is a named file"
fi
if test -h $FILE
then
	echo "File is a symbolic link"
fi
if test -d $FILE
then
	echo "File is Directory"
if test -d $FILE
	

