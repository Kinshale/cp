#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", (*head).data);
        head = (*head).next;
    }

    printf("\n");
}

void reversePrint(struct Node *head)
{
    if (head->next != NULL)
        reversePrint(head->next);

    printf("%d\n", head->data);
}

/* Given a reference (pointer to pointer) to the head of a list
   and an int,  inserts a new node on the front of the list. */

void insertAtBeginning(struct Node **head_ref, int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    temp->data = data;
    temp->next = *head_ref;
    *head_ref = temp;
}

void insertAtEnd(struct Node **head_ref, int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    new_node->data = data;
    new_node->next = NULL;

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    // We cannot traverse with a pointer to pointer, we need a pointer to node;
    struct Node *last = *head_ref;

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    return;
}

void insertAtNth(struct Node **head_ref, int data, int n)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    new_node->data = data;
    new_node->next = NULL;

    if (n == 1)
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }

    struct Node *prevNode = *head_ref;

    for (int i = 1; i < n - 1; i++)
    {
        prevNode = prevNode->next;
    }

    new_node->next = prevNode->next;
    prevNode->next = new_node;

    return;
}

void deleteNth(struct Node **head_ref, int n)
{
    struct Node *prevNode = *head_ref;

    for (int i = 1; i < n - 1; i++)
    {
        prevNode = prevNode->next;
    }

    struct Node *toBeDelNode = prevNode->next;
    prevNode->next = (prevNode->next)->next;
    free(toBeDelNode);
}

void reverseList(struct Node **head_ref)
{
    struct Node *prevNode = NULL;
    struct Node *currentNode = *head_ref;
    struct Node *nextNode;

    while (currentNode != NULL)
    {
        nextNode = currentNode->next;
        currentNode->next = prevNode;

        prevNode = currentNode;
        currentNode = nextNode;
    }

    *head_ref = prevNode;
}

void freeList(struct Node **head_ref)
{
    struct Node *node = *head_ref;
    struct Node *temp;
    while (node != NULL)
    {
        temp = node->next;
        free(node);
        node = temp;
    }

    *head_ref = NULL; 
}

int main(int argc, char **argv)
{
    struct Node *listHead;
    listHead = NULL;

    for (int i = 0; i < 5; i++)
        insertAtEnd(&listHead, i + 1);

    printList(listHead);
    reverseList(&listHead);
    printList(listHead);
    freeList(&listHead);

    return 0;
}
