#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Case 1: Deleting the first element from the linked list
struct Node *deleteFirst(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// Case 2: Deleting the element at a given index from the linked list
struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;

    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);

    return head;
}

// Case 3: Deleting the last element
struct Node *deleteLastNode(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;

    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);

    return head;
}

// Case 4: Deleting the element with a given value from the linked list
struct Node *deleteAtKey(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;

    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }

    return head;
}

void traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory for node in the linked list in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->data = 17;
    second->next = third;

    // Link third and fourth nodes
    third->data = 41;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 66;
    fourth->next = NULL;

    int choice, index, value;
    printf("Choose from the list given below\n");
    printf("1). Deletion at begining\n");
    printf("2). Deletion at index\n");
    printf("3). Deletion at end\n");
    printf("4). Deletion of given value\n");
    printf("===> ");

    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("Linked list before deletion\n");
        traversal(head);
        head = deleteFirst(head);
        printf("Linked list after deletion\n");
        traversal(head);
    }

    else if (choice == 2)
    {
        printf("Linked list before deletion\n");
        traversal(head);
        printf("Enter the index at which you want to apply deletion: ");
        scanf("%d", &index);
        head = deleteAtIndex(head, index);
        printf("Linked list after deletion\n");
        traversal(head);
    }

    else if (choice == 3)
    {
        printf("Linked list before deletion\n");
        traversal(head);
        head = deleteLastNode(head);
        printf("Linked list after deletion\n");
        traversal(head);
    }

    else if (choice == 4)
    {
        printf("Linked list before deletion\n");
        traversal(head);
        printf("Enter the value which you want to apply deletion: ");
        scanf("%d", &value);
        head = deleteAtKey(head, value);
        printf("Linked list after deletion\n");
        traversal(head);
    }

    else
    {
        printf("Invalid choice");
    }

    

    return 0;
}

// Case 1: Deleting the first element from the linked list
    // head = deleteFirst(head);
    // printf("Linked list after deletion\n");
    // traversal(head);

    // Case 2: Deleting the element at a given index from the linked list
    // head = deleteAtIndex(head, 2);
    // printf("Linked list after deletion\n");
    // traversal(head);

    // Case 3: Deleting the last element
    // head = deleteLastNode(head);
    // printf("Linked list after deletion\n");
    // traversal(head);

    // Case 4: Deleting the element with a given value from the linked list
    // head = deleteAtKey(head, 66);
    // printf("Linked list after deletion\n");
    // traversal(head);