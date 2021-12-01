#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node {
    void *data;
    struct Node *left;
    struct Node *right;
};

typedef struct Node* TreeNode;

TreeNode createTreeNode(void *data) {
    TreeNode newNode = (TreeNode) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        perror("Memory issues.");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreeNode insert(TreeNode root, void *data, bool (*compareFunction)(void *, void *)) {
    if (!root) {
        return createTreeNode(data);
    }
    if (!compareFunction(data, root->data)) {
        root->left = insert(root->left, data, compareFunction);
    } else {
        root->right = insert(root->right, data, compareFunction);
    }
    return root;
}

void printInOrder(TreeNode root, void (*printFunction)(void *)) {
    if (!root) {
        return;
    }
    printInOrder(root->left, printFunction);
    printFunction(root->data);
    printInOrder(root->right, printFunction);
}

bool compareDouble (void* data1, void* data2) {
    double first = *(double *)data1;
    double second = *(double *)data2;
    return (first >= second);
}

void printDouble(void *data) {
    printf(" %.2lf", *(double *)data);
}

bool compareString(void* first, void* second) {
    return strcmp(*(char**) first, *(char**) second) > 0;
}

void printString(void *data) {
    printf("%s\n", *(char **) data);
}

void sort(void *array, size_t size, int sizeOfDataType,
          bool (*compareFunctionPointer)(void *, void *), void (*printFunctionPointer)(void *)) {
    TreeNode root = NULL;
    for (int i = 0; i < size; i++) {
        root = insert(root, (array + (i * sizeOfDataType)), compareFunctionPointer);
    }
    printInOrder(root, printFunctionPointer);
}

int main() {
    printf("sorting an array of doubles:\n");
    double doubleInputArray[5] = {9.0, 2.1, 6.6, 4.4, 5.7};
    sort(doubleInputArray, 5, sizeof(double), &compareDouble, &printDouble);

    printf("\n----------------------------\n");

    printf("sorting an array of strings:\n");
    char* stringInputArray[3] = {"hello", "world", "victor"};
    sort(stringInputArray, 3, sizeof(char*), &compareString, &printString);
    return 0;
}