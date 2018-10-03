// Ch 9, exercise 13 from "Programming in C" by Stephen G. Kochan, 4th ed.
// Create a function that converts lowercase to uppercase letters
// By: boglinballet, Oct. 3, 2018

#include <stdio.h>

void uppercase(char string[]);

int main(void)
{
    char text1[20] = "cheese dog";
    char text2[20] = "I'm hungry";
    char text3[20] = "wHaT AbOuT tHiS";

    uppercase(text1);
    uppercase(text2);
    uppercase(text3);

    printf("%s\n", text1);
    printf("%s\n", text2);
    printf("%s\n", text3);

    return 0;
}


void uppercase(char string[])
{
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] >= 'a' && string[i] <= 'z')
        {
            string[i] = string[i] - 'a' + 'A';
        }
    }
}
