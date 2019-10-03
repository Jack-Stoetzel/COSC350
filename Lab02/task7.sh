#!/bin/bash

# Jack Stoetzel
# Lab 02
# task7.sh

prompt="Please enter a positive number to calculate: "
error="Invalid entry!"

echo -n "$prompt"
read num

holder=num
total=1

# Checks for positive input
while [ $num -lt 0 ]; do
	echo "$error"
	echo -n "$prompt"
	read num
done

# Calculates the factorial
while [ $num -gt 0 ]; do
	total=$(($total * $num))
	num=$(($num - 1))
done

echo "The factorial of $holder is $total."

exit 0

'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
OUTPUT

jstoetzel1:Lab02$ ./task7.sh
Enter a number to calculate: -1
Invalid entry!
Enter a number to calculate: 6
The factorial of 6 is 720.

'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
