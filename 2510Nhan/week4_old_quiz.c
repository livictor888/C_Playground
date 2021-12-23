#include <stdio.h>
#include <string.h>
#include <assert.h>

#define CHAR_A 'A'
#define MAX_LENGTH 100

void removeA(char *input, char *output) {
    if (!*input) {
        *output = 0;
        return;
    }

    if (*input != CHAR_A) {
        *output++ = *input;
    }

    removeA(++input, output);
}

int main() {
    char output[MAX_LENGTH];

    strcpy(output, "QQQQQQQQQQQQQQQQQQQQQQQ");
    removeA("", output);
    printf("Test empty = %s\n", output);

    strcpy(output, "QQQQQQQQQQQQQQQQQQQQQQQ");
    removeA("            ", output);
    printf("Test whitespace = ---->%s<----\n", output);

    strcpy(output, "QQQQQQQQQQQQQQQQQQQQQQQ");
    removeA("A", output);
    printf("Test single A = ---->%s<----\n", output);

    strcpy(output, "QQQQQQQQQQQQQQQQQQQQQQQ");
    removeA("%AaaaaA  A", output);
    printf("Test complex = ---->%s<----\n", output);

    return 0;
}