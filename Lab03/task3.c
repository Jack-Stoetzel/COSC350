/*
Jack Stoetzel
Lab 03
task03.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 32

int main(int argc, char *argv[])
{
	int infile, outfile, bytes;
	char buffer[BUFFER_SIZE];

	// Opens a file called "foo"
	infile = open("foo", O_RDONLY);
	if(infile < 0)
	{
		puts("Input file error.");
		exit(1);
	}

	// Opens a file called "clone2"
	umask(0);
	outfile = open("clone2", O_WRONLY|O_CREAT|O_EXCL, 0770);
	if(outfile < 0)
	{
		puts("Output file error.");
		exit(1);
	}

	// Copys contents of "foo" 32 bytes at a time to "clone1"
	while((bytes = read(infile, buffer, BUFFER_SIZE)) > 0)
		write(outfile, buffer, bytes);

	close (infile);
	close (outfile);
	exit(0);
}
