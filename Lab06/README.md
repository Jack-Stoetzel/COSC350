# Lab 06

## Task 1: getenv() Function

* Write your own getenv() function called mygetenv(), which has the same syntax and semantics.
* Write a simple C program to show your mygetenv() function works well.

## Task 2: Creating New Processes Using fork()

1. Copy fork1.c from the textbook.
2. Compile and run it to be sure you understand what it does.
3. Modify your fork1.c to take four command-line arguments:
    1. Nc - The number of iterations for the child process
    2. Np - The number of iterations for the parent process
    3. Tc - The sleep time for the child process
    4. Tp - The sleep time for the parent process   
  
Then, modify the code accordingly.
    
4. Run the program as ```./fork1 5 3 1 1```. You should get the same results as running the original version.
5. Run the program with the following values (and any other values you find interesting).

| Nc | Np | Tc | Tp |
|:--:|:--:|:--:|:--:|
| 5  | 3  | 1  | 5  |
| 5  | 3  | 5  | 1  |

## Task 3: Using wait()

1. Copy your modified fork1.c to a file named forkWait.c.
2. Modify forkWait.c so the parent process waits for the child to finish. Use code from the textbook for the wait portion.
3. Run the program as ```./forkWait 5 3 1 1```.

## Task 4: Fork With exec()

This task forks a child process and uses exec() to replace its process image with another image. 
Its very similar to Task 3, but the child process is implemented as a sperate program.

1. Copy forkWait.c from Task 3 to a file named forkExec.c.
2. Modify forkExec.c so the child process image is replaced by the image of a program named child.c. 
Use one of the exec() family functions to do this.
3. Write child.c to do the same thing as the child process did in Task 4.
    * The child should give its pid each time it prints the message.
    * The parent should give its pid each time it prints the message.
    * The child program should take three command-line arguments, the message, Nc, and Tc.
    * To get an interesting exit status from the child, have it return 37 rather than 0.
    
## Task 5: File Sharing Between Parent and Child.

Write a C program such that it receives an input file name as an argument and opens the file as inputs.
And then create a child process. 
The input file must open only one time and the file descriptor is shared by the parent and child process.
Both parent and child read a byte at a time from the input file and write output to independent files 
(parent.txt for the parent, and child.txt for the child).
The parent process collects numeric characters and the child process will create wrong output file.

* Modify the previous program and try to synchronize and get correct outputs for each process.
    
Note)
* Do not open the input file twice for synchronization.
* Define your own functions to check numeric characters.
* Do not use vfork(), sleep(), wait(), or waitpid() for synchronization.
* Check all possible errors for system calls.
