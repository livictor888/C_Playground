#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node* Link;


Link createLink(int data) {
    Link newNode = (Link) malloc(sizeof (struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(Link *head, int data) {
    Link newHead = createLink(data);
    Link oldHead = *head;
    newHead->next = oldHead;
    *head = newHead;
}

void printLinkedList(Link head) {
    if (!head) {
        printf("NULL\n");
        return;
    }
    printf("%d->", head->data);
    printLinkedList(head->next);
}

void insertToSortedLinkedList(Link *head, int data) {
    if (!(*head)->next) {
        (*head)->next = createLink(data);
        return;
    }

    if ((*head)->next->data > data) {
        Link tempNode = (*head)->next;
        (*head)->next = createLink(data);
        (*head)->next->next = tempNode;
        return;
    }

    insertToSortedLinkedList(&(*head)->next, data);
}

void addElementToSortedLinkedList(Link *head, int data) {
    if (!*head || (*head)->data > data) {
        push(head, data);
        return;
    }

    insertToSortedLinkedList(head, data);
}

void freeLinkedList(Link head) {
    if (!head) {
        return;
    }

    freeLinkedList(head->next);
    free(head);
}

int main() {
    Link head = NULL;
    push(&head, 10);
    push(&head, 10);
    push(&head, 9);
    push(&head, 6);
    push(&head, 5);
    push(&head, 2);
    push(&head, 1);
    printLinkedList(head);

    addElementToSortedLinkedList(&head, 7);
    printLinkedList(head);
    addElementToSortedLinkedList(&head, -5);
    printLinkedList(head);
    addElementToSortedLinkedList(&head, 15);
    printLinkedList(head);

    freeLinkedList(head);

    return 0;
}