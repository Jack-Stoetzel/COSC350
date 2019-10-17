# Lab #4


## Task #1

Write a C main function that takes one command-line argument, the name of an input file. The input file contains exactly one integer spread out over a single line of up to 80 characters. For example, the integer 3579 is embedded in the line az3mqrm5t?7!z9v. 

Your program uses system calls to do the following:
  1. Open and read the input file, accumulating the discovered digit characters into a character array (string)
  2. Convert the string to an integer (do not use atoi function)
  3. Add 10 to the integer
  4. Convert the sum back to a string (using function convIntToStr)
  5. Make a system call to write the string to standard output
  
    /****************************************************
        Convert integer to string
        Params: x is the int to be converted
                str is the string into which to write
        Returns: length of the string
    *****************************************************/
    
    int convIntToStr(char * str, int x)
    {
        sprintf(str, "%d", x);
        return (strlen(str));
    }
    

    /* Returns a non-zero value if character c is a digit, zero otherwise. */
   
    int isdigit(int c)

You need to include five header files, <unistd.h>, <fcntl.h>, <ctype.h>, <stdio.h>, <string.h> for read write open system calls and sprint return strlen library functions.


## Task #2

Write a C program which accepts two file names as arguments: input file name and output file name. Your program copies one file to another file. Exit the program with an appropriate error message under the following error conditions:

  1. If input file is not available
  
## Task #3.1

Write a simple program called hello.c and compile it and create executable file named hello. 

Write a C program for sequence of following tasks:
  1. By using system calls, build the following directory structure
  
  ![Pic 1](./3.1 w_o hello.png)
  
  2. By using system calls, copy hello file under ~/Dir2/Dir12/
  3. By using system calls, make a symbolic link named toDir12 to directory toDir12
  4. By using system calls, make a symbolic link named toHello to executable file ~/Dir12/hello
  
  ![Pic 2](./3.1 w_ hello.png)
   
## Task #3.2

(Test for Task #3.1) Execute hello by using symbolic link toHello. Try to delete a file, make a directory by using symbolic link toDir21

## Task #4

By using bash command mv, you can move a file from current directory to another directory. Write your own mv called MyMv **by using system calls link() and unlink()**. Your program named MyMv can move a file from a current directory to a directory. Your program receives two arguments: **file name and path to a directory where the file needs to be move,** **or file name and path to directory with a file name**.

If the second argument is a directory, move a file to the directory. If the second argument is not a directory, move file to a directory as a file name.

Ex.)

  * Move a file foo to under directory **~/separk/cosc350**
      
        ./MyMv foo ~/separk/cosc350
    
  * Move a file foo to under directory **~/separk/cosc350** named **abc** if there is no directory named abc
  
        ./MyMv foo ~/separk/cosc350/abc
  
  * Move a file foo under directory **~/separk/cosc350** named **foo** if there is no directory named foo
  
        ./MyMv foo ~/separk/cosc350/foo
    
