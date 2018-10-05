// Ch 10, exercise 12 from "Programming in C" by Stephen G. Kochan, 4th ed
// Determine if the statements are valid or not
// By: boglinballet, Oct. 5, 2018

#include <stdio.h>

void set_1(void);
void set_2(void);
void set_3(void);
void set_4(void);

int main(void)
{
    set_4();
    return 0;
}

void set_1(void)
{
    char *message = "Programming in C is fun\n";
    printf("Programming in C is fun\n");
    printf("%s", "Programming in C is fun\n");
    printf("%s", message);

    /* the following command did not work and raised the error
    "Format string is not a string literal (potentially insecure)"
    printf(message);  */
}

void set_2(void)
{
    char message2[] = "You said it\n";

    printf("You said it\n");
    printf("%s", message2);

    /* again the following command raised the error
    "Format string is not a string literal (potentially insecure)"
    printf(message2); */

    printf("%s", &message2[0]);
}

void set_3(void)
{
    char message2[] = "You said it\n";

    printf("said it\n");

    /* doesn't work, see above
    printf(message2 + 4); */

    printf("%s", message2 + 4);
    printf("%s", &message2[4]);
}

void set_4(void)
{
    char *format = "x = %i\n";
    int x = 100;

    printf("x = %i\n", x);

    // Now this sytax works and displays the same thing!
    printf(format, x);
}
