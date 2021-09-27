#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void reverse(char *inputString, char *reverseString) {
    size_t length = strlen(inputString);
    if (!length) {
        return;
    }

    reverseString[length -1] = *inputString;
    reverse(inputString + 1, reverseString);
}

int main() {
    char input[] = "Seyed";
    char output[20] = "Javididfdf";
    reverse(input, output);
    printf("Reverse = %s\n", output);
    return 0;
}