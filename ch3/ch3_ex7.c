// Chapter 3, exercise 7 in "Programming in C" by Stephen G. Kochan 4th ed.
// Calculate an expression and display as exponential format
// By: boglinballet Sep. 5, 2018

#include <stdio.h>

int main(void)
{
    float result = (3.31e-8 * 2.01e-7) / (7.16e-6 + 2.01e-8);
    printf("The result is: %e\n", result);
    return 0;
}
