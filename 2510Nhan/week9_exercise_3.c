#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct Point {
    int x;
    int y;
};

void printArray(int *array, size_t size) {
    for (int i = 0; i < size; i++) {
        printf("%d\n", *(array + i));
    }
}

char *append(char *array[], int count) {
    if (count <= 0) {
        return "";
    }

    int currentSize = strlen(array[0]) + 1;
    char *result = (char *) malloc(currentSize * sizeof(char));
    *result = 0;
    char *original = result;
    for (int index = 0; index < count; index++) {
        if (strlen(result) + strlen(array[index]) >= currentSize) {
            result = (char *) realloc(original, currentSize * 2);
            currentSize *= 2;
            original = result;
        }
        strcat(result, array[index]);
    }
    return result;
}

void printPoints(struct Point *points, size_t size) {
    for (int i = 0; i < size; i += sizeof(struct Point)) {
        printf("%d %d\n", (points + i)->x, (points + i)->y);
    }
}

int main() {
    int *array = (int *) malloc(5 * sizeof(int));
    *(array) = 1;
    *(array + 1) = 2;
    *(array + 2) = 3;
    *(array + 3) = 4;
    *(array + 4) = 5;
    printArray(array, 5);
    int *copy = array;
    free(copy);
//    printArray(array, 5); // point to dead allocation memory

    char name[10] = "Seyed!";
//    free(name); // free non-heap address

    char *names[5] = {"Hello", "World", "Significantly", "Me", "Useful"};
    char *result = append(names, 5);
    printf("%s\n", result);
    free(result);

    struct Point firstPoint = {1, 2};
    struct Point secondPoint = {4, 5};

    struct Point *points = NULL;
    points = &firstPoint;
    struct Point *original = points;
    printPoints(original, 2 * sizeof(struct Point));


    return 0;
}