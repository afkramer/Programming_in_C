// Ch. 4, exercise 8 from "Programming in C" by Stephen G. Kochan
// By: boglinballet, Sep 12, 2018

#include <stdio.h>

int main(void)
{
    int num_of_tris;
    printf("How many triangular numbers do you want to calculate? ");
    scanf("%i", &num_of_tris);

    int sum = 0;
    int triangularNumber = 0;

    for (int n = 0; n < num_of_tris; n++)
    {
        printf("What triangular number do you want? ");
        scanf("%i", &triangularNumber);

        for (int i = 1; i <= triangularNumber; i++)
        {
            sum += i;
        }

        printf("Your triangular number is: %i\n", sum);
        sum = 0;
    }
}
