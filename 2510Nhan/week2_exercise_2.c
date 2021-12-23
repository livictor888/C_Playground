#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define UPPERCASE_LOWEST_ASCII 65
#define UPPERCASE_HIGHEST_ASCII 90
#define LOWERCASE_LOWEST_ASCII 97
#define LOWERCASE_HIGHEST_ASCII 122
#define MINIMUM_LENGTH 8

bool isPasswordValid(char * password) {
    if (strlen(password) < MINIMUM_LENGTH) {
        return false;
    }

    bool hasUppercase = false;
    bool hasLowercase = false;
    bool hasNonCharacter = false;

    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= UPPERCASE_LOWEST_ASCII && password[i]  <= UPPERCASE_HIGHEST_ASCII) {
            hasUppercase = true;
        } else if (password[i] >= LOWERCASE_LOWEST_ASCII && password[i]  <= LOWERCASE_HIGHEST_ASCII) {
            hasLowercase = true;
        } else {
            hasNonCharacter = true;
        }
    }

    return hasUppercase && hasNonCharacter && hasLowercase;
}

int main() {
    bool res = isPasswordValid("Co_MP2510");
    printf("Your password is %s\n", (res ? "valid" : "invalid"));
    res = isPasswordValid("123456789");
    printf("Your password is %s\n", (res ? "valid" : "invalid"));
    res = isPasswordValid("Co_MP");
    printf("Your password is %s\n", (res ? "valid" : "invalid"));
    res = isPasswordValid("CCC!CCCCCC");
    printf("Your password is %s\n", (res ? "valid" : "invalid"));
    res = isPasswordValid("cc!cccccc");
    printf("Your password is %s\n", (res ? "valid" : "invalid"));

    return 0;
}