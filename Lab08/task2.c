/*
 Jack Stoetzel
 Lab 08
 Task 2
 task2.c

	1. Get test scores from the keyboard, up to 20, and saves them into the array.
	2. Calculate an average score and Medium value and display.
	3. Get the minimum and the maximum score and display.
	4. Clear buffer to all 0's
 */

#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void readScores(int* scores)
{
	int i, k, n, score;
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

	i--;

	// Sorting the array with selection sort. Will be helpful later with median, min, and max
	for(k = 0; k < i - 1; k++)
	{
		int min = k;
		for(n = k + 1; n < i; n++)
		{
			if(scores[n] < scores[min])
			{
				min = n;
			}
		}
		int temp = scores[k];
		scores[k] = scores[min];
		scores[min] = temp;
	}

	pthread_exit(NULL);
}

void calcAvgMed(int* scores)
{
	int i;
	int total = 0;
	float avg, median;

	for(i = 0; scores[i] != -1; i++)
	{
		total += scores[i];
	}

	if(i == 0)
	{
		puts("The average and median are 0 becuase there were no scores entered.");
		pthread_exit(NULL);
	}

	avg = (float) total / i;

	if(i % 2 == 0)
	{
		int rhs = (i / 2) - 1;
		int lhs = i / 2;
		median = (float) (scores[rhs] + scores[lhs]) / 2;
	}
	else
	{
		median = scores[i / 2];
	}

	printf("The average score is %2.2f and the median score is %2.2f \n", avg, median);

	pthread_exit(NULL);
}

void calcMinMax(int* scores)
{
	int i, max;
	// Minimum can be assumed becusae the list was sorted in thread 1
	int min = scores[0];

	for(i = 0; scores[i] != -1; i++)
	{
		max = scores[i];
	}

	if(i == 0)
	{
		puts("The lowest and highest are 0 becuase there were no scores entered.");
		pthread_exit(NULL);
	}

	printf("The lowest score was a %d, and the highest was a %d \n", min, max);

	pthread_exit(NULL);
}

void clearBuffer(int* scores)
{
	int i;

	puts("Clearing buffer with all 0's");
	for(i = 0; i < 20; i++)
	{
		scores[i] = 0;
		printf("%d ", scores[i]);
	}
	puts("");

	pthread_exit(NULL);
}

int main(int argc, char* argv[])
{
	pthread_t THREAD[4];
	int rc, i;

	int* scores = malloc(20 * sizeof(int));

	// Setting every position to -1 will be used to determine valid array positions later
	for(i = 0; i < 20; i++)
	{
		scores[i] = -1;
	}

	rc = pthread_create(&THREAD[0], NULL, readScores, (void *) scores);
	if(rc)
	{
		puts("Error ocurred when creating pthread for reading test scores.");
		exit(-1);
	}

	pthread_join(THREAD[0], NULL);

	rc = pthread_create(&THREAD[1], NULL, calcAvgMed, (void *) scores);
	if(rc)
	{
		puts("Error ocurred when creating pthread for reading test scores.");
		exit(-1);
	}

	rc = pthread_create(&THREAD[2], NULL, calcMinMax, (void *) scores);
	if(rc)
	{
		puts("Error ocurred when creating pthread for reading test scores.");
		exit(-1);
	}

	pthread_join(THREAD[1], NULL);
	pthread_join(THREAD[2], NULL);

	rc = pthread_create(&THREAD[3], NULL, clearBuffer, (void *) scores);
	if(rc)
	{
		puts("Error ocurred when creating pthread for reading test scores.");
		exit(-1);
	}

	pthread_join(THREAD[3], NULL);

	pthread_exit(NULL);

    return 0;
}
