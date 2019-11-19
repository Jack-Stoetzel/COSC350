/*
 Jack Stoetzel
 Lab 09
 Task 3
 twoPipesParent.c

 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int data_processed;
    int file_pipes[2];
    int pipe2[2];
    const char some_data[] = "123";
    char buffer[BUFSIZ + 1];
    pid_t fork_result;

    memset(buffer, '\0' ,sizeof(buffer));

    if(pipe(file_pipes) == 0 && pipe(pipe2) == 0)
    {
        fork_result = fork();
    	if(fork_result == -1)
    	{
        	fprintf(stderr, "Fork Failure");
        	exit(EXIT_FAILURE);
    	}
    	
    	if(fork_result==0)
    	{
            // Send both file descriptors to the child and the message "Hi there, Kiddo"
    		char wBuffer[BUFSIZ + 1];
        	sprintf(buffer, "%d", file_pipes[0]);
        	sprintf(wBuffer, "%d", file_pipes[1]);
       		(void)execl("pipe4","pipe4", buffer, wBuffer, (char*)0);
    	    exit(EXIT_FAILURE);
    	}
    	else
    	{
            // Read and print the message from the child
        	data_processed=write(file_pipes[1], some_data, strlen(some_data));
        	close(file_pipes[1]);
        	wait(&fork_result);
        	printf("%d - wrote %d bytes \n", getpid(), data_processed);
    	}  
  	}
    exit(EXIT_SUCCESS);
}
