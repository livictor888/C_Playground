#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILE_NOT_FOUND_ERROR_CODE 1
#define MAX_OUTPUT_SIZE 100

void mapCharactersUsingFile(char *fileName, char *input, char *output) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        perror("File not found");
        exit(FILE_NOT_FOUND_ERROR_CODE);
    }
    strcpy(output, input);
    char *startOfOutputPointer = output;
    char mapKey;
    char mapValue;
    while (fscanf(file, "%c %c\n", &mapKey, &mapValue) == 2) {
        while (*output) {
            if (*output == mapKey) {
                *output = mapValue;
            }
            output++;
        }
        output = startOfOutputPointer;
    }
    fclose(file);
}

int main() {
    char *fileName = "lab8.txt";
    char input1[] = "Seyed";
    char input2[] = "Adam's name.";
    char input3[] = "Ascend";

    char output1[MAX_OUTPUT_SIZE];
    char output2[MAX_OUTPUT_SIZE];
    char output3[MAX_OUTPUT_SIZE];

    mapCharactersUsingFile(fileName, input1, output1);
    mapCharactersUsingFile(fileName, input2, output2);
    mapCharactersUsingFile(fileName, input3, output3);

    printf("The input is: %s\nThe output is: %s\n", input1, output1);
    printf("The input is: %s\nThe output is: %s\n", input2, output2);
    printf("The input is: %s\nThe output is: %s\n", input3, output3);

    return 0;
}