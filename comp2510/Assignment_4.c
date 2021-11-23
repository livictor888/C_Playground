#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MEMORY_ALLOCATION_ERROR_CODE 1
#define EMPTY_LIST_REMOVE_TAIL_ERROR_CODE 2
#define EMPTY_LIST_POP_ERROR_CODE 3

struct Node {
    bool isProcess;
    char *pid;
    int base;
    int limit;
    struct Node *next;
};

typedef struct Node* Link;

Link createNode(bool isProcess, char *pid, int base, int limit) {
    Link link = (Link) malloc(sizeof(struct Node));
    if (link == NULL) {
        perror("Failed to allocate memory.");
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }
    link->isProcess = isProcess;
    strcpy(link->pid, pid);
    link->base = base;
    link->limit = limit;
    link->next = NULL;
    return link;
}

Link createNodeWithNextNode(bool isProcess, char *pid, int base, int limit, Link next) {
    Link link = createNode(isProcess, pid, base, limit);
    link->next = next;
    return link;
}

void printLink(Link head, int index) {
    if (head == NULL) {
        printf("\n");
        return;
    }
    if (head->isProcess) {
        printf("Node %d: %s, base = %d, limit = %d\n", index, head->pid, head->base, head->limit);
        printLink(head->next, index + 1);
    } else {
        printf("Node %d: H (Hole), base = %d, limit = %d\n", index, head->base, head->limit);
        printLink(head->next, index + 1);
    }
}
void printMemory(Link head) {
    printLink(head, 1);
}

int main() {
    Link head = NULL;
    head = createNode(true, "hello", 0, 5);

    return 0;
}