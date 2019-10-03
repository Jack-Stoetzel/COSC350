#!/bin/bash

# Jack Stoetzel
# Lab 02
# Task6a.sh

# Prints the descending triangle
for i in $(seq 1 5); do
	for k in $(seq 1 $i); do
		echo -n "$i"
	done
	echo
done

exit 0

'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
OUTPUT

jstoetzel1:Lab02$ ./Task6a.sh
1
22
333
4444
55555
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
