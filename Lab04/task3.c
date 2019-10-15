/*
Jack Stoetzel
Lab 04
task3.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    char home[] = "/Users/jstoetzel/";

    chdir(home);
    char dir1[] = "./Dir1/";
    int test = mkdir(dir1, 0755);
    printf("%d \n", test);
    char dir2[] = "/Users/jstoetzel/Dir2/";
    mkdir(dir2, 0755);
    chdir(dir2);
    char dir21[] = "/Users/jstoetzel/Dir2/Dir21/";
    mkdir(dir21, 0755);
    return 0;
}
