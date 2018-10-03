// Ch 9, exercise 7 from "Programming in C" by Stephen G. Kochan
// Write a function to insert a word at a certain place in a string
// By: boglinballet, Oct 3, 2018

#include <stdio.h>

void insert_string(char source[], char add[], int position);

int main(void)
{
    char source[81] = "the wrong son";
    char add[81] = "per";
    insert_string(source, add, 10);
    printf("%s\n", source);
}

void insert_string(char source[], char add[], int position)
{
    char buffer[81];
    int i, j = 0;

    for (i = position; source[i] != '\0'; i++)
    {
        buffer[j] = source[i];
        j++;
    }
    buffer[j] = '\0';

    for (i = 0; add[i] != '\0'; i++)
    {
        source[position + i] = add[i];
    }

    for (j = 0; buffer[j] != '\0'; j++)
    {
        source[position + i + j] = buffer[j];
    }

    source[position + i + j] = '\0';
}
