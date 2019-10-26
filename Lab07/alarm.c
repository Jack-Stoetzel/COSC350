/*
 * Jack Stoetzel
 * Lab 07
 * Task 1
 * alarm.c
 * 
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
    puts("\a");
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
            // Waits 5 seconds, then kills the child process with SIGALRM
            sleep(5);
            kill(getppid(), SIGALRM);   // SIGALRM 14 Alarm Clock (POSIX)
            exit(0);
        }
    }

    puts("Waiting for alarm to go off... \n");
    (void) signal(SIGALRM, ding);   // Sends SIGALRM signal to the ding function

    pause();

    if(alarm_fired)
    {
        puts("DING!");
    }

    puts("Done. \n");

    exit(0);
}

