// Ch 10 exercise 10 from "Programming in C" by Stephen G. Kochan, 4th ed
// rewrite the compare_strings() function to use character pointers instead of arrays
// By: boglinballet, Oct 5, 2018

#include <stdio.h>
#include <stdbool.h>

bool compare_strings_new(const char *string1, const char *string2);
bool compare_strings_old(const char string1[], const char string2[]);

int main(void)
{
    const char *string1 = "The same";
    const char *string2 = "The saaame";
    if (compare_strings_new(string1, string2))
    {
        printf("They are the same!\n");
    }
    else
    {
        printf("They are not the same.\n");
    }

    return 0;
}


bool compare_strings_new(const char *string1, const char *string2)
{
    bool areEqual = false;

    // while the character is not '\0', which evaluates as 0 or false
    while(*string1 && *string2)
    {
        string1++;
        string2++;
    }

    if(*string1 == '\0' && *string2 == '\0')
    {
        areEqual = true;
    }

    return areEqual;
}

bool compare_strings_old(const char s1[], const char s2[])
{
    int i = 0;
    bool areEqual;

    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
    {
        i++;
    }

    if (s1[i] == '\0' && s2[i] == '\0')
    {
        areEqual = true;
    }
    else
    {
        areEqual = false;
    }

    return areEqual;
}
