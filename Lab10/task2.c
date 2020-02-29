/*
 Jack Stoetzel
 Lab 10
 Task 2
 task2.c

 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <pthread.h>

int list[10];
int curr = 0;

void producer()
{
    while(1){
        int item = rand() % 10;
    	if(curr < 10){
    		list[curr++] = item;
        }
    	else{
    		printf("No space to insert. \n");
        }
        printf("Producing %d\n", item);
        int i;
        for(i = 0; i < 10; i++)
        {
            printf("%d ", list[i]);
        }
        puts("");
        sleep(1);
    }
}
void consumer()
{
    while(1){
        int temp = list[curr - 1];
    	if(curr >= 0)
    	{
    		curr--;
    		list[curr] = 0;
    	}
    	else{
    		printf("No value to remove\n");
        }
        printf("Consuming %d\n", temp);
        int i;
    	for(i = 0; i < 10; i++)
        {
    		printf("%d ", list[i]);
        }
    	puts("");
    	sleep(2);
    }
}

int main(int argc, char* argv[])
{
    pthread_t thread_ID[2];
    pthread_create(&thread_ID[0], NULL, producer, NULL);
    pthread_create(&thread_ID[1], NULL, consumer, NULL);

    pthread_join(thread_ID[0], NULL);
    pthread_join(thread_ID[1], NULL);

    return 0;
}
