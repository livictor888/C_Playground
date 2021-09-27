#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void reverseWithNoNullTerminotor(char *inputString, char *reverseString) {
    size_t length = strlen(inputString);
    if (!length) {
        return;
    }

    reverseString[length -1] = *inputString;
    reverseWithNoNullTerminotor(inputString + 1, reverseString);
}

void reverse(char *inputString, char *reverseString) {
    reverseWithNoNullTerminotor(inputString, reverseString);
    reverseString[strlen(inputString)] =0;                      // adds the null terminator
}

int main() {
    char input[] = "Seyed";
    char output[20] = "Javididfdf";
    reverseWithNoNullTerminotor(input, output);
    printf("Reverse = %s\n", output);
    return 0;
}