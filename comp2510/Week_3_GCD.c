#include <stdlib.h>

int gcd(int first, int second) {
    if (first < second) {
        return gcd(second, first);
    }

    if (second == 0) {
        return first;
    }

    return gcd(second, first - second);
}
 int main() {


    gcd(1, 100);
}