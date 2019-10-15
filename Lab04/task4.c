/*
Jack Stoetzel
Lab 04
task4.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char* argv[])
{

    umask(0);
    struct stat dir;
    stat(argv[2], &dir);
    if(S_ISDIR(dir.st_mode)){
        char path[strlen(argv[2]) + strlen(argv[1])];
        sprintf(path, "%s", argv[2]);
        sprintf(path, "%s/%s", path, argv[1]);
        link(argv[1], path);
        unlink(argv[1]);
    }
    else{
        char path[strlen(argv[2]) + strlen(argv[1])];
        sprintf(path, "%s", argv[2]);
        printf("%s \n", path);
        sprintf(path, "%s/%s", path, argv[1]);
        printf("%s \n", path);
        mkdir(argv[2], 0777);
        link(argv[1], path);
        unlink(argv[1]);
    }
}
