/*
Jack Stoetzel
Lab 05
task2.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <utmp.h>

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

int main(int argc, char* argv[])
{
    umask(0);
    setutent();
    int ufd = openUtmpFile();

    struct utmp *buf = getutent();

    printf("%s \n", buf->ut_user);

    close(ufd);
    return 0;
}
