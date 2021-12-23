#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int getTheMaximum(void *firstNumber, void *secondNumber, void *thirdNumber, bool (*compare)(void *, void *)) {
    if (compare(firstNumber, secondNumber) && compare(firstNumber, thirdNumber)) {
        return 1;
    } else if (compare(secondNumber, firstNumber) && compare(secondNumber, thirdNumber)) {
        return 2;
    } else {
        return 3;
    }
}

bool integerCompare(void *firstNumber, void *secondNumber) {
    return *((int *) firstNumber) > *((int *) secondNumber);
}

bool stringCompare(void *firstString, void *secondString) {
    return strcmp((char *) firstString, (char *) secondString) > 0;
}


int main() {
    int firstNumber = 10;
    int secondNumber = 11;
    int thirdNumber = 12;

    int result = getTheMaximum(&firstNumber, &secondNumber, &thirdNumber, &integerCompare);
    printf("Largest number is number %d\n", result);

    char *firstString = "aeyed";
    char *secondString = "seyed";
    char *thirdString = "aeyed";

    result = getTheMaximum(&firstString, &secondString, &thirdString, &stringCompare);
    printf("Largest number is number %d\n", result);

    return 0;
}