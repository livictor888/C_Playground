#include <stdio.h>
#include <stdbool.h>

bool isLetter(int c) {
    return (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z');
}

void printMap(int *map) {
    for (int c = 'A'; c <= 'z'; c++) {
        if (map[c] && isLetter(c)) {
            printf("%c: %d\n", c, map[c]);
        }
    }
}

void printLettersOfAlphabetFrequencyInString(char *input) {
    //creates a map of size 'z', chars have integer values
    int map['z' + 1]  = {0};
    while (*input) {
        map[*input]++;
        input++;
    }
    printMap(map);
}

int main() {
    printLettersOfAlphabetFrequencyInString("Seyed PRO123456 @![] seyed masterz");
    return 0;
}