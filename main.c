#include <stdio.h>

void copyFile(char *inputFileName, char *outputFileName) {
    FILE *inputFile = fopen(inputFileName, "r");
    FILE *outputFile = fopen(outputFileName, "w");
    char copiedChar = (char) fgetc(inputFile);
    while (copiedChar != EOF) {
        printf("%c\n", copiedChar);
        char *pointer = &copiedChar;
        fwrite(pointer, 1, 1, outputFile);
        copiedChar = (char) fgetc(inputFile);
    }
    fclose(inputFile);
    fclose(outputFile);
}

int main(int argc, char *argv[]) {
//    char *inputFileName = argv[1];
//    char *outputFileName = argv[2];
//
//    copyFile(inputFileName, outputFileName);
    int map[100] = {0, 1, 2, 3};
    for (int i = 0; i < 100; i++) {
        printf("%d\n", map[i]);
    }
    return 0;
}