/*
Jack Stoetzel
Lab 06
Task 2
fork1.c

*/
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

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
    int Nc = myatoi(argv[1]);
    int Np = myatoi(argv[2]);
    int Tc = myatoi(argv[3]);
    int Tp = myatoi(argv[4]);

    pid_t pid;
    char* message;
    int n, t;

    printf("Fork program starting.\n");
    pid = fork();
    switch(pid)
    {
        case -1:
            perror("Fork failed.");
            exit(1);
        case 0:
            message = "This is the child.";
            n = Nc;
            t = Tc;
            break;
        default:
            message = "This is the parent.";
            n = Np;
            t = Tp;
            break;
    }

    for(; n > 0; n--)
    {
        puts(message);
        sleep(t);
    }
    exit(0);
}
