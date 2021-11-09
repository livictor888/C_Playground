// improve this code:
// scanf expected a number, if a string/char is passed it will crash
// must have checks to see if malloc or reallocate returns a null value, meaning it didn't work

#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 5

int *resizeArrayIfNeeded(int *array, int usedLength, int *arraySize) {
    if (usedLength <= *arraySize) {
        return array;
    }
    printf("Oops, need to resize!\n");
    *arraySize *= 2;
    return (int *) realloc(array, *arraySize * sizeof(int));
}

int main(void) {
    int length = 0, currentNumber = 0;
    int size = INITIAL_SIZE;
    int *array = (int *) malloc(size * sizeof(int));
    scanf("%d", &currentNumber);
    while (currentNumber > 0) {
        length++;
        array = resizeArrayIfNeeded(array, length, &size);
        array[length - 1] = currentNumber;
        scanf("%d", &currentNumber);
    }
    for (int i = 0; i < length; i++) {
        printf("A[%d] = %d\n", i, array[i]);
    }
    free(array);
    return 0;
}
