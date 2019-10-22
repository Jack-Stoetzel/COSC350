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

    infile = open(argv[1], O_RDONLY);
    parentOut = open("parent.txt", O_WRONLY|O_CREAT|O_EXCL, 0755);
    childOut = open("child.txt", O_WRONLY|O_CREAT|O_EXCL, 0755);

    lseek(infile, 0, SEEK_SET);

    int childOff = lseek(infile, 0, SEEK_SET);
    int parentOff = lseek(infile, 0, SEEK_SET);

    pid = fork();

        switch(pid)
        {
            case -1:
                perror("Fork failed.");
                exit(1);
            case 0:
                exit_code = 37;
                //lseek(infile, childOff, SEEK_SET);
                while(pread(infile, &buf, 1, childOff) == 1)
                {
                if(isdigit(buf) == 0)
                {
                    //printf("%c is a letter \n", buf);
                    write(childOut, &buf, 1);
                }
                childOff++;
                //lseek(infile, childOff, SEEK_SET);
            }
                break;
            default:
                exit_code = 0;
                //lseek(infile, parentOff, SEEK_SET);
                while(pread(infile, &buf, 1, parentOff) == 1)
                {
                if(isdigit(buf) == 1)
                {
                    //printf("%c is a number \n", buf);
                    write(parentOut, &buf, 1);
                }
                parentOff++;
                //lseek(infile, parentOff, SEEK_SET);
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
