#include <stdio.h>

struct Node {
    int data;
    struct Node *next;
};

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

int main() {
    // 4 -> 20 -> 10 -> NULL
    struct Node node3 = {10, NULL};
    struct Node node2 = {20, &node3};
    struct Node node1 = {4, &node2};

    printLinkedList(&node1);

    return 0;
}