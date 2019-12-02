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

typedef struct MSGBUF{
    long type;
    int one;
    int two;
}MsgBuf;

int myatoi(char *str)
{
	int num = 0;
	int index = 0;
	while(str[index] != '\0' && str[index] != '\n')
	{
		num = (num * 10) + (str[index] - 48);
		index++;
	}
	return num;
}

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
    while(fgets(input, 256, stdin), !feof(stdin)) {
        sprintf(input, "%d%d", buf.one, buf.two);
        if (msgsnd(Qid, (MsgBuf *) &buf, sizeof(buf), 0) == -1){
            perror("msgsnd() error");
        }
    }

    // Removing the message queue
    if(msgctl(Qid, IPC_RMID, NULL) == -1)
    {
        perror("msgctl() error.");
        exit(1);
    }
    return 0;
}
