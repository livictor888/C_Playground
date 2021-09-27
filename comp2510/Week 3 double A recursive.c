#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void doubleA(char *input, char *output) {
    if (!*input) {
        *output = 0;
        return;
    }
    *output = *input;

    if (*input == 'A') {
        output++;
        *output = 'A';

    }

    doubleA(input + 1, output + 1);
}

int main() {
    char input[] = "Hi Adam";
    char output[20] = "";
    doubleA(input, output);
    printf("Output is: %s\n", output);
    return 0;
}