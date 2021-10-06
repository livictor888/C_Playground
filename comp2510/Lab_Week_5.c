#include <stdio.h>

#define MAX_COLUMNS 10

int fromBinary(int *binaryArray, int size) {
    if (size == 0) {
        return 0;
    }
    int number = fromBinary(binaryArray, size - 1);
    return 2 * number + binaryArray[size - 1];
}

void readNextNumberFromFile(FILE *file, int binaryArray[MAX_COLUMNS], int numberOfColumns) {
    for (int currentNumber = 0; currentNumber < numberOfColumns; currentNumber ++) {
        fscanf(file, "%d", &binaryArray[currentNumber]);
    }
    printf("%d\n", fromBinary(binaryArray, numberOfColumns));
}

void processFile(char *fileName) {
    FILE *file = fopen(fileName, "r");
    int numberOfRows;
    int numberOfColumns;
    fscanf(file, "%d %d", &numberOfRows, &numberOfColumns);
    int binaryArray[MAX_COLUMNS];
    for(int row = 0 ;row < numberOfRows; row++) {
        readNextNumberFromFile(file, binaryArray, numberOfColumns);
    }
    fclose(file);
}

int main() {
    char *fileName = "text.txt";
    processFile(fileName);
    return 0;
}