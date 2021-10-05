#include "stdio.h"

#define UPPER_TO_LOWER_ASCII_DIFFERENCE 32

void transformString(char *input, char *output) {
    if (!*input) {
        return;
    }

    if (*input >= 'A' && *input <= 'Z') {
        *output = *input;
        transformString(input + 1, output + 1);
    }

    else if (*input >= 'a' && *input <= 'z') {
        int characterAsciiValue = (int) *input;
        *output = (char) (characterAsciiValue - UPPER_TO_LOWER_ASCII_DIFFERENCE);
        transformString(input + 1, output + 1);
    }

    else if (*input == ' ') {
        transformString(input + 1, output);
    }

    else {
        *output = *input;
        transformString(input + 1, output + 1);
    }

}

int main() {
    char *input1 = "Hi Adam, How Are You?";
    char *input2 = "ABCD";
    char *input3 = "Easiest quiz ever";

    char output1[256] = "";

    char output2[256] = "";
    char output3[256] = "";

    transformString(input1, output1);
    transformString(input2, output2);
    transformString(input3, output3);

    return 0;
}