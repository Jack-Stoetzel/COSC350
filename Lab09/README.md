# Lab 09

## Task 1: A Simple Pipe

This task is intended to help your understanding of how pipes work.

1. Copy pipe1.c from the textbook.
2. Compile and run it.
3. Modify pipe1.c in the following ways:
	1. Define two global integer constants to keep track of which pipes are open and are closed.
		1. READ_END = 0
		2. WRITE_END = 1
	2. Dyanmically allocate buffer so it's exactly the right size for some_data.
	3. Copy the string from some_data into buffer.
	4. Modify the read so it's third argument is the exact size of buffer (rather than the large BUFSIZ).


## Task 2: Pipes Across a fork/exec

1. Copy pipe3.c from the textbook.
2. Copy pipe4.c from the textbook.
3. Compile and run both programs to see what they do.
4. Modify pipe3.c as follows.
	1. Have a parent wait for the child.
	2. Close the file descriptor of the write end of the pipe on the parents side.
	3. Pass the write end of the pipe to the child as a command-line argument.
	4. Close the file descriptor of the read end of the pipe on the child's side.

## Task 3: Multiple Pipes Across a fork/exec

In this task, you will write a program that has two-way communication between parent and child. 
Use task 2 as a starting point, and add a second pipe to it.

1. Copy pipe3.c to twoPipesParent.c.
2. Copy pipe4.c to twoPipesChild.c.
3. Modify twoPipesParent.c as follows:
	1. Add a second pipe that will be used for a message from child to parent.
	2. Close the appropriate file descriptors on both pipes.
	3. Pass both pipes' files descriptors to the child in the exec.
	4. Send the message "Hi there, Kiddo" to the child over one pipe (as in Task 2). 
	Print the pid and byte count as in Task 2.
	5. Then, read a messgae from the child over the second pipe. 
	Print the pid, byte count, and message text as in Task 2. 
4. Modify twoPipesChild.c as follows:
	1. Grab the file descriptor of both pipes from the argument list.
	2. Close the appropriate file descriptor.
	3. Read a message from the parent over the first pipe (as in Task 2).
	Print the pid, byte count, and message text as in Task 2. 
	4. Send the message "Hi Mom" to the parent over the sewcond pipe. 
	Print the pid and byte count as in Task 2.

## Task 4: FIFOs

In this task, you will modify pipe1.c from Task 1 so it uses a FIFO instead of a pipe.

1. Cope pipe1.c from Task 1 and name is pipeFifo.c.
2. From your shell, create a FIFO /tmp/task4_fifo with appropriate file permissions and 
ownership by using mkfifo command.
3. Modify pipeFifo.c so it uses the FIFO you created instead of using a pipe.
