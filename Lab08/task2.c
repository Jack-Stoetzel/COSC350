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

#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void readScores(int* scores)
{
	//int* tempScores = (int*) scores;
	int i, score, k;
	int valid = 1;

	puts("You may enter up to 20 test scores, or enter -1 to quit early.");

	for(i = 0; i < 20 && valid; i++)
	{
		printf("Enter test score %d: ", i + 1);
		scanf("%d", &score);
		while(score < -1)
		{
			puts("Invalid score input. Please input a positive score.");
			scanf("%d", &score);
		}

		scores[i] = score;

		if(score == -1)
		{
			valid = 0;
		}
	}
	printf("Reallocating to %d \n", (i - 1) * sizeof(int));
	scores = (int*) realloc(scores, i * sizeof(int));
	printf("Printing %d \n", (sizeof(scores) / sizeof(int)));
	for(k = 0; k < (sizeof(scores) / sizeof(int)); k++)
	{
		printf("%d ", scores[k]);
	}
	puts("");

	pthread_exit(NULL);
}

void calcAvgMed(int* scores)
{
	int i;
	int total = 0;

	for(i = 0; scores[i] != -1; i++)
	{
		total += scores[i];
	}

	if(i == 0)
	{
		puts("The average and median are 0 becuase there were no scores entered.");
		pthread_exit(NULL);
	}

	float avg = (float) total / i;

	pthread_exit(NULL);
}

int main(int argc, char* argv[])
{
	pthread_t THREADS[4];
	int rc, i;

	int* scores = malloc(20 * sizeof(int));

	rc = pthread_create(&THREADS[0], NULL, readScores, scores);
	if(rc)
	{
		puts("Error ocurred when creating pthread for reading test scores.");
		exit(-1);
	}

	pthread_join(THREADS[0], scores);
/*
	for(i = 0; i < 20; i++)
	{
		printf("%d ", scores[i]);
	}
*/
	/*

	rc = pthread_create(&THREADS[1], NULL, calcAvgMed, scores);
	if(rc)
	{
		puts("Error ocurred when creating pthread for reading test scores.");
		exit(-1);
	}
	*/

	pthread_exit(NULL);

    return 0;
}
