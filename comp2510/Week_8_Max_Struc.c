#include <stdio.h>
#include <stdlib.h>

struct arrayWithSize {
    int *elements;
    int size;
};

int findMaxElement(struct arrayWithSize array) {
    if (array.size == 0) {
        perror("Empty array passed to findMaxElement");
        exit(1);
    }

    int firstElement = *(array.elements);
    if (array.size == 1) {
        return firstElement;
    }

    struct arrayWithSize arrayWithoutFirstElement;
    arrayWithoutFirstElement.elements = array.elements + 1;
    arrayWithoutFirstElement.size = array.size - 1;
    int max = findMaxElement(arrayWithoutFirstElement);
    return (max > firstElement) ? max : firstElement;
}

int main() {
    int elements[] = {1, 2, 10, 7, 3};
    struct arrayWithSize array = {elements, 5};
    printf("Max = %d\n", findMaxElement(array));
    return 0;
}
