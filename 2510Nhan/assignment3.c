#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define EXPECTED_NUMBER_OF_ARGUMENTS 1
#define MAX_LENGTH_OUTPUT 100
#define MAX_LENGTH_NAME 50
#define MINIMUM_GPA 3.9f
#define INITIAL_SIZE 5

#define ERROR_CODE_INVALID_NUMBER_OF_ARGUMENTS 1
#define ERROR_CODE_FILE_NOT_FOUND 2
#define ERROR_CODE_FAILED_ALLOCATE_MEMORY 3

struct Student {
    char *name;
    float gpa;
};

void printStudentInfo(struct Student *students, size_t size, double minGPA) {
    for (int index = 0; index < size; index++) {
        if ((students + index)->gpa > minGPA) {
            printf("%s %.4f\n", (students + index)->name, (students + index)->gpa);
        }
    }
}

void swapStudent(struct Student *firstStudent, struct Student *secondStudent) {
    struct Student tempStudent = *firstStudent;
    *firstStudent = *secondStudent;
    *secondStudent = tempStudent;
}

void sortByGPA(struct Student *students, size_t size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if ((students + i)->gpa < (students + j)->gpa) {
                swapStudent(students + i, students + j);
            }
        }
    }
}

void checkAllocatedMemory(struct Student *allocatedMemoryPtr) {
    if (allocatedMemoryPtr == NULL) {
        perror("Failed to allocate memory");
        exit(ERROR_CODE_FAILED_ALLOCATE_MEMORY);
    }
}

struct Student *resizeListOfStudentsIfNeeded(struct Student *students,
                                             unsigned long *currentSize, unsigned long usedSize) {
    if (usedSize <= *currentSize) {
        return students;
    }

    *currentSize *= 2;
    struct Student *allocatedList = (struct Student *) realloc(students, *currentSize * sizeof(struct Student));
    checkAllocatedMemory(allocatedList);
    return allocatedList;
}

struct Student *importStudentsFromFile(FILE *file, int *numberOfStudent) {
    unsigned long currentSize = INITIAL_SIZE;
    struct Student *students = (struct Student *) malloc(currentSize  * sizeof(struct Student));
    checkAllocatedMemory(students);

    *numberOfStudent = 0; // Reset counter back to zero
    char name[MAX_LENGTH_NAME] = {0};
    float gpa = 0.0f;
    while (fscanf(file, "%s %f\n", name, &gpa) == 2) {
        students = resizeListOfStudentsIfNeeded(students, &currentSize, *numberOfStudent + 1);
        struct Student newStudent = {strdup(name), gpa};
        *(students + *numberOfStudent) = newStudent;
        (*numberOfStudent)++;
    }

    return students;
}

void freeMemory(struct Student *students, size_t size) {
    for (int index = 0; index < size; index++) {
        free((students + index)->name);
    }
    free(students);
}

void sortAndPrintListOfStudentsByGPA(char *filename, double minGPA) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("File not found");
        exit(ERROR_CODE_FILE_NOT_FOUND);
    }

    int numberOfStudent = 0;
    struct Student *students = importStudentsFromFile(file, &numberOfStudent);
    sortByGPA(students, numberOfStudent);
    printStudentInfo(students, numberOfStudent, minGPA);

    freeMemory(students, numberOfStudent);
    fclose(file);
}

void validateNumberOfArguments(int argc) {
    if (argc != (EXPECTED_NUMBER_OF_ARGUMENTS + 1)) {
        char error[MAX_LENGTH_OUTPUT];
        sprintf(error, "Need exactly %d arguments.", EXPECTED_NUMBER_OF_ARGUMENTS);
        perror(error);
        exit(ERROR_CODE_INVALID_NUMBER_OF_ARGUMENTS);
    }
}

int main(int argc, char *argv[]) {
    validateNumberOfArguments(argc);
    sortAndPrintListOfStudentsByGPA(argv[1], MINIMUM_GPA);

    return 0;
}
