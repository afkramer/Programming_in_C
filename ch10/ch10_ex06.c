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

void insert_entry(struct entry *to_ins, struct entry *before);
void remove_entry(struct entry *to_rem);
void print_entries(struct entry head);

int main(void)
{
    struct entry head, node1, node2, node3, node4, new_node;

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

    new_node.prev = (struct entry *) 0;
    new_node.value = 350;
    new_node.next = (struct entry *) 0;

    print_entries(head);

    printf("Removing node2\n");;
    remove_entry(&node2);

    printf("Inserting a new node after node3\n");
    insert_entry(&new_node, &node3);

    print_entries(head);

    return 0;
}

void insert_entry(struct entry *to_ins, struct entry *before)
{
    // update new entry's prev and next data
    to_ins->prev = before;
    to_ins->next = before->next;
    // update the entry before to now point to the new entry
    before->next = to_ins;
}

void remove_entry(struct entry *to_rem)
{
    // using data stored in prev and next, change the pointers in entries before and after
    to_rem->prev->next = to_rem->next;
    to_rem->next->prev = to_rem->prev;
}

void print_entries(struct entry head)
{
    while (head.next != (struct entry *) 0)
    {
        printf("%i\n", head.next->value);
        head.next = head.next->next;
    }
}
