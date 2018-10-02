// Ch. 4, exercise 11 from 'Programming in C' by Stephen G. Kochan, 4th ed.
// By: boglinballet, Sep 12, 2018

#include <stdio.h>

int main(void)
{
    int orig_num;

    printf("Please enter a number: ");
    scanf("%i", &orig_num);

    int num = orig_num;
    int num_sum = 0;

    while (num != 0)
    {
        num_sum += num % 10;
        num /= 10;
    }

    printf("The sum of the digits in %i is: %i\n", orig_num, num_sum);
}
