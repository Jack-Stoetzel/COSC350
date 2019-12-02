/*
 Jack Stoetzel
 Lab 10
 Task 1
 msgQsnd.c

 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

typedef struct MSGBUF
{
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
    buf.type = 1;
    char* input = (char*) calloc(256, sizeof(int));

    puts("Enter two inerger values...");

    // Reading in data from the user
    while(fgets(input, 256, stdin), !feof(stdin))
    {
        // Converting the string to two ints
        sscanf(input, "%d%d", &buf.one, &buf.two);
        // Sending the struct with the two ints to the message queue
        if (msgsnd(Qid, (MsgBuf *) &buf,  2 * sizeof(int), 0) == -1)
        {
            perror("msgsnd() error");
        }
        puts("Enter two inerger values...");
    }

    // Removing the message queue
    if(msgctl(Qid, IPC_RMID, NULL) == -1)
    {
        perror("msgctl() error.");
        exit(1);
    }
    return 0;
}
