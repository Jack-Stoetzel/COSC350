/*
 Jack Stoetzel
 Lab 09
 Task 1
 pipe1.c

 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define READ_END = 0;
#define WRITE_END = 1;

int main(int argc, char* argv[])
{
    int file_pipes[2];
    int data_processed;
    const char some_data[] = "123";
    char* buffer = malloc(3 * sizeof(char));

    memset(buffer, '\0', sizeof(buffer));

    if(pipe(file_pipes) == 0)
    {
        data_processed = write(file_pipes[1], some_data, strlen(some_data));

        printf("Wrote %d bytes. \n", data_processed);

        data_processed = read(file_pipes[0], buffer, BUFSIZ);

        printf("Read %d bytes: %s \n", data_processed, buffer);

        exit(EXIT_SUCCESS);
    }
    exit(EXIT_FAILURE);
}
