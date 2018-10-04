// Ch 10 exercise 7 from "Programming in C" by Stephen G. Kochan, 4th ed
// Rewrite the sort function from chapter 7 using pointers exclusively
// By: boglinballet, Oct. 4, 2018

#include <stdio.h>

void sort(int *array, int n);

int main(void)
{
    int i;
    int array[16] = {34, -5, 6, 0, 12, 100, 56, 22,
                    44, -3, -9, 12, 17, 22, 6, 11};

    printf("The array before the sort:\n");
    for (i = 0; i < 16; i++)
    {
        // change this reference also to pointers
        printf("%i ", *(array + i));
    }

    sort(array, 16);

    // change these lines also to pointers
    printf("The array after the sort:\n");
    for (i = 0; i < 16; i++)
    {
        printf("%i ", *(array + i));
    }

    printf("\n");

    return 0;
}

// not sure if it is possible to replace the for () initializations without i and j
void sort(int *array, int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (*(array + i) > *(array + j))
            {
                temp = *(array + i);
                *(array + i) = *(array + j);
                *(array + j) = temp;
            }
        }
    }
}
