#!/bin/bash 
#example for output file descriptor
exec 3>errors.txt
exec 4<names.txt
echo "This is the  data written to combined fd" >&3
date >&3
echo "Displaying the content using input fd"
cat <&4
echo "Closing both the fds"
exec 3<&-
exec 4<&-
