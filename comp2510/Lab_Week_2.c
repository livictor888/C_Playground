#include <stdio.h>
#include <stdbool.h>

void printMultiplicationTable() {
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            printf("%d\t ", i*j);
        }
        printf("\n");
    }
}

bool isPalindrome(int elements[], int size) {
    if (size == 1 || size == 0) {
        return true;
    }
    for (int i = 0; i < size/2; i++) {
        if (elements[i] != elements[size-1-i]) {
            return false;
        }
    }
    return true;
}

int main() {
    printMultiplicationTable();

    int emptyArray[] = {};
    int singleElementArray[] = {1};
    int evenNumberOfElements[] = {1, 2, 2, 1};
    int oddNumberOfElements[] = {1, 2, 2, 5, 2, 2, 1};
    int notPalindromeOdd[] = {1, 2, 3};
    int notPalindromeEven[] = {1, 2, 3, 4};

    bool testEmptyArray = isPalindrome(emptyArray, 0);
    bool testSingleElementArray = isPalindrome(singleElementArray, 1);
    bool testEvenNumberOfElements = isPalindrome(evenNumberOfElements, 4);
    bool testOddNumberOfElements = isPalindrome(oddNumberOfElements, 7);
    bool testNotPalindromeOdd = isPalindrome(notPalindromeOdd, 3);
    bool testNotPalindromeEven = isPalindrome(notPalindromeEven, 4);

    printf("\nTests for isPalindrome:\n");

    printf("{ }: Expected result for an empty array: True\nActual result: ");
    (testEmptyArray) ? printf("True\n") : printf("False\n");

    printf("{1}: Expected result for an array with size 1: True\nActual result: ");
    (testSingleElementArray) ? printf("True\n") : printf("False\n");

    printf("{1, 2, 2, 1}: Expected result for an even palindrome: True\nActual result: ");
    (testEvenNumberOfElements) ? printf("True\n") : printf("False\n");

    printf("{1, 2, 2, 5, 2, 2, 1}: Expected result for an odd palindrome: True\nActual result: ");
    (testOddNumberOfElements) ? printf("True\n") : printf("False\n");

    printf("{1, 2, 3}: Expected result for an even array that is not a palindrome: False\nActual result: ");
    (testNotPalindromeEven) ? printf("True\n") : printf("False\n");

    printf("{1, 2, 3, 4}: Expected result for an odd array that is not a palindrome: False\nActual result: ");
    (testNotPalindromeOdd) ? printf("True\n") : printf("False\n");

    return 0;
}
