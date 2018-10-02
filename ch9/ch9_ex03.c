// Ch 9, exercise 3 from "Programming in C" by Stephen G. Kochan
// Changing programs 9.7 and 9.8 to allow for words with apostrophes as well as numbers
// By: boglinballet, Oct. 2, 2018

#include <stdio.h>
#include <stdbool.h>
// to be able to use isalpha() and isdigit()
#include <ctype.h>

bool OK_char(const char c);
int count_words(const char string[]);

int main(void)
{
    const char text1[] = "The current total is -145,678.77.";
    const char text2[] = "I've eaten 67,567.9 cheeseburgers in my life.";
    const char text3[] = "How about hyphenated-words. I guess they count as one.";

    printf("%s - words = %i\n", text1, count_words(text1));
    printf("%s - words = %i\n", text2, count_words(text2));
    printf("%s - words = %i\n", text3, count_words(text3));
}

bool OK_char(const char c)
{
    if ( isalpha(c) || isdigit(c) || c == '\'' || c == '.' || c == ',' || c == '-')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int count_words(const char string[])
{
    int wordCount = 0;
    bool lookingForWord = true;

    for (int i = 0; string[i] != '\0'; i++)
    {
        if (OK_char(string[i]))
        {
            if (lookingForWord)
            {
                wordCount++;
                lookingForWord = false;
            }
        }
        else
        {
            lookingForWord = true;
        }
    }

    return wordCount;
}
