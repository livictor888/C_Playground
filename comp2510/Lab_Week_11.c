#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SIZE_OF_ARRAY 5

bool integerCompare(void *first, void *second) {
    int *firstPointer = (int *) first;
    int *secondPointer = (int *) second;
    return (*firstPointer > *secondPointer);
}

bool charCompare(void *first, void *second) {
    char *firstPointer = (char *) first;
    char *secondPointer = (char *) second;
    return *firstPointer > *secondPointer;
}

void swap(void *first, void *second, size_t numberOfBytes) {
    char temp[numberOfBytes];
    memcpy(temp, first, numberOfBytes);
    memcpy(first, second, numberOfBytes);
    memcpy(second, temp, numberOfBytes);
}

void BubbleSort(void *array, size_t size, size_t elementSize, bool (*compare)(void *, void *)) {
    while (true) {
        bool swapped = false;
        for (int i = 1; i < size; i++) {
            if (compare((array + (i - 1) * elementSize), array + (i * elementSize))) {
                swapped = true;
                swap(array + (i - 1) * elementSize, array + (i * elementSize), elementSize);
            }
        }
        if (!swapped) {
            return;
        }
    }
}

int main() {
    int size = 5;
    int integerArray[SIZE_OF_ARRAY] = {10, 1, -2, 5, 7};
    size_t integerSize = sizeof(int);

    char charArray[SIZE_OF_ARRAY] = {'x', 'z', 'a', 'b', 'c'};
    size_t charSize = sizeof(char);

    BubbleSort(integerArray, size, integerSize, &integerCompare);
    BubbleSort(charArray, size, charSize, charCompare);
    printf("integer array sorted: \n");
    for (int i = 0; i < size; i++) {
        printf("A[%d] = %d\n", i, integerArray[i]);
    }
    printf("char array sorted: \n");
    for (int i = 0; i < size; i++) {
        printf("A[%d] = %c\n", i, charArray[i]);
    }
    return 0;
}
