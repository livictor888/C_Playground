#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define MAX_NUMBER_OF_CHAR 255
#define FILE_NOT_FOUND_ERROR_CODE 2

void transformString(int transformMap[MAX_NUMBER_OF_CHAR], char *inputString, char *outputString) {
    while (*inputString) {
        if (transformMap[*inputString] > 0) {
            *outputString = (char) transformMap[*inputString];
        } else {
            *outputString = *inputString;
        }
        outputString++;
        inputString++;
    }
    *outputString = 0;
}

void scanTransformMap(FILE *file, int transformMap[MAX_NUMBER_OF_CHAR]) {
    char firstChar = 0;
    char secondChar = 0;
    while (fscanf(file, "%c %c\n", &firstChar, &secondChar) == 2) {
        transformMap[firstChar] = (int) secondChar;
    }
}

void mapCharactersUsingFile(char *fileName, char *input, char *output) {
    FILE *file;
    file = fopen(fileName, "r");

    if (file == NULL) {
        perror("Could not open file");
        exit(FILE_NOT_FOUND_ERROR_CODE);
    }

    int transformMap[MAX_NUMBER_OF_CHAR] = {0};
    scanTransformMap(file, transformMap);
    transformString(transformMap, input, output);

    fclose(file);
}

int main() {
    char filename[] = "input.txt";
    char outputString[MAX_NUMBER_OF_CHAR] = "";

    mapCharactersUsingFile(filename, "Seyed", outputString);
        printf("%s\n", outputString);

    mapCharactersUsingFile(filename, "Adam’s name.", outputString);
    printf("%s\n", outputString);

    mapCharactersUsingFile(filename, "Ascend.", outputString);
    printf("%s\n", outputString);

    return 0;
}
