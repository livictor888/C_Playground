#include <stdio.h>
#include <stdbool.h>

#define MASK_TO_TURN_ON_SECOND_AND_THIRD_BIT (0b0110)
#define MASK_TO_TURN_OFF_FOURTH_BIT (~0b1000)

int thirdBitFromRight(int n) {
    if ((n & 4) == 0) {
        return 0;
    }
    return 1;
}

int turnOnThirdBitFromRight(int n) {
    return n | 4;
}

bool isAllUpperCase(char *string) {
    return !*string ||
           (((*string >= 'A' && *string <= 'Z') || *string == ' ') &&
            isAllUpperCase(string + 1));
}

int turnOnFirstAndThirdBinary(int n) {
    return n | 5;
}

int bitFun(int number) {
    return (number | MASK_TO_TURN_ON_SECOND_AND_THIRD_BIT) & MASK_TO_TURN_OFF_FOURTH_BIT;
}

int main() {
    printf("Third bit from right of %d is %d\n", 5, thirdBitFromRight(5));
    printf("Third bit from right of %d is %d\n", 10, thirdBitFromRight(10));

    printf("Third bit is on from right of %d is %d\n", 5, turnOnThirdBitFromRight(5));
    printf("Third bit is on from right of %d is %d\n", 10, turnOnThirdBitFromRight(10));

    printf("Is string %s all upper? %d\n", "Seyed", isAllUpperCase("Seyed"));
    printf("Is string %s all upper? %d\n", "SEYED HELLO", isAllUpperCase("SEYED HELLO"));
    printf("Is string %s all upper? %d\n", "SEYED HELLo", isAllUpperCase("SEYED HELLo"));

    printf("Turn on 1st and 3rd from right of %d is %d\n", 8, turnOnFirstAndThirdBinary(8));
    printf("Turn on 1st and 3rd from right of %d is %d\n", 0, turnOnFirstAndThirdBinary(0));
    printf("Turn on 1st and 3rd from right of %d is %d\n", 17, turnOnFirstAndThirdBinary(17));
    printf("Turn on 1st and 3rd from right of %d is %d\n", 29, turnOnFirstAndThirdBinary(29));

    printf("Turn on 2nd and 3rd, and off 4th from right of %d is %d\n", 9, bitFun(9));
    printf("Turn on 2nd and 3rd, and off 4th from right of %d is %d\n", 0, bitFun(0));
    printf("Turn on 2nd and 3rd, and off 4th from right of %d is %d\n", 17, bitFun(17));
    printf("Turn on 2nd and 3rd, and off 4th from right of %d is %d\n", 31, bitFun(31));
    return 0;
}