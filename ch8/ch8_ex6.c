// Chapter 8, exercise 6 from "Programming in C" by Stephen G. Kochan, 4th ed.
// Replace the dateUpdate() function from program 8.4 in the reading with the modified one
// By: boglinballet, Oct. 1, 2018

#include <stdio.h>
#include <stdbool.h>

struct date
{
    int month;
    int day;
    int year;
};

struct date update_date(struct date today);
int days_in_mon(struct date d);
bool is_leapyear(struct date d);

int main(void)
{
    struct date thisDate, nextDate;

    printf("Enter today's date (mm dd yyyy): ");
    scanf("%i %i %i", &thisDate.month, &thisDate.day, &thisDate.year);

    nextDate = update_date(thisDate);

    printf("The next day is: %.2i/%.2i/%.2i.\n", nextDate.month, nextDate.day, nextDate.year % 100);
    return 0;
}

struct date update_date(struct date today)
{
    struct date tomorrow;

    if (today.day != days_in_mon(today))
    {
        tomorrow = (struct date) { .month = today.month, .day = today.day + 1, .year = today.year };
    }
    else if (today.month == 12)
    {
        tomorrow = (struct date) { .month = 1, .day = 1, .year = today.year + 1 };
    }
    else
    {
        tomorrow = (struct date) { .month = today.month + 1, .day = 1, .year = today.year };
    }

    return tomorrow;
}

int days_in_mon(struct date d)
{
    const int daysPerMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (is_leapyear(d) && d.month == 2)
    {
        return 29;
    }
    else
    {
        return daysPerMonth[d.month];
    }
}

bool is_leapyear(struct date d)
{
    bool leapYearFlag = false;

    if ((d.year % 4 == 0 && d.year % 100 != 0) || (d.year % 400 == 0))
    {
        leapYearFlag = true;
    }

    return leapYearFlag;
}
