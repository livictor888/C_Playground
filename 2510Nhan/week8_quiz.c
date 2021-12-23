#include <stdio.h>
#include <stdbool.h>

#define ALPHABET_MAP_SIZE 'z' + 1

bool isAlphabetCharacter(char character) {
    return (character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'z');
}

void printMap(int *map) {
    // Change the variable name to character better explaining than c
    for (int character = 'A'; character < ALPHABET_MAP_SIZE; character++) {
        // Wrong logic in checking the alphabet range of letter previously (c <= 'Z' || c >= 'a')
        // But we already check it when we construct the map, so we can get rid of it.
        // We only need to check the frequency is > 0 or not to print out.
        if (map[character]) {
            printf("%c: %d\n", character, map[character]);
        }
    }
}

void printLettersOfAlphabetFrequencyInString(char *input) {
    // Recall that characters have integer values.
    // Wrong size map previously, it did not contain character 'z'
    int map[ALPHABET_MAP_SIZE] = {0};

    while (*input) {
        // Wrong order of ++ and input. Previously, it is map[*++input]++
        // It should be map[*input++]++. But better to separate and add logic
        // check to avoid unnecessary counting for non-alphabet characters
        if (isAlphabetCharacter(*input)) {
            map[*input]++;
        }
        input++;
    }

    printMap(map);
}

int main() {
    printLettersOfAlphabetFrequencyInString("^.Seyed was here.[]!!!!");

    // Missing the return 0 statement in main previously
    return 0;
}
