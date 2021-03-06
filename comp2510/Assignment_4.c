#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MEMORY_ALLOCATION_ERROR_CODE 1
#define EMPTY_LIST_REMOVE_TAIL_ERROR_CODE 2
#define EMPTY_LIST_POP_ERROR_CODE 3

struct Node {
    bool isHole;
    int pid;
    int base;
    int limit;
    struct Node *next;
};

typedef struct Node *Link;

Link createNode(bool isHole, int pid, int base, int limit) {
    Link link = (Link) malloc(sizeof(struct Node));
    if (link == NULL) {
        perror("Failed to allocate memory.");
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    link->isHole = isHole;
    link->pid = pid;
    link->base = base;
    link->limit = limit;
    link->next = NULL;
    return link;
}

Link createNodeWithNextNode(bool isHole, int pid, int base, int limit, Link next) {
    Link link = createNode(isHole, pid, base, limit);
    link->next = next;
    return link;
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

void addLast(Link *head, bool isHole, int pid, int base, int limit) {
    Link newTail = createNode(isHole, pid, base, limit);
    if (!*head) {
        *head = newTail;
        return;
    }
    Link currentTail = getTail(*head);
    currentTail->next = newTail;
}

void push(Link *head, bool isHole, int pid, int base, int limit) {
    Link newHead = createNodeWithNextNode(isHole, pid, base, limit, *head);
    //4->20->10
    //5->4->20->10
    *head = newHead;
}


void printLink(Link head, int index) {
    if (head == NULL) {
        printf("\n");
        return;
    }
    if (!(head->isHole)) {
        printf("Node %d: P%d, base = %d, limit = %d\n", index, head->pid, head->base, head->limit);
        printLink(head->next, index + 1);
    } else {
        printf("Node %d: H (Hole), base = %d, limit = %d\n", index, head->base, head->limit);
        printLink(head->next, index + 1);
    }
}

void printMemory(Link head) {
    if (head == NULL) {
        printf("Empty linked list.\n");
    }
    printLink(head, 1);
}

void freeLinkedList(Link *head) {
    Link temp = NULL;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void mergeFreeBlocks(Link *head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
    Link current = *head;
    Link lookAhead = (*head)->next;
    while (current != NULL && lookAhead != NULL) {
        if (current->isHole && lookAhead->isHole) {
            current->limit += lookAhead->limit;
            current->next = lookAhead->next;
            free(lookAhead);
            lookAhead = current->next;
        } else {
            current = lookAhead;
            lookAhead = current->next;
        }
    }
}

void compaction(Link *head) {
    if (*head == NULL) {
        return;
    }
    mergeFreeBlocks(head);
    if ((*head)->next == NULL) { // only 1 node
        return;
    }

    bool startsWithHole = (*head)->isHole;
    Link *newHead = NULL;
    Link previous = NULL;
    Link current = *head;
    int limitCounter = 0;
    int lastBase = 0;

    while (current != NULL) {                       // traverse from the beginning to the end of the linked list
        if (startsWithHole) {                      // in the case that the linked list starts with a hole.
            limitCounter += current->limit;
            (*head)->next->base = (*head)->base;
            lastBase = (*head)->base;
            startsWithHole = false;
            current = (*head)->next;
        } else if (!(current->isHole)) {
            if (previous == NULL) {     // the case where the first node is a process, executes one time only
                Link copyNode = createNodeWithNextNode(current->isHole, current->pid,
                                                       current->base, current->limit, NULL);
                lastBase = copyNode->base;
                newHead = &copyNode;     // make sure to change the head pointer to this one afterwards
                previous = *newHead;
                current = current->next;
            } else {                    // we are not on the first node anymore
                addLast(newHead, current->isHole,
                        current->pid, // can we use add last here to connect the node to the new linked list?
                        (previous->base) + (previous->limit), current->limit);
                lastBase = (previous->base) + (previous->limit);
                previous = previous->next; // old head previous
                current = current->next;
            }
        } else { // it's a hole, move on to the next node
            if (current->next == NULL) {
                current = current->next;

            } else {
                limitCounter += current->limit;
                current = current->next;
            }
        }
    }
    if (limitCounter > 0) {
        addLast(newHead, true, 0, lastBase + 1, limitCounter);
    }
    //printMemory(*head);
    freeLinkedList(head);
    *head = *newHead;
}


int main() {
    printf("COMPACTION TESTS BEGIN HERE\n");
    printf("Empty list test:\n");
    Link head = NULL;
    printf("Before compaction:\n");
    printMemory(head);
    printf("After compaction:\n");
    compaction(&head);
    printMemory(head);

    printf("\nOne process test:\n");
    head = NULL;
    push(&head, false, 1, 0, 10);
    printf("Before compaction:\n");
    printMemory(head);
    printf("After compaction:\n");
    compaction(&head);
    printMemory(head);

    printf("\nTwo process test:\n");
    head = NULL;
    push(&head, false, 2, 10, 12);
    push(&head, false, 1, 0, 10);
    printf("Before compaction:\n");
    printMemory(head);
    printf("After compaction:\n");
    compaction(&head);
    printMemory(head);

    printf("\nOne hole test:\n");
    head = NULL;
    push(&head, true, 0, 0, 10);
    printf("Before compaction:\n");
    printMemory(head);
    printf("After compaction:\n");
    compaction(&head);
    printMemory(head);

    printf("\nTwo hole test:\n");
    head = NULL;
    push(&head, true, 0, 10, 12);
    push(&head, true, 0, 0, 10);
    printf("Before compaction:\n");
    printMemory(head);
    printf("After compaction:\n");
    compaction(&head);
    printMemory(head);

    printf("\nList starting with hole test:\n");
    head = NULL;
    push(&head, true, 0, 47, 2);
    push(&head, false, 5, 46, 1);
    push(&head, false, 4, 37, 9);
    push(&head, true, 0, 35, 2);
    push(&head, true, 0, 34, 1);
    push(&head, true, 0, 28, 6);
    push(&head, false, 3, 18, 10);
    push(&head, true, 0, 17, 1);
    push(&head, false, 2, 16, 1);
    push(&head, false, 1, 10, 6);
    push(&head, true, 0, 0, 10);
    printf("Before compaction:\n");
    printMemory(head);
    printf("After compaction:\n");
    compaction(&head);
    printMemory(head);

    printf("\nList starting with process test:\n");
    head = NULL;
    push(&head, true, 0, 47, 2);
    push(&head, false, 6, 46, 1);
    push(&head, false, 5, 37, 9);
    push(&head, true, 0, 35, 2);
    push(&head, true, 0, 34, 1);
    push(&head, true, 0, 28, 6);
    push(&head, false, 4, 18, 10);
    push(&head, true, 0, 17, 1);
    push(&head, false, 3, 16, 1);
    push(&head, false, 2, 10, 6);
    push(&head, false, 1, 0, 10);
    printf("Before compaction:\n");
    printMemory(head);
    printf("After compaction:\n");
    compaction(&head);
    printMemory(head);

    printf("\nmergeFreeBlocks TESTS BEGIN HERE\n");
    printf("Empty list test:\n");
    head = NULL;
    printf("Before merge:\n");
    printMemory(head);
    printf("After merge:\n");
    mergeFreeBlocks(&head);
    printMemory(head);

    printf("\nOne process test:\n");
    head = NULL;
    push(&head, false, 1, 0, 10);
    printf("Before merge:\n");
    printMemory(head);
    printf("After merge:\n");
    mergeFreeBlocks(&head);
    printMemory(head);

    printf("\nTwo process test:\n");
    head = NULL;
    push(&head, false, 2, 10, 12);
    push(&head, false, 1, 0, 10);
    printf("Before merge:\n");
    printMemory(head);
    printf("After merge:\n");
    mergeFreeBlocks(&head);
    printMemory(head);

    printf("\nOne hole test:\n");
    head = NULL;
    push(&head, true, 0, 0, 10);
    printf("Before merge:\n");
    printMemory(head);
    printf("After merge:\n");
    mergeFreeBlocks(&head);
    printMemory(head);

    printf("\nTwo hole test:\n");
    head = NULL;
    push(&head, true, 0, 10, 12);
    push(&head, true, 0, 0, 10);
    printf("Before merge:\n");
    printMemory(head);
    printf("After merge:\n");
    mergeFreeBlocks(&head);
    printMemory(head);

    printf("\nList starting with hole test:\n");
    head = NULL;
    push(&head, true, 0, 49, 4);
    push(&head, true, 0, 47, 2);
    push(&head, false, 5, 46, 1);
    push(&head, false, 4, 37, 9);
    push(&head, true, 0, 35, 2);
    push(&head, true, 0, 34, 1);
    push(&head, true, 0, 28, 6);
    push(&head, false, 3, 18, 10);
    push(&head, true, 0, 17, 1);
    push(&head, false, 2, 16, 1);
    push(&head, false, 1, 10, 6);
    push(&head, true, 0, 0, 10);
    printf("Before merge:\n");
    printMemory(head);
    printf("After merge:\n");
    mergeFreeBlocks(&head);
    printMemory(head);

    printf("\nlist starting with process test\n");
    head = NULL;
    push(&head, true, 0, 49, 4);
    push(&head, true, 0, 47, 2);
    push(&head, false, 6, 46, 1);
    push(&head, false, 5, 37, 9);
    push(&head, true, 0, 35, 2);
    push(&head, true, 0, 34, 1);
    push(&head, true, 0, 28, 6);
    push(&head, false, 4, 18, 10);
    push(&head, true, 0, 17, 1);
    push(&head, false, 3, 16, 1);
    push(&head, false, 2, 10, 6);
    push(&head, false, 1, 0, 10);
    printf("Before merge:\n");
    printMemory(head);
    printf("After merge:\n");
    mergeFreeBlocks(&head);
    printMemory(head);

    freeLinkedList(&head);
    printf("\nIf freeLinkedList works, next print is empty:\n");
    printMemory(head);
    return 0;
}