// Ch 10 ex 9 from "Programming in C" by Stephen G. Kochan
// Rewrite read_line() program with character pointer instead of array
// By: boglinballet, Oct. 4, 2018

#include <stdio.h>

void read_line_old(char buffer[]);
void read_line_new(char *buffer);
void read_line_new_2(char *buffer);

int main(void)
{
    char buffer[81];
    read_line_new_2(buffer);
    printf("%s\n", buffer);
    return 0;
}

// New syntax -- pointer to a character string
// This works as expected
void read_line_new(char *buffer)
{
    char character;

    do
    {
        character = getchar();
        *buffer++ = character;
    }
    while (character != '\n');

    *(--buffer) = '\0';
}

// New syntax take 2 -- pointer to a character string
// Produces a segmentation fault!
void read_line_new_2(char *buffer)
{
    char character;

    character = getchar();
    while (character != '\n')
    {
        *buffer++ = character;
    }
    
    *buffer = '\0';
}

// syntax from Ch 9: indexing through the array
void read_line_old(char buffer[])
{
    char character;
    int i = 0;

    do
    {
        character = getchar();
        buffer[i] = character;
        i++;
    }
    while (character != '\n');

    buffer[i - 1] = '\0';
}
