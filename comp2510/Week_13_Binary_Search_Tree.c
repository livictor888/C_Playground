#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

typedef struct Node* TreeNode;

TreeNode createTreeNode(int data) {
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

TreeNode createTreeNodeWithChildren(int data, TreeNode leftChild, TreeNode rightChild) {
    TreeNode newNode = createTreeNode(data);
    newNode->left = leftChild;
    newNode->right = rightChild;
    return newNode;
}

void printTreeNode(TreeNode node) { // 4 different possible states, no child, 1 child (left), 1 child (right), 2 children
    if (!node) {
        printf("NULL\n");
        return;
    }

    if (node->left && node->right) {
        printf("Node:%d, left = %d, right = %d\n",
               node->data, node->left->data, node->right->data);
        return;
    }

    if (node->left) {
        printf("Node:%d, left = %d, right = NULL\n",
               node->data, node->left->data);
        return;
    }

    if (node->right) {
        printf("Node:%d, left = NULL, right = %d\n",
               node->data, node->right->data);
        return;
    }

    printf("Node:%d, left = NULL, right = NULL\n", node->data);
}

void printTree(TreeNode root) {
    if (!root) {
        return;
    }
    printTreeNode(root);
    printTree(root->left);
    printTree(root->right);
}

int getNumberOfNodesInLongestPath(TreeNode root) {
    if (!root) {
        return 0;
    }
    int left = getNumberOfNodesInLongestPath(root->left);
    int right = getNumberOfNodesInLongestPath(root->right);
    int max = (left > right) ? left : right;
    return max + 1;
}

int getTreeHeight(TreeNode root) {
    if (!root) {
        perror("Root is NULL.");
        exit(2);
    }
    return getNumberOfNodesInLongestPath(root) - 1;
}

TreeNode findNodeWithData(TreeNode root, int targetData) {
    if (!root) {
        return NULL;
    }
    if (root->data == targetData) {
        return root;
    }
    if (root->data > targetData) {
        return findNodeWithData(root->left, targetData);
    }
    return findNodeWithData(root->right, targetData);
}

TreeNode insert(TreeNode root, int data) {
    if (!root) {
        return createTreeNode(data);
    }
    if (data <= root->data) {
      root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

void printInOrder(TreeNode root) {
    if (!root) {
        return;
    }
    printInOrder(root->left);
    printf(" %d", root->data);
    printInOrder(root->right);
}

void printPreOrder(TreeNode root) {
    if (!root) {
        return;
    }
    printf(" %d", root->data);
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void printPostOrder(TreeNode root) {
    if (!root) {
        return;
    }
    printPostOrder(root->left);
    printPostOrder(root->right);
    printf(" %d", root->data);
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

int main() {
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

    root = insert(root, 10);
    printTree(root);

    //printTree(root);
    int height = getTreeHeight(root);
    printf("Height = %d\n", height);

    printf("Finding a node: \n");
    TreeNode node = findNodeWithData(root, 5);
    printTreeNode(node);


    printf("--------------Creating a tree with only insert-----------------------\n");
/*
 *          4
 *      2       6
 *  1   3    5      7
 */
    TreeNode newTreeRoot = NULL;
    newTreeRoot = insert(newTreeRoot, 4);
    newTreeRoot = insert(newTreeRoot, 2);
    newTreeRoot = insert(newTreeRoot, 6);
    newTreeRoot = insert(newTreeRoot, 1);
    newTreeRoot = insert(newTreeRoot, 3);
    newTreeRoot = insert(newTreeRoot, 5);
    newTreeRoot = insert(newTreeRoot, 7);
    printTree(newTreeRoot);


    // in-order traversal: left, data, right
    printf("In order traversal: \n");
    printInOrder(newTreeRoot);
    printf("\n");
    // pre-order traversal: data, left right
    printf("Pre-order traversal: \n");
    printPreOrder(newTreeRoot);
    printf("\n");
    // post-order traversal: left right data
    printf("Post-order traversal: \n");
    printPostOrder(newTreeRoot);
    printf("\n");

    printf("------------------------------------\nDuplicated left nodes: \n");
    duplicateNodeToLeft(newTreeRoot);
    printTree(newTreeRoot);
    return 0;
}