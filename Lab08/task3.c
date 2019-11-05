/*
Jack Stoetzel
Lab 08
Task 3
task3.c

*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

/* Read characters from the pipe and echo them to stdout. */
void read_from_pipe (int fd)
{
    FILE *stream;
    int c;
    stream = fdopen (fd, "r");
    while ((c = fgetc (stream)) != EOF) /* Read a character by character until EOF */
    putchar (c); /* Write on standard output */
    fclose (stream);s
}
/* Write some random text to the pipe. */
void write_to_pipe (int fd)
{
    FILE *stream;
    stream = fdopen (fd, "w"); /* open a pipe for writing */
    fprintf (stream, "hello, world!\n");
    fprintf (stream, "goodbye, world!\n");
    fclose (stream);
}

int main(int argc, char* argv[])
{
    return 0;
}
