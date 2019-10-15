/*
Jack Stoetzel
Lab 04
task3.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int openUtmpFile()
{
    int ufd;
    ufd = open("/var/run/utmp", O_RDONLY);
    if(ufd < 0)
    {
        puts("Unable to open the utmp file. \n");
        exit(1);
    }
    return ufd;
}

int main(int argc, char **argv)
{
    int ufd = openUtmpFile();
    printf("The utmp file descriptor is %d. \n", ufd);
    return 0;
}
