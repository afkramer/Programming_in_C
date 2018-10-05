// Ch 10 exercise 11 from "Programming in C" by Stephen G. Kochan, 4th ed.
// Write a function to update a pointer to a date
// By: boglinballet, Oct 5, 2018

#include <stdio.h>
#include <stdbool.h>

struct date
{
    int month;
    int day;
    int year;
};

void update_date(struct date *ptr);
int days_in_mon(struct date d);
bool is_leapyear(struct date d);

int main(void)
{
    struct date date1;
    printf("Please enter a date (mm dd yyyy): ");
    scanf("%i%i%i", &date1.month, &date1.day, &date1.year);

    update_date(&date1);

    printf("The new date is: %i/%i/%.2i.\n", date1.month, date1.day, date1.year);

    return 0;
}


void update_date(struct date *ptr)
{
    if (ptr->day != days_in_mon(*ptr))
    {
        ptr->day += 1;
    }
    else if (ptr->month == 12)
    {
        ptr->month = 1;
        ptr->day = 1;
        ptr->year += 1;
    }
    else
    {
        ptr->month += 1;
        ptr->day = 1;
    }
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
