#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define ERROR_CODE_MEMORY_ALLOCATION 1

struct Node {
    void *data;
    struct Node *left;
    struct Node *right;
};

typedef struct Node* TreeNode;

void freeTreeNode(TreeNode head) {
    if (!head) {
        return;
    }

    freeTreeNode(head->left);
    freeTreeNode(head->right);
    free(head);
}

TreeNode createTreeNode(void* data) {
    TreeNode treeNode = (TreeNode) malloc(sizeof (struct Node));
    if (treeNode == NULL) {
        perror("Memory Issue!");
        exit(ERROR_CODE_MEMORY_ALLOCATION);
    }
    treeNode->data = data;
    treeNode->left = NULL;
    treeNode->right = NULL;
    return treeNode;
}

TreeNode insert(TreeNode root, void *data, bool compare(void *, void *)) {
    if (!root) {
        return createTreeNode(data);
    }

    if (compare(root->data, data)) {
        root->left = insert(root->left, data, compare);
    } else {
        root->right = insert(root->right, data, compare);
    }

    return root;
}

void *getElementAtIndex(void *elements, size_t sizeOfEachElement, int index) {
    return (char *)elements + index * sizeOfEachElement;
}

void printInOrder(TreeNode root, void printFunction(void *)) {
    if (root) {
        printInOrder(root->left, printFunction);
        printFunction(root->data);
        printInOrder(root->right, printFunction);
    }
}

TreeNode createBTS(void *elements, size_t length, size_t sizeOfEachElement, bool compare(void *, void *)) {
    TreeNode head = NULL;
    for (int index = 0; index < length; index++) {
        void *element = getElementAtIndex(elements, sizeOfEachElement, index);
        head = insert(head, element, compare);
    }
    return head;
}

void sortAndPrintElements(void *elements, size_t length, size_t sizeOfEachElement,
                          bool compare(void *, void *), void printFunction(void *)) {
    TreeNode root = createBTS(elements, length, sizeOfEachElement, compare);
    printInOrder(root, printFunction);
    printf("\n");
    freeTreeNode(root);
}

bool compareInteger(void *firstElement, void *secondElement) {
    int *firstInteger = (int *) firstElement;
    int *secondInteger = (int *) secondElement;
    return *firstInteger > *secondInteger;
}

void printBTSIntegerElement(void *element) {
    int *result = (int *) element;
    printf("%d ", *result);
}

bool compareString(void *firstElement, void *secondElement) {
    char *firstString = *(char **) firstElement;
    char *secondString = *(char **) secondElement;
    return strcmp(firstString, secondString) > 0;
}

void printBTSStringElement(void *element) {
    char *string = *(char **) element;
    printf("%s ", string);
}

bool compareDouble(void *firstElement, void *secondElement) {
    double *firstDouble = (double *) firstElement;
    double *secondDouble = (double *) secondElement;
    return *firstDouble > *secondDouble;
}

void printBTSDoubleElement(void *element) {
    double *result = (double *) element;
    printf("%.2f ", *result);
}

void runIntegerTestCase() {
    printf("\n--- Test case for Integer ---\n");
    int arrayOfInteger[] = {5, -1, 20, 10, 0, 7, -9};
    printf("Before sorting:\n");
    for (int i = 0; i < 7; i++) {
        printf("%d ", arrayOfInteger[i]);
    }
    printf("\nAfter sorting:\n");
    sortAndPrintElements(arrayOfInteger, 7, sizeof(int), compareInteger, printBTSIntegerElement);
}

void runStringTestCase() {
    printf("\n--- Test case for String ---\n");
    char* arrayOfString[] = {"Alex", "Katie", "Amex", "Mike", "Paul", "Bob", "Sean"};
    printf("Before sorting:\n");
    for (int i = 0; i < 7; i++) {
        printf("%s ", arrayOfString[i]);
    }
    printf("\nAfter sorting:\n");
    sortAndPrintElements(arrayOfString, 7, sizeof(char *), compareString, printBTSStringElement);
}

void runDoubleTestCase() {
    printf("\n--- Test case for Double ---\n");
    double arrayOfDouble[] = {2.5, -44.5, 0.5, 12.7, 10.2, -4.5, 8.15};
    printf("Before sorting:\n");
    for (int i = 0; i < 7; i++) {
        printf("%.2f ", arrayOfDouble[i]);
    }
    printf("\nAfter sorting:\n");
    sortAndPrintElements(arrayOfDouble, 7, sizeof(double), compareDouble, printBTSDoubleElement);
}

int main() {
    runIntegerTestCase();
    runStringTestCase();
    runDoubleTestCase();
    return 0;
}