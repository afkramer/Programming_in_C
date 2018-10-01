// Chapter 8, exercise 3
// Write a function that takes two time structures and calculates the elapsed time between the two
// By: boglinballet, Oct 1, 2018

#include <stdio.h>

struct time
{
    int hours;
    int minutes;
    int seconds;
};

struct time elapsed_time(struct time time1, struct time time2);

int main(void)
{
    // set up variables for the two user-defined times
    struct time time1;
    struct time time2;
    struct time elapsed;

    printf("Please enter the first time (hh:mm:ss): ");
    scanf("%i:%i:%i", &time1.hours, &time1.minutes, &time1.seconds);

    printf("Please enter the second time (hh:mm:ss): ");
    scanf("%i:%i:%i", &time2.hours, &time2. minutes, &time2.seconds);

    // make sure that the two times are allowable
    if (time1.hours > 23 || time1.hours < 0 || time1.minutes > 59 || time1.minutes < 0 || time1.seconds > 59 || time1.seconds < 0 ||
        time2.hours > 23 || time2.hours < 0 || time2.minutes > 59 || time2.minutes < 0 || time2.seconds > 59 || time2.seconds < 0)
    {
        printf("One of the times you entered is not valid. Please try again.\n");
    }

    // Calculate the difference between the two times
    elapsed = elapsed_time(time1, time2);

    // Print the time elapsed
    printf("The time elapsed between %.2i:%.2i:%.2i and %.2i:%.2i:%.2i is: %.2i:%.2i:%.2i.\n",
            time1.hours, time1.minutes, time1.seconds, time2.hours, time2.minutes, time2.seconds, elapsed.hours, elapsed.minutes, elapsed.seconds);
    return 0;
}

struct time elapsed_time(struct time time1, struct time time2)
{
    struct time elapsed;

    if (time2.seconds < time1.seconds)
    {
        elapsed.seconds = time2.seconds + 60 - time1.seconds;
    }

    else
    {
        elapsed.seconds = time2.seconds - time1.seconds;
    }

    if (elapsed.seconds != 0)
    {
        // increase time1.minutes by one before calculating minutes
        time1.minutes++;
    }

    if (time2.minutes < time1.minutes)
    {
        elapsed.minutes = time2.minutes + 60 - time1.minutes;
    }

    else
    {
        elapsed.minutes = time2.minutes - time1.minutes;
    }

    if (elapsed.minutes != 0)
    {
        time1.hours++;
    }

    if (time2.hours < time1.hours)
    {
        elapsed.hours = time2.hours + 24 - time1.hours;
    }

    else
    {
        elapsed.hours = time2.hours - time1.hours;
    }

    return elapsed;
}
