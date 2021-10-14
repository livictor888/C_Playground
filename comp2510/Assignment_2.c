#include <stdio.h>
#include <stdlib.h>

#define EXPECTED_NUMBER_OF_ARGUMENTS 2
#define INVALID_NUMBER_OF_ARGUMENTS_CODE 1
#define FILE_NOT_FOUND_CODE 2

void searchForToken(FILE *file, char *searchToken) {
    int lineNumber = 1;
    int charNumber = 1;
    int numberOfCharactersMatched;
    char currentChar = (char) fgetc(file);
    while (currentChar != EOF) {
        if (currentChar == '\n') {                              // case 1: encounter a new line
            lineNumber++;
            charNumber = 1;
            currentChar = (char) fgetc(file);
        } else if (currentChar == *searchToken) {               // case 2: match the first character of the searchToken
            char *remainingCharactersInSearchToken = searchToken;
            numberOfCharactersMatched = 0;
            while (currentChar == *remainingCharactersInSearchToken) {
                remainingCharactersInSearchToken++;
                currentChar = (char) fgetc(file);
                numberOfCharactersMatched++;
                if (*remainingCharactersInSearchToken == '\0') {
                    printf("Line: %d, character: %d\n", lineNumber, charNumber);
                    return;
                }
            }
            charNumber += numberOfCharactersMatched;
        } else {                                                // case 3 : character doesn't match
            currentChar = (char) fgetc(file);
            charNumber++;
        }
    }
    printf("Not found!\n");
}

void processFile(char *fileName, char *searchToken) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        perror("File not found.");
        exit(FILE_NOT_FOUND_CODE);
    }
    searchForToken(file, searchToken);
    fclose(file);
}

void validateNumberOfArguments(int argc) {
    if (argc != EXPECTED_NUMBER_OF_ARGUMENTS + 1) {
        perror("Need exactly 2 arguments");
        exit(INVALID_NUMBER_OF_ARGUMENTS_CODE);
    }
}

int main(int argc, char *argv[]) {
    printf("Program name is %s\n", argv[0]);
    validateNumberOfArguments(argc);
    processFile(argv[1], argv[2]);
    return 0;
}