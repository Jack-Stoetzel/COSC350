#!/bin/bash

# Jack Stoetzel
# Lab 02
# Task6c.sh

prompt="Please enter a number between 5 and 9: "
error="Invalid entry!"

echo -n "$prompt"
read size

# Checks for input between 5 and 9
while [ $size -lt 5 -o $size -gt 9 ]; do
	echo "$error"
	echo -n "$prompt"
	read size
done

# Prints out the descending value triangle
for i in $(seq 1 $size); do
	for k in $(seq $i $size); do
		echo -n " "
	done
	for k in $(seq 1 $i); do
		echo -n "$i "
	done
	echo
done

exit 0

'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
OUTPUT

jstoetzel1:Lab02$ ./Task6c.sh
Please enter a number between 5 and 9: 4
Invalid entry!
Please enter a number between 5 and 9: 9
        1
       2 2
      3 3 3
     4 4 4 4
    5 5 5 5 5
   6 6 6 6 6 6
  7 7 7 7 7 7 7
 8 8 8 8 8 8 8 8
9 9 9 9 9 9 9 9 9

'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
