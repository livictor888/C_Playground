#include <stdio.h>
#include <stdbool.h>

#define ERROR_FILE_NOT_FOUND 1
#define ERROR_TOO_MANY_ARGUMENTS 2
#define ERROR_MISSING_ARGUMENTS 3

void searchForToken(FILE *file, char *searchToken) {
    int lineNumber = 1;
    int charNumber = 1;
    char currentChar = (char) fgetc(file);
    while (currentChar != EOF) {
        if (currentChar == '\n') {                              // case 1: encounter a new line
            lineNumber++;
            charNumber = 1;
            currentChar = (char) fgetc(file);
        } else if (currentChar == *searchToken) {               // case 2: match the first character of the searchToken
            char *pointer = searchToken;
            while (currentChar == *pointer) {
                pointer++;
                currentChar = (char) fgetc(file);
                if (*pointer == '\0') {
                    printf("Line: %d, character: %d\n", lineNumber, charNumber);
                    return;
                }
            }
            charNumber++;
        } else {                                                // case 3 : character doesn't match
            currentChar = (char) fgetc(file);
            charNumber++;
        }
    }
    printf("Character not found.\n");
}

bool processFile(char *fileName, char *searchToken) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("File not found.\n");
        return false;
    }
    searchForToken(file, searchToken);
    fclose(file);
    return true;
}

int main(int argc, char *argv[]) {
    printf("Program name is %s\n", argv[0]);
    if (argc == 3) {
        printf("The arguments supplied are %s, %s\n", argv[1], argv[2]);
        char *fileName = argv[1];
        char *searchToken = argv[2];
        bool succeeded = processFile(fileName, searchToken);
        if (succeeded == false) {
            return ERROR_FILE_NOT_FOUND;
        }
    } else if (argc > 3) {
        printf("Too many arguments supplied.\n");
        return ERROR_TOO_MANY_ARGUMENTS;
    } else {
        printf("Missing arguments.\n");
        return ERROR_MISSING_ARGUMENTS;
    }
    return 0;
}