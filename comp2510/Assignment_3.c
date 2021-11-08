#include <stdio.h>
#include <stdlib.h>

#define EXPECTED_NUMBER_OF_ARGUMENTS 1
#define INITIAL_SIZE 5

#define INVALID_NUMBER_OF_ARGUMENTS_CODE 1
#define FILE_NOT_FOUND_CODE 2

void storeIntoArray();

void processFile(char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        perror("File not found.");
        exit(FILE_NOT_FOUND_CODE);
    }
    // do stuff
    fclose(file);
}

void validateNumberOfArguments(int argc) {
    if (argc != EXPECTED_NUMBER_OF_ARGUMENTS + 1) {
        perror("Need exactly 2 arguments");
        exit(INVALID_NUMBER_OF_ARGUMENTS_CODE);
    }
}

int main(int argc, char *argv[]) {
    printf("The program name is %s\n", argv[0]);
    validateNumberOfArguments(argc);
    processFile(argv[1]);

    return 0;
}