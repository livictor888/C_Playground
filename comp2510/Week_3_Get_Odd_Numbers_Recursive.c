// 89201 --> 821
// -123 --> -13

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int getOddPositionedDigits(int input) {
    if (input < 10 && input > -10) {
        return input;
    }
    return (input % 10) + getOddPositionedDigits(input / 100) * 10;
}

int main() {
    printf("%d\n", getOddPositionedDigits(89201));
    printf("%d\n", getOddPositionedDigits(-123));
    printf("%d\n", getOddPositionedDigits(20));
    printf("%d\n", getOddPositionedDigits(87654321));
}