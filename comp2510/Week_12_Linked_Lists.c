#include <stdio.h>
#include <stdlib.h>
#define FAILED_TO_ALLOCATE_MEMORY_CODE 1

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node * Link;

void printLinkedList(struct Node *head) {
    struct Node *currentNode = head;
    while(currentNode !=  NULL) {
        printf("%d", currentNode->data);
        currentNode = currentNode->next;
        if (currentNode != NULL) {
            printf("->");
        }
    }
    printf("\n");
}

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
    Link link = malloc(sizeof(Link));
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

int main() {
    // 4 -> 20 -> 10 -> NULL
    //struct Node node3 = {10, NULL};
    Link node3 = createNode(10);
    //struct Node node2 = {20, &node3};
    Link node2 = createNodeWithNext(10, node3);
    //struct Node node1 = {4, &node2};
    Link node1 = createNodeWithNext(4, node2);
    //printLinkedList(&node1);
    printLinkedListRecursively(node1);
    return 0;
}