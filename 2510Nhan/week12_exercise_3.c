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

TreeNode getTheMaximumAmongThreeNodes(TreeNode first, TreeNode second, TreeNode third) {
    if (first->data > second->data && first->data > third->data) {
        return first;
    } else if (second->data > first->data && second->data > third->data) {
        return second;
    } else {
        return third;
    }
}

TreeNode findMaxNodeInBinaryTree(TreeNode root) {
    if (!root) {
        return NULL;
    }

    TreeNode maxElementLeftNode = findMaxNodeInBinaryTree(root->left);
    TreeNode maxElementRightNode = findMaxNodeInBinaryTree(root->right);

    if (maxElementLeftNode && maxElementRightNode) {
        return getTheMaximumAmongThreeNodes(root, maxElementLeftNode, maxElementRightNode);
    } else if (maxElementLeftNode) {
        return (root->data > maxElementLeftNode->data) ? root : maxElementLeftNode;
    } else if (maxElementRightNode) {
        return (root->data > maxElementRightNode->data) ? root : maxElementRightNode;
    } else {
        return root;
    }
}


void duplicatedToTheLeft(TreeNode root) {
    if (!root) {
        return;
    }

    TreeNode originalLeft = root->left;
    TreeNode newNode = createTreeNode(root->data);
    newNode->left = root->left;
    root->left = newNode;

    duplicatedToTheLeft(originalLeft);
    duplicatedToTheLeft(root->right);
}

int main() {
    TreeNode node1 = createTreeNode(1);
    TreeNode node4 = createTreeNode(4);
    TreeNode node6 = createTreeNode(6);
    TreeNode node9 = createTreeNode(9);
    TreeNode node3 = createTreeNodeWithChildren(3, node1, node4);
    TreeNode node8 = createTreeNodeWithChildren(15, node6, node9);
    TreeNode root = createTreeNodeWithChildren(5, node3, node8);
    printTree(root);
    printf("------------------\n");

    TreeNode maxNode = findMaxNodeInBinaryTree(root);
    printTree(maxNode);
    printf("------------------\n");


    TreeNode node23 = createTreeNode(20);
    TreeNode node22 = createTreeNodeWithChildren(40, node23, NULL);
    TreeNode node21 = createTreeNodeWithChildren(30, NULL, node22);
    printTree(node21);
    printf("------------------\n");

    duplicatedToTheLeft(node21);
    printTree(node21);

    return 0;
}