/*
 Jack Stoetzel
 Lab 10
 Task 1
 msgQrcv.c

 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

typedef struct MSGBUF{
    long type;
    int one;
    int two;
}MsgBuf;

int main(int argc, char* argv[])
{
    // Sets key value to 'msgQsnd.c'
    key_t key;
    if((key = ftok("msgQsnd.c", 'B')) == -1)
    {
        perror("ftok() error.");
        exit(1);
    }

    // Creates the message queue with the key and the privileges rw-r--r--
    int Qid;
    if((Qid = msgget(key, 0644 | IPC_CREAT)) == -1)
    {
        perror("msgget() error.");
        exit(1);
    }

    MsgBuf buf;
    while(1)
    {
        // Reads the message from teh buffer and stores it into the MsgBuf object
        if(msgrcv(Qid, (MsgBuf*) &buf, 2 * sizeof(int), 0, 0) == -1)
        {
            perror("msgrcv() error");
            exit(1);
        }
        printf("The sum of the digits recieved from 'msgQsnd.c' is %d \n", buf.one + buf.two);
    }

    return 0;
}
