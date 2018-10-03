// Ch 9, exercise 12 from "Programming in C" by Stephen G. Kochan, 4th ed.
// Create a function to turn strings into floats
// By: boglinballet, Oct 3, 2018

/* Note: I believe that the results are not 100% exact due to how floats are handled by C. */

#include <stdio.h>

float str_to_float(const char string[]);

int main(void)
{
    printf("%f\n", str_to_float("-837.3895"));
    printf("%f\n", str_to_float("456.6921"));
    printf("%f\n", str_to_float("-180.2345"));
    printf("%f\n", str_to_float("-200.00005"));
    return 0;
}


float str_to_float(const char string[])
{
    int i, intVal, mult = 1, count = 0, sign = 1;
    float intPart, floatPart;

    // Obtain the integer part of the number by looping through until the decimal is reached
    for (i = 0; (string[i] >= '0' && string[i] <= '9') || string[i] == '-'; i++)
    {
        if (string[i] == '-')
        {
            sign = -1;
        }
        else
        {
            intVal = string[i] - '0';
            intPart = intPart * 10 + intVal;
        }
    }

    // continue looping through the number after the decimal
    // add the int to the running total as above
    for (i = i + 1; (string[i] >= '0' && string[i] <= '9') || string[i] == '-'; i++)
    {
        intVal = string[i] - '0';
        floatPart = floatPart * 10 + intVal;
        count++;
    }

    // divide floatPart by 10 ** count to be able to obtain the decimal part
    for (i = 0; i < count; i++)
    {
        mult *= 10;
    }

    // only if there is a decimal part higher than 0, divide by the multiple of 10
    if (floatPart != 0)
    {
        floatPart = floatPart / mult;
    }

    return (intPart + floatPart) * sign;
}
