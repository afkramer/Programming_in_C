// Ch 9, exercise 10 from "Programming in C" by Stephen G. Kochan
// Write a function to sort a dictionary into alphabetical order
// By: boglinballet, Oct. 3, 2018

#include <stdio.h>
#include <string.h>

struct entry
{
    char word[15];
    char definition[50];
};

void sort_dictionary(struct entry dictionary[], int num_entries);
void print_dictionary(struct entry dictionary[], int num_entries);

int main(void)
{
    // create the dictionary not in order
    struct entry dictionary[100] =
    {  {"addle",    "to become confused"                },
       {"aardvark", "a burrowing African mammal"        },
       {"ahoy",     "a nautical call of greeting"       },
       {"zebra",    "a white and black striped animal"  },
       {"gross",    "the number 144; disgusting"        },
       {"abyss",    "a bottomless pit"                  },
       {"aigrette", "an ornamental cluster of feathers" },
       {"acumen",   "mentally sharp; keen"              },
       {"yolo",     "catchphrase you only live once"    },
       {"aerie",    "a high nest"                       },
       {"affix",    "to append; attach"                 },
       {"agar",     "a jelly made from seaweed"         },
       {"supreme",  "the top; the best"                 },
       {"barnacle", "an animal that lives on ships"     },
       {"chess",    "a game of skill and strategy"      },
       {"ajar",     "partially opened"                  }  };

    // use the sort_dictionary function to bring the entries into order
    sort_dictionary(dictionary, 16);
    // create a loop function to print the dictionary to check that it is in order
    print_dictionary(dictionary, 16);

    return 0;
}

void sort_dictionary(struct entry dictionary[], int num_entries)
{
    int i, j;
    char temp_word[15];
    char temp_def[50];

    for (i = 0; i < num_entries - 1; i++)
    {
        for (j = i + 1; j < num_entries; j++)
        {
            if (strcmp(dictionary[i].word, dictionary[j].word) > 0)
            {
                // switch out the words
                // strcpy is used for sake of simplicity
                // otherwise loop through letter by letter to switch out the strings
                strcpy(temp_word, dictionary[i].word);
                strcpy(dictionary[i].word, dictionary[j].word);
                strcpy(dictionary[j].word, temp_word);

                // switch out the definitions
                strcpy(temp_def, dictionary[i].definition);
                strcpy(dictionary[i].definition, dictionary[j].definition);
                strcpy(dictionary[j].definition, temp_def);
            }
        }
    }
}

void print_dictionary(struct entry dictionary[], int num_entries)
{
    for (int i = 0; i < num_entries; i++)
    {
        printf("\"%s\": %s\n", dictionary[i].word, dictionary[i].definition);
    }
}
