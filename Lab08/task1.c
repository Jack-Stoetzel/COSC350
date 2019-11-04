/*
 Jack Stoetzel
 Lab 08
 Task 1
 task1.c

	Take in 2 command line arguments.
	Make 2 threads
		1. One thread finds the sum from 1 - n
		2. The other finds the product from 1 - n

 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *findSum(void *n)
{
	int nn = (int) n;
	int i;

	for(i = nn - 1; i > 0; i--)
	{
		nn += i;
	}

	printf("The sum of all numbers from 1 - n is %d \n", nn);
	
	pthread_exit(NULL);
}

void *findProduct(void *n)
{
	int nn = (int) n;
	int i;

	for(i = nn - 1; i > 0; i--)
	{
		nn *= i;
	}

	printf("The product of all numbers from 1 - n is %d \n", nn);
	
	pthread_exit(NULL);
}

int myatoi(char *str)
{
	int num = 0;
	int index = 0;

	while(str[index] != '\0')
	{
		num = (num * 10) + (str[index] - 48);
		index++;
	}
	return num;
}

int main(int argc, char* argv[])
{
	pthread_t sumThread, prodThread;
	int rc;
	int n = myatoi(argv[1]);

	rc = pthread_create(&sumThread, NULL, findSum, (void *) n);
		if(rc)
	{
		puts("Error ocurred when creating pthreads");
		exit(-1);
	}

	rc = pthread_create(&prodThread, NULL, findProduct, (void *) n);
	
	if(rc)
	{
		puts("Error ocurred when creating pthreads");
		exit(-1);
	}

	
	pthread_exit(NULL);

	
    return 0;
}
