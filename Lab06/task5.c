/*
Jack Stoetzel
Lab 06
Task 5
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
    int infile, childOut, parentOut, exit_code;
    char buf;
    int childOff = 0;
    int parentOff = 0;

    infile = open(argv[1], O_RDONLY);
    if(infile < 0)
    {
        puts("Input file error.");
		exit(1);
    }
    parentOut = open("parent.txt", O_WRONLY|O_CREAT|O_EXCL, 0755);
    childOut = open("child.txt", O_WRONLY|O_CREAT|O_EXCL, 0755);
    if(childOut < 0 || parentOut < 0)
    {
        puts("Output file error.");
		exit(1);
    }

    pid = fork();

        switch(pid)
        {
            case -1:
                perror("Fork failed.");
                exit(1);
            case 0:
                exit_code = 37;
                while(pread(infile, &buf, 1, childOff) == 1)
                {
                if(isdigit(buf) == 0)
                {
                    write(childOut, &buf, 1);
                }
                childOff++;
            }
                break;
            default:
                exit_code = 0;
                while(pread(infile, &buf, 1, parentOff) == 1)
                {
                if(isdigit(buf) == 1)
                {
                    write(parentOut, &buf, 1);
                }
                parentOff++;
            }
                break;
        }

    close(infile);
    close(childOut);
    close(parentOut);

    if(pid != 0)
    {
        int stat_val;
        pid_t child_pid;

        child_pid = wait(&stat_val);

        printf("Child  has finished: PID = %d. \n", child_pid);
        if(WIFEXITED(stat_val))
        {
            printf("Child exited with code %d. \n", WEXITSTATUS(stat_val));
        }
        else
        {
            printf("Child terminated abnormally. \n");
        }
    }
    exit(exit_code);
}
