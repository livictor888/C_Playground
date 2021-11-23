#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define FAILED_TO_ALLOCATE_MEMORY_CODE 1
#define EMPTY_LIST_POP_ERROR_CODE 2

struct Node {
    float data;
    struct Node *next;
};

typedef struct Node *Link;

void printLinkedList(Link head) {
    if (!head) {         // empty linked list or reached the end
        printf("\n");
        return;
    }
    printf("%f", head->data);
    if (head->next) {   // if there is a next node
        printf("->");
    }
    printLinkedList(head->next);
}

Link createNode(float data) {
    Link link = malloc(sizeof(struct Node));
    if (!link) {
        perror("Failed to allocate memory");
        exit(FAILED_TO_ALLOCATE_MEMORY_CODE);
    }
    link->data = data;
    link->next = NULL;
    return link;
}

Link createNodeWithNext(float data, Link next) {
    Link link = createNode(data);
    link->next = next;
    return link;
}

int getLength(Link head) {
    int lengthCounter = 0;
    Link currentNode = head;
    while (currentNode != NULL) {
        currentNode = currentNode->next;
        lengthCounter++;
    }
    return lengthCounter;
}

int getLengthRecursively(Link head) {
    if (head == NULL) {
        return 0;
    }
    return 1 + getLengthRecursively(head->next);
}

void push(Link *head, float data) {                       //you must use a pointer to a pointer, recall swapping pointers
    Link newHead = createNodeWithNext(data, *head);
    *head = newHead;
}

Link getTailIterative(Link head) {
    if (!head) {
        return NULL;
    }
    Link currentNode = head;
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }
    return currentNode;
}

Link getTail(Link head) {
    if (!head) {                    // 0 (empty) case
        return NULL;
    }
    if (!head->next) {       // 1 (single) case
        return head;
    }
    return getTail(head->next);     // multiple nodes in the list case
}

void addLast(Link *head, float data) {
    Link newTail = createNode(data);
    if (*head == NULL) {
        *head = newTail;
        return;
    }
    Link currentTail = getTail(*head);
    currentTail->next = newTail;
}

void deleteNodeAtPosition(Link *head, int position) {
    if (position == 1) {
        *head == NULL;
    }

    if (position == getLength(*head)) {

    }
    int currentPosition = 1;
    Link nodeBeforeTheNodeToDelete = *head;
    while (currentPosition != position - 1) {
        nodeBeforeTheNodeToDelete = nodeBeforeTheNodeToDelete->next;
        currentPosition++;
    }
    nodeBeforeTheNodeToDelete->next = nodeBeforeTheNodeToDelete->next->next;
}


float pop(Link *head) {
    if (!*head) {
        perror("Empty list is passed to pop function.\n");
        exit(EMPTY_LIST_POP_ERROR_CODE);
    }

    float data = (*head)->data;
    Link oldHead = *head;
    *head = (*head)->next;
    free(oldHead);
    return data;
}

bool isGreaterThanThreshold(float data) {
    return (data > 3.4f);
}

// TODO iterative solution incomplete

//void filter(Link *head, bool (*isValid)(float data)) {
//    Link currentNode = *head;
//    int currentPosition = 1;
//    while (currentNode != NULL) {
//        if (!isValid(currentNode->data)) {
//            deleteNodeAtPosition(head, currentPosition);
//        }
//        currentNode = currentNode->next;
//        currentPosition++;
//    }
//}

// TODO In class exercise 1
void filter(Link *head, bool (*isValid)(float)) {
    if (!*head) {
        return;
    }

    if (!isValid((*head)->data)) {
        pop(head);
        filter(head, isValid);
        return;
    }

    filter(&(*head)->next, isValid);
}

// TODO In class exercise 2
void addElementToSortedLinkedList(Link *head, float data) {
    if (!*head) {
        Link newNode = createNode(data);
        *head = newNode;
        return;
    }
    if (data < (*head)->data) {
        // add here
        return;
    }
    if (data >= (*head)->data) {
        if (data < (*head)->next->data) {
            //add here
            return;
        }
        addElementToSortedLinkedList(&(*head)->next, data);
    }
}

// Seyed Solution
//void addElementToSortedLinkedList(Link *head, int data) {
//    if (*head == NULL || (*head)->data > data) {
//        push(head, data);
//        return;
//    }
//
//    addElementToSortedLinkedList(&(*head)->next, data);
//}

// TODO In class exercise 3
void constructLinkedList(Link head, Link *newList, int start, int size) {
    if (start > 0) {
        return constructLinkedList(head->next, newList, start - 1, size);
    }
    if (size == 0) {
        return;
    }

    push(newList, head->data);
    constructLinkedList(head->next, &(*newList)->next, start, size - 1);
}

Link split(Link head, Link *first, Link *second) {
    int originalSize = getLengthRecursively(head);
    int expectedFirstSize = (originalSize + 1) / 2;
    //int expectedFirstSize = originalSize % 2? (originalSize / 2) + 1 :originalSize / 2;
    int expectedSecondSize = originalSize - expectedFirstSize;

    constructLinkedList(head, first, 0, expectedFirstSize);
    constructLinkedList(head, second, expectedFirstSize, expectedSecondSize);
}

int main() {
    Link head = NULL;
    push(&head, 4.4f);
    push(&head, 6.9f);
    push(&head, 3.4f);
    push(&head, 1.4f);


    printLinkedList(head);
    //filter(&head, &isGreaterThanThreshold);

    Link first = NULL;
    Link second = NULL;

    split(head, NULL, NULL);
    printLinkedList(head);
    printLinkedList(first);
    printLinkedList(second);


    return 0;
}