#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#define CHAR_A 'A'
#define MAX_LENGTH 100
#define ERR_EMPTY_LIST 1

int findMaxNumber(int elements[], size_t size, int currentMax) {
    if (size == 0) {
        return currentMax;
    }

    int tempMax = currentMax > elements[size - 1] ? currentMax : elements[size - 1];
    return findMaxNumber(elements, size - 1, tempMax);
}

int maxElementInArray(int elements[], size_t size) {
    if (size == 0) {
        exit(ERR_EMPTY_LIST);
    }

    return findMaxNumber(elements, size - 1, elements[size - 1]);
}

int main() {
    int nums[MAX_LENGTH] = {-1, -12, 0, 2, 3};
    printf("Max number = %d\n", maxElementInArray(nums, 5));

    int nums2[MAX_LENGTH] = {-1};
    printf("Max number = %d\n", maxElementInArray(nums2, 1));

    int nums3[MAX_LENGTH] = {};
    printf("Max number = %d\n", maxElementInArray(nums3, 0));

    return 0;
}