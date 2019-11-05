/*
 Jack Stoetzel
 Lab 08
 Task 4
 task4.c

 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int i;
    int size = 0;
    char *cmd;

    for(i = 1; i < argc; i++)
    {
        size += strlen(argv[i]);
    }

    cmd = calloc(size, sizeof(char));

    for(i = 1; i < argc; i++)
    {
        sprintf(cmd, "%s %s", cmd, argv[i]);
    }

    char buf[BUFSIZ];
    FILE *ptr;
   	
    if ((ptr = popen(cmd, "r")) != NULL)
    {
        while (fgets(buf, BUFSIZ, ptr) != NULL)
        {
            (void) printf("%s", buf);
        }
    }

    pclose(ptr);

    return 0;
}
