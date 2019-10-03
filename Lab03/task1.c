/*
Jack Stoetzel
Lab 03
task01.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	int bytes;
	char buf;

	while((bytes = read(0, &buf, 1)) > 0)
		write(1, &buf, bytes);

}
