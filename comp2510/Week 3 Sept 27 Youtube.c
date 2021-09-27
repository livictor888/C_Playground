#include <stdio.h>

void moveTonNextChar(char *inputString) {
    printf("Function:\n");
    printf("Pointer value: %\n", inputString);
    printf("Pointer Address: %p\n", &inputString);
    *inputString = '!';
    inputString++;
}


int main() {
    char firstName[] = "Victor";
    char *pointerName = "Victor";
    printf("Before: %s\n", firstName);
    printf("Pointer value: %p\n", firstName);
    printf("Pointer Address: %p\n", &firstName);
    moveTonNextChar(firstName);
    printf("After: %s\n", firstName);

//    printf("Before: %s\n", *pointerName);
//    moveTonNextChar(pointerName);
//    printf("After: %s\n", *pointerName);

    return 0;
//    *firstName = 'S';
//    printf("firstName = %c\n", *firstName);
//
//    char sentence[20] = "Hi, how are you?";
//    printf(sentence);

}