#include <stdio.h>
#include <stdlib.h>

#define INVALID_NUMBER_OF_ARGUMENTS_CODE 1
#define FAILED_TO_ALLOCATE_MEMORY 2

#define EXPECTED_NUMBER_OF_ARGUMENTS 1
#define INITIAL_SIZE 5
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

char *transform(char *string) {
    int size = INITIAL_SIZE;
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
    char* string = transform(argv[1]);
    printf("%s\n", string);
    free(string);
    return 0;
}