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


int main(int argc, char* argv[])
{
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
			
		}
	}

	return 0;
}