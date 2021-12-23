#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ARRAY_SIZE 1000

#define BAD_INPUT_ERROR_CODE 1
bool mystery(int x) {
    if (x <= 0) {
        perror("x needs to be at least 1.");
        exit(BAD_INPUT_ERROR_CODE);
    }
    return ((x - 1) & x) == 0;
}


int midpoint_bad(int x, int y) {
    return (x + y) / 2;
}

int midpoint_better(int x, int y) {
    return x + ((y - x) / 2);
}

int midpoint_knuth(int x, int y) {
    return (x & y) + ((x ^ y) >> 1);
}



int main() {
//    for (int x = 1; x <= 10; x++) {
//        printf("%d\n", mystery(x));
//    }

    printf("midpoint_bad of 2147483647 and 1 is: %d\n", midpoint_bad(2147483647,  1));
    printf("midpoint_better of 2147483647 and 1 is: %d\n", midpoint_better(1,  -2147483648));
    printf("midpoint_better of 2147483647 and 1 is: %d\n", midpoint_knuth(2147483647,  1));
    printf("midpoint_better of 2147483647 and 1 is: %d\n", midpoint_knuth(-5,  -11));
    return 0;
}