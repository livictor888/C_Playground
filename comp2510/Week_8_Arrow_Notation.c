#include <stdio.h>
#include <stdlib.h>

struct string {
    int length;
    char *data;
};

void printString(struct string s) {
    printf("length: %d, data: %s\n", s.length, s.data);
}
int main() {
    struct string myName = {5, "Seyed"};
    struct string *pointerToString = &myName;
    printString(*pointerToString);
    (*pointerToString).data = "Awesome";
    (*pointerToString).length = 7;
    printString(*pointerToString);
    pointerToString->data = "The best";
    pointerToString->length = 8;
    printString(*pointerToString);
    return 0;
}
