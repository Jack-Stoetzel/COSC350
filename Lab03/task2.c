/*
Jack Stoetzel
Lab 03
task02.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int infile, outfile;
	char buf;

	// Opens a file called "foo"
	infile = open("foo", O_RDONLY);
	if(infile < 0)
	{
		puts("Input file error.");
		exit(1);
	}

	// Opens a file called "clone1"
	umask(0);
	outfile = open("clone1", O_WRONLY|O_CREAT|O_EXCL, 0666);
	if(outfile < 0)
	{
		puts("Output file error.");
		exit(1);
	}

	// Copys content of "foo" byte by byte to "clone1"
	while (read(infile, &buf, 1) == 1)
		write(outfile, &buf, 1);

	close(infile);
	close(outfile);
	exit (0);
}
