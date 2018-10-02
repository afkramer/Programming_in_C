// Ch.9 exercise 4 from "Programming in C" by Stephen G. Kochan, 4th ed.
// Create a function that creates a substring from a given string
// By: boglinballet Oct. 2, 2018

#include <stdio.h>

void substring(const char source[], int start, int count, char result[]);

int main(void)
{
    char result[5];
    substring("catsup", 3, 4, result);
    printf("%s\n", result);

    substring("cheeseburger", 6, 4, result);
    printf("%s\n", result);
}

void substring(const char source[], int start, int count, char result[])
{
    int i;

    for (i = 0; i <= count && source[i] != '\0'; i++)
    {
        result[i] = source[start + i];
    }

    result[i - 1] = '\0';
}
