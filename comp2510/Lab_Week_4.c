#include <stdio.h>
#include <string.h>

void findMinDistance(char *inputString) {
    size_t length = strlen(inputString);
    int characterDistanceCounter;
    int minDistance = (int) length;
    char minChar;

    for (int charIndex = 0; charIndex < length -1 ; charIndex++) {
        characterDistanceCounter = 0;
        for (int compareIndex = charIndex + 1; compareIndex < length; compareIndex++) {
            if (inputString[charIndex] == inputString[compareIndex]) {
                if (characterDistanceCounter < minDistance) {
                    minDistance = characterDistanceCounter;
                    minChar = inputString[charIndex];
                }
            } else {
                characterDistanceCounter++;
            }
        }
    }
    if (minDistance == length) {
        printf("There is no min distance.\n");
        return;
    } else {
        printf("Repeated char: %c\nThe min distance is: %d\n", minChar, minDistance);
    }
}

int main() {
    char *testString = "Hello there, how's it going?";
    char *testString2 = "Hi there, how's it going?";
    char *testString3 = "123";

    findMinDistance(testString);
    findMinDistance(testString2);
    findMinDistance(testString3);
    return 0;
}