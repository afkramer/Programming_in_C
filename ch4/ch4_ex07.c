// Ch.4, exercise 7 from 'Programming in C' by Stephen G. Kochan
// figuring out what a decimal point does in the format specifier
// By: boglinballet, Sep 12, 2018

#include <stdio.h>

int main(void)
{
    int dollars, cents, count;

    for (count = 1; count <= 10; count++)
    {
        printf("Enter dollars: ");
        scanf("%i", &dollars);
        printf("Enter cents: ");
        scanf("%i", &cents);
        printf("$%i.%2.i\n\n", dollars, cents);
    }

    return 0;
}
