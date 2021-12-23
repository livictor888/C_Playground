#include <stdio.h>
#include <string.h>

void printChar(void *string) {
    printf("%c", *((char *) string));
}

void printInteger(void *number) {
    printf("%d", *((int *) number));
}

void printString(void *string) {
    char **fString = (char **) string;
    printf("%s", *fString);
}

void *findNthElement(void *array, int n, size_t sizeOfEachElementInBytes) {
    return (char *) array + (n - 1) * sizeOfEachElementInBytes;
}

void printArray(void *array, size_t size, size_t numberOfByte, void (* printFunc)(void *)) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printFunc(findNthElement(array, i + 1, numberOfByte));
        printf(",");
    }
    printf("]\n");
}


int main() {
    char testArray[6] = "Hello";
    printArray(testArray, 5, sizeof(char), &printChar);

    int testArray2[5] = {1,2,3,4,5};
    printArray(testArray2, 5, sizeof(int), &printInteger);


    char *testArray3[3] = {0};
    testArray3[0] = "Hello";
    testArray3[1] = "World";
    testArray3[2] = "Hi";
    printArray(testArray3, 3, sizeof(char *), &printString);

    return 0;
}