#include <stdio.h>
#include <string.h>

#define MAX_WORD_LENGTH 20
#define MAX_NUMBER_OF_WORDS 100
#define SPACE ' '

void insertSpaceAndPrintLine(char *startIndex, int numberOfInsertedSpace, int numberOfCurrentSpace, int lineLength) {
    int numberOfInsertedSpaceInBetween = numberOfInsertedSpace / numberOfCurrentSpace;
    int remainNumberOfSpace = numberOfInsertedSpace - numberOfInsertedSpaceInBetween * numberOfCurrentSpace;

    char line[lineLength + 1];
    strncpy(line, "", lineLength);

    for (int i = 0; i < lineLength; i++) {
        line[i] = *startIndex;
        if (*startIndex == SPACE) {
            for (int j = 0; j < numberOfInsertedSpaceInBetween && i < lineLength; j++) {
                line[++i] = SPACE;
            }

            if (remainNumberOfSpace > 0 && i < lineLength) {
                line[++i] = SPACE;
                remainNumberOfSpace--;
            }
        }
        startIndex++;
    }

    line[lineLength] = 0;
    printf("%s\n", line);
}

int getNumberOfSpaceByPosition(char *startIndex, char *stopIndex) {
    int count = 0;
    while(*startIndex && startIndex <= stopIndex) {
        if (*startIndex == SPACE && startIndex != stopIndex) {
            count++;
        }
        startIndex++;
    }
    return count;
}

void formatAndPrintLine(char *startIndex, char *stopIndex, int lineLength) {
    int numberOfInsertedSpace = lineLength - (int)(stopIndex - startIndex + 1);
    int numberOfCurrentSpace = getNumberOfSpaceByPosition(startIndex, stopIndex);

    // Handle the case where last line has only one word
    if (numberOfCurrentSpace == 0) {
        printf("%s\n", startIndex);
        return;
    }

    insertSpaceAndPrintLine(startIndex, numberOfInsertedSpace, numberOfCurrentSpace, lineLength);
}

char *getLastIndexInLine(char *currentIndex, char *endOfParagraph, int lineLength) {
    if (currentIndex + lineLength - 1 >= endOfParagraph) {
        return endOfParagraph;
    }

    for (int i = lineLength - 1; i > 0; i--) {
        if (*(currentIndex + i) == SPACE) {
            return currentIndex + i - 1;
        } else if (*(currentIndex + i + 1) == SPACE) {
            return currentIndex + i;
        }
    }

    return currentIndex + lineLength - 1;
}

void formatAndPrintParagraph(char *paragraph, int lineLength) {
    char *startIndex = paragraph;
    char *stopIndex = startIndex;
    char *endOfParagraph = startIndex;
    while (*(endOfParagraph + 1) && endOfParagraph++);

    while (stopIndex <= endOfParagraph) {
        stopIndex = getLastIndexInLine(stopIndex, endOfParagraph, lineLength);
        formatAndPrintLine(startIndex, stopIndex, lineLength);
        stopIndex += 2; // Move to next non-space character
        startIndex = stopIndex;
    }
};



int main() {
    char *testString = "Hi everyone.      This is the 2nd    assignment. Please make sure you start early as this is going to take some time!";
    formatAndPrintParagraph(testString, 20);
//    printf("\n");
//    formatAndPrintParagraph(testString, 21);
//    printf("\n");
//    formatAndPrintParagraph(testString, 25);
//    printf("\n");
    return 0;
}