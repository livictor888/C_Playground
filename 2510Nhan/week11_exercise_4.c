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

int getLinkedListSize(Link head) {
    if (!head) {
        return 0;
    }

    return 1 + getLinkedListSize(head->next);
}

void constructLinkedList(Link head, Link *newList, int start, int size) {
    if (start > 0) {
        return constructLinkedList(head->next, newList, start - 1, size);
    }
    if (size == 0) {
        return;
    }

    push(newList, head->data);
    constructLinkedList(head->next, &(*newList)->next, start, size - 1);
}

void split(Link head, Link *first, Link *second) {
    int originalSize = getLinkedListSize(head);
    int expectedFirstSize = (originalSize + 1) / 2;
    int expectedSecondSize = originalSize - expectedFirstSize;

    constructLinkedList(head, first, 0, expectedFirstSize);
    constructLinkedList(head, second, expectedFirstSize, expectedSecondSize);
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
//    push(&head, 1);
    printLinkedList(head);

    Link first = NULL;
    Link second = NULL;
    split(head, &first, &second);
    printLinkedList(first);
    printLinkedList(second);

    freeLinkedList(head);

    return 0;
}