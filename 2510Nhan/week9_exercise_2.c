#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int askingForValue(int *value) {
    printf("Please enter an integer number: ");
    scanf("%d", value);
}

void example() {
    int currentSize = 5;
    int *elements = (int *) malloc(currentSize * sizeof(int));
    int *originElements = elements;
    if (elements == NULL) {
        perror("Somethings wrong OOM!");
        exit(1);
    }

    int index = 0;
    int currentValue = 0;

    askingForValue(&currentValue);
    *(elements + index) = currentValue;
    index++;

    while (currentValue >= 0) {
        if (index == currentSize) {
            elements = (int *) realloc(originElements, currentSize * 2 * sizeof(int));
            if (elements == NULL) {
                perror("Somethings wrong OOM!");
                exit(1);
            }
            originElements = elements;
            currentSize = currentSize * 2;
            printf("Increased stack to %d\n", currentSize);
        }
        askingForValue(&currentValue);
        *(elements + index) = currentValue;
        index++;
    }

    for (int i = 0; i < index - 1; i++) {
        printf("%d ", *(elements + i));
    }
    printf("\n");
}


int main() {
    char *string = (char *) malloc(21 * sizeof(char));
    strcat(string, "12345678901234567890");
    printf("String : %s\n", string);
    example();
    return 0;
}