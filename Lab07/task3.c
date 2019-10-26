/*
 * Jack Stoetzel
 * Lab 07
 * Task 3
 * task3.c
 * 
 */

#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>	// For strlen (I didn't want to use this, but it's the only way I won't get a warning)

int main(int argc, char* argv[])
{
	pid_t pid;
	int i, infile, outfile;
	char buf;

	if(outfile < 0)
	{
		puts("Ouput file error");
		exit(1);
	}

	pid = fork();

	if(pid < 0)
	{
		puts("Fork failed.");
		exit(1);
	}
	else if(pid == 0)
	{
		// Child process writes "Hi, Mom." to the file 'foo', and then terminates.
		
		outfile = open("foo", O_WRONLY|O_CREAT|O_EXCL, 0755);
		char hello[] = "Hi, Mom.";
		
		for(i = 0; i < strlen(hello); i++)
		{
			write(outfile, &hello[i], 1);
		}
	}
	else
	{
		// Parent process reads the file 'foo' and then writes it to the screen

		wait(&pid);

		infile = open("foo", O_RDONLY);
		printf("My son said, ");

		while(read(infile, &buf, 1) > 0)
		{
			printf("%c", buf);
		}
	}

	close(infile);
	close(outfile);
	return 0;
}