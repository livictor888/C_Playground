#include "stdio.h"
#include "stdbool.h"
#include "string.h"

bool isStartWith(char * inputString, char * needles) {
    if (!*needles) {
        return true;
    } else if (!*inputString) {
        return false;
    }

    if (*inputString == *needles) {
        return isStartWith(++inputString, ++needles);
    }
    return false;
}

bool doesContain(char * inputString, char * needles, int curCheckPos) {
    if (curCheckPos >= strlen(needles)) {
        return true;
    } else if (!*inputString) {
        return false;
    }

    if (*inputString == *(needles + curCheckPos)) {
        return doesContain(++inputString, needles, curCheckPos + 1);
    } else if (curCheckPos != 0) {
        return doesContain(inputString, needles, 0);
    } else {
        return doesContain(++inputString, needles, 0);
    }
}

void askForTwoStrings(char * inputString, char * needles) {
    printf("Enter first string: ");
    scanf(" %s", inputString);
    printf("Enter second string: ");
    scanf(" %s", needles);
}

int main() {
    char firstString[10];
    char secondString[10];
    askForTwoStrings(firstString, secondString);
    printf("%s\n", isStartWith(firstString, secondString) ? "Yes" : "No");
    printf("%s\n", doesContain(firstString, secondString, 0) ? "Yes" : "No");

    return 0;
}