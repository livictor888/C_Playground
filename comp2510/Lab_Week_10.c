#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INVALID_NUMBER_OF_ARGUMENTS_CODE 1
#define FAILED_TO_ALLOCATE_MEMORY 2

#define EXPECTED_NUMBER_OF_ARGUMENTS 1
#define SPACE ' '
#define ASTERISK '*'
#define TO_UPPER ('a' - 'A')

char *resizeArrayIfNeeded(char *array, int amountFilled, int *arraySize) {
    if (amountFilled < *arraySize) {
        return array;
    }
    *arraySize *= 2;
    array = (char *) realloc(array, *arraySize * sizeof(char));
    if (array == NULL) {
        perror("Failed to reallocate memory.");
        exit(FAILED_TO_ALLOCATE_MEMORY);
    }
    return array;
}

int findSize(char *string) {
    int size = (int) strlen(string);
    while (*string) {
        if (*string == SPACE) {
            size--;
        } else if (*string == ASTERISK) {
            size++;
        }
        string++;
    }
    return size;
}

char *transform(char *string) {
    int size = findSize(string);
    int length = 0;

    char *result = malloc(size * sizeof(char));
    if (result == NULL) {
        perror("Failed to allocate memory.");
        exit(FAILED_TO_ALLOCATE_MEMORY);
    }

    while (*string) {

        resizeArrayIfNeeded(result, length + 2, &size);
        if (*string == ASTERISK) {
            *(result + length++) = '*';
            *(result + length++) = '*';
        } else if (*string >= 'a' && *string <= 'z') {
            *(result + length++) = (char) (*string - TO_UPPER);
        } else if (*string != SPACE) {
            *(result + length++) = *string;
        }
        string++;
    }
    *(result + length) = 0;
    return result;
}

void validateNumberOfArguments(int argc) {
    if (argc != EXPECTED_NUMBER_OF_ARGUMENTS + 1) {
        perror("Wrong number of arguments");
        exit(INVALID_NUMBER_OF_ARGUMENTS_CODE);
    }
}

int main(int argc, char *argv[]) {
    validateNumberOfArguments(argc);
    char* output = transform(argv[1]);
    printf("%s\n", output);
    free(output);
    return 0;
}
