#include "string.h"
#include "stdio.h"

void swap(int *firstNumber, int *secondNumber) {
    int temp = *firstNumber;
    *firstNumber = *secondNumber;
    *secondNumber = temp;
}

void reverseArray(int *array, int size) {
    if (size < 2) {
        return;
    }

    swap(array, array + size - 1);
    reverseArray(array + 1, size - 2);
}

void swapPointers(int **p1, int **p2) {
    int *temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void swapPointers2(int **p1, int **p2) {
    int temp = **p1;
    **p1 = **p2;
    **p2 = temp;
}

void swapExample2() {
    int firstNumber = 1;
    int secondNumber = 2;
    int *firstPointer = &firstNumber;
    int *secondPointer = &secondNumber;
    swapPointers(&firstPointer, &secondPointer);
    printf("*firstNumber = %d, *secondNumber = %d\n", firstNumber, secondNumber);
    printf("*firstPointer = %d, *secondPointer = %d\n", *firstPointer, *secondPointer);
}


void swapExample3() {
    int firstNumber = 1;
    int secondNumber = 2;
    int *firstPointer = &firstNumber;
    int *secondPointer = &secondNumber;
    swapPointers2(&firstPointer, &secondPointer);
    printf("firstNumber = %d, secondNumber = %d\n", firstNumber, secondNumber);
    printf("*firstPointer = %d, *secondPointer = %d\n", *firstPointer, *secondPointer);
}

int main() {
    int array[] = {1, 2, 3, 4, 5};
    reverseArray(array, 5);
    for (int i = 0; i < 5; i ++) {
        printf("%d\n", array[i]);
    }

    swapExample2();
    swapExample3();
    return 0;
}