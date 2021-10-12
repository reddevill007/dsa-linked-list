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

// Program for insertion at begining of DLL
void insertion_beginning()
{
    struct node *ptr;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));

    // If ptr is NULL then show overflow
    if (ptr == NULL)
    {
        printf("\nOVERFLOW....");
    }

    else
    {
        // Value of node to be inserted
        printf("\nEnter Item value: ");
        scanf("%d", &item);

        // If DLL is empty
        if (head == NULL)
        {
            // Both next and previous will NULL as DLL is empty
            ptr->next = NULL;
            ptr->previous = NULL;

            // Assigning value to data
            ptr->data = item;

            // head will be equal to ptr
            head = ptr;
        }

        else
        {
            // Assigning value to data
            ptr->data = item;

            // previous will point to NULL and next will point to head
            ptr->previous = NULL;
            ptr->next = head;

            // Pointing previous to new node
            head->previous = ptr;

            // head will be equal to ptr
            head = ptr;
        }
        printf("\nNode inserted\n");
    }
}

// Insertion at the end of the DLL
void insertion_last()
{
    // If ptr is NULL then show overflow
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));

    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }

    else
    {
        printf("\nEnter value: ");
        scanf("%d", &item);

        ptr->data = item;

        // If DLL is empty
        if (head == NULL)
        {
            // Both next and previous will NULL as DLL is empty
            ptr->next = NULL;
            ptr->previous = NULL;
            // head will be equal to ptr
            head = ptr;
        }

        else
        {
            // Making a temp variable which stores head
            temp = head;
            while (temp->next != NULL)
            {
                // temp will point to next untill it reaches NULL
                temp = temp->next;
            }

            // temp will be last element and will point to ptr which is inserted at end
            temp->next = ptr;

            // Assigning value
            ptr->previous = temp;

            // Last element point to NULL
            ptr->next = NULL;
        }
    }
    printf("\nnode inserted\n");
}

// Insertion after specific node
void insertion_specified()
{
    struct node *ptr, *temp;
    int item, loc, i;
    ptr = (struct node *)malloc(sizeof(struct node));

    if (ptr == NULL)
    {
        printf("\n OVERFLOW");
    }

    else
    {
        temp = head;

        printf("Enter the location: ");
        scanf("%d", &loc);

        for (i = 0; i < loc; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                printf("\n There are less than %d elements", loc);
                return;
            }
        }

        printf("Enter value: ");
        scanf("%d", &item);

        ptr->data = item;
        ptr->next = temp->next;
        ptr->previous = temp;
        temp->next = ptr;
        temp->next->previous = ptr;

        printf("\nnode inserted\n");
    }
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

    insertion_beginning();
    display();

    insertion_last();
    display();

    insertion_specified();
    display();

    return 0;
}