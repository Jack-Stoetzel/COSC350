/*
Jack Stoetzel
Lab 06
child.c

*/
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char* argv[])
{
	int Nc = myatoi(argv[1]);
	int Tc = myatoi(argv[2]);

	for(; Nc > 0; Nc--)
    {
        puts("This is the child");
        sleep(Tc);
    }
	exit(37);
}
