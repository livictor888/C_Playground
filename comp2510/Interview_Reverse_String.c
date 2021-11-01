#include <string.h>
#include <stdio.h>

void reverse(char *front, char *end, int length) {
    for (int i = 0; i < length / 2; i++) {
        char toSwap = front[i];
        front[i] = *(end - i);
        *(end - i) = toSwap;
    }
}

int main() {
    char string[9] = "ABCDEFGH";
    reverse(&string[0], &string[7], 8);
    printf("reversed is: %s", string);
    return 0;
}
