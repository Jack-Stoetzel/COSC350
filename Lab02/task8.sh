#!/bin/bash

# Jack Stoetzel
# Lab 02
# task8.sh

output="Sum of digit for number is"
error="You need pass one numerical argument."

# Checks if any arguments were passed
if [ $# -ne 1 ]; then
    echo $error
    exit 1
else
    # Converts number to base 10 if not already
    num=$((10#$1))
    total=0

    # Adds all numbers together
    while [ $num -gt 0 ]; do
        total=$((total + num % 10))
        num=$((num / 10))
    done

    echo "$output $total."
fi

exit 0

'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
OUTPUT

jstoetzel1:Lab02$ ./task7.sh 345
Sum of digit for number is 12.

jstoetzel1:Lab02$ ./task7.sh
You need pass one numerical argument.

'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
