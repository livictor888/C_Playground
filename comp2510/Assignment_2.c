#include <stdio.h>

#define ERROR_FILE_NOT_FOUND 1
#define ERROR_TOO_MANY_ARGUMENTS 2
#define ERROR_MISSING_ARGUMENTS 3

void matchSearchToken(FILE *file, char *searchToken) {
    int lineNumber;
    char currentChar;
    fscanf(file, "%c", currentChar);
    if (currentChar == *searchToken) {
        printf("character matches\n");
    }

}

int processFile(char *fileName, char *searchToken) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("File not found.\n");
        return ERROR_FILE_NOT_FOUND;
    }
    matchSearchToken(file, searchToken);
    fclose(file);
    return 0;
}

int main(int argc, char *argv[]) {
    // Arguments: input.txt assignment
    // Output:    Line: 1, character; 53
    // Arguments: input.txt third
    // Output:    Not found!
    printf("Program name is %s\n", argv[0]);
    if (argc == 3) {
        printf("The arguments supplied are %s, %s\n", argv[1], argv[2]);
        char *fileName = argv[1];
        char *searchToken = argv[2];
        processFile(fileName, searchToken);
    } else if (argc > 3) {
        printf("Too many arguments supplied.\n");
        return ERROR_TOO_MANY_ARGUMENTS;
    } else {
        printf("Missing arguments.\n");
        return ERROR_MISSING_ARGUMENTS;
    }
    return 0;
}
