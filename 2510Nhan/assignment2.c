#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define EXPECTED_NUMBER_OF_ARGUMENTS 2
#define MAX_LENGTH_FILENAME 100
#define MAX_LENGTH_WORD 20
#define NEW_LINE_CHAR_UNIX '\n'
#define MAX_LENGTH_OUTPUT 100

// ERROR CODES
#define INVALID_NUMBER_OF_ARGUMENTS_ERROR_CODE 1
#define FILE_NOT_FOUND_ERROR_CODE 2

void printResult(int lineNumber, int charNumber) {
    char result[MAX_LENGTH_OUTPUT];
    sprintf(result, "Line: %d, character %d", lineNumber, charNumber);
    printf("%s\n", result);
}

void handleEOFSearch(char* keyword, int currentReadingLine, int currentCheckingPosition, int currentKeywordIndex) {
    if (currentKeywordIndex == strlen(keyword)) {
        int foundIndex = (int) (currentCheckingPosition - strlen(keyword));
        printResult(currentReadingLine, foundIndex);
        return;
    }
    printf("Not found!\n");
}

void search(FILE *file, char *keyword, int currentReadingLine, int currentCheckingPosition, int currentKeywordIndex) {
    char currentChar = (char) fgetc(file);

    if (currentChar == EOF) {
        return handleEOFSearch(keyword, currentReadingLine, currentCheckingPosition, currentKeywordIndex);
    } else if (currentChar == NEW_LINE_CHAR_UNIX) {
        return search(file, keyword, currentReadingLine + 1, 1, 0);
    } else if (currentChar == *(keyword + currentKeywordIndex)) {
        if (currentKeywordIndex == (strlen(keyword) - 1)) {
            return printResult(currentReadingLine, (int) (currentCheckingPosition - strlen(keyword)) + 1);
        }
        return search(file, keyword, currentReadingLine, currentCheckingPosition + 1, currentKeywordIndex + 1);
    }

    return search(file, keyword, currentReadingLine, currentCheckingPosition + 1, currentChar == *keyword);
}

void searchKeyword(char *filename, char *keyword) {
    FILE *file;
    file = fopen(filename, "r");

    if (file == NULL) {
        perror("File not found");
        exit(FILE_NOT_FOUND_ERROR_CODE);
    }

    search(file, keyword, 1, 1, 0);
    fclose(file);
}

void validateNumberOfArguments(int argc) {
    if (argc != (EXPECTED_NUMBER_OF_ARGUMENTS + 1)) {
        char error[MAX_LENGTH_OUTPUT];
        sprintf(error, "Need exactly %d arguments.", EXPECTED_NUMBER_OF_ARGUMENTS);
        perror(error);
        exit(INVALID_NUMBER_OF_ARGUMENTS_ERROR_CODE);
    }
}

int main(int argc, char *argv[]) {
    validateNumberOfArguments(argc);

    char filename[MAX_LENGTH_FILENAME] = "";
    char keyword[MAX_LENGTH_WORD] = "";
    strcat(filename, argv[1]);
    strcat(keyword, argv[2]);
    searchKeyword(filename, keyword);

    return 0;
}
