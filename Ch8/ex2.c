#include <stdio.h>
#include <stdbool.h>

struct date
{
    int month;
    int day;
    int year;
};

int elapsed_time(struct date d);
int days_in_mon(struct date d);
bool is_leap_year(struct date d);
int absolute_val(int n);

int main(void)
{
    // set up two variables to contain the user-defined dates and values for N
    struct date date1;
    struct date date2;

    int N_date1;
    int N_date2;

    // Allow user to type in two dates
    printf("Please enter the first date (mm dd yyyy): ");
    scanf("%i %i %i", &date1.month, &date1.day, &date1.year);
    printf("Please enter the second date (mm dd yyyy): ");
    scanf("%i %i %i", &date2.month, &date2.day, &date2.year);

    // Check that the two dates are allowable (day can't be less than 0 or greater than # of days in month, month can't be less than 0 or greater than 12)
    if (date1.month > 12 || date1.month < 1 || date1.day < 1 || date1.day > days_in_mon(date1) ||
        date2.month > 12 || date2.month < 1 || date2.day < 1 || date2.day > days_in_mon(date2))
    {
        printf("Sorry, one of your dates is not valid. Please try again.\n");
        return 1;
    }

    // Calculate the number of days between the dates with the elapsed_time function
    N_date1 = elapsed_time(date1);
    N_date2 = elapsed_time(date2);

    // error handling -- if elapsed_time returns 1 then quit the program because the user entered a date too old
    if (N_date1 == 1 || N_date2 == 1)
    {
        return 1;
    }

    // return the number of days between the dates
    printf("The number of days between those two dates is: %i\n", absolute_val(N_date2 - N_date1));
    return 0;
}

int elapsed_time(struct date d)
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
        printf("Sorry, one of your dates is too old -- can't calculate. Please try again.\n");
        return 1;
    }

    return (N + extra);
}

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

int absolute_val(int n)
{
    if (n < 0)
    {
        n *= -1;
    }

    return n;
}
