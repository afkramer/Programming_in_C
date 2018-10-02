// Ch. 9 exercise 6 from "Programming in C" by Stephen G. Kochan
// Write a program to remove a certain number of characters from a string
// By: boglinballet, Oct. 2, 2018

#include <stdio.h>

void remove_string(char source[], int start, int count);

int main(void)
{
    char text[] = "the wrong son";
    remove_string(text, 4, 6);
    printf("%s\n", text);
}


void remove_string(char source[], int start, int count)
{
    int i = 0;

    while(source[i + count] != '\0')
    {
        if (i >= start)
        {
            source[i] = source[i + count];
        }
        i++;
    }

    source[i] = '\0';
}
