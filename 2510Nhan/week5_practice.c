#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void transformStringToUpper(char * input, char * output) {
    if (!*input) {
        *output = 0;
        return;
    }

    if (*input == ' ') {
        return transformStringToUpper(++input, output);
    }

    if (*input >= 'a' && *input <= 'z') {
        *output = (char) (*input - ('a' - 'A'));
    } else {
        *output = *input;
    }

    transformStringToUpper(++input, ++output);
}

void transformStringToLower(char * input, char * output) {
    if (!*input) {
        *output = 0;
        return;
    }

    if (*input == ' ') {
        return transformStringToLower(++input, output);
    }

    if (*input >= 'A' && *input <= 'Z') {
        *output = (char) (*input + ('a' - 'A'));
    } else {
        *output = *input;
    }

    transformStringToLower(++input, ++output);
}

void transformStringInverse(char * input, char * output) {
    if (!*input) {
        *output = 0;
        return;
    }

    if (*input == ' ') {
        return transformStringInverse(++input, output);
    }

    if (*input >= 'A' && *input <= 'Z') {
        *output = (char) (*input + ('a' - 'A'));
    } else if (*input >= 'a' && *input <= 'z') {
        *output = (char) (*input - ('a' - 'A'));
    } else {
        *output = *input;
    }

    transformStringInverse(++input, ++output);
}

void transformTitleCase(char * input, char * output, bool startOfWord) {
    if (!*input) {
        *output = 0;
        return;
    }

    if (*input == ' ') {
        return transformTitleCase(++input, output, true);
    }

    if (startOfWord && *input >= 'a' && *input <= 'z') {
        *output = (char) (*input - ('a' - 'A'));
    } else if (*input >= 'A' && *input <= 'Z') {
        *output = (char) (*input + ('a' - 'A'));
    } else {
        *output = *input;
    }

    transformTitleCase(++input, ++output, false);
}

void transformStringTitleCase(char * input, char * output) {
    transformTitleCase(input, output, true);
}

int countUpperCaseLetter(char * input) {
    return !*input ? 0 : ((*input >= 'A' && *input <= 'Z') ? 1 : 0) + countUpperCaseLetter(input + 1);
}


int main() {
    char * input = "hI thERE, My nAMe  IS aDAM";
    char result[200] = "";
    transformStringToUpper(input, result);
    char result2[200] = "";
    transformStringToLower(input, result2);
    char result3[200] = "";
    transformStringInverse(input, result3);
    char result4[200] = "";
    transformStringTitleCase(input, result4);

    printf("%s\n", result);
    printf("%s\n", result2);
    printf("%s\n", result3);
    printf("%s\n", result4);
    printf("%d\n", countUpperCaseLetter(" hI thERE, My nAMe  IS aDAM      "));
    return 0;
}