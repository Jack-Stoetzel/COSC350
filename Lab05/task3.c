/*
Jack Stoetzel
Lab 05
task3.c

Tue Oct 15 12:00:00 2019
stuct tm
{
    int tm_sec;     // Seconds after the minute     0-60
    int tm_min;  	// Minutes after the hour	    0-59
    int tm_hour;    // Hours since midnight	        0-23
    int tm_mday;    // Day of the month	            1-31
    int tm_mon;     // Months since January	        0-11
    int tm_year;    // Years since 1900
    int tm_wday;    // Days since Sunday            0-6
    int tm_yday;    // Days since January 1	        0-365
    int tm_isdst;   // Daylight Saving Time flag
}
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <utmp.h>
#include <time.h>

char* myasctime(const struct tm *timeptr)
{
    char wDay[][4] =
    {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    char month[][4] =
    {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    static char time[26];
    sprintf(time, "%s %s %2d %.2d:%.2d:%.2d %d",
    wDay[timeptr->tm_wday], month[timeptr -> tm_mon],
    timeptr -> tm_mday, timeptr -> tm_hour, timeptr -> tm_min,
    timeptr -> tm_sec, timeptr -> tm_year + 1900);

    return time;
}

int main(int argc, char* argv[])
{
    time_t raw;
    time(&raw);
    struct tm *time;
    time = localtime(&raw);
    printf("The time is %s \n", myasctime(time));
    return 0;
}
