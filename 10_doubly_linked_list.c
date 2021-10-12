/*
    <=== A Doubly Linked List (DLL) ===>
    A Doubly Linked List (DLL) contains an extra pointer, typically called previous pointer, together with next pointer and data which are there in singly linked list.

    <=== Advantages over singly linked list ===>
    1) A DLL can be traversed in both forward and backward direction. 
    2) The delete operation in DLL is more efficient if pointer to the node to be deleted is given. 
    3) We can quickly insert a new node before a given node. 
    In singly linked list, to delete a node, pointer to the previous node is needed. To get this previous node, sometimes the list is traversed. In DLL, we can get the previous node using previous pointer. 
    

    
    <=== Disadvantages over singly linked list ===>
    1) Every node of DLL Require extra space for an previous pointer. It is possible to implement DLL with single pointer though. 
    2) All operations require an extra pointer previous to be maintained. For example, in insertion, we need to modify previous pointers together with next pointers. For example in following functions for insertions at different positions, we need 1 or 2 extra steps to set previous pointer.
    
    -> Insertion 
    A node can be added in four ways 
    1) At the front of the DLL
    2) After a given node. 
    3) At the end of the DLL 
    4) Before a given node.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Represent a node of the doubly linked list

struct node
{
    int data;
    struct node *previous;
    struct node *next;
};

// Represent the head and tail of the doubly linked list
struct node *head, *tail = NULL;

void addNode(int data)
{
    // Create a new node
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;

    // If list is empty
    if (head == NULL)
    {
        // Both head and tail will point to newNode
        head = tail = newNode;
        // head's previous will point to NULL
        head->previous = NULL;
        // tail's next will point to NULL, as it is the last node of the list
        tail->next = NULL;
    }
    else
    {
        // newNode will be added after tail such that tail's next will point to newNode
        tail->next = newNode;
        // newNode's previous will point to tail
        newNode->previous = tail;
        // newNode will become new tail
        tail = newNode;
        // As it is last node, tail's next will point to NULL
        tail->next = NULL;
    }
}

// display() will print out the nodes of the list
void display()
{
    // Node current will point to head
    struct node *current = head;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("Nodes of doubly linked list: \n");
    while (current != NULL)
    {
        //Prints each node by incrementing pointer.
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}


int main()
{
    int n, element;

    printf("Enter the number of nodes you want in your linked list: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter the elemnet at node %d: ", i);
        scanf("%d", &element);
        addNode(element);
    }

    display();

    return 0;
}