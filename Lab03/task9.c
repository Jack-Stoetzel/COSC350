/*
Jack Stoetzel
Lab 03
task09.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int palind(int fd1, int fd2)
{
    char buf1, buf2;
    int size = lseek(fd2, -2, SEEK_END);
    int curr;
    // Compares the back of the file to the front of the file
    for(curr = 0; curr < size; curr++)
	{
        lseek(fd1, curr, SEEK_SET);
        read(fd1, &buf1, 1);
        lseek(fd2, -2 - curr, SEEK_END);
		read(fd2, &buf2, 1);

        //printf("%c = %c \n", buf1, buf2);
        if(buf1 != buf2)
            return 0;
	}
    return 1;
}


int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        puts("Argument number error.");
        exit(1);
    }
    int infile1, infile2, result;

    // Opens a file named in an argument
    infile1 = open(argv[1], O_RDONLY);
    infile2 = dup(infile1);
    if(infile1 < 0 || infile2 < 0)
    {
        puts("Input file error.");
        exit(1);
    }

    // Test file for palindrome, returns 1 if valid
    result = palind(infile1, infile2);
    if(result == 1)
        puts("The file is a palindrome.");
    else
        puts("The file is not a palindrome.");

    close(infile1);
    close(infile2);
    exit(0);
}
