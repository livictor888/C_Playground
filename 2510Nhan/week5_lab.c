#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 10
#define ERR_FILE_NOT_FOUND 1

int fromBinary(int * binaryArray, int size) {
    if (size == 0) {
        return 0;
    }

    int number = fromBinary(binaryArray, size - 1);
    return 2 * number + binaryArray[size - 1];
}

void readNextNumberFromFile(FILE * file, int binaryArray[MAX_COLUMNS], int numberOfColumns) {
    for (int j = 0; j < numberOfColumns; j++) {
        fscanf(file, "%d ", &binaryArray[j]);
    }
}

void processFile(char * filename) {
    FILE *file;
    file = fopen(filename, "r");

    if (file == NULL) {
        perror("Could not open file");
        exit(ERR_FILE_NOT_FOUND);
    }

    int numberOfRow;
    int numberOfCol;
    fscanf(file, "%d %d\n", &numberOfRow, &numberOfCol);

    for (int i = 0; i < numberOfRow; i++) {
        int numbers[numberOfCol];
        readNextNumberFromFile(file, numbers, numberOfCol);
        printf("%d\n", fromBinary(numbers, numberOfCol));
    }
}

int main() {
    char * filename = "test.txt";
    processFile(filename);
    return 0;
}