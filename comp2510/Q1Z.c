#include "stdio.h"

#define LOWER_TO_UPPER_DIFFERENCE 32

int countUpperCase(char *input, char *output) {
    int count = 0;

    if (!*input) {
        return count;
    }

    if (*input >= 'A' && *input <= 'Z') {
        count++;
        return count + countUpperCase(input + 1, output + 1);
    } else {
        return count + countUpperCase(input + 1, output + 1);
    }

}

int main() {
    char *input1 = "Hi Adam, How Are You?";
    char *input2 = "ABCD";
    char *input3 = "Easiest quiz ever";

    char output1[256] = "";

    char output2[256] = "";
    char output3[256] = "";

    int i = countUpperCase(input1, output1);
    int j = countUpperCase(input2, output2);
    int k = countUpperCase(input3, output3);

    return 0;
}