#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX(a,b) (((a) > (b)) ? (a) : (b))

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void test() {
    long double array[2] = {1.1, 6.2};
    long double *firstPointer = array;
    long double *secondPointer = firstPointer + 1;
    printf("First output: %ld\n", secondPointer - firstPointer);
    printf("Second output: %ld\n", (long) secondPointer - (long) firstPointer);
}

char *resizeIfNeeded(char *array, int usedSize, int *currentSize) {
    if (usedSize <= *currentSize) {
        return array;
    }
    *currentSize *= 2;
    array = (char *) realloc(array, *currentSize * sizeof(char));
    if (!array) {
        perror("Memory allocation wrong");
        exit(1);
    }
    return array;
}

char *append(char *data[], int count) {
    int currentSize = 5;
    char *stringResult = (char *) malloc(currentSize * sizeof(char));

    if (!stringResult) {
        perror("Memory allocation wrong");
        exit(1);
    }

    int usedSize = 0;
    for (int i = 0; i < count; i++) {
        usedSize += strlen(data[i]) + 1;
        stringResult = resizeIfNeeded(stringResult, usedSize, &currentSize);
        strcat(stringResult, data[i]);
    }

    return stringResult;
}

void test3(int a, void (* fp)(int)) {
    fp(a);
}

void test4(int a) {
    printf("Number %d\n", a);
}

int main() {
    int firstNumber = 1;
    int secondNumber = 2;

    swap(&firstNumber, &secondNumber);
    printf("First number %d, second number %d\n", firstNumber, secondNumber);
    test();

    char a[] = "123";
    printf("%s\n", a);
    *a = 'c';
    printf("%s\n", a);

    int arr[3][4];
    int *pointer = &firstNumber;
    *(*arr + 1) = 109;

    char *stringList[] = {"Hello", "World", "I", "MoreThanWelcomeHere"};
    char *appendedString = append(stringList, 4);
    printf("%s\n", appendedString);
    free(appendedString);

    test3(10, test4);

    printf("Hello world!\n");
//    sleep(5);

    int x = 5;
    int y = 10;
    printf("max = %d\n", MAX(++x, --y));
    printf("x = %d, y = %d\n", x, y);
    return 0;
}