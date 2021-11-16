#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# define MEMORY_ALLOCATION_ERROR 1
struct NameStruct {
    char *name;
};

//This function creates a NameStruct. The function will allocate memory for the
//name struct and check if it is successful by checking that the newNode is not null.
//However, when trying to assign the parameter message to the struct's name variable,
//no memory is allocated. To fix this, we can use strdup to allocate the appropriate memory.
//strdup does a check within the function itself so in this case we do not have to check if it
//is null again.
struct NameStruct *createNameStruct(char *message) {
    struct NameStruct *newNode = (struct NameStruct*) malloc(sizeof(struct NameStruct));
    if (!newNode) {
        perror("Out of memory.");
        exit(MEMORY_ALLOCATION_ERROR);
    }
    newNode->name = strdup(message);                // use strdup(message) to allocate memory
//    newNode->name = malloc((strlen(message) + 1) * sizeof(char));
//    newNode->name =message;
//    if (!newNode->name) {
//        perror("Out of memory.");
//        exit(MEMORY_ALLOCATION_ERROR);
//    }
    return newNode;
}

void destroy(struct NameStruct *node) {
    free(node->name);
    free(node);
}

int main() {
    char message[] = "This is an easy question";
    struct NameStruct *element = createNameStruct(message);
    if (element) {
        printf("Name : %s\n", element->name);
        destroy(element);
    }
    return 0;
}
