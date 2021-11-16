#include <stdio.h>

void outsideFunction(int number) {
    printf("This is from the outside function. The input is: %d\n", number);
}

void functionRunner(int number, void (*someFunctionPointer)(int)) {
    someFunctionPointer(number);
    printf("This is from the function runner.");
}

int main() {
    int numberInput = 1;
    functionRunner(numberInput, outsideFunction);
    return 0;
}