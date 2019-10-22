/*
Jack Stoetzel
Lab 07
Task 1
task1.c

*/

#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static int alarm_fired = 0;

void ding(int sig)
{
    alarm_fired = 1;
    printf("\a \n");
}

int main(int argc, char* argv[])
{
    pid_t pid;

    puts("Alarm application starting. \n");

    pid = fork();

    switch(pid)
    {
        case -1:
        {
            perror("Fork failed. \n");
            exit(1);
        }
        case 0:
        {
            sleep(5);
            kill(getppid(), SIGALRM);
            exit(0);
        }
    }

    puts("Waiting for alarm to go off... \n");
    (void) signal(SIGALRM, ding);

    pause();

    if(alarm_fired)
    {
        puts("DING!");
    }

    puts("Done. \n");

    exit(0);
}
