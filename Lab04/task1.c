/*
Jack Stoetzel
Lab 04
task1.c
*/

#include <unistd.h>
#include <fcntl.h>
//#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Converts integer number to string,
// and returns the length of the string
int convIntToStr(char * str, int x)
{
    sprintf(str, "%d", x);
    return (strlen(str));
}

// Checks if an integer falls in the ascii range of 0 - 9,
// and returns 1 if true, and zero if false
int isdigit(int c)
{
    if(c >= 48 && c <= 57)
        return 1;
    else
        return 0;
}

// Converts a string to an integer,
// and returns the integer value
int myatoi(char *str)
{
	int num = 0;
	int index = 0;

	while(str[index] != '\0')
	{
		num = (num * 10) + (str[index] - 48);
		index++;
	}
	return num;
}

int main(int argc, char *argv[])
{
    // Check for correct number of arguments
    if (argc != 2)
    {
        puts("Argument number error.");
        return 1;
    }

    // Opens an input file from command line argument,
    // and checks for any errors
    int infile;
    infile = open(argv[1], O_RDONLY);
    if(infile < 0)
    {
        puts("Input file error.");
        return 1;
    }

    // Reads through the input file,
    // checking every character for if it is a digit,
    // and stores it inside a string if it is a digit
    char str[80], buf;
    int i = 0;
    while(read(infile, &buf, 1) == 1)
        if(isdigit(buf))
        {
            str[i] = buf;
            i++;
        }

    // Converts the string to an integer and adds 10 to it
    int num = myatoi(str);
    num += 10;
    convIntToStr(str, num);

    // Writes the integer to the standard output
    write(1, str, i);

    return 0;
}
