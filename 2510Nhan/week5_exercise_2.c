#include "stdio.h"
#include "stdbool.h"
#include "string.h"

bool createFile(char * fileName, char * content) {
    FILE *file;
    file = fopen(fileName, "w");

    if (file == NULL) {
        printf("Could not open file");
        return false;
    }

    fprintf(file, "%s\n", content);
    fclose(file);
    return true;
}

bool readFile(char * fileName, char storage[1000]) {
    FILE *file;
    file = fopen(fileName, "r");

    if (file == NULL) {
        printf("Could not open file");
        return false;
    }

    char line[1000];
    strcpy(line, "");
    while(fgets(line, 1000, file) != NULL) {
        strcat(storage, line);
    }

    fclose(file);
    return true;
}

int countChar(char * fileName) {
    FILE *file;
    file = fopen(fileName, "r");

    if (file == NULL) {
        printf("Could not open file");
        return false;
    }

    int count = 0;
    while(fgetc(file) != EOF) {
        count++;
    }
    return count;
}

int main() {
    createFile("./test.txt", "Hello World\nNew World\nIs\tComming");

    char storage[1000];
    strcpy(storage, "");
    readFile("./test.txt", storage);
    printf("%s\n", storage);
    printf("%d\n", countChar("./test.txt"));
}