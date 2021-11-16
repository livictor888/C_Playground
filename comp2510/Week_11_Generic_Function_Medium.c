#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// return the largest of 3 generic inputs
// elements can be string, char, int, double..
// have separate functions for string, char, numbers and call them by function pointers
// use the function pointers as a parameter
int returnLargest(void *first, void *second, void *third, bool (*compare)(void *, void *)) {
    if (compare(first, second) > 0 && compare(first, third) > 0) {
        return 1;
    } else if (compare(second, first) > 0 &&  compare(second, third) > 0) {
        return 2;
    } else {
        return 3;
    }

}

bool compareInteger(void *first, void *second) {
    return *((int *) first) > *((int *) second);
}

bool compareString(void *first, void * second) {
    return strcmp((char *) first, (char *) second) > 0;
}

int main() {
    int first = 0;
    int second = 1;
    int third = 3;
    int result = returnLargest(&first, &second, &third, &compareInteger);
    printf("The largest number is: %d\n", result);

    char *firstString = "hello";
    char *secondString = "Hello";
    char *thirdString = "HELLO";
    result = returnLargest(firstString, secondString, thirdString, &compareString);
    printf("The largest string is: %d\n", result);

    return 0;
}