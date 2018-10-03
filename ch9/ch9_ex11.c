// Ch 9, exercise 11 from "Programming in C" by Stephen G. Kochan, 4th ed.
// Expand function strToInt from program 9.11 to allow for negative numbers
// By: boglinballet, Oct. 3, 2018

#include <stdio.h>

int str_to_int(const char string[]);

int main(void)
{
    printf("%i\n", str_to_int("245"));
    printf("%i\n", str_to_int("-836"));
    printf("%i\n", str_to_int("-72"));

    return 0;
}

int str_to_int(const char string[])
{
    int i, intValue, result = 0, sign = 1;

    for (i = 0; (string[i] >= '0' && string[i] <= '9') || string[i] == '-'; i++)
    {
        if (string[i] == '-')
        {
            sign = -1;
        }

        else
        {
            intValue = string[i] - '0';
            result = result * 10 + intValue;
        }
    }

    return result * sign;
}
