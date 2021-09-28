// September 20 2021

#include <stdio.h>

char getFirstNonRepeatedCharacter(char *string) {
    char characters[256];
    while(*string) {
        characters[*string] += 1;

    }
    for (int i = 0; i <256; i++ ) {
        if (characters[i] == 1) {
            return characters[i];
        }
    }
    return "";
}

int main() {
    printf("Hello, World!\n");
    return 0;
}


//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <assert.h>
//
//#define NO_RESULT_ERROR_CODE 1
//
//int getCharacterFrequencyInString(char *input, char target) {
//    int count = 0;
//    for (size_t i = 0; i < strlen(input); i++) {
//        if (input[i] == target) {
//            count++;
//        }
//    }
//
//    return count;
//}
//
//char getFirstNonRepeatedCharacter(char *input) {
//    char *copy = input;
//
//    while (*input) {
//        if (getCharacterFrequencyInString(copy, *input) == 1) {
//            return *input;
//        }
//        input++;
//    }
//
//    perror("Did not find a non-repeating character.");
//    exit(NO_RESULT_ERROR_CODE);
//}
//
//void testQ2() {
//    assert(getFirstNonRepeatedCharacter("Seyed") == 'S');
//    assert(getFirstNonRepeatedCharacter("I don't know what I would do without you.") == '\'');
//    // Depending on how you handle errors: uncomment one of the following two lines:
//    getFirstNonRepeatedCharacter("AA");
//    // assert(getFirstNonRepeatedCharacter("AA") == 0);
//}
//
//int main() {
//    testQ2();
//    return 0;
//}