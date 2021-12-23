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
//    Link newHead = createLink(data);
//    Link oldHead = *head;
//    newHead->next = oldHead;
//    *head = newHead;
    Link newHead = createLink(data);
    Link oldHead = *head;
    newHead->next = *head;
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

void filter(Link *head, bool (* isValid)(float)) {
    if (!*head) {
        return;
    }

    if (isValid((*head)->data)) {
        filter(&(*head)->next, isValid);
    } else {
        Link oldLink = *head;
        *head = (*head)->next;
        free(oldLink);
        filter(head, isValid);
    }
}


bool isGreaterThanAThreshold(float data) {
    return data > 3.9f;
}

bool isPositive(float data) {
    return data > 0;
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
    printLinkedList(head);

    filter(&head, isGreaterThanAThreshold);
    printLinkedList(head);
    freeLinkedList(head);

    head = NULL;
    push(&head, 3.9f);
    push(&head, -2.3f);
    push(&head, 5.0f);
    push(&head, -1.6f);
    push(&head, 8.9f);
    printLinkedList(head);

    filter(&head, isPositive);
    printLinkedList(head);
    freeLinkedList(head);
    return 0;
}