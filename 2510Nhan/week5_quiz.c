#include <string.h>
#include <assert.h>

#define STAR '*'
#define ASCII_UPPER_TO_LOWER_DISTANCE ('a' - 'A')

void transformString(char * input, char * output) {
    if (!*input) {
        *output = 0;
        return;
    }

    if (*input == STAR) {
        *output++ = *input;
        *output = *input;
    } else if (*input >= 'A' && *input <= 'Z') {
        *output = (char) (*input + ASCII_UPPER_TO_LOWER_DISTANCE);
    } else {
        *output = *input;
    }

    transformString(++input, ++output);
}


int main() {
    char output[100];

    transformString("int *Pointer;", output);
    assert(strcmp(output, "int **pointer;") == 0);

    transformString("WHAT?!", output);
    assert(strcmp(output, "what?!") == 0);

    transformString("I * C", output);
    assert(strcmp(output, "i ** c") == 0);

    transformString("Triple pointers ***", output);
    assert(strcmp(output, "triple pointers ******") == 0);

    transformString(" SpAce * * *  ", output);
    assert(strcmp(output, " space ** ** **  ") == 0);

    return 0;
}