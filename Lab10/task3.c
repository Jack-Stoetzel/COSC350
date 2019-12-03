/*
 Jack Stoetzel
 Lab 10
 Task 3
 task3.c

 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define N 10
typedef int semaphore;
semaphore mutex = 1;
semaphore empty = N;
semaphore full = 0;

int semid;
int list[10];
int curr = 0;
pthread_t thread_id[2];


void producer()
{
    int item;
    while(1)
    {
        item = producer_item();
        down(&empty);
        down(&mutex);
        insert_item(item);
        up(&mutex);
        up(&full);
    }
}

void consumer()
{
    int item;
    while(1)
    {
        down(&full);
        down(&mutex);
        item = remove_item();
        up(&mutex);
        up(&empty);
        consume_item(item);
    }
}

void insert_item(int item)
{
    if(curr < 10)
    {
        list[curr] = item;
        curr++;
    }
    else{
        printf("list is full\n");
    }
}
int remove_item()
{
    int i = -1;
    if(curr >= 0)
    {
        i = list[--curr];
        list[curr] = 0;
        return i;
    }
    else
        printf("list is empty\n");
}

void up(int sem_num)
{
    struct sembuf up = {sem_num, 1, 0};
    if(semop(semid, &up, 1) == -1) 
    {
        perror("semop() error");
        exit(1);
    }
}

void down(int sem_num)
{
    struct sembuf down = {sem_num, -1, 0};
    if(semop(semid, &down, 1) == -1)
    {
        perror("semop() error");
        exit(1);
    }
}

int main(int argc, char* argv[])
{

    key_t key;
    struct senum arg;
    if((key = ftok("task3.c", 'B')) == -1)
    {
        perror("ftok() error.");
        exit(1);
    }
/* create a semaphore set with 1 semaphore: */

    if((semid = semget(key, 3, 0644 | IPC_CREAT)) == -1)
    {
        perror("semget Error");
        exit(1);
    }

    //initialize all of the semaphores
    arg.val = 0;
    if(semctl(semid, full, SETVAL, arg) == -1)
    {
        perror("semctl Error");
        exit(1);
    }
    arg.val = 10;
    if(semctl(semid, empty, SETVAL, arg) == -1)
    {
        perror("semctl Error");
        exit(1);
    }
    arg.val = 1;
    if(semctl(semid, mutex, SETVAL, arg) == -1)
    {
        perror("semctl Error");
        exit(1);
    }

    printf("Starting threads\n");
    pthread_create(&thread_id[0], NULL, producer, (void*)&semid);
    pthread_create(&thread_id[1], NULL, consumer, (void*)&semid);

    pthread_join(thread_id[0], NULL);
    pthread_join(thread_id[1], NULL);

    return 0;
}
