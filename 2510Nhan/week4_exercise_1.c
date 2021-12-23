#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef char* String;

bool isSumOfArrayEqualTo(int elements[], int size, int sum) {
    return size == 1 ? (elements[0] == sum) : isSumOfArrayEqualTo(elements, size - 1, sum - elements[size - 1]);
}

bool isPalindrome(int elements[], int size) {
    /**
     * [0, 1, 2, 3, 2, 1, 0]
     *
     * [x]    --> true
     * []     --> true
     * [x, y] --> x == y => true otherwise false
     *
     */
    if (size == 1 || size == 0) {
        return true;
    } else if (size == 2) {
        return elements[0] == elements[1];
    }
    if (elements[0] != elements[size - 1]) {
        return false;
    } else {
        for (int i = 0; i < size - 2; i++) {
            elements[i] = elements[i + 1];
        }
        return isPalindrome(elements, size - 2);
    }
}

void reverseSTR(char * inputString, char *reverse, size_t length) {
    if (*inputString) {
        *(reverse + strlen(inputString) - 1) = *inputString;
        reverseSTR(++inputString, reverse, length);
    } else {
        *(reverse + length) = 0;
    }
}

void reverseString(char * inputString, char *reverse) {
    reverseSTR(inputString, reverse, strlen(inputString));
}

int gcd(int p, int q) {
    if (q == 0) {
        return p;
    } else {
        return gcd(q, p % q);
    }
}

int main() {
//    int elems[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//    printf("%s\n", isSumOfArrayEqualTo(elems, 10, 55) ? "Equal" : "Not Equal");
//
//    int elems2[] = {1, 2, 3, 3, 2, 1};
//    printf("%s\n", isPalindrome(elems2, 6) ? "Palindrome" : "Not Palindrome");

    String str = "Seyed";
    char reverse[6] = "fef";
    reverseString(str, reverse);
    printf("%s\n", reverse);

//    int num1 = 120;
//    int num2 = 110;
//    printf("%d\n", gcd(num1, num2));
//
//    int elem[5] = {20};
//    for (int i = 0; i < 5; i++) {
//        printf("%d\n", elem[i]);
//    }

    char test[3] = "abc";
    for (int i = 0; i < 5; i++) {
        printf("%c\n", test[i]);
    }
}