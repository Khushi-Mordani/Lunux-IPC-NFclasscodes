#!/bin/bash
#script to open 
exec 3< errors.txt
exec 4<>names.txt
cat <&3 >&4
cat names.txt
exec 3<&-
exec 4<&-
