#include <stdio.h>
#include <stdlib.h>

#define MEMORY_ALLOCATION_ERROR_CODE 1
#define EMPTY_LIST_REMOVE_TAIL_ERROR_CODE 2
#define EMPTY_LIST_POP_ERROR_CODE 3

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node* Link;

void printLinkedList(Link head) {
    if (!head) {
        printf("\n");
        return;
    }

    printf("%d", head->data);
    if (head->next) {
        printf("->");
    }

    printLinkedList(head->next);
}

Link createNode(int data) {
    Link link = (Link) malloc(sizeof(struct Node));
    if (link == NULL) {
        perror("Memory issues again?!");
        exit(MEMORY_ALLOCATION_ERROR_CODE);
    }

    link->data = data;
    link->next = NULL;
    return link;
}

Link createNodeWithNextNode(int data, Link next) {
    Link link = createNode(data);
    link->next = next;
    return link;
}

int getLinkedListLengthRecursive(Link head) {
    if (!head) {
        return 0;
    }

    return 1 + getLinkedListLengthRecursive(head->next);
}

void push(Link *head, int data) {
    Link newHead = createNodeWithNextNode(data, *head);
    //4->20->10
    //5->4->20->10
    *head = newHead;
}

Link getTail(Link head) {
    if (!head) {
        return NULL;
    }

    if (!head->next) {
        return head;
    }

    return getTail(head->next);
}

void addLast(Link *head, int data) {
    Link newTail = createNode(data);
    if (!*head) {
        *head = newTail;
        return;
    }
    Link currentTail = getTail(*head);
    currentTail->next = newTail;
}

int removeTail(Link *head) {
    if (!*head) {
        perror("Empty list is passed to removeTail function.\n");
        exit(EMPTY_LIST_REMOVE_TAIL_ERROR_CODE);
    }

    Link currentNode = *head;
    if (!currentNode->next) {
        *head = NULL;
        int data = currentNode->data;
        free(currentNode);
        return data;
    }

    while (currentNode->next->next) {
        currentNode = currentNode->next;
    }

    Link oldTail = currentNode->next;
    int oldTailData = oldTail->data;
    free(oldTail);
    currentNode->next = NULL;
    return oldTailData;
}

int pop(Link *head) {
    if (!*head) {
        perror("Empty list is passed to pop function.\n");
        exit(EMPTY_LIST_POP_ERROR_CODE);
    }

    int data = (*head)->data;
    Link oldHead = *head;
    *head = (*head)->next;
    free(oldHead);
    return data;
}




/*
 * What does the mystery function do:
 *
 * The mystery function takes an input linked list, the length of the linked list,
 * and a substitute node value as parameters.
 *
 * If the size of the linked list is 0, the function will return 0.
 *
 * The function first stores the data of the head into the variable "data". If the data in the head is NULL,
 * it will store the "sub" value instead into "data".
 *
 * Next, the function will create a nextNode Link to store the next node in the input linked list. If the current
 * node is NULL, the nextNode will be assigned NULL.
 *
 * The function will now call addLast to add "data" as a new node into the "output" linked list.
 *
 * Now the function check if the current input node is NULL, if so, it will add 1 to the output.
 * Additionally, it will make a recursive call to itself, with the nextNode as the new head, the "output" linked list,
 * "length - 1", and the substitute integer as its parameters.
 *
 * Summary:
 * This function will return a size_t counting the number of nodes created with a substituted value.
 *
 * When the length is greater than the number of existing nodes in the linked lists, the function will create extra
 * nodes with the substitute values and add them to the output linked list, keeping track of how many "substituted"
 * nodes.
 * As a side effect, output concatenates the input linked list to the output linked list along with the new "substitute"
 * nodes.
 *
 * Rename to: size_t copyListAndAddSubNodes(Link input, Link *output, size_t length, int sub) {
 *
 * Problems:
 * None found
 *
 */
size_t mystery(Link input, Link *output, size_t length, int sub) {
    if (!length) {
        return 0;
    }

    int data = (input != NULL) ? input->data : sub;
    Link nextNode = (input != NULL) ? input->next : NULL;
    addLast(output, data);
    return (input != NULL) + mystery(nextNode, output, length - 1, sub);
}

int main() {
    Link head = NULL;
    addLast(&head, 0);
    addLast(&head, 4);
    addLast(&head, 20);
    addLast(&head, 15);


    Link output = NULL;
    addLast(&output, 5);
    addLast(&output, 6);
    addLast(&output, 9);
    addLast(&output, 2);

    size_t mysteryReturn = mystery(head, &output, 20, 9);
    printf("return value of mystery function is : %zu\n", mysteryReturn);

    return 0;
}