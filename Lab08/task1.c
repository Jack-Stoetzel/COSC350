/*
 Jack Stoetzel
 Lab 08
 Task 1
 task1.c

	When compiling, this error occurs:
	warning: cast to 'void *' from smaller integer type 'int' 
	[-Wint-to-void-pointer-cast]

	pthread_create(pthread_t *thread, const pthread_attr_t *att, void *(*start_routine)(void*), void *arg);

 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *findSum(void *n)
{
	int i;
	int nn = (int) n;

	for(i = nn - 1; i > 0; i--)
	{
		nn += i;
	}
	
	n = (void *) nn;

	return n;

}

void *findProduct(void *n)
{
	int i;
	int nn = (int) n;
	
	for(i = nn - 1; i > 0; i--)
	{
		nn *= i;
	}
	
	n = (void *) nn;
	
	return n;
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

	if(argc != 2)
	{
		puts("Invalid argument input. Only accepting one integer argument.");
		exit(1);
	}
	
	int n = myatoi(argv[1]);

	// Makes a thread to find the sum of all numbers from 1 - n
	rc = pthread_create(&sumThread, NULL, findSum, (void*) n);
	if(rc)
	{
		puts("Error ocurred when creating pthread.");
		exit(-1);
	}

	// Makes a thread to find the product of all numbers from 1 - n
	rc = pthread_create(&prodThread, NULL, findProduct, (void*) n);
		if(rc)
	{
		puts("Error ocurred when creating pthread.");
		exit(-1);
	}

	void* sum;
	void* prod;

	pthread_join(sumThread, &sum);
	pthread_join(prodThread, &prod);

	printf("∑n = %d \n", (int) sum);
	printf("n! = %d \n", (int) prod);

	pthread_exit(NULL);
    
    exit(0);
}
