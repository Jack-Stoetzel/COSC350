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

void *doMath(void *threadID){
	int ID = (int) threadID;
	printf("My thread ID is %d \n", ID);
	if(ID == 0){

	}
	if(ID == 1){

	}
	pthread_exit(NULL);
}

int main(int argc, char* argv[])
{
	pthread_t THREADS[2];
	int currentThread, i;
	int num = myatoi(argv[1]);
	for(i = 0; i < 2; i++){
		currentThread = pthread_create(&THREADS[i], NULL, doMath, (void *) i, num);
		if(currentThread){
			printf("Error! pthread_create returned the error code %d \n", currentThread);
			exit(-1);
		}
	}
	pthread_exit(NULL);
    return 0;
}
