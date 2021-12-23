#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

typedef struct Node* TreeNode;

TreeNode createTreeNode(int data) {
    TreeNode treeNode = (TreeNode) malloc(sizeof (struct Node));
    if (treeNode == NULL) {
        perror("Memory Issue!");
        exit(1);
    }

    treeNode->data = data;
    treeNode->left = NULL;
    treeNode->right = NULL;
    return treeNode;
}

TreeNode createTreeNodeWithChildren(int data, TreeNode left, TreeNode right) {
    TreeNode treeNode = createTreeNode(data);
    treeNode->left = left;
    treeNode->right = right;
    return treeNode;
}

int getTreeHeight(TreeNode root) {
    if (!root) {
        return 0;
    }

    int leftHeight = getTreeHeight(root->left);
    int rightHeight = getTreeHeight(root->right);
    return leftHeight > rightHeight ? 1 + leftHeight : 1 + rightHeight;
}

TreeNode findNodeWithData(TreeNode root, int targetData) {
    if (!root) {
        return NULL;
    }

    if (root->data == targetData) {
        return root;
    }

    TreeNode leftResultNode = findNodeWithData(root->left, targetData);
    if (leftResultNode) {
        return leftResultNode;
    }

    return findNodeWithData(root->right, targetData);
}

void insertNodeIntoTree(TreeNode *root, int data) {
    if (!*root) {
        *root = createTreeNode(data);
        return;
    }

    if ((*root)->data > data) {
        insertNodeIntoTree(&(*root)->left, data);
    } else {
        insertNodeIntoTree(&(*root)->right, data);
    }
}

TreeNode insert(TreeNode root, int data) {
    if (!root) {
        return createTreeNode(data);
    }

    if (root->data >= data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }

    return root;
}

void preOrder(TreeNode root) {
    if (root) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(TreeNode root) {
    if (root) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void postOrder(TreeNode root) {
    if (root) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void printTreeNode(TreeNode node) {
    if (!node) {
        printf("NULL\n");
        return;
    }

    if (node->left && node->right) {
        printf("Node: %d, left = %d, right = %d\n",
               node->data, node->left->data, node->right->data);
        return;
    }

    if (node->left) {
        printf("Node: %d, left = %d, right = NULL\n",
               node->data, node->left->data);
        return;
    }

    if (node->right) {
        printf("Node: %d, left = NULL, right = %d\n",
               node->data, node->right->data);
        return;
    }

    printf("Node: %d, left = NULL, right = NULL\n", node->data);
}

void printTree(TreeNode root) {
    if (!root) {
        return;
    }

    printTreeNode(root);
    printTree(root->left);
    printTree(root->right);
}

int main() {
    TreeNode node1 = createTreeNode(1);
    TreeNode node4 = createTreeNode(4);
    TreeNode node6 = createTreeNode(6);
    TreeNode node9 = createTreeNode(9);
    TreeNode node3 = createTreeNodeWithChildren(3, node1, node4);
    TreeNode node8 = createTreeNodeWithChildren(8, node6, node9);
    TreeNode root = createTreeNodeWithChildren(5, node3, node8);
    printTree(root);

    printf("Height of the tree %d\n", getTreeHeight(root));

    TreeNode resultNode = findNodeWithData(root, 8);
    printTree(resultNode);

    printf("-----\n");
    insertNodeIntoTree(&root, 7);
    printTree(root);

    printf("-----\n");
    insertNodeIntoTree(&root, 15);
    printTree(root);

    printf("-----\n");
    TreeNode newNode = NULL;
    newNode = insert(newNode, 5);
    newNode = insert(newNode, 8);
    newNode = insert(newNode, 3);
    newNode = insert(newNode, 4);
    newNode = insert(newNode, 1);
    newNode = insert(newNode, 9);
    newNode = insert(newNode, 6);
    printTree(newNode);

    printf("-----\n");
    preOrder(newNode);
    printf("\n");
    inOrder(newNode);
    printf("\n");
    postOrder(newNode);
    printf("\n");
    return 0;
}