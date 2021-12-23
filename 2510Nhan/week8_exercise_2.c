#include <stdio.h>

#define MAX_NUMBER_OF_ELEMENTS 100

void printResult(int elements[], int size) {
    if (size == 1) {
        printf("%d\n", elements[0]);
        return;
    }
    printf("%d", elements[0]);
    for (int i = 1; i < size; i++) {
        printf(" + %d", elements[i]);
    }
    printf("\n");
}

void find(int elements[], int size, int paths[], int pathSize, int target) {
    if (target == 0) {
        printResult(paths, pathSize);
        return;
    }

    for (int i = 0; i < size; i++) {
        if (elements[i] <= target) {
            paths[pathSize] = elements[i];
            find(elements + i + 1, size - i - 1, paths, pathSize + 1, target - elements[i]);
        }
    }
}

void findAllElementsAddUpToANumber(int elements[], int size, int target) {
    if (size <= 0) {
        return;
    }
    int paths[MAX_NUMBER_OF_ELEMENTS] = {0};
    find(elements, size, paths, 0, target);
}

int main() {
    int elements[] = {1, 2, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 18;
    findAllElementsAddUpToANumber(elements, 11, target);
    return 0;
}
