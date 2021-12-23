#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node* Link;

Link createLink(int data) {
    Link newNode = (Link) malloc(sizeof (struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(Link *head, int data) {
    Link newHead = createLink(data);
    Link oldHead = *head;
    newHead->next = oldHead;
    *head = newHead;
}

void printLinkedList(Link head) {
    if (!head) {
        printf("NULL\n");
        return;
    }
    printf("%d->", head->data);
    printLinkedList(head->next);
}

void freeLinkedList(Link head) {
    if (!head) {
        return;
    }
    freeLinkedList(head->next);
    free(head);
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
    Link newTail = createLink(data);
    if (!*head) {
        *head = newTail;
        return;
    }
    Link currentTail = getTail(*head);
    currentTail->next = newTail;
}

/**
 * This function intake the original linked list as input type Link and one pointer to the output
 * linked list with type Link*. A variable name length to indicate the expected number of Node that will be added to
 * the output linked list and an integer sub as the "default" data to create a node if the given length is
 * larger than the size of the original linked list.
 *
 * @param input original linked list as type Link
 * @param output pointer of type Link* to the given linked list that concatenate to
 * @param length expected output of length
 * @param sub default value
 *
 * @return number of created nodes (extra nodes) with data equals to given parameter sub as default value.
 * @notes If input linked list has length of 4, then the output is equal to 0 if given length parameter <= 4.
 *           + In this case, output linked list will be added the nodes from input linked list (up to the given length)
 *        If input linked list has length of 4, and given length parameter > 4, then the output equals to
 *              given length parameter - the length of the original linked list
 *           + In this case, output linked list will be added the nodes from input linked list up until it reaches
 *              the end of the original list and the remaining number of nodes will be filled in with default
 *              "sub" value.
 *
 *  @notes 1) addLast will result in poor performance if we concatenate with a long linked list.
 *         2) repeatedly check (input != NULL) is not a good practice, we can create a bool variable for that checking
 *
 */
size_t concatLinkedListWithDefaultValue(Link input, Link *output, size_t length, int sub) {
    // Return 0 if no more nodes need to add
    if (!length) {
        return 0;
    }

    // Get the data of the current node of input if it is not NULL, or just take the default value
    int data = (input != NULL) ? input->data : sub;

    // Move to the next node if input still have it, otherwise just put NULL,
    // so next time it will intake default value
    Link nextNode = (input != NULL) ? input->next : NULL;

    // Add to the last of output linked list with the selected data
    addLast(output, data);

    // If the newly created node has default value, then plus 1 and recursively call the function with
    // length minus one. Otherwise, just recursively call the function with length minus one
    return (input == NULL) + concatLinkedListWithDefaultValue(nextNode, output, length - 1, sub);
}

int main() {
    Link head = NULL;
    push(&head, 10);
    push(&head, 10);
    push(&head, 9);
    push(&head, 6);
    push(&head, 5);
    push(&head, 2);
    printLinkedList(head);

    Link other = NULL;
    push(&other, 5);
    push(&other, 2);

    size_t result = concatLinkedListWithDefaultValue(head, &other, 0, -5);
    printf("%d\n", (int) result);
    printLinkedList(other);

    freeLinkedList(head);
    freeLinkedList(other);
    return 0;
}
