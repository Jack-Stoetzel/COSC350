/*
 Jack Stoetzel
 Lab 08
 Task 2
 task2.c
	
	1. Get test scores from the keyboard, up to 20, and saves them into the array.
	2. Calculate an average score and Medium value and display.
	3. Get the minimum and the maximum score and display.
	4. Display results
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void readScores(float* scores)
{
	int i, valid = 1;

	puts("You may enter up to 20 test scores, or enter -1 to quit early.");

	for(i = 0; i < 20 && valid; i++)
	{
		printf("Enter test score %d: ", i + 1);
		scanf("%f", scores[i]);
		
		if(scores[i] == -1)
		{
			valid = 0;
		}
	}
	pthread_exit(NULL);
}

int main(int argc, char* argv[])
{
	pthread_t THREADS[4];
	int rc, i;

	float* scores = malloc(20 * sizeof(float));
	for(i = 0; i < 20; i++)
	{
		scores[i] = -1;
	}

	rc = pthread_create(&THREADS[0], NULL, readScores, scores);
	if(rc)
	{
		puts("Error ocurred when creating pthread for reading test scores.");
		exit(-1);
	}

	pthread_exit(NULL);

    return 0;
}
