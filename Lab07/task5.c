/*
 * Jack Stoetzel
 * Lab 07
 * Task 5
 * task5.c
 * 
 */

#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


int main(int argc, char* argv[])
{
	int i;

	struct sigaction act;
	//act.sa_handler = ouch;  
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;

	//Loop 1: Block SIGINT and SIGQUIT
	for(i = 1; i <= 5; i++){
		printf("%d \n", i);
		sigaction(SIGINT, &act, NULL);
		sigaction(SIGQUIT, &act, NULL);
		sleep(1);
	}

	// Loop 2: Block SIGINT
	for(i = 1; i <= 5; i++){
		printf("%d \n", i);
		sigaction(SIGINT, &act, NULL);
		sleep(1);
	}

	return 0;
}