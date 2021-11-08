#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE_OF_INTEGER 1001

bool isAnagram(int *first, int *second, size_t size){
    int mapFirst[MAX_SIZE_OF_INTEGER] = {0};
    int mapSecond[MAX_SIZE_OF_INTEGER] = {0};
    for (int i = 0; i < size; i++) {
        mapFirst[*first]++;
        first++;
    }
    for (int j = 0; j < size; j++) {
        mapSecond[*second]++;
        second++;
    }
    for (int k = 0; k < 1001; k++) {
        if (mapFirst[k] != mapSecond[k]) {
            return false;
        }
    }
    return true;
}

int main() {
    int first[4] = {1, 2, 2, 4};
    int second[4] = {1, 2, 22, 4};
    printf("%d\n", isAnagram(first, second, 4));
    return 0;
}