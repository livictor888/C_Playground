#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int getEvenPositionedDigitsV2(int input) {
    if (input < 10 && input > -10) {
        return 0;
    }

    return ((input / 10) % 10) + getEvenPositionedDigitsV2(input / 100) * 10;
}

int getOddPositionedDigits(int input) {
    if (input < 10 && input > -10) {
        return input;
    }

    return (input % 10) + getOddPositionedDigits(input / 100) * 10;
}

int getEvenPositionedDigits(int input) {
    return getOddPositionedDigits(input / 10);
}

int main() {
    printf("%d\n", getEvenPositionedDigitsV2(89201));
    printf("%d\n", getEvenPositionedDigitsV2(-123));
    printf("%d\n", getEvenPositionedDigitsV2(20));
    printf("%d\n", getEvenPositionedDigitsV2(87654321));
}
