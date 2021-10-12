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
    char *inputFileName = argv[1];
    char *outputFileName = argv[2];

    copyFile(inputFileName, outputFileName);

    return 0;
}