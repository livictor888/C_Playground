#include <stdio.h>
#include <stdlib.h>

#define ERROR_CODE_INVALID_SIZE 1
#define ERROR_CODE_CANNOT_ALLOCATE_MEMORY 2

int *generateSubtractArray (const int *firstArray, int *secondArray, int size) {
    if (!size) {
        return (int *) malloc(1 * sizeof(int));
    }

    int *resultArray = (int *) malloc(size * sizeof(int));
    if (resultArray == NULL) {
        perror("Cannot allocate memory");
        exit(ERROR_CODE_CANNOT_ALLOCATE_MEMORY);
    }

    for (int i = 0; i < size; i++) {
        resultArray[i] = firstArray[i] - secondArray[i];
    }
    return resultArray;
}

int *subtractArray (int *firstArray, int *secondArray, int size) {
    if (size < 0) {
        perror("Invalid array size given");
        exit(ERROR_CODE_INVALID_SIZE);
    }

    return generateSubtractArray(firstArray, secondArray, size);
}


int main() {
    int firstArray[5] = {1, 2, 3, 4, 5};
    int secondArray[5] = {4, 3, 2, 1, 5};
    int size = 0;
    int *resultArray = subtractArray(firstArray, secondArray, size);

    for (int i = 0; i < size; i++) {
        printf("%d\n", *(resultArray + i));
    }

    free(resultArray);
    return 0;
}