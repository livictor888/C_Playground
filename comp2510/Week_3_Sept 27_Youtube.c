#include <stdio.h>
#include <assert.h>

//void moveTonNextChar(char *inputString) {
//    printf("Function:\n");
//    printf("Pointer value: %\n", inputString);
//    printf("Pointer Address: %p\n", &inputString);
//    *inputString = '!';
//    inputString++;
//}


int main() {
//    char firstName[] = "Victor";
//    char *pointerName = "Victor";
//    printf("Before: %s\n", firstName);
//    printf("Pointer value: %p\n", firstName);
//    printf("Pointer Address: %p\n", &firstName);
//    moveTonNextChar(firstName);
//    printf("After: %s\n", firstName);


//    printf("Before: %s\n", *pointerName);
//    moveTonNextChar(pointerName);
//    printf("After: %s\n", *pointerName);

    int anotherNumber = 3;
    int number = (anotherNumber -= 2);
    printf("number: %d\n", number);
    printf("anotherNumber: %d\n", anotherNumber);

//    *firstName = 'S';
//    printf("firstName = %c\n", *firstName);
//
//    char sentence[20] = "Hi, how are you?";
//    printf(sentence);

typedef char* String;
String myFirstName = "Seyed";
//printf("assert %b\n", assert(*myFirstName));
String someString = "Hello";
char someString[2] = "abc";


return 0;

}