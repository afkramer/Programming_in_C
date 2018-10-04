// Ch 10 exercise 4 from "Programming in C" by Stephen G. Kochan, 4th ed.
// Create a function to remove an entry from a linked list
// By: boglinballet, Oct 4, 2018

#include <stdio.h>

struct entry
{
    int value;
    struct entry *next;
};

void remove_entry(struct entry *before);
void print_entries(struct entry head);

int main(void)
{
    struct entry head, node1, node2, node3, node4;

    head.next = &node1;

    node1.value = 100;
    node1.next = &node2;

    node2.value = 200;
    node2.next = &node3;

    node3.value = 300;
    node3.next = &node4;

    node4.value = 400;
    node4.next = (struct entry *) 0;

    print_entries(head);

    printf("Deleting node3\n");
    remove_entry(&node2);

    print_entries(head);

    printf("Deleting node1\n");
    remove_entry(&head);

    print_entries(head);

    return 0;
}

// the old node still points to the next node but is no longer part of the list
void remove_entry(struct entry *before)
{
    before->next = (before->next)->next;
}

void print_entries(struct entry head)
{
    while (head.next != (struct entry *) 0)
    {
        printf("%i\n", head.next->value);
        head.next = head.next->next;
    }
}
