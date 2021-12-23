#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define EXPECTED_NUMBER_OF_ARGUMENTS 2
#define MAX_LENGTH_FILENAME 100
#define MAX_LENGTH_OUTPUT 100

// ERROR CODES
#define INVALID_NUMBER_OF_ARGUMENTS_ERROR_CODE 1
#define FILE_NOT_FOUND 2

void makeCopy(FILE * originalFile, FILE * copyFile) {
    char currentChar = (char) fgetc(originalFile);

    while (currentChar != EOF) {
        char *tempStr = &currentChar;
        fwrite(tempStr , 1 , sizeof(currentChar) , copyFile);
        currentChar = (char) fgetc(originalFile);
    }
}

void openFile(FILE **file, char * filename, char *mode) {
    *file = fopen(filename, mode);

    if (*file == NULL) {
        perror("File not found");
        exit(FILE_NOT_FOUND);
    }
}

void copy(char *filename, char *newFilename) {
    FILE * originalFile = NULL;
    FILE * copyFile = NULL;
    openFile(&originalFile, filename, "r");
    openFile(&copyFile, newFilename, "w+");

    makeCopy(originalFile, copyFile);

    fclose(originalFile);
    fclose(copyFile);
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
    char newFilename[MAX_LENGTH_FILENAME] = "";
    strcat(filename, argv[1]);
    strcat(newFilename, argv[2]);

    copy(filename, newFilename);

    return 0;
}
