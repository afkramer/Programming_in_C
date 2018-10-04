// Ch 10, exercise 5 in "Programming in C" by Stephen G. Kochan, 4th ed.
// Create a doubly linked list
// By: boglinballet, Oct. 4, 2018

#include <stdio.h>

struct entry
{
    struct entry *prev;
    int value;
    struct entry *next;
};

void print_entries(struct entry head);

int main(void)
{
    struct entry head, node1, node2, node3, node4;

    head.prev = (struct entry *) 0;
    head.next = &node1;

    node1.prev = &head;
    node1.value = 100;
    node1.next = &node2;

    node2.prev = &node1;
    node2.value = 200;
    node2.next = &node3;

    node3.prev = &node2;
    node3.value = 300;
    node3.next = &node4;

    node4.prev = &node3;
    node4.value = 400;
    node4.next = (struct entry *) 0;

    print_entries(head);

    return 0;
}

void print_entries(struct entry head)
{
    while (head.next != (struct entry *) 0)
    {
        printf("%i\n", head.next->value);
        head.next = head.next->next;
    }
}
