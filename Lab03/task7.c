/*
Jack Stoetzel
Lab 03
task07.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
	if(argc < 2)
	{
		puts("Argument number error.");
		exit(1);
	}

	int num;
	int index = 1;
	int total = 0;

	for(; index <= (argc - 1); index++)
	{
		num = myatoi(argv[index]);
		total += num;
	}
	printf("total = %d \n", total);
	exit(0);
}
