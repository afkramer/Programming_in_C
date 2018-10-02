// Ch.9, exercise 5 from "Programming in C" by Stephen G. Kochan, 4th ed.
// Write a program to see if a substring is contained in another string
// By: boglinballet, Oct. 2, 2018

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int find_string(const char source[], const char find[]);

int main(void)
{
    const char source[] = "a chatterbox";
    //const char find[] = "bird";
    //const char find2[] = "hat";
    const char find3[] = "HAT";

    int position = find_string(source, find3);

    if (position == -1)
    {
        printf("\"%s\" is not in \"%s\".\n", find3, source);
    }

    else
    {
        printf("\"%s\" is in \"%s\" starting at position %i.\n", find3, source, position);
    }
}

int find_string(const char source[], const char find[])
{

    int i, j;
    char check[strlen(find) + 1];
    for(i = 0; source[i] != '\0'; i++)
    {
        for(j = 0; find[j] != '\0'; j++)
        {
            check[j] = source[i + j];
        }

        check[j] = '\0';

        if (strcmp(check, find) == 0)
        {
            return i;
        }
    }

    // find is not in source
    return -1;
}
