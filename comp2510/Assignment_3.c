/**
 * read student.txt
 * store as a student struct element in an array only if their GPA is greater than 3.9
 * realloc memory as it fills up
 * sort the list by GPA in descending order, if same than sort by name?
 */

#include <stdio.h>
#include <stdlib.h>

#define EXPECTED_NUMBER_OF_ARGUMENTS 1
#define INITIAL_SIZE 5
#define MAX_NAME_LENGTH 50

#define INVALID_NUMBER_OF_ARGUMENTS_CODE 1
#define FILE_NOT_FOUND_CODE 2
#define FAILED_TO_ALLOCATE_MEMORY 3

struct Student {
    char name[MAX_NAME_LENGTH];
    double grade;
};

void storeIntoArray();
// read line from file
int *resizeArrayIfNeeded(int *array, int usedLength, int *arraySize) {
    if (usedLength <= *arraySize) {
        return array;
    }
    printf("resizing..\n");
    *arraySize *= 2; // double the array size
    array = (int *) realloc(array, *arraySize * sizeof(int));
    if (array == NULL) {
        perror("Failed to reallocate memory.");
        exit(FAILED_TO_ALLOCATE_MEMORY);
    }
    return array;
}

void readFile(FILE *file) {

    char name[10];
    float grade = 0;
    int length = 0;
    int size = INITIAL_SIZE;
    //struct Student *array[INITIAL_SIZE];

    int *array = (int *) malloc(size * sizeof(int));

    while (fscanf(file, "%s %f", name, &grade) != EOF) {
        //printf("%s %.3f\n", name, grade);
        length++;
        array = resizeArrayIfNeeded(array, length, &size);


    }

}



void processFile(char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        perror("File not found.");
        exit(FILE_NOT_FOUND_CODE);
    }
    readFile(file);
    fclose(file);
}

void validateNumberOfArguments(int argc) {
    if (argc != EXPECTED_NUMBER_OF_ARGUMENTS + 1) {
        perror("Need exactly 2 arguments");
        exit(INVALID_NUMBER_OF_ARGUMENTS_CODE);
    } else {
        printf("Correct amount of arguments!\n");
    }
}

int main(int argc, char *argv[]) {
    printf("The program name is %s\n", argv[0]);
    validateNumberOfArguments(argc);
    processFile(argv[1]);
    return 0;
}

/*
 * #include <stdlib.h>
#define MEMORY_ALLOCATION_ERROR_CODE 1

void *safe_malloc(size_t n) {
  void *ptr = malloc(n);
  if (ptr == NULL) {
    perror("Failed to allocate memory.");
    exit(MEMORY_ALLOCATION_ERROR_CODE);
  }
  return ptr;
}

 FILE *openFile(char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        perror("Could not open file for reading.\n");
        exit(COULD_NOT_OPEN_FILE_ERROR_CODE);
    }
    return file;
}
 */