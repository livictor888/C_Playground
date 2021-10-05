#include "stdio.h"

#define UPPER_TO_LOWER_ASCII_DIFFERENCE 32
#define CHARACTER_TO_DOUBLE '*'

void transformString(char *input, char *output) {
    if (!*input) {
        return;
    } else if (*input >= 'A' && *input <= 'Z') {
        int characterASCIIValue = (int) *input;
        *output = (char) (characterASCIIValue + UPPER_TO_LOWER_ASCII_DIFFERENCE);
        transformString(input + 1, output + 1);
    } else if (*input == CHARACTER_TO_DOUBLE) {
        *output = *input;
        output++;
        *output = *input;
        transformString(input + 1, output + 1);
    } else {
        *output = *input;
        transformString(input + 1, output + 1);
    }
}

int main() {
    char *input1 = "int *Pointer;";
    char *input2 = "WHAT?!";
    char *input3 = "I * C";
    char *input4 = "Triple pointers ***";

    char output1[512] = "";
    char output2[512] = "";
    char output3[512] = "";
    char output4[512] = "";

    transformString(input1, output1);
    transformString(input2, output2);
    transformString(input3, output3);
    transformString(input4, output4);

    printf("Test 1:\ninput 1: %s\noutput 1: %s\n\n", input1, output1);
    printf("Test 2:\ninput 2: %s\noutput 2: %s\n\n", input2, output2);
    printf("Test 3:\ninput 3: %s\noutput 3: %s\n\n", input3, output3);
    printf("Test 4:\ninput 4: %s\noutput 4: %s\n\n", input4, output4);

    return 0;
}