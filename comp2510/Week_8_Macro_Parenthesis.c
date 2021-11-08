#include <stdio.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int main() {
    int x = 5;
    int y = 10;
    printf("max = %d\n", max(x++, y--));
    printf("x = %d, y = %d\n", x, y);
    return 0;
}