

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

* Thread \#2 and Thread \#3 must wait for Thread \#1 to finish it's job. Once Thread \#1 finishes it's job, 

## Task 3: Process Communication Without Sending Signal

Write a complete C program in which a child process writes a message "Hi, Mom" to a file named foo.
The parent process reads the message and prints it to standard output "My son said 'Hi, Mom'".
The part of the message, "Hi, Mom" comes from the file foo.
Assume that all system calls succeed (no need to error check).
Use only low-level file operations (fork, wait, open, close, read, lseek).
You must make sure a child process terminates first.

## Task 4: Using Signal and Kill System Calls

Write a complete C program in which two children processes send a signal to the parent.
The first child sends the message SIGUSR1 to the parent, and the parent process responds by writing the message
"Hi Honey! Anything Wrong?".
The second child sends the message SIGUSR2 to the parent, and the parent process responds by writing the message
"Did you make trouble again?".

## Task 5: sigprocmask

Write a complete C program that demonstrates how you can block and unblock signals.
Your program will have two loops, each of which simply prints the integers 1 to 5 at 1 second intervals.
During the first loop, SIGINT and SIGQUIT are blocked.
During the second loop, only SIGINT is blocked.
While the program is running, you can try ^C and/or ^\ to see if they are blocked as expected.

* The signal SIGINT is usually bound to ^C by the terminal driver. The SIGINT signal terminates the program by default.
* The signal SIGQUIT is usually bound to ^\ by the terminal driver. The SIGQUIT by default causes the program to terminate
  and create a core file.
