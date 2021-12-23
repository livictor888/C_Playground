#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define SIZE_OF_ARRAY 5

void swap(void *firstElement, void *secondElement, size_t numberOfBytes) {
    char temp[numberOfBytes];
    memcpy(temp, firstElement, numberOfBytes);
    memcpy(firstElement, secondElement, numberOfBytes);
    memcpy(secondElement, temp, numberOfBytes);
}

void *findNthElement(void *array, int nth, size_t numberOfBytes) {
    return (char *)array + nth * numberOfBytes;
}

void bubbleSort(void *array, size_t size, size_t numberOfBytes, bool (* compare)(void *, void *)) {
    while (true) {
        bool swapped = false;
        for (int i = 1; i < size; i++) {
            void *firstElement = findNthElement(array, i - 1, numberOfBytes);
            void *secondElement = findNthElement(array, i, numberOfBytes);
            if (compare(firstElement, secondElement) > 0) {
                swapped = true;
                swap(firstElement, secondElement, numberOfBytes);
            }
        }
        if (!swapped) {
            return;
        }
    }
}

bool integerCompare(void *firstInteger, void *secondInteger) {
    int *firstNumber = (int *) firstInteger;
    int *secondNumber = (int *) secondInteger;
    return *firstNumber > *secondNumber;
}

bool stringCompare(void *firstString, void *secondString) {
    char *firstStringF = *(char **) firstString;
    char *secondStringF = *(char **) secondString;
    return strcmp(firstStringF, secondStringF) > 0;
}

bool doubleCompare(void *firstDouble, void *secondDouble) {
    double *firstDoubleF = (double *) firstDouble;
    double *secondDoubleF = (double *) secondDouble;
    return *firstDoubleF > *secondDoubleF;
}

int main() {
    int integerArray[SIZE_OF_ARRAY] = {10, 1, -2, 5, 7};
    bubbleSort(integerArray, SIZE_OF_ARRAY, sizeof(int), &integerCompare);
    for (int i = 0; i < SIZE_OF_ARRAY; i++) {
        printf("integerArray[%d] = %d\n", i, integerArray[i]);
    }

    char *stringArray[SIZE_OF_ARRAY] = {"Hello", "hello", "hEllo", "hELlo", "hELLo"};
    bubbleSort(stringArray, SIZE_OF_ARRAY, sizeof(char *), &stringCompare);
    for (int i = 0; i < SIZE_OF_ARRAY; i++) {
        printf("stringArray[%d] = %s\n", i, stringArray[i]);
    }

    double doubleArray[SIZE_OF_ARRAY] = {1.2, 2.2, -1.2, -12.0, 5.3};
    bubbleSort(doubleArray, SIZE_OF_ARRAY, sizeof(double), &doubleCompare);
    for (int i = 0; i < SIZE_OF_ARRAY; i++) {
        printf("doubleArray[%d] = %f\n", i, doubleArray[i]);
    }

    return 0;
}
