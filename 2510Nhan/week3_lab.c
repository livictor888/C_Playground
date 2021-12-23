#include <stdio.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100
#define DELIMITER  ' '

void printTokenWithPositions(char *startIndex, char *stopIndex) {
    while (*startIndex && startIndex < stopIndex) {
        printf("%c", *startIndex);
        startIndex++;
    }
    printf("\n");
}

void printTokens(char *inputString) {
    char *startIndex = inputString;
    bool isStoring = false;

    while(*inputString) {
        if (*inputString != DELIMITER && !isStoring) {
            startIndex = inputString;
            isStoring = true;
        } else if (*inputString == DELIMITER && isStoring) {
            printTokenWithPositions(startIndex, inputString);
            isStoring = false;
        }

        // Print the last word if possible
        if (!*(inputString + 1) && isStoring) {
            printTokenWithPositions(startIndex, inputString + 1);
        }

        inputString++;
    }
};

void printTestCase(char * string) {
    printf("String \"%s\" will be printed as: \n", string);
    printTokens(string);
    printf("----\n");
}

int main() {
    printTestCase("Hi     there! How is it    going?");
    printTestCase("  Hi     there! ");
    printTestCase("  Hi  ");
    printTestCase("Hi");
    printTestCase("Hi  ");
    printTestCase("   Hi");
}