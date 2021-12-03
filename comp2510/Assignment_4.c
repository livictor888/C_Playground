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

typedef struct Node* Link;

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
    printLink(head, 1);
}

void mergeFreeBlocks(Link *head) {
    /*
     * traverse through the linked list
     * if you encounter a hole and then the link is also a hole,
     * delete the current hole
     */
    Link current = *head;
    Link lookAhead = (*head)->next;
    while (current != NULL && lookAhead != NULL) {
        if (current->isHole && lookAhead->isHole) {
            current->limit += lookAhead->limit;
            current->next = lookAhead->next;
            free(lookAhead);                 // if I merge, move the stats of the lookahead into the current,
            // do I need to free the node afterwards?
            lookAhead = current->next;
            //Link lookahead = current->next;
        } else {
            current = lookAhead;
            lookAhead = current->next;
        }
    }
}

Link *compaction(Link *head) {
    mergeFreeBlocks(head);
    Link current = *head;
    int limitCounter = 0;
    if (!((*head)->isHole)) {
        Link returnHead = createNode((*head)->isHole, (*head)->pid, (*head)->base, (*head)->limit);
    }
    Link resultHead = NULL;
    Link lookAhead = (*head)->next;
    while (current != NULL) {
        if (current->isHole) {
            limitCounter+= current->limit;
        } else {

            current = current->next;
        }
    }
    *head = resultHead;
    return *head;
}

int main() {
    Link head = NULL;
//    head = createNode(true, 2, 0, 5);
//    push(&head, false, 0, 11, 4);
//    push(&head, false, 0, 7, 4);
//    push(&head, true, 1, 6, 1);

//    printf("\ntwo hole test\n");
//    head = NULL;
//    push(&head, true, 0, 10, 12);
//    push(&head, true, 0, 0, 10);
//    printMemory(head);
//    printf("\n");
//    compaction(&head);
//    printMemory(head);

//    printMemory(head);
//    mergeFreeBlocks(head);
//    printMemory(head);

    printf("\nlist starting with hole test\n");
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
    printMemory(head);
    printf("\n");
    compaction(&head);
    printMemory(head);

    printf("\nlist starting with process and ending in Hole\n");
    printf("--------------------------------\n");
    Link testNode = createNodeWithNextNode(true, 0, 26, 6, NULL);
    Link testNode2 = createNodeWithNextNode(false, 3, 16, 10, testNode);
    Link testNode3 = createNodeWithNextNode(true, 0, 7, 9, testNode2);
    Link testNode4 = createNodeWithNextNode(false, 2, 6, 1, testNode3);
    Link testHead = createNodeWithNextNode(false, 1, 0, 6, testNode4);

    printMemory(testHead);
    printf("\n");
    compaction(&testHead);
    printMemory(testHead);
    printf("--------------------------------\n");

    printf("\nlist starting with hole test\n");
    printf("----------------------------------\n");
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
    printMemory(head);
    printf("\n");
    mergeFreeBlocks(&head);
    printMemory(head);
    printf("----------------------------------\n");
    return 0;
}