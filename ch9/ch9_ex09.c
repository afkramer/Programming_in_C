// Ch 9, ex 9 from "Programming in C" by Stephen G. Kochan, 4th ed.
// Further optimize replace_string() so that all instances of a text are found and replaced
// By: boglinballet, Oct. 3, 2018

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int find_string(char source[], const char find[]);
void remove_string(char source[], int start, int count);
void insert_string(char source[], const char add[], int position);
bool replace_string(char source[], const char find[], const char replace[]);

int main(void)
{
    char source[81] = "The worst dog ever is a dog I love.";
    const char find[] = " ";
    const char replace[] = "";
    bool replaced = replace_string(source, find, replace);
    printf("%s\n", source);
    if (replaced)
    {
        printf("The text \"%s\" was found and replaced.\n", find);
    }
    else
    {
        printf("The text \"%s\" was not found and could not be replaced.\n", find);
    }

    return 0;
}

int find_string(char source[], const char find[])
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

void insert_string(char source[], const char add[], int position)
{
    char buffer[81];
    int i, j = 0;

    // Write the part of the string to buffer that will be overwritten
    for (i = position; source[i] != '\0'; i++)
    {
        buffer[j] = source[i];
        j++;
    }
    buffer[j] = '\0';

    // write the text from string add to the source at the correct position
    for (i = 0; add[i] != '\0'; i++)
    {
        source[position + i] = add[i];
    }

    // write the text saved to the buffer back to the original string
    for (j = 0; buffer[j] != '\0'; j++)
    {
        source[position + i + j] = buffer[j];
    }

    source[position + i + j] = '\0';
}

bool replace_string(char source[], const char find[], const char replace[])
{
    int count = strlen(find);
    bool textReplaced = false;

    // see if the text to be replaced is in the source text
    int start = find_string(source, find);

    // create a loop so that all instances of the text are found and replaced
    while (start != -1)
    {
        remove_string(source, start, count);
        insert_string(source, replace, start);
        textReplaced = true;
        start = find_string(source, find);
    }

    // if the loop condition is not fulfilled, false will be returned
    return textReplaced;
}
