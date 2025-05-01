#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 200

// Politica LIFO (Last In First Out)
// POP(S) cancella l’elemento in cima alla pila e lo restituisce
// PUSH(S) aggiunge un elemento in cima alla pila
// S.peek è l’elemento in cima alla pila
// Se può contenere al massimo n elementi, si implementa come un array di dimensione n

// Array implementation

int A[MAX_SIZE];
int top = -1;

void a_push(int x){
    if (top == MAX_SIZE - 1)
        printf("Stack overflow\n");
    else 
        A[++top] = x;
}

int a_pop() {
    if (top == -1) {
        printf("No element to pop\n");
        return -1; 
    } else 
        return A[top--];    
}

int a_isEmpty() {
    return top == -1;
}

int a_peek() {
    if (top == -1) {
        printf("Stack is empty\n");
        return -1; 
    } else 
        return A[top];
}

// Linked list implementation
struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL; // Head is a pointer. 

void l_push(int x){
    struct Node *temp = malloc(sizeof(struct Node));
    temp -> data = x;
    temp -> next = head;
    head = temp;
    
}

int l_pop() {
    if (head == NULL) {
        printf("No element to pop\n");
        return -1; 
    } 

    struct Node *toBeDelNode = head;
    int toBeDelData = toBeDelNode -> data;
   
    head = head -> next;
    
    free(toBeDelNode);
    return(toBeDelData);
}

int l_isEmpty() {
    return head == NULL;
}

int l_peek() {
    if (head == NULL) {
        printf("Stack is empty\n");
        return -1; 
    } else 
        return head -> data;
}

int main(int argc, char **argv)
{   
    // Array implementation
    a_push(10);
    a_push(24);
    a_push(3);
    printf("Top element is %d\n", a_peek());
    a_pop();
    printf("Popped element is %d\n", a_pop());

    // Linked list implementation
    l_push(10);
    l_push(24);
    l_push(3);
    printf("Top element is %d\n", l_peek());
    l_pop();
    printf("Popped element is %d\n", l_pop());

    return 0;
}