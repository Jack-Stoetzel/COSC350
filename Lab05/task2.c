/*
Jack Stoetzel
Lab 05
task2.c

struct utmp
{
    short ut_type;              // Type of login
    pid_t ut_pid;               // PID of login process
    char ut)line[12];           // Device name of tty - "/dev/"
    char ut_id[4];              // Init id or abbrev. ttyname
    char ut_user[32];           // User name
    char ut_host[256];          // Hostname for remote login
    struct exit_status ut_exit; // The exit status of a process
}
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
    // utmp file is always in the same location
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
    // setutent - Sets the file cursor to begining of utmp file
    //            Should be done before all other functions
    setutent();
    umask(0);

    struct utmp *buf;
    int count = 0;
    int ufd = openUtmpFile();
    printf("The file descriptor of the utmp file is %d.\n", ufd);

    // getutent - Reads a line from the current utmp file
    buf = getutent();
    while(buf != NULL)
    {
        printf("%s \n", buf->ut_user);

        if(buf -> ut_type == USER_PROCESS)
        {
            count ++;
        }
        buf = getutent();

    }

    printf("The number of user processes is %d. \n", count);

    // endutent - closes the utmp file
    endutent();
    close(ufd);
    return 0;
}
