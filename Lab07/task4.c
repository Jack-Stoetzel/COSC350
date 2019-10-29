/*
 * Jack Stoetzel
 * Lab 07
 * Task 4
 * task4.c
 * 
 */

#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void ProcessSignal(int sig){
	if(sig == SIGUSR1){
		puts("Hi Honey! Anything wrong?");
	}
	else if(sig == SIGUSR2){
		puts("Do you make trouble again?");
	}
}

int main(int argc, char* argv[])
{
	signal(SIGUSR1, ProcessSignal);
  	signal(SIGUSR2, ProcessSignal);

	pid_t pid1, pid2;
	pid1 = fork();
	if(pid1 < 0)
	{
		puts("Fork failed.");
		exit(1);
	}
	else if(pid1 == 0)
	{
		
	}
	else
	{
		pid2 = fork();
		if(pid2 < 0)
		{
			puts("Fork failed.");
			exit(1);
		}
		else if(pid2 == 0)
		{

		}
		else
		{
			kill(pid1, SIGUSR1);
			kill(pid2, SIGUSR2);
		}
	}
	//wait();
	//wait();

	return 0;
}