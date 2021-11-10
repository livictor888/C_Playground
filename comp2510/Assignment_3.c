#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INVALID_NUMBER_OF_ARGUMENTS_CODE 1
#define FILE_NOT_FOUND_CODE 2
#define FAILED_TO_ALLOCATE_MEMORY 3

#define EXPECTED_NUMBER_OF_ARGUMENTS 1
#define INITIAL_SIZE 5
#define MAX_NAME_LENGTH 50
#define GPA_THRESHOLD 3.9f

struct Student {
    char name[MAX_NAME_LENGTH];
    float gpa;
};

void printArray(struct Student *arrayOfStudents, int length) {
    for (int index = 0; index < length; index++) {
        if (arrayOfStudents[index].gpa > GPA_THRESHOLD) {
            printf("%s %.3f\n", arrayOfStudents[index].name, arrayOfStudents[index].gpa);
        }
    }
}

void swap(struct Student *first, struct Student *second) {
    struct Student temp = *first;
    *first = *second;
    *second = temp;
}

void sort(struct Student *arrayOfStudents, int length) {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (arrayOfStudents[j].gpa < arrayOfStudents[j + 1].gpa) {
                swap(&arrayOfStudents[j], &arrayOfStudents[j + 1]);
            }
        }
    }
    printArray(arrayOfStudents, length);
}

struct Student *resizeArrayIfNeeded(struct Student *array, int usedLength, int *arraySize) {
    if (usedLength < *arraySize) {
        return array;
    }
    *arraySize *= 2;
    array = (struct Student *) realloc(array, *arraySize * sizeof(struct Student));
    if (array == NULL) {
        perror("Failed to reallocate memory.");
        exit(FAILED_TO_ALLOCATE_MEMORY);
    }
    return array;
}

void readFile(FILE *file) {
    char name[MAX_NAME_LENGTH] = {0};
    float gpa = 0;
    int length = 0;
    int size = INITIAL_SIZE;
    struct Student currentStudent;

    struct Student *arrayOfStudents = (struct Student *) malloc(size * sizeof(struct Student));
    if (arrayOfStudents == NULL) {
        perror("Failed to allocate memory.");
        exit(FAILED_TO_ALLOCATE_MEMORY);
    }

    while (fscanf(file, "%s %f", name, &gpa) != EOF) {
        arrayOfStudents = resizeArrayIfNeeded(arrayOfStudents, length + 1, &size); // check first
        strcpy(currentStudent.name, name);
        currentStudent.gpa = gpa;
        arrayOfStudents[length] = currentStudent;
        length++;
    }
    sort(arrayOfStudents, length);
    free(arrayOfStudents);
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
        perror("Wrong number of arguments");
        exit(INVALID_NUMBER_OF_ARGUMENTS_CODE);
    }
}

int main(int argc, char *argv[]) {
    validateNumberOfArguments(argc);
    processFile(argv[1]);
    return 0;
}