// Ch. 4, exercise 6 from "Programming in C" by Stephen G. Kochan, 4th ed.
// program to generate a table of triangular numbers
// By: boglinballet, Sep. 12, 2018

#include <stdio.h>

int main(void)
{
    int n, triangularNumber;

    printf("TABLE OF TRIANGULAR NUMBERS\n\n");
    printf(" n    Sum from 1 to n\n");
    printf("---   ---------------\n");

    triangularNumber = 0;

    for (n = 1; n <= 10; n++)
    {
        triangularNumber += n;

        // non-justified format of the program
        //printf(" %i           %i\n", n, triangularNumber);

        printf("%-2i           %-3i\n", n, triangularNumber);

    }

    return 0;

}
