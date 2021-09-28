#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool validPassword(char* password, int length) {
    bool checks[4] = {false, false, false, false};
    //              length  upper   lower   non-letter
    if (length >= 8) {
        checks[0] = true;
        for (int i = 0; i < length; i++) {
            if (isupper(password[i])) {
                checks[1] = true;
            }
            if (islower(password[i])) {
                checks[2] = true;
            }
            if (!isalpha(password[i])) {
                checks[3] = true;
            }
        }
        for (int i = 0; i < length; i++) {
            if (checks[i] == false) {
                return false;
            }
        }
        return true;
    }
    return false;
}


int main() {
    char *testPassword = "Hello World!";
    printf("result: %b", validPassword(testPassword, 11));
    return 0;
}

//#include <stdio.h>
//#include <stdbool.h>
//#include <string.h>
//
//#define MINIMUM_LENGTH 8
//
//bool isLowerCaseLetter(char character) {
//    return character >= 'a' && character <= 'z';
//}
//
//bool isUpperCaseLetter(char character) {
//    return character >= 'A' && character <= 'Z';
//}
//
//bool isNonLetterCharacter(char character) {
//    return !isLowerCaseLetter(character) && !isUpperCaseLetter(character);
//}
//
//bool isPasswordLongEnough(char *password) {
//    return strlen(password) >= MINIMUM_LENGTH;
//}
//
//bool isPasswordValid(char *password) {
//    if (!isPasswordLongEnough(password)) {
//        return false;
//    }
//
//    bool hasUpperCaseLetter = false;
//    bool hasLowerCaseLetter = false;
//    bool hasNonLetterCharacter = false;
//
//    while (*password && (!hasUpperCaseLetter || !hasLowerCaseLetter || !hasNonLetterCharacter)) {
//        hasUpperCaseLetter |= isUpperCaseLetter(*password);
//        hasLowerCaseLetter |= isLowerCaseLetter(*password);
//        hasNonLetterCharacter |= isNonLetterCharacter(*password);
//        password++;
//    }
//
//    return hasNonLetterCharacter && hasLowerCaseLetter && hasUpperCaseLetter;
//}
//
//int main() {
//    char *password = "Comp-2510";
//    printf("Is %s a valid password = %s\n", password, (isPasswordValid(password)) ? "True" : "False" );
//    return 0;
//}