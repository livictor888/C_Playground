#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define EXPECTED_NUMBER_OF_ARGUMENTS 3

// ERROR CODES
#define INVALID_NUMBER_OF_ARGUMENTS_ERROR_CODE 1
#define NOT_A_NUMBER_ERROR_CODE 2

void exitWithNotANumberErrorCode(char *input) {
    char error[100];
    sprintf(error, "Argument: %s is not a number.", input);
    perror(error);
    exit(NOT_A_NUMBER_ERROR_CODE);
}

long convertStringArgumentToNumber(char *input) {
    char *remaining;
    long number = strtol(input, &remaining, 10);
    if (strlen(remaining) > 0) {
        exitWithNotANumberErrorCode(input);
    }
    return number;
}

void printSumOfArguments(char *argv[]) {
    long firstNumber = convertStringArgumentToNumber(argv[1]);
    long secondNumber = convertStringArgumentToNumber(argv[2]);
    long thirdNumber = convertStringArgumentToNumber(argv[3]);
    long sum = firstNumber + secondNumber + thirdNumber;
    printf("Sum = %ld\n", sum);
}

void validateNumberOfArguments(int argc) {
    if (argc != (EXPECTED_NUMBER_OF_ARGUMENTS + 1)) {
        perror("Need exactly three arguments");
        exit(INVALID_NUMBER_OF_ARGUMENTS_ERROR_CODE);
    }
}

int main(int argc, char *argv[]) {
    // First argument is always the name of the running program (executable)
    // arguments: 1 2 3
    // output: Sum = 6
    printf("Name of the program: %s\n", argv[0]);

    validateNumberOfArguments(argc);
    printSumOfArguments(argv);

    return 0;
}
 