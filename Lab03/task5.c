/*
Jack Stoetzel
Lab 03
task05.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int infile, outfile, curr;
	char buf;

	// Opens a file called "foo"
	infile = open("foo", O_RDONLY);
	if(infile < 0)
	{
		puts("Input file error.");
		exit(1);
	}

	// Opens a file called "foorev"
	umask(0);
	outfile = open("foorev", O_WRONLY|O_CREAT|O_EXCL, 0760);
	if(outfile < 0)
	{
		puts("Output file error.");
		exit(1);
	}

	curr = lseek(infile, -1, SEEK_END);

	// Copys content starting from the back of "foo" to "foorev"
	for(; curr >= 0; curr--)
	{
		read(infile, &buf, 1);
		write(outfile, &buf, 1);
		lseek(infile, -2, SEEK_CUR);
	}
	close(infile);
	close(outfile);
	exit(0);

}
