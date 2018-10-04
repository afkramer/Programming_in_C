// Ch 10, exercise 3 from "Programming in C" by Stephen G. Kochan, 4th ed
// Update the insert_entry function so that it is possible to insert node at the beginning
// By: boglinballet, Oct. 4, 2018

#include <stdio.h>

struct entry
{
    int value;
    struct entry *next;
};

void insert_entry(struct entry *insert, struct entry *before);
void print_nodes(struct entry head);

int main(void)
{
    struct entry head, node1, node2, node3, node4, node_new;

    // create a beginning node that only contains a pointer to the next node
    head.next = &node1;

    node1.value = 10;
    node1.next = &node2;

    node2.value = 20;
    node2.next = &node3;

    node3.value = 30;
    node3.next = &node4;

    node4.value = 40;
    node4.next = (struct entry *) 0;

    node_new.value = 5;
    node_new.next = (struct entry *) 0;

    // print through the nodes to check that set-up is correct
    print_nodes(head);

    printf("Inserting new node.\n");

    // insert the node after node2
    insert_entry(&node_new, &head);

    // print through the nodes to check that the function worked
    print_nodes(head);

    return 0;
}

void insert_entry(struct entry *insert, struct entry *before)
{
    insert->next = before->next;
    before->next = insert;
}


void print_nodes(struct entry head)
{
    while (head.next != (struct entry *) 0)
    {
        printf("%i\n", head.next->value);
        head.next = head.next->next;
    }
}
