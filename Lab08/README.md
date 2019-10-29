# Lab 08

## Task 1: Concurrent Calculation

Write a C program which accepts an integer argument and calculate sum (1 + 2 + 3 + ... + n) and factorial
(1 x 2 x 3 x ... x n). Instead of calling sequence of two functions, two threads will be created and each thread works
for different task concurrently.

## Task 2: Wait for a Thread for Concurrent Calculations

Three threads are sharing an integer array (you may define as global) and each thread does different jobs.

* Thread \#1: Get test scores from the keyboard, up to 20, and saves them into the array.
* Thread \#2: Calculate an average score and Medium value and display.
* Thread \#3: Get the minimum and the maximum score and display.
* Thread \#4: Clear the buffer and set to 0 and display after Thread \#2 and Thread \#3 finish their jobs.

Thread \#2 and Thread \#3 must wait for Thread \#1 to finish it's job. Once Thread \#1 finishes it's job, 
Thread \#2 and Thread \#3 work concurrently. Thread \#4 must wait for Thread \#2 and Thread \#3 to finish their jobs.

## Task 3: Inter-process Communication Using Pipe

A parent process asks two integers from the command line and sends to child using pipe. The child processes to make sure
the two inputs are integers. The child process calculates the sum of the two integers and outputs on standard output.
The child process continues until the input from the parent is EOF.

## Task 4: Inter-process Communication Using popen() and pclose()

popen() creates a child and a pipe. A parent process asks two arguments from the command line: a shell command and a
file name, and then sends them to the child by using popen(). The child process will implement the command with the file
as an input then sends it to the parent. The parent simply displays the output from the child on standard output.

Ex.)

    ./task4 cat task4.c
    ./task4 sort task4.c
    ./task4 cat task4.c | grep main
 
