#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define EXPECTED_NUMBER_OF_ARGUMENTS 1
#define MAX_LENGTH_FILENAME 100
#define MAX_LENGTH_NAME 100
#define MAX_NUMBER_OF_LINES 200
#define MAX_NUMBER_OF_CHAR 255

// ERROR CODES
#define INVALID_NUMBER_OF_ARGUMENTS_ERROR_CODE 1
#define FILE_NOT_FOUND_ERROR_CODE 2


void transformString(int transformMap[MAX_NUMBER_OF_CHAR], char *inputString, char *outputString) {
    while (*inputString) {
        inputString++;
    }
}

void scanTransformMap(FILE *file, int transformMap[MAX_NUMBER_OF_CHAR]) {
    char firstChar = 0;
    char secondChar = 0;
    while (fscanf(file, "%c %c\n", &firstChar, &secondChar) == 2) {
        transformMap[firstChar] =(int) secondChar;
    }
}

void mapCharactersUsingFile(char *fileName, char *input, char *output) {
    FILE *file;
    file = fopen(fileName, "r");

    if (file == NULL) {
        perror("Could not open file");
        exit(FILE_NOT_FOUND_ERROR_CODE);
    }

    int transformMap[MAX_NUMBER_OF_CHAR] = {0};
    scanTransformMap(file, transformMap);
    transformString(transformMap, input, output);
    fclose(file);
}

void validateNumberOfArguments(int argc) {
    if (argc != (EXPECTED_NUMBER_OF_ARGUMENTS + 1)) {
        char error[100];
        sprintf(error, "Need exactly %d arguments.", EXPECTED_NUMBER_OF_ARGUMENTS);
        perror(error);
        exit(INVALID_NUMBER_OF_ARGUMENTS_ERROR_CODE);
    }
}

int main(int argc, char *argv[]) {
    validateNumberOfArguments(argc);

    char filename[MAX_LENGTH_FILENAME] = "";
    char inputString[MAX_NUMBER_OF_CHAR] = "";
    strcat(filename, argv[1]);
    strcat(filename, argv[2]);

    char outputString[MAX_NUMBER_OF_CHAR] = "";
    mapCharactersUsingFile(filename, inputString, outputString);

    return 0;
}