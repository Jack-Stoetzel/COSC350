/*
 Jack Stoetzel
 Lab 09
 Task 3
 twoPipesChild.c

 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
  int data_processed, data2;
  char buffer[BUFSIZ+1];
  int wfd, rfd;
  char message[] = "Hi Mom";

  memset(buffer, '\0', sizeof(buffer));
  sscanf(argv[1], "%d", &rfd);
  sscanf(argv[2], "%d", &wfd);

  data_processed = read(rfd, buffer, BUFSIZ);
  data2 = write(wfd, message, 6);
  printf("Child (%d) recieved the message \" %s \" made of %d bytes. \n", getpid(), buffer, data_processed);
  printf("Child (%d) sent %d bytes to the parent. \n", getpid(), data2);
  exit(EXIT_SUCCESS);
}
