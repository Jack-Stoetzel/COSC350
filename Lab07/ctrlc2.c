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

    // Converts Ctrl+C and Ctrl+\ back to their default operations
    signal(SIGINT, SIG_DFL);
    //signal(SIGQUIT, SIG_DFL);
}

int main(int argc, char* argv[])
{
    struct sigaction act;

    act.sa_handler = ouch;  // When a signal is used with act, the ouch() function will be called
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;

    sigaction(SIGINT, &act, NULL);      // Sets Ctrl+C to trigger the ouch() function
    //sigaction(SIGQUIT, &act, NULL);   // Sets Ctrl+\ to trigger the ouch() function

    while(1)
    {
        printf("Hello, World! \n");
        sleep(1);
    }

    return 0;
}
