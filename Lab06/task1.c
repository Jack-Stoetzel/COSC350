/*
Jack Stoetzel
Lab 06
Task 1
task1.c

*/
#include <stdio.h>
#include <stdlib.h>

char* mygetenv(char* name)
{
    extern char**  environ;
    int i, k, valid;

    for(i = 0; i < 71; i++)
    {
        //printf("%d = %s \n", i, environ[i]);
        valid = 1;
        for(k = 0; k < 3; k++)
        {
            //printf("%c == %c \n", environ[i][k], name[k]);
            if(environ[i][k] != name[k])
            {
                valid = 0;
            }
        }
        if(valid == 1)
        {
            return environ[i];
        }
    }
}

int main(int argc, char* argv[])
{
    printf("%s \n", mygetenv(argv[1]));
    return 0;
}
