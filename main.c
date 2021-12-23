#include <stdio.h>

struct point {
    int x;
    int y;
    int z;
};

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


void printString(void *data) {
    char **arrayOfStrings = (char **)data;
    char *string = *(arrayOfStrings + 1);
    char character = *string;

    printf("%s\n", string);
    printf("%c\n", character);
}

void mysteryFunction(int * firstPointer, int * secondPointer) {
    int *temp = firstPointer;
    firstPointer = secondPointer;
    secondPointer = temp;
    *temp = 3;
}


int main(int argc, char *argv[]) {

    int first = 1, second = 2;
    mysteryFunction(&first, &second);
    printf("First: %d, Second: %d\n", first, second);

//    char * strings[] = {"hello", "world"};
//    printString(strings);

////    char *inputFileName = argv[1];
////    char *outputFileName = argv[2];
////
////    copyFile(inputFileName, outputFileName);
//    int map[100] = {0, 1, 2, 3};
//    for (int i = 0; i < 100; i++) {
//        printf("%d\n", map[i]);
//    }
//
//
//    struct point p;
//    p.x = 10;
//    p.y = -3;
//    p.z = 2;
//    printf("sizeof(p) = %zu\n", sizeof(p));
    return 0;
}