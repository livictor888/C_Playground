/**
 * read student.txt
 * store as a student struct element in an array only if their GPA is greater than 3.9
 * reallocate memory as it fills up
 * sort the list by GPA in descending order, if same than sort by name?
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EXPECTED_NUMBER_OF_ARGUMENTS 1
#define INITIAL_SIZE 5
#define MAX_NAME_LENGTH 50
#define GPA_THRESHOLD 3.9f

#define INVALID_NUMBER_OF_ARGUMENTS_CODE 1
#define FILE_NOT_FOUND_CODE 2
#define FAILED_TO_ALLOCATE_MEMORY 3

struct Student {
    char name[MAX_NAME_LENGTH];
    float gpa;
};

void printArray(struct Student *arrayOfStudents, int length) {
    // sort the students by GPA
    for (int i = 0; i < length; i++) {
        printf("name: %s gpa: %.3f\n", arrayOfStudents[i].name, arrayOfStudents[i].gpa);
    }
}
struct Student *resizeArrayIfNeeded(struct Student *array, int usedLength, int *arraySize) {
    if (usedLength < *arraySize) {
        return array;
    }
    printf("resizing..\n");
    *arraySize *= 2; // double the array size
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
        //printf("%s %.3f\n", name, gpa);
        if (gpa >= GPA_THRESHOLD) {
            arrayOfStudents = resizeArrayIfNeeded(arrayOfStudents, length + 1, &size); // check first
            strcpy(currentStudent.name, name);
            currentStudent.gpa = gpa;
            arrayOfStudents[length] = currentStudent;
            length++;
        }
    }
    printArray(arrayOfStudents, length);
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