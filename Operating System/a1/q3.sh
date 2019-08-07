#! /bin/sh

searchstrings=("printf" "scanf" "int")
filenames=($1 $2 $3 $4)
echo "-----------------------------------------------------------------------------"
echo -e "Name of the file\t${searchstrings[0]}\t\t${searchstrings[1]}\t\t${searchstrings[2]}\t"
echo "-----------------------------------------------------------------------------"

for file in ${filenames[*]}
do
	echo -n -e "\t$file\t"
	for string in ${searchstrings[*]}
	do
		freq=$(grep -c "$string" $file)
		echo -n -e "\t$freq\t"
	done
	echo
done

echo "-----------------------------------------------------------------------------"
echo
