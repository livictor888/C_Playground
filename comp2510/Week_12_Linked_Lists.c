#include <stdio.h>
#include <stdlib.h>
#define FAILED_TO_ALLOCATE_MEMORY_CODE 1

struct Node {
    int data;
    struct Node *next;
};

// replace "struct Node *" with "Link" everywhere
typedef struct Node * Link;

//void printLinkedList(struct Node *head) {
//    struct Node *currentNode = head;
//    while(currentNode !=  NULL) {
//        printf("%d", currentNode->data);
//        currentNode = currentNode->next;
//        if (currentNode != NULL) {
//            printf("->");
//        }
//    }
//    printf("\n");
//}

void printLinkedListRecursively(Link head) {
    if(!head) {         // empty linked list or reached the end
        printf("\n");
        return;
    }
    printf("%d", head->data);
    if(head->next) {   // if there is a next node
        printf("->");
    }
    printLinkedListRecursively(head->next);
}

Link createNode(int data) {
    Link link = malloc(sizeof(struct Node));
    if (!link) {
        perror("Failed to allocate memory");
        exit(FAILED_TO_ALLOCATE_MEMORY_CODE);
    }
    link->data = data;
    link->next = NULL;
    return link;
}

Link createNodeWithNext(int data, Link next) {
    Link link = createNode(data);
    link->next = next;
    return link;
}

int getLength(Link head) {
    int lengthCounter = 0;
    Link currentNode = head;
    while (currentNode != NULL) {
        currentNode = currentNode->next;
        lengthCounter++;
    }
    return lengthCounter;
}

int getLengthRecursively(Link head) {
    if (head == NULL) {
        return 0;
    }
    return 1 + getLengthRecursively(head->next);
}

void push(Link *head, int data) {                       //you must use a pointer to a pointer, recall swapping pointers
    Link newHead = createNodeWithNext(data, *head);
    *head = newHead;
}

int main() {
    // 4 -> 20 -> 10 -> NULL
    //struct Node node3 = {10, NULL};
    Link node3 = createNode(10);
    //struct Node node2 = {20, &node3};
    Link node2 = createNodeWithNext(20, node3);
    //struct Node node1 = {4, &node2};
    Link node1 = createNodeWithNext(4, node2);
    //printLinkedList(&node1);
    printLinkedListRecursively(node1);
    printf("Iterative: the length of the linked list is: %d\n", getLength(node1));
    printf("Recursive: the length of the linked list is: %d\n", getLengthRecursively(node1));

    printf("\n");

    printf("Adding a new head here with a value of 5 using the push function.\n");
    push(&node1, 5);
    printLinkedListRecursively(node1);
    printf("Recursive: the length of the linked list is: %d\n", getLengthRecursively(node1));

    return 0;
}