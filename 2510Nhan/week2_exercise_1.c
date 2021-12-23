#include <stdio.h>

void increaseOne(int *num) {
    *num += 1;
}

int main() {
    int num = 10;
    printf("Value before increase %d\n", num);
    increaseOne(&num);
    printf("Value after increase %d\n", num);
}