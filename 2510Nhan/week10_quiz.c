#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEMORY_ALLOCATION_ERROR 1

struct NameStruct {
    char *name;
};

/*
 * 1) When we assign a name to newNode, the given parameter message is
 * pointer that point to the string in the stack. Where in the struct
 * attribute name is a pointer string, and it should be allocated a memory in the heap.
 * So using strdup(message) is a one of the correct way to fix it.
 * We already have destroy function which free the name.
 *
 * 2) strdup also has the possibility of return NULL, but regard to Seyed saying
 * for this scope of this course we can ignore this checking.
 */
struct NameStruct *createNameStruct(char *message) {
    struct NameStruct *newNode = (struct NameStruct *) malloc(sizeof(struct NameStruct));
    if (!newNode) {
        perror("Out of memory.");
        exit(MEMORY_ALLOCATION_ERROR);
    }
    newNode->name = strdup(message);
    return newNode;
}

void destroy(struct NameStruct *node) {
    free(node->name);
    free(node);
}

/*
 * 3) Unnecessary checking if element here because we already throw error if
 * we cannot allocate memory in function createNameStruct. Unless we want to check
 * if the name is not empty to print out, but in this case, I think it can output
 * an empty name.
 */
int main() {
    char message[] = "This is an easy question";
    struct NameStruct *element = createNameStruct(message);
    printf("Name : %s\n", element->name);
    destroy(element);
    return 0;
}
