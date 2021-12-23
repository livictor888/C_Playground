#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define EMPTY_LIST_POP_ERROR_CODE 1

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

int pop(Link *head) {
    if (!*head) {
        perror("Empty list is passed to pop function.\n");
        exit(EMPTY_LIST_POP_ERROR_CODE);
    }

    int data = (*head)->data;
    Link oldHead = *head;
    *head = (*head)->next;
    free(oldHead);
    return data;
}

void printLinkedList(Link head) {
    if (!head) {
        printf("NULL\n");
        return;
    }
    printf("%d->", head->data);
    printLinkedList(head->next);
}

void freeLinkedList(Link head) {
    if (!head) {
        return;
    }
    freeLinkedList(head->next);
    free(head);
}

void makeCopyList(Link originalHead, Link *copyHead) {
    if (!originalHead) {
        *copyHead = NULL;
        return;
    }
    push(copyHead, originalHead->data);
    makeCopyList(originalHead->next, &(*copyHead)->next);
}

Link copyList(Link originalHead) {
    Link newList = NULL;
    makeCopyList(originalHead, &newList);
    return newList;
}

void makeCopyListReverse(Link originalHead, Link *copyHead) {
    if (!originalHead) {
        return;
    }
    push(copyHead, originalHead->data);
    makeCopyListReverse(originalHead->next, copyHead);
}

Link copyListReverse(Link originalHead) {
    Link newList = NULL;
    makeCopyListReverse(originalHead, &newList);
    return newList;
}


void runTestCase(Link originalHead, Link (* copyMethod)(Link)) {
    printf("Original List:\n");
    printLinkedList(originalHead);

    Link newList = copyMethod(originalHead);

    printf("Copied List:\n");
    printLinkedList(newList);

    printf("\n");
    freeLinkedList(originalHead);
    freeLinkedList(newList);
}


void runTestCaseForCopyList() {
    printf("\n--- copyList test cases ---\n");
    Link head = NULL;

    printf("1) Empty List\n");
    head = NULL;
    runTestCase(head, copyList);

    printf("2) One node List\n");
    head = NULL;
    push(&head, 10);
    runTestCase(head, copyList);

    printf("3) Multiple nodes List\n");
    head = NULL;
    push(&head, 10);
    push(&head, 10);
    push(&head, 9);
    push(&head, 6);
    push(&head, 5);
    push(&head, 2);
    push(&head, 1);
    runTestCase(head, copyList);


    printf("3) Side Effects test\n");
    head = NULL;
    push(&head, 10);
    push(&head, 10);
    push(&head, 9);
    push(&head, 6);
    push(&head, 5);
    push(&head, 2);
    push(&head, 1);
    printf("Original List:\n");
    printLinkedList(head);
    Link newList = copyList(head);
    printf("Copied List:\n");
    printLinkedList(newList);
    printf("\n");
    printf("Removed first two nodes from original\n");
    pop(&head);
    pop(&head);
    printf("Original List after removing:\n");
    printLinkedList(head);
    printf("Copied List after removing:\n");
    printLinkedList(newList);
    freeLinkedList(head);
    freeLinkedList(newList);
}

void runTestCaseForCopyListReverse() {
    printf("\n--- copyListReverse test cases ---\n");
    Link head = NULL;

    printf("1) Empty List\n");
    head = NULL;
    runTestCase(head, copyListReverse);

    printf("2) One node List\n");
    head = NULL;
    push(&head, 10);
    runTestCase(head, copyListReverse);

    printf("3) Multiple nodes List\n");
    head = NULL;
    push(&head, 10);
    push(&head, 10);
    push(&head, 9);
    push(&head, 6);
    push(&head, 5);
    push(&head, 2);
    push(&head, 1);
    runTestCase(head, copyListReverse);


    printf("3) Side Effects test\n");
    head = NULL;
    push(&head, 10);
    push(&head, 10);
    push(&head, 9);
    push(&head, 6);
    push(&head, 5);
    push(&head, 2);
    push(&head, 1);
    printf("Original List:\n");
    printLinkedList(head);
    Link newList = copyListReverse(head);
    printf("Copied List:\n");
    printLinkedList(newList);
    printf("\n");
    printf("Removed first two nodes from original\n");
    pop(&head);
    pop(&head);
    printf("Original List after removing:\n");
    printLinkedList(head);
    printf("Copied List after removing:\n");
    printLinkedList(newList);
    freeLinkedList(head);
    freeLinkedList(newList);
}

int main() {
    runTestCaseForCopyList();
    runTestCaseForCopyListReverse();

    return 0;
}
