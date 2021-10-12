#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head->next;
    while(p->next != head){
        p = p->next;
    }
    // At this point p points to the last node of circlar LL
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    
    return head;
}

void circularTraversal(struct Node *head){
    struct Node *ptr = head;

    printf("Element: %d\n", ptr->data);
    ptr = ptr->next;

    do
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }while (ptr != head);
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

    // Last node pointing to the list at the head node
    fourth->data = 66;
    fourth->next = head;

    circularTraversal(head);
    head = insertAtFirst(head, 80);
    circularTraversal(head);
    return 0;
}