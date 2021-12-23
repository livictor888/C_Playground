#include <stdio.h>

#define REQUIRED_SIZE 5

void find(int elements[], int size, int paths[], int pathSize, int target) {
    if (target == 0 && pathSize == REQUIRED_SIZE) {
        printf("%d + %d + %d + %d + %d\n", paths[0], paths[1], paths[2], paths[3], paths[4]);
    } else if (pathSize < REQUIRED_SIZE) {
        for (int i = 0; i < size; i++) {
            if (elements[i] <= target) {
                paths[pathSize] = elements[i];
                find(elements + i + 1, size - i - 1, paths, pathSize + 1, target - elements[i]);
            }
        }
    }
}

void findAllElementsAddUpToANumber(int elements[], int size, int target) {
    if (size <= 0) {
        return;
    }
    int paths[5] = {0};
    find(elements, size, paths, 0, target);
}

int main() {
    int elements[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 18;
    findAllElementsAddUpToANumber(elements, 10, target);

    return 0;
}
