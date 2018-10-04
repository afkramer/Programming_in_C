// Ch 10, exercise 2 from "Programming in C" by Stephen G. Kochan, 4th ed
// Create a function to insert a new entry in a linked list
// By: boglinballet, Oct. 4, 2018

#include <stdio.h>

struct entry
{
    int value;
    struct entry *next;
};

void insert_entry(struct entry *insert, struct entry *before);
void insert_entry_2(struct entry *insert, struct entry *before);
void print_nodes(struct entry *pointer);

int main(void)
{
    struct entry node1, node2, node3, node4, node_new, node_new2;
    struct entry *list_pointer = &node1;

    node1.value = 10;
    node1.next = &node2;

    node2.value = 20;
    node2.next = &node3;

    node3.value = 30;
    node3.next = &node4;

    node4.value = 40;
    node4.next = (struct entry *) 0;

    node_new.value = 25;
    node_new.next = (struct entry *) 0;

    node_new2.value = 35;
    node_new2.next = (struct entry *) 0;

    // print through the nodes to check that set-up is correct
    print_nodes(list_pointer);

    printf("Inserting new node.\n");

    // insert the node after node2
    insert_entry(&node_new, &node2);

    // print through the nodes to check that the function worked
    print_nodes(list_pointer);

    printf("Inserting another new node.\n");

    //insert new node after node3
    insert_entry_2(&node_new2, &node3);

    //print the nodes to show that the second function syntax worked
    print_nodes(list_pointer);
}

void insert_entry(struct entry *insert, struct entry *before)
{
    (*insert).next = (*before).next;
    (*before).next = insert;
}

// using special pointer syntax
void insert_entry_2(struct entry *insert, struct entry *before)
{
    insert->next = before->next;
    before->next = insert;
}


void print_nodes(struct entry *pointer)
{
    while (pointer != (struct entry *) 0)
    {
        printf("%i\n", (*pointer).value);
        pointer = (*pointer).next;
    }
}
