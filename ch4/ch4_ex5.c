// Chapter 4, exercise 5 from "Programming in C" by Stephen G. Kochan, 4th ed.
// By: boglinballet, Sep. 12, 2018

#include <stdio.h>

int main(void)
{
    int n, two_to_the_n;
    printf("TABLE OF POWER OF TWO\n\n");
    printf(" n    2 to the n\n");
    printf("---   -------------\n");

    two_to_the_n = 1;

    for (n = 0; n <= 10; n++)
    {
        printf("%2i        %i\n", n, two_to_the_n);
        two_to_the_n *= 2;
    }

    return 0;
}
