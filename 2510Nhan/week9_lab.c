#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SPACE ' '
#define STAR '*'
#define EXPECTED_NUMBER_OF_ARGUMENTS 1
#define MAX_LENGTH_OUTPUT 100
#define ASCII_GAP ('a' - 'A')

#define ERROR_CODE_INVALID_NUMBER_OF_ARGUMENTS 1
#define ERROR_CODE_FAILED_ALLOCATE_MEMORY 2

int getExpectedSizeOfResult(char *string) {
    int length = 0;
    while (*string) {
        if (*string == STAR) {
            length += 2;
        } else if (*string != SPACE){
            length += 1;
        }
        string++;
    }
    return length + 1;
}

void format(char *string, char *output) {
    while (*string) {
        if (*string == STAR) {
            *output++ = STAR;
            *output++ = STAR;
        } else if (*string >= 'a' && *string <= 'z' ) {
            *output++ = (char) (*string - ASCII_GAP);
        } else if (*string != SPACE) {
            *output++ = *string;
        }
        string++;
    }
    *output = 0;
}

char *formatAndPrint(char *string) {
    char *formattedString = (char *) malloc(getExpectedSizeOfResult(string) * sizeof(char));
    if (formattedString == NULL) {
        perror("Failed to allocate memory!");
        exit(ERROR_CODE_FAILED_ALLOCATE_MEMORY);
    }

    format(string, formattedString);
    return formattedString;
}

void validateNumberOfArguments(int argc) {
    if (argc != (EXPECTED_NUMBER_OF_ARGUMENTS + 1)) {
        char error[MAX_LENGTH_OUTPUT];
        sprintf(error, "Need exactly %d arguments.", EXPECTED_NUMBER_OF_ARGUMENTS);
        perror(error);
        exit(ERROR_CODE_INVALID_NUMBER_OF_ARGUMENTS);
    }
}

int main(int argc, char *argv[]) {
    validateNumberOfArguments(argc);
    char *output = formatAndPrint(argv[1]);
    printf("%s\n", output);
    free(output);
    return 0;
}