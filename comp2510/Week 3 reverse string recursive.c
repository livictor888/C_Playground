#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void reverseWithNoNullTerminator(char *inputString, char *reverseString) {
    size_t length = strlen(inputString);
    if (!length) {
        return;
    }

    reverseString[length -1] = *inputString;
    reverseWithNoNullTerminator(inputString + 1, reverseString);
}

void reverse(char *inputString, char *reverseString) {
    reverseWithNoNullTerminator(inputString, reverseString);
    reverseString[strlen(inputString)] =0;                      // adds the null terminator
}

int main() {
    char input[] = "Seyed";
    char output[20] = "Javididfdf";
    reverseWithNoNullTerminator(input, output);
    printf("Reverse = %s\n", output);
    return 0;
}