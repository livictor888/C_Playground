#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// need to have all the parenthesis
#define IS_POWER_OF_TWO(x) ((((x) - 1) & (x)) == 0)
#define IS_POWER_OF_TWO_BAD(x) ((x - 1) & x) == 0

int main() {
    printf("%d\n", IS_POWER_OF_TWO(16) + 1);
    printf("%d\n", IS_POWER_OF_TWO_BAD(16) + 1);
    printf("%d\n", ((16 - 1) & 16) == 0);
    return 0;
}
