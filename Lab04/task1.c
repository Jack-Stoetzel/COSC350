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

int convIntToStr(char * str, int x)
{
    sprintf(str, "%d", x);
    return (strlen(str));
}

int isdigit(int c)
{
    if(c >= 48 && c <= 57)
        return 1;
    else
        return 0;
}

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
    if (argc != 2)
    {
        puts("Argument number error.");
        return 1;
    }

    int infile;
    infile = open(argv[1], O_RDONLY);
    if(infile < 0)
    {
        puts("Input file error.");
        return 1;
    }

    char str[80], buf;
    int i = 0;
    while(read(infile, &buf, 1) == 1)
        if(isdigit(buf))
        {
            str[i] = buf;
            i++;
        }

    int num = myatoi(str);
    num += 10;
    convIntToStr(str, num);
    write(1, str, i);

    return 0;
}
