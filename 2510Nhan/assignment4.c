#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ERROR_CODE_CANNOT_ALLOCATE_MEMORY 1

#define TNRM  "\x1B[0m"
#define TBLK  "\x1B[30m"
#define BGBL  "\x1B[106m"
#define BGGR  "\x1B[42m"
#define BGWH  "\x1B[107m"
#define RESET  "\033[0m"

struct Node {
    int base;
    int limit;
    int pid;
    bool isAllocated;
    struct Node *next;
};

typedef struct Node *Link;

bool isAProcessNode(Link node) {
    return node && node->isAllocated;
}

Link createNode(int pid, int base, int limit, bool isAllocated) {
    Link node = (Link) malloc(sizeof(struct Node));
    if (!node) {
        perror("Cannot allocate memory address.");
        exit(ERROR_CODE_CANNOT_ALLOCATE_MEMORY);
    }

    node->pid = pid;
    node->base = base;
    node->limit = limit;
    node->isAllocated = isAllocated;
    node->next = NULL;
    return node;
}

Link createNodeWithNextNode(Link next, int pid, int base, int limit, bool isAllocated) {
    Link node = createNode(pid, base, limit, isAllocated);
    node->next = next;
    return node;
}

void push(Link *head, int pid, int base, int limit, bool isAllocated) {
    Link newHead = createNodeWithNextNode(*head, pid, base, limit, isAllocated);
    *head = newHead;
}

void performMergeHoles(Link head, int nextBase) {
    if (!head || !head->next) {
        return;
    }

    if (head->base != nextBase) {
        head->base = nextBase;
    }

    if (!isAProcessNode(head) && !isAProcessNode(head->next)) {
        head->limit = head->limit + head->next->limit;
        Link expectedNext = head->next->next;
        free(head->next);
        head->next = expectedNext;
        return performMergeHoles(head, head->base);
    }

    performMergeHoles(head->next, head->base + head->limit);
}

void mergeHoles(Link head) {
    if (!head || !head->next) {
        return;
    }
    performMergeHoles(head, head->base);
}

void performCompaction(Link *currentNode, int nextBase, int totalFreeLimit) {
    if (!(*currentNode)->next) {
        if (totalFreeLimit > 0) {
            (*currentNode)->next = createNode(0, nextBase, totalFreeLimit, false);
        }
        return;
    }

    if (!isAProcessNode((*currentNode)->next)) {
        int newTotalFreeLimit = totalFreeLimit + (*currentNode)->next->limit;
        Link oldNode = (*currentNode)->next;
        (*currentNode)->next = (*currentNode)->next->next;
        free(oldNode);
        performCompaction(currentNode, nextBase, newTotalFreeLimit);
    } else {
        (*currentNode)->next->base = nextBase;
        performCompaction(&(*currentNode)->next, (*currentNode)->next->base + (*currentNode)->next->limit,
                          totalFreeLimit);
    }
}

void compaction(Link *head) {
    mergeHoles(*head);
    if (!*head || !(*head)->next) {
        return;
    }

    if (isAProcessNode(*head)) {
        performCompaction(head, (*head)->base + (*head)->limit, 0);
    } else {
        Link oldNode = *head;
        int newTotalFreeLimit = (*head)->limit;
        *head = (*head)->next;
        (*head)->base = oldNode->base;
        free(oldNode);
        performCompaction(head, (*head)->base + (*head)->limit, newTotalFreeLimit);
    }
}

void printNode(Link head, int index) {
    if (!head) {
        return;
    }

    if (isAProcessNode(head)) {
        printf("Link %d: P%d, base = %d, limit = %d\n", index, head->pid, head->base, head->limit);
    } else {
        printf("Link %d: H (Hole), base = %d, limit = %d\n", index, head->base, head->limit);
    }
    printNode(head->next, index + 1);
}

void printMemory(Link head) {
    printNode(head, 1);
}

void printUI(Link head) {
    if (!head) {
        return;
    }

    if (isAProcessNode(head)) {
        printf("%s%s P%d %s %d |%s %d %s", TBLK, BGBL, head->pid, BGWH, head->base, BGWH, head->limit, RESET);
    } else {
        printf("%s%s H %s %d |%s %d %s", TBLK, BGGR, BGWH, head->base, BGWH, head->limit, RESET);
    }

    if (head->next) {
        printf("%s--->%s", TNRM, RESET);
        printUI(head->next);
    } else {
        printf("\x1b[K%s\n", RESET);
    }
}

void freeLinkedList(Link head) {
    if (!head) {
        return;
    }
    freeLinkedList(head->next);
    free(head);
}

void runMergeHolesTestCase(Link head) {
    printf("Before Merge\n");
    printMemory(head);
    printUI(head);
    printf("\nAfter Merge\n");
    mergeHoles(head);
    printMemory(head);
    printUI(head);

    if (head) {
        freeLinkedList(head);
    }
}

void runMergeHolesTestCases() {
    Link head = NULL;
    printf("\n--- mergeHoles TESTS BEGIN HERE ---\n");
    printf("1) Empty list test\n");
    head = NULL;
    runMergeHolesTestCase(head);

    printf("\n2) One process test\n");
    head = NULL;
    push(&head, 1, 0, 10, true);
    runMergeHolesTestCase(head);

    printf("\n3) Two processes test\n");
    head = NULL;
    push(&head, 2, 10, 12, true);
    push(&head, 1, 0, 10, true);
    runMergeHolesTestCase(head);

    printf("\n4) One hole test\n");
    head = NULL;
    push(&head, 0, 0, 10, false);
    runMergeHolesTestCase(head);

    printf("\n5) Two holes test\n");
    head = NULL;
    push(&head, 0, 10, 12, false);
    push(&head, 0, 0, 10, false);
    runMergeHolesTestCase(head);

    printf("\n6) List starting with hole test\n");
    head = NULL;
    push(&head, 0, 49, 4, false);
    push(&head, 0, 47, 2, false);
    push(&head, 5, 46, 1, true);
    push(&head, 4, 37, 9, true);
    push(&head, 0, 35, 2, false);
    push(&head, 0, 34, 1, false);
    push(&head, 0, 28, 6, false);
    push(&head, 3, 18, 10, true);
    push(&head, 0, 17, 1, false);
    push(&head, 2, 16, 1, true);
    push(&head, 1, 10, 6, true);
    push(&head, 0, 0, 10, false);
    runMergeHolesTestCase(head);

    printf("\n7) List starting with process test\n");
    head = NULL;
    push(&head, 0, 49, 4, false);
    push(&head, 0, 47, 2, false);
    push(&head, 6, 46, 1, true);
    push(&head, 5, 37, 9, true);
    push(&head, 0, 35, 2, false);
    push(&head, 0, 34, 1, false);
    push(&head, 0, 28, 6, false);
    push(&head, 4, 18, 10, true);
    push(&head, 0, 17, 1, false);
    push(&head, 3, 16, 1, true);
    push(&head, 2, 10, 6, true);
    push(&head, 1, 0, 10, true);
    runMergeHolesTestCase(head);
}

void runCompactionTestCase(Link head) {
    printf("Before Compact\n");
    printMemory(head);
    printUI(head);
    printf("\nAfter Compact\n");
    compaction(&head);
    printMemory(head);
    printUI(head);
    if (head) {
        freeLinkedList(head);
    }
}

void runCompactionTestCases() {
    Link head = NULL;
    printf("\n\n--- compaction TESTS BEGIN HERE ---\n");
    printf("1) Empty list test\n");
    head = NULL;
    runCompactionTestCase(head);

    printf("\n2) One process test\n");
    head = NULL;
    push(&head, 1, 0, 10, true);
    runCompactionTestCase(head);

    printf("\n3) Two processes test\n");
    head = NULL;
    push(&head, 2, 10, 12, true);
    push(&head, 1, 0, 10, true);
    runCompactionTestCase(head);

    printf("4) One hole test\n");
    head = NULL;
    push(&head, 0, 0, 10, false);
    runCompactionTestCase(head);

    printf("\n5) Two holes test\n");
    head = NULL;
    push(&head, 0, 10, 12, false);
    push(&head, 0, 0, 10, false);
    runCompactionTestCase(head);

    printf("\n6) List starting with hole test\n");
    head = NULL;
    push(&head, 0, 47, 2, false);
    push(&head, 5, 46, 1, true);
    push(&head, 4, 37, 9, true);
    push(&head, 0, 35, 2, false);
    push(&head, 0, 34, 1, false);
    push(&head, 0, 28, 6, false);
    push(&head, 3, 18, 10, true);
    push(&head, 0, 17, 1, false);
    push(&head, 2, 16, 1, true);
    push(&head, 1, 10, 6, true);
    push(&head, 0, 0, 10, false);
    runCompactionTestCase(head);

    printf("\n7) List starting with process test\n");
    head = NULL;
    push(&head, 0, 47, 2, false);
    push(&head, 6, 46, 1, true);
    push(&head, 5, 37, 9, true);
    push(&head, 0, 35, 2, false);
    push(&head, 0, 34, 1, false);
    push(&head, 0, 28, 6, false);
    push(&head, 4, 18, 10, true);
    push(&head, 0, 17, 1, false);
    push(&head, 3, 16, 1, true);
    push(&head, 2, 10, 6, true);
    push(&head, 1, 0, 10, true);
    runCompactionTestCase(head);
}

int main() {
    runMergeHolesTestCases();
    runCompactionTestCases();
    return 0;
}