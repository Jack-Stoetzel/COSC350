/*
Jack Stoetzel
Lab 06
task5.c

*/
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int isdigit(int c)
{
    if(c >= 48 && c <= 57)
        return 1;
    else
        return 0;
}

int main(int argc, char* argv[])
{
    pid_t pid;
    int childOff, parentOff;
    int infile, childOut, parentOut;
    char buf;

    infile = open(argv[1], O_RDONLY);
    parentOut = open("parent.txt", O_WRONLY|O_CREAT|O_EXCL, 0755);
    childOut = open("child.txt", O_WRONLY|O_CREAT|O_EXCL, 0755);

    int size = lseek(infile, -1, SEEK_END);
    lseek(infile, 0, SEEK_CUR);

    pid = fork();
    while(childOff <= size && parentOff <= size)
    {
        switch(pid)
        {
            case -1:
                perror("Fork failed.");
                exit(1);
            case 0:
                lseek(infile, childOff, SEEK_SET);
                read(infile, &buf, 1);
                if(isdigit(buf) == 1)
                {
                    write(childOut, &buf, 1);
                }
                childOff++;
                break;
            default:
                lseek(infile, parentOff, SEEK_SET);
                read(infile, &buf, 1);
                if(isdigit(buf) == 1)
                {
                    write(parentOut, &buf, 1);
                }
                parentOff++;
                break;
        }
    }
    close(infile);
    close(childOut);
    close(parentOut);

    return 0;
}
