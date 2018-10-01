// Chapter 8, exercise 4 in "Programming in C", 4th Ed. by Stephen G. Kochan
// Use the formula to calculate N to get the day of the week
// By: boglinballet, Oct. 1, 2018

#include <stdio.h>

struct date
{
    int month;
    int day;
    int year;
};

int calculate_N(struct date d);
void day_of_week(int N);

int main(void)
{
    struct date d;
    printf("Please enter a date (mm dd yyyy): ");
    scanf("%i %i %i", &d.month, &d.day, &d.year);

    // I skip any checks that the date is realistic -- see ch8_ex2.c for this

    // error handling -- the date is older than March 1, 1700 and can't be calculated
    if (calculate_N(d) == 1)
    {
        printf("Sorry -- the date you entered is too old!");
        return 1;
    }

    else
    {
        printf("The date %.2i/%.2i/%.2i falls on a ", d.month, d.day, d.year);

        // day_of_week prints the weekday name
        day_of_week(calculate_N(d));

        return 0;
    }
}

// uses same structure as answer from ch8_ex2
int calculate_N (struct date d)
{

    int f;
    if (d.month <= 2)
    {
        f = d.year - 1;
    }

    else
    {
        f = d.year;
    }

    int g;
    if (d.month <= 2)
    {
        g = d.month + 13;
    }

    else
    {
        g = d.month + 1;
    }

    int N;
    N = 1461 * f / 4 + 153 * g / 5 + d.day;

    // for dates between 1700 and 1900 extra days have to be added to the total
    // is there a better way to do this other than constant values calculated for each of the relevant dates?
    int extra;
    if (N >= 694098)  // date is after March 1, 1900
    {
        extra = 0;
    }
    else if (N >= 657573 && N <= 694096)  // date is between March 1, 1800 and Feb 28, 1900
    {
        extra = 1;
    }
    else if (N >= 621048 && N <= 657571)
    {
        extra = 2;
    }
    else
    {
        // error handling is done in main if value 1 is returned
        return 1;
    }

    return (N + extra);
}

void day_of_week(int N)
{
    // printing the day of the week is difficult based on what has been presented so far in the book
    // In example 8.7, the abbreviation for the month name is printed one letter at a time
    // As the weekdays have different lengths of letters I will resort to a switch construction, from chapter 5

    N = (N - 621049) % 7;

    switch(N)
    {
        case 0:
            printf("Sunday\n");
            break;
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        case 6:
            printf("Saturday\n");
            break;
    }
}
