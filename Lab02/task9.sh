#!/bin/bash

# Jack Stoetzel
# Lab 02
# task9.sh

echo -n "Enter the directory of the file: "
read dir

if [ ${dir:0:1} = '~' ]; then
    dir="/mnt/linuxlab/home/jstoetzel1/${dir:2:${#dir}-2}"
fi

# Checks if input is valid directory
if [ -d $dir ]; then
    echo -n "Enter the name of the file: "
    read file

    # Converts directory and file to valid path
    location="$dir/$file"

    attempts=1

    # Gives user 3 attempts to enter a valid file
    while [ ! -r $location -a $attempts -lt 3 ]; do
        echo -n "Invalid file name. Enter the name of the file: "
        read file

        location="$dir/$file"

        attempts=$((attempts+1))
    done

    # Asks user for a word to search in the file
    if [ -r $location ]; then
        echo -n "Enter the word to search in the file: "
        read word

        result=$(grep $word $location)

        # Searches the file for the word and reports if found
        if [ -z "$result" ]; then
            echo "$word NOT FOUND"
            exit 4
        else
            echo "$word FOUND!"
            exit 0
        fi

    elif [ -e $location ]; then
        echo "$file exists but is not readable"
        exit 3
    else
        echo "$file is not a vaild file"
    fi

else
    echo "$dir is not a valid directory"
    exit 1
fi

'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
OUTPUT

jstoetzel1:Lab02$ ./task9.sh
Enter the directory of the file: folder
folder is not a valid directory

jstoetzel1:Lab02$ ./task9.sh
Enter the directory of the file: Test
Enter the name of the file: foo
Invalid file name. Enter the name of the file: poo
Invalid file name. Enter the name of the file: NoRead
NoRead exists but is not readable

jstoetzel1:Lab02$ ./task9.sh
Enter the directory of the file: Test
Enter the name of the file: Read
Enter the word to search in the file: wafle
wafle NOT FOUND

jstoetzel1:Lab02$ ./task9.sh
Enter the directory of the file: Test
Enter the name of the file: Read
Enter the word to search in the file: waffle
waffle FOUND!

'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
