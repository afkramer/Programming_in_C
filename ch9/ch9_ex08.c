// Ch 9, ex 8 from "Programming in C" by Stephen G. Kochan, 4th ed.
// Use the find_string(), remove_string() and insert_string() to find a replace text
// By: boglinballet, Oct. 3, 2018

#include <stdio.h>
#include <string.h>

int find_string(char source[], const char find[]);
void remove_string(char source[], int start, int count);
void insert_string(char source[], const char add[], int position);
void replace_string(char source[], const char find[], const char replace[]);

int main(void)
{
    char source[81] = "The worst dog ever.";
    const char find[] = "worst";
    const char replace[] = "best";
    replace_string(source, find, replace);
    printf("%s\n", source);
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

void replace_string(char source[], const char find[], const char replace[])
{
    int count = 0;
    int start = find_string(source, find);

    // if the text to be replaced is found in the source string
    if (start != -1)
    {
        // find out how long the string is to be removed
        // could have also been done with strlen()
        while (find[count] != '\0')
        {
            count++;
        }

        remove_string(source, start, count);
        insert_string(source, replace, start);
    }
}
