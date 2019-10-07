/*
Jack Stoetzel
Lab 04
task2.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        puts("Argument number error.");
        return 1;
    }

	int infile, outfile;
	char buf;

	// Opens an input file from command line argument
	infile = open(argv[1], O_RDONLY);
	if(infile < 0)
	{
		puts("Input file error.");
		return 1;
	}

	// Opens an output file from command line argument
	umask(0);
	outfile = open(argv[2], O_WRONLY|O_CREAT|O_EXCL, 0666);
	if(outfile < 0)
	{
		puts("Output file error.");
		return 1;
	}

	// Copys content from input file byte by byte to
	while (read(infile, &buf, 1) == 1)
		write(outfile, &buf, 1);

	close(infile);
	close(outfile);
	return 0;
}
