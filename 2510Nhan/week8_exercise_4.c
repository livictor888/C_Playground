#include <stdio.h>
#include <stdbool.h>

#define MAX_ARRAY_SIZE 1000

bool isTwoArrayAnagram(int firstArray[], size_t firstArraySize, int secondArray[], size_t secondArraySize) {
    if (firstArraySize != secondArraySize || firstArraySize < 0 || secondArraySize < 0) {
        return false;
    }

    // Check XOR
    int xorResult = 0;
    for (int index = 0; index < firstArraySize; index++) {
        xorResult ^= firstArray[index] ^ secondArray[index];
    }
    return xorResult ? false : true;
}


int main() {
    int firstArray[MAX_ARRAY_SIZE] = {1, -1, 2, 2};
    int secondArray[MAX_ARRAY_SIZE] = {2, 1, 2, -1};
    bool result = isTwoArrayAnagram(firstArray, 4, secondArray, 4);
    printf("Two arrays are anagram? %s\n", result ? "Yes" : "No");

    return 0;
}