// Chapter 8, Exercise 5 from "Programming in C" by Stephen G. Kochan, 4th ed.
// Create a function to update the time and date
// By: boglinballet, Oct. 1, 2018

#include <stdio.h>
#include <stdbool.h>

struct time
{
    int hours;
    int minutes;
    int seconds;
};

struct date
{
    int month;
    int day;
    int year;
};

struct dateAndTime
{
    struct date sdate;
    struct time stime;
};

struct dateAndTime clockKeeper(struct dateAndTime dat);
struct time update_time(struct time t);
struct date update_date(struct date d);
int days_in_mon(struct date d);
bool is_leap_year(struct date d);

int main(void)
{
    // No error handling is done in case the date or time is not permissible!
    
    struct dateAndTime dat;
    printf("Please enter a date and time (mm dd yyyy hh:mm:ss): ");
    scanf("%i %i %i %i:%i:%i", &dat.sdate.month, &dat.sdate.day, &dat.sdate.year, &dat.stime.hours, &dat.stime.minutes, &dat.stime.seconds);

    dat = clockKeeper(dat);
    printf("It is now: %.2i/%.2i/%.2i %.2i:%.2i:%.2i\n",
            dat.sdate.month, dat.sdate.day, dat.sdate.year, dat.stime.hours, dat.stime.minutes, dat.stime.seconds);
    return 0;
}

struct dateAndTime clockKeeper(struct dateAndTime dat)
{
    dat.stime = update_time(dat.stime);

    if (dat.stime.hours == 0 && dat.stime.minutes == 0 && dat.stime.seconds == 0)
    {
        dat.sdate = update_date(dat.sdate);
    }

    return dat;
}

struct time update_time(struct time t)
{
    t.seconds++;

    if (t.seconds == 60)
    {
        t.seconds = 0;
        t.minutes++;

        if (t.minutes == 60)
        {
            t.minutes = 0;
            t.hours++;

            if (t.hours == 24)
            {
                t.hours = 0;
            }
        }
    }

    return t;
}

struct date update_date(struct date d)
{
    struct date tomorrow;

    if (d.day == days_in_mon(d))
    {
        if (d.month == 12)
        {
            tomorrow.day = 1;
            tomorrow.month = 1;
            tomorrow.year = d.year + 1;
        }

        else
        {
            tomorrow.day = 1;
            tomorrow.month = d.month + 1;
            tomorrow.year = d.year;
        }
    }

    else
    {
        tomorrow.day = d.day + 1;
        tomorrow.month = d.month;
        tomorrow.year = d.year;
    }
    return tomorrow;
}

// returns the number of days in the month as a comparison
int days_in_mon(struct date d)
{
    int days_per_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (d.month == 2 && is_leap_year(d))
    {
        return 29;
    }

    else
    {
        return days_per_month[d.month];
    }
}

// checks if year is a leap year; returns true and false
bool is_leap_year(struct date d)
{
    bool leapYearFlag;

    if ((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0)
    {
        leapYearFlag = true;  // It's a leap year
    }

    else
    {
        leapYearFlag = false;  // Not a leap year
    }

    return leapYearFlag;
}
