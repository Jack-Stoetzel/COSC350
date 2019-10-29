/*
 Jack Stoetzel
 Lab 07
 Task 5
 task5.c

 	int sigprocmask(int how, const sigset_t *set, const sigset_t *oset);

	how options:
		SIG_BLOCK
		SIG_UNBLOCK
		SIG_SETMASK
 */

#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


int main(int argc, char* argv[])
{
	int i;
	sigset_t sigs, old;

	// Clears the signal set
	sigemptyset(&sigs);

	// Adds SIGINT to the signal set 'sigs'
	sigaddset(&sigs, SIGINT);

	// Adds SIGQUIT to the signal set 'sigs'
	sigaddset(&sigs, SIGQUIT);

	// Blocks the signal in the signal set 'sigs' and store the old signal mask in the set 'old'
	sigprocmask(SIG_BLOCK, &sigs, &old);

	//Loop 1: Block SIGINT and SIGQUIT
	for(i = 1; i <= 5; i++){
		printf("%d \n", i);
		sleep(1);
	}

	//sigprocmask(SIG_SETMASK, &sigs, &old);

	sigemptyset(&sigs);

	sigaddset(&sigs, SIGINT);

	sigprocmask(SIG_BLOCK, &sigs, &old);

	// Loop 2: Block SIGINT
	for(i = 1; i <= 5; i++){
		printf("%d \n", i);
		sleep(1);
	}

	return 0;
}
