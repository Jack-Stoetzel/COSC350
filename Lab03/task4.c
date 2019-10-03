/*
Jack Stoetzel
Lab 03
task04.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int infile1, infile2, outfile;
	char buf1, buf2;

	// Opens two files called "foo" and "foo1"
	infile1 = open("foo", O_RDONLY);
	infile2 = open("foo1", O_RDONLY);
	if(infile1 < 0 || infile2 < 0)
	{
		puts("Input file error.");
		exit(1);
	}

	// Opens a file called "foo12"
	umask(0);
	outfile = open("foo12", O_WRONLY|O_CREAT|O_EXCL, 0760);
	if(outfile < 0)
	{
		puts("Output file error.");
		exit(1);
	}

	// Copys contents of "foo" byte by byte to "foo12"
	while((read(infile1, &buf1, 1) == 1))
		write(outfile, &buf1, 1);

	// Copys contents of "foo1" byte by byte to "foo12"
	while(read(infile2, &buf2, 1) == 1)
		write(outfile, &buf2, 1);

	close(infile1);
	close(infile2);
	close(outfile);
	exit(0);
}
