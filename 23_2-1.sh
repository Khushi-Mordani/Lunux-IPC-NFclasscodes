#!/bin/bash
#using input and output fds

exec 3<names.txt
exec 4>errors.txt
read -u 3 a b
mypid=$$
echo "Current files open by $0 are:"
ls -l /proc/$mypid/fd
#echo " data read from fd3 $a "
#echo " data read from fd3 field 2 $b"
#echo " Writing back to fd4- output fd"
#echo " Writing first field $a" >&4
#echo " Writing second field $b" >&4
exec 3<&-
exec 4<&-

