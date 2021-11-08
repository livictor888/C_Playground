#include <stdio.h>
#include <stdbool.h>

bool isLetter(int letter) {
    // ignore symbols just print out the count for A-Z and a-z
    return (letter >= 'A' && letter <= 'Z' || letter >= 'a' && letter <= 'z');
}

void printMap(int *map) {
    // change one letter variables for better readability
    for (int letter = 'A'; letter <= 'z'; letter++) {
        // incorrect character checking, refactored part of the if statement into a function
        if (map[letter] && isLetter(letter)) {
            printf("%c: %d\n", letter, map[letter]);
        }
    }
}

void printLettersOfAlphabetFrequencyInString(char *input) {
    // Recall that characters have integer values.
    // +1 to include 'z'
    int map['z' + 1] = {0};

    while (*input) {
        // increment the value at the character's ascii value index
        // then check the next character in the string
        // if the pointer is pointing to 'z', then map[122]++
        map[*input]++;
        input++;
    }
    printMap(map);
}

int main() {
    printLettersOfAlphabetFrequencyInString(".Seyed was here.");
    //missing return for main function
    return 0;
}
