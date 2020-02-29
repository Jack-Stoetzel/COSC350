### Jack Stoetzel

# Lab 07

## Task 1: Alarm Using sigaction

The textbook version of alarm.c uses the old-fashioned signal methodology. 
In this task you will modify alarm.c to use sigaction.

1. Copy alarm.c from the textbook.
2. Modify alarm.c so it uses sigaction.

## Task 2: Catch ^C With sigaction

1. Copy ctrlc1.c from the textbook. Run it to see how it behaves.
2. Copy ctrlc2.c from the textbook. Run it to see how it behaves.
3. The textbook advises using SIGQUIT(^\\) to quit from ctrlc2.c. Try it to see how it behaves.
4. As an alternative way to quit from it, put it in the background, then issue a kill.
5. Modify ctrlc.2 so it behaves exactly the same as ctrlc1.c.

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
* The signal SIGQUIT is usually bound to ^\ by the terminal driver. 
The SIGQUIT by default causes the program to terminate and create a core file.
