#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node *next;
};

typedef struct Node* Link;

bool convertLinkedListToNumber(Link head, int *number) {
    if (!head) {
        return true;
    }

    if (head->data > '9' || head->data < '0') {
        *number = 0;
        return false;
    }

    *number *= 10;
    *number += (head->data - '0');
    return convertLinkedListToNumber(head->next, number);
}

int main() {


    return 0;
}