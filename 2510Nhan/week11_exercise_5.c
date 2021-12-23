#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR_CODE_EMPTY_LIST 1
#define ERROR_CODE_CANNOT_FIND 2

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

Link findPreviousNode(Link head, Link target) {
    if (head->next == target || (!head->next && !target)) {
        return head;
    }
    if (!head->next) {
        perror("Cannot find the previous node!");
        exit(ERROR_CODE_CANNOT_FIND);
    }
    return findPreviousNode(head->next, target);
}

Link getPreviousNode(Link head, Link target) {
    if (!head) {
        perror("Empty List!");
        exit(ERROR_CODE_EMPTY_LIST);
    }
    if (head == target) {
        return NULL;
    }
    return findPreviousNode(head, target);
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

    Link prevNode = NULL;
    prevNode = getPreviousNode(head, head);
    printLinkedList(prevNode);
    prevNode = getPreviousNode(head, head->next);
    printLinkedList(prevNode);
    prevNode = getPreviousNode(head, head->next->next);
    printLinkedList(prevNode);
    prevNode = getPreviousNode(head, head->next->next->next->next->next);
    printLinkedList(prevNode);
    prevNode = getPreviousNode(head, head->next->next->next->next->next->next->next);
    printLinkedList(prevNode);
    prevNode = getPreviousNode(head, NULL);
    printLinkedList(prevNode);
    prevNode = getPreviousNode(head, createLink(10));
    printLinkedList(prevNode);

    freeLinkedList(head);

    return 0;
}