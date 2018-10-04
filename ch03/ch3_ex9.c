// Chapter 3, exercise 9 from "Programming in C" by Stephen G. Kochan, 4th ed.
// Use the formula from exercise 8 to calculate next largest even multiples
// By: boglinballet Sep 5, 2018

#include <stdio.h>

int main(void)
{

    int i = 365;
    int j = 7;

    int next_mult = i + j - i % j;

    printf("For %i and %i the largest even multiple is: %i\n", i, j, next_mult);

    i = 12258;
    j = 23;
    next_mult = i + j - i % j;

    printf("For %i and %i the largest even multiple is: %i\n", i, j, next_mult);

    i = 996;
    j = 4;
    next_mult = i + j - i % j;

    printf("For %i and %i the largest even multiple is: %i\n", i, j, next_mult);

    return 0;
}
