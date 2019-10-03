/*
Jack Stoetzel
Lab 03
task08.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>



int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        puts("Argument number error.");
        exit(1);
    }
    int infile, outfile, num;
    char buf;

    // Opens a file named in an argument
    infile = open(argv[1], O_RDONLY);
    if(infile < 0)
    {
        puts("Input file error.");
        exit(1);
    }

    // Opens a file named in an argument
    umask(0);
    outfile = open(argv[2], O_RDWR|O_CREAT|O_EXCL, 0666);
    if(outfile < 0)
    {
        puts("Output file error.");
        exit(1);
    }

    dup2(outfile, 1);
    while(read(infile, &buf, 1) == 1)
    {
        num = (int) buf;
        printf("%d ", num);
    }
    puts("");

    close(infile);
    close(outfile);
    exit(0);
}
