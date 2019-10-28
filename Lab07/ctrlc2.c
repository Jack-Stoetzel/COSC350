/*
 Jack Stoetzel
 Lab 07
 Task 2
 ctrlc2.c

     struct sigaction {
        void (*) (int) sa_hadler;   // function, SIG_DFL or SIG_IGN 
        sigset_t sa_mask;           // signals to block in sa_handler 
        int sa_flags;               // signal actoin modifiers
    };

 */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void ouch(int sig)
{
    printf("\t OUCH! - I got signal %d. \n", sig);
    //sigaction(SIGQUIT, &act, NULL);
}

int main(int argc, char* argv[])
{
    struct sigaction act;

    act.sa_handler = ouch;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;

    sigaction(SIGINT, &act, 0);

    while(1)
    {
        printf("Hello, World! \n");
        sleep(1);
    }

    return 0;
}