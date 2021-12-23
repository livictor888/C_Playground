#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int func2int(int a, int b, int (*func)(int, int)) {
    return func(a, b);
}

char *strFunc1(char *input, char *output) {
    *output = 0;
    strcat(output, input);
    output[strlen(input)] = '!';
    output[strlen(input) + 1] = 0;
    return output;
}


int main() {
    int a = 10;
    int b = 5;
    int (*p)(int, int) = max;

    printf("Max (%d, %d) = %d\n", a, b, p(a, b));
    printf("Max (%d, %d) = %d\n", a, b, func2int(a, b, max));
    printf("Min (%d, %d) = %d\n", a, b, func2int(a, b, min));

    printf("Max (%d, %d) = %d\n", a, b, func2int(a, b, &max));
    printf("Min (%d, %d) = %d\n", a, b, func2int(a, b, &min));

    char output[100] = {0};
    char *string = "Hello";
    char *(*p1)(char *, char *) = strFunc1;
    printf("%s\n", p1(string, output));
}