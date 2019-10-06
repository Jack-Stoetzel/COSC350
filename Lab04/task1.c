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

int main(int argc, char *argv[])
{
    int num = 56;
    char word[2];
    num = convIntToStr(word, num);
    printf("%d \n", num);
    printf("%s \n", word);
    exit(0);
}
