#include <stdio.h>
#include <stdlib.h>

#define MEMORY_ALLOCATION_ERROR_CODE 1
#define EMPTY_LIST_REMOVE_TAIL_ERROR_CODE 2
#define EMPTY_LIST_POP_ERROR_CODE 3

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node* Link;

void printLinkedList(Link head) {
    if (!head) {
        printf("\n");
        return;
    }

    printf("%d", head->data);
    if (head->next) {
        printf("->");
    }

    printLinkedList(head->next);
}

Link createNode(int data) {
    Link link = (Link) malloc(sizeof(struct Node));
    if (link == NULL) {
        perror("Memory issues again?!");
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }

    link->data = data;
    link->next = NULL;
    return link;
}

Link createNodeWithNextNode(int data, Link next) {
    Link link = createNode(data);
    link->next = next;
    return link;
}

int getLinkedListLength(Link head) {
    int length = 0;
    Link currentNode = head;
    while (currentNode) {
        currentNode = currentNode->next;
        length++;
    }
    return length;
}

int getLinkedListLengthRecursive(Link head) {
    if (!head) {
        return 0;
    }

    return 1 + getLinkedListLengthRecursive(head->next);
}

void push(Link *head, int data) {
    Link newHead = createNodeWithNextNode(data, *head);
    //4->20->10
    //5->4->20->10
    *head = newHead;
}

Link getTail(Link head) {
    if (!head) {
        return NULL;
    }

    if (!head->next) {
        return head;
    }

    return getTail(head->next);
}

void addLast(Link *head, int data) {
    Link newTail = createNode(data);
    if (!*head) {
        *head = newTail;
        return;
    }
    Link currentTail = getTail(*head);
    currentTail->next = newTail;
}

int removeTail(Link *head) {
    if (!*head) {
        perror("Empty list is passed to removeTail function.\n");
        exit(EMPTY_LIST_REMOVE_TAIL_ERROR_CODE);
    }

    Link currentNode = *head;
    if (!currentNode->next) {
        *head = NULL;
        int data = currentNode->data;
        free(currentNode);
        return data;
    }

    while (currentNode->next->next) {
        currentNode = currentNode->next;
    }

    Link oldTail = currentNode->next;
    int oldTailData = oldTail->data;
    free(oldTail);
    currentNode->next = NULL;
    return oldTailData;
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

void addElementAfterPosition(Link head, int data, int position) {
/* Left as an exercise */
}

int deleteNodeAtPosition(Link *head, int position) {
/* Left as an exercise */
    return 0;
}

int main() {
    Link head = NULL;
    addLast(&head, 5);
    addLast(&head, 4);
    addLast(&head, 20);
    addLast(&head, 10);
    addLast(&head, 89);
    printLinkedList(head);
    // 5 -> 4 -> 20 -> 10 -> 89 -> NULL
    int tailData = removeTail(&head);
    printLinkedList(head);
    printf("Old tail's data = %d\n", tailData);
    // 5 -> 4 -> 20 -> 10 -> NULL
    int headData = pop(&head);
    printLinkedList(head);
    printf("Old head's data = %d\n", headData);
    return 0;
}