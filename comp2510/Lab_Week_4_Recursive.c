#include <stdio.h>
#include <string.h>

#define MAX_NUMBER_OF_CHARACTER 256

void find(char *inputString, int positions[], int currentPosition, int *currentMinDistance, char *currentMinDistanceChar) {
    if (!*currentMinDistance || !*inputString) {
        return;
    }

    if (positions[*inputString] >= 0 && currentPosition - positions[*inputString] < *currentMinDistance) {
        *currentMinDistance = currentPosition - positions[*inputString];
        *currentMinDistanceChar = *inputString;
    }

    positions[*inputString] = currentPosition;
    find(++inputString, positions, currentPosition + 1, currentMinDistance, currentMinDistanceChar);
}


void findMinDistance(char *inputString) {
    char minDistanceChar;
    int minDistance = (int) strlen(inputString);
    int positions[MAX_NUMBER_OF_CHARACTER];
    for (int i = 0; i < MAX_NUMBER_OF_CHARACTER; i++) {
        positions[i] = -1;
    }

    find(inputString, positions, 0, &minDistance, &minDistanceChar);
    if (minDistance != (int) strlen(inputString)) {
        printf("Repeated char: \'%c\', min distance: %d\n", minDistanceChar, minDistance - 1);
    } else {
        printf("No repeated character\n");
    }
}

int main() {
    printf("* Test case: \"Hi there, how is it going?\"\n");
    findMinDistance("Hi there, how is it going?");
    printf("* Test case: \"Hello there, how is it going?\"\n");
    findMinDistance("Hello there, how is it going?");
    printf("* Test case: \"123\"\n");
    findMinDistance("123");
    printf("* Test case: \"     Hi there, how is it going?\"\n");
    findMinDistance("     Hi there, how is it going?");
    printf("* Test case: \"Hi !!\"\n");
    findMinDistance("Hi !!");
    printf("* Test case: \"Helinlee\"\n");
    findMinDistance("Helinlee");
}