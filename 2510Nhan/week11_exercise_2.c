#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    float data;
    struct Node *next;
};

typedef struct Node* Link;


Link createLink(float data) {
    Link newNode = (Link) malloc(sizeof (struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(Link *head, float data) {
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
    printf("%f->", head->data);
    printLinkedList(head->next);
}

void constructAlternateLinked(Link origin, Link *head) {
    if (!origin) {
        return;
    }

    *head = createLink(origin->data);
    if (!origin->next || !origin->next->next) {
        return;
    } else {
        constructAlternateLinked(origin->next->next, &(*head)->next);
    }
}

void alternateLists(Link origin, Link *firstLinkedList, Link *secondLinkedList) {
    constructAlternateLinked(origin, firstLinkedList);

    if (!origin->next) {
        *secondLinkedList = NULL;
    } else {
        constructAlternateLinked(origin->next, secondLinkedList);
    }
}

void alternateList(Link input, Link *firstHead, Link *secondHead) {
    if (!input) {
        *firstHead = NULL;
        *secondHead = NULL;
        return;
    }

    *firstHead = createLink(input->data);
    alternateList(input->next, secondHead, &(*firstHead)->next);
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
    push(&head, 3.9f);
    push(&head, -2.3f);
    push(&head, 5.0f);
    push(&head, -1.6f);
    push(&head, 8.9f);
    push(&head, 1.9f);
    push(&head, 5.4f);
    printLinkedList(head);

    Link firstLinkedList = NULL;
    Link secondLinkedList = NULL;
    alternateLists(head, &firstLinkedList, &secondLinkedList);
    printLinkedList(firstLinkedList);
    printLinkedList(secondLinkedList);


    freeLinkedList(head);
    freeLinkedList(firstLinkedList);
    freeLinkedList(secondLinkedList);

    return 0;
}