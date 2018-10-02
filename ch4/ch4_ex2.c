// Chapter 4, exercise 2 from 'Programming in C' by Stephen G. Kochan, 4th ed
// By: boglinballet, Sep. 12, 2018

#include <stdio.h>

int main(void)
{
    printf("CHART OF N AND N SQUARED\n");
    printf("   n      n2  \n");
    printf("---------------\n");

    for (int i = 1; i < 11; i++)
    {
        printf("  %2i     %3i\n", i, i * i);
    }
    return 0;
}
