#!/bin/bash

# Jack Stoetzel
# Lab 02
# Task6b.sh

# Prints the top half of the triangle
for i in $(seq 1 5); do
	for k in $(seq 1 $i); do
		echo -n "*"
	done
	echo
done

# Prints the bottom half of the triangle
for i in $(seq 1 4); do
    for k in $(seq 4 -1 $i); do
        echo -n "*"
    done
	echo
done

exit 0

'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
OUTPUT

jstoetzel1:Lab02$ ./Task6b.sh
*
**
***
****
*****
****
***
**
*
'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
