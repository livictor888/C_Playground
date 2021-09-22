#include "stdio.h"

char *removeLeadingSpaces(char *inputString) {
    while (*inputString == ' ') {
        inputString++;
    }
    return inputString;
}

void printTokens(char *inputString) {
    char *inputStringNoLeadingSpace = removeLeadingSpaces(inputString);

    while (*inputStringNoLeadingSpace) {

            if (*inputStringNoLeadingSpace != ' ') {
                printf("%c", *inputStringNoLeadingSpace);
                inputStringNoLeadingSpace++;
            } else {

                while(*inputStringNoLeadingSpace == ' ') {
                    inputStringNoLeadingSpace++;
                }
                printf("\n");
            }
    }
    printf("\n");
}

int main() {
    char *test1 = "    Hi   there! How is it      going?";
    char *test2 = "Hi     there!";
    char *test3 = "Hi there!   ";

    printf("Test for both leading and trailing spaces:     Hi   there! How is it      going?\n");
    printTokens(test1);

    printf("Test for leading spaces:     Hi     there!\n");
    printTokens(test2);

    printf("Test for trailing spaces:    Hi there!   \n");
    printTokens(test3);

    return 0;
}
