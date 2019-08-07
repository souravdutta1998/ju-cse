#! /bin/bash

function newdir() 
{
	if [ $# -eq 0 ]
	then 
		echo "Error : No argument provided. Please enter only one argumnent"
	elif [ $# -gt 1 ]
	then 
		echo "Error : Please enter only one argument"
	else 
		mkdir "$1"
		echo "$1 : Directory successfully created"
	fi
}

function editfile() 
{
	if [ $# -eq 0 ]
	then
		vi
	elif [ $# -gt 1 ]
	then 
		echo "Error : Please enter only one argument"
	else
		vi "$1"
	fi 
}

function content() 
{
	if [ $# -eq 0 ]
	then
		echo "Error : No argument provided. Please enter only one argument"
	elif [ ! -e "$1" ]
	then 
		echo "Error : File does not exist"
	elif [ $# -gt 1 ]
	then 
		echo "Error : Please enter only one argument"
	else
		cat "$1"
	fi
}

function getinfo()
{
	filepath=$( realpath "$1" )
	filesize=$( stat --printf="%s" "$1" )
	lastdate=$( stat -c %y "$1" )
	creatorname=$( stat -c '%U' "$1" )

	echo "Path of the file       : $filepath"
	echo "Size of the file       : $filesize"
	echo "Last modification date : $lastdate"
	echo "Name of the creator    : $creatorname"
}

function info()
{
	if [ $# -eq 0 ]
	then 
		getinfo .
	elif [ ! -e "$1" ]
	then
		echo "Error : File does not exist."
	elif [ $# -gt 1 ]
	then
		echo "Error : Please enter only one argument"
	else 
		getinfo "$1"
	fi
}

function exitbcse() 
{
	echo "Successfully exited from JUBCSEIII shell"
	exit 1
}

function getmessage() 
{
	curtime=$(date +%H:%M )
	if [[ "$curtime" > "00:01" ]] && [[ "$curtime" < "12:00" ]]
	then
		message="Morning"
	elif [[ "$curtime" > "12:01" ]] && [[ "$curtime" < "18:00" ]]
    then
        message="Afternoon"
	elif [[ "$curtime" > "18:01" ]] && [[ "$curtime" < "00:00" ]]
    then
        message="Evening"	
	fi
	echo "Hi! Good $message"
	echo "Time : $curtime"
}

function main() 
{
	
	echo "------------------------- JUBCSEIII ---------------------------"
	getmessage
	echo "newdir <directoryname>  (Create a new directory)"
	echo "editfile [filename]     (Open existing/new file in vi editor)"
	echo "content <filename>      (Prints the content of the file)"
	echo "info [filename]         (Display information about the file)"
	echo "exitbcse                (Exit from JUBCSEIII shell)"
	echo "---------------------------------------------------------------"
	echo 
	
	user=$(whoami)
	while true
	do
		read -p "JUBCSEIII@$user: " command filename
		
		if [ "$command" == "newdir" ]
		then 
			newdir "$filename"
		elif [ "$command" == "editfile" ]
		then 
			editfile "$filename"
		elif [ "$command"  == "content" ]
		then
			content "$filename"
		elif [ "$command" == "info" ]
		then 
			info "$filename"
		elif [ "$command" == "exitbcse" ]
		then
			exitbcse
		else
			echo "$command: Command not found!"
		fi
	done

}

main
