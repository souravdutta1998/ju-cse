#!/bin/sh

read -p "Enter file name : " filename
test -e $filename && echo $(file $filename) || echo "File not found!"
