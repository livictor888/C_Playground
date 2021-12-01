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

TreeNode createTreeNodeWithChildren(void *data, TreeNode leftChild, TreeNode rightChild) {
    TreeNode newNode = createTreeNode(data);
    newNode->left = leftChild;
    newNode->right = rightChild;
    return newNode;
}

TreeNode insert(TreeNode root, void *data, bool (*compareFunction)(void *, void *)) {
    if (!root) {
        return createTreeNode(data);
    }
    if (data <= root->data) {
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
//    printf(" %d", root->data);
    printFunction(root->data);
    printInOrder(root->right, printFunction);
}

void printPreOrder(TreeNode root, void (*printFunction)(void *)) {
    if (!root) {
        return;
    }
//    printf(" %d", root->data);
    printFunction(root->data);
    printPreOrder(root->left, printFunction);
    printPreOrder(root->right, printFunction);
}

void printPostOrder(TreeNode root, void (*printFunction)(void *)) {
    if (!root) {
        return;
    }
    printPostOrder(root->left, printFunction);
    printPostOrder(root->right, printFunction);
    printFunction(root->data);
    //printf(" %d", root->data);
}

void duplicateNodeToLeft(TreeNode node) {
    if (!node) {
        return;
    }
    duplicateNodeToLeft(node->left);
    duplicateNodeToLeft(node->right);
    TreeNode oldLeft = node->left;
    node->left = createTreeNode(node->data);
    node->left->left = oldLeft;
}

void findMaxNodeInBinaryTreeRecursive(TreeNode node, TreeNode* currentMax) {
    if (!node) {
        return;
    }
    if (node->data > (*currentMax)->data) {
        *currentMax = node;
    }
    findMaxNodeInBinaryTreeRecursive(node->left, currentMax);
    findMaxNodeInBinaryTreeRecursive(node->right, currentMax);
}

TreeNode findMaxNodeInBinaryTree(TreeNode root) {
    findMaxNodeInBinaryTreeRecursive(root, &root);
    return root;
}

bool compareDouble (void* data1, void* data2) {
    double first = *(double *)data1;
    double second = *(double *)data2;
    return (first >= second);
}

void printDouble(void *data) {
    printf(" %.2lf", *(double *) data);
}

bool compareString(void* first, void* second) {
    return strcmp(*(char**) first, *(char**) second) > 0;
}

void printString(void *data) {
    printf("%s", *(char **) data);
}

void sort(void *array, size_t size, size_t sizeOfDataType,
          bool (*compareFunctionPointer)(void *, void *), bool (*printFunctionPointer)(void *, void *)) {

}

int main() {
    //declare an array
    //call sort
/*
 * Binary Search Tree
 *
 *              5
 *          3       8
 *      1    4      6   9
 *                          10
 */
    TreeNode node_1 = createTreeNode(1);
    TreeNode node_4 = createTreeNode(4);
    TreeNode node_6 = createTreeNode(6);
    TreeNode node_9 = createTreeNode(9);
    TreeNode node_3 = createTreeNodeWithChildren(3, node_1, node_4);
    TreeNode node_8 = createTreeNodeWithChildren(8, node_6, node_9);
    TreeNode root = createTreeNodeWithChildren(5, node_3, node_8);

    root = insert(root, 10, &compareDouble);
    printInOrder(root, printDouble);
    int input[5] = {1, 2, 3, 4, 5};


    return 0;
}