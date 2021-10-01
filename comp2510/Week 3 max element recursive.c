#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define EMPTY_ARRAY_ERROR_CODE 1

int maxOfTwo(int first, int second) {
    return (first > second) ? first : second;
}

int findMaximumElement(int elements[], size_t size) {
    if (size == 0) {
        perror("Empty array is passed.");
        exit(EMPTY_ARRAY_ERROR_CODE);
    }

    if (size == 1) {
        return elements[0];
    }

    int maxOfRest = findMaximumElement(elements, size - 1);
    return maxOfTwo(maxOfRest, elements[size - 1]);
}

int main() {
    int input[] = { 100, -1, 23, 0, 3998, 4};
    printf("Max element = %d\n", findMaximumElement(input, 6));
    return 0;
}



//int findMaximumElement(int *array, int max) {
//    size_t arraySize = sizeof(array);
//    if (arraySize == 0) {
//        return max;
//    } else {
//        arraySize--;
//    }
//
//    if (*array > max) {
//        max = *array;
//        findMaximumElement(array + 1, max);
//    } else {
//        findMaximumElement(array + 1, max);
//    }
//}
//
//int main() {
//    int input[] = { 100, -1, 23, 0, 3998, 4};
//    printf("Max element = %d\n", findMaximumElement(input, 5));
//    return 0;
//}
//
//
