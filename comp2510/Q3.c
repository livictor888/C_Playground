#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEMORY_ALLOCATION_ERROR 1

struct NameStruct {
    char *name;
};

struct NameStruct *createNameStruct(char *message) {
    struct NameStruct *newNode = (struct NameStruct*) malloc(sizeof(struct NameStruct));
    if (!newNode) {
        perror("Out of memory.");
        exit(MEMORY_ALLOCATION_ERROR);
    }
    //(*newNode).name = message;
    // newNode->name = message;                 // wrong
    newNode->name=strdup(message);              // use strdup to allocate and copy the message
    if (!newNode->name) {                       // also check if the name is null after
        perror("Out of memory.");
        exit(MEMORY_ALLOCATION_ERROR);
    }
    return newNode;
}

void destroy(struct NameStruct *node) {
    free(node->name);
    free(node);
}

int main() {
    char message[] = "this is an easy question.";
    struct NameStruct *element = createNameStruct(message);
    if (element) {
        printf("Name: %s\n", element->name);
        destroy(element);
    }
    return 0;
}