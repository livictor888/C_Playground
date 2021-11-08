#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct date {
    int day;
    int month;
    int year;
};

bool isFirstDateAfterSecondDate(struct date firstDate, struct date secondDate) {
    if (firstDate.year < secondDate.year) {
        return false;
    }
    if (firstDate.year > secondDate.year) {
        return true;
    }
    if (firstDate.month < secondDate.month) {
        return false;
    }
    if (firstDate.month > secondDate.month) {
        return true;
    }
    return firstDate.day > secondDate.day;
}

void printDateDelta(struct date firstDate, struct date secondDate) {
    if (!isFirstDateAfterSecondDate(firstDate, secondDate)) {
        return printDateDelta(secondDate, firstDate);
    }
    struct date delta;
    delta.year = firstDate.year - secondDate.year;
    delta.month = firstDate.month - secondDate.month;
    delta.day = firstDate.day - secondDate.day;
    if (delta.day < 0) {
        delta.day += 30;
        delta.month--;
    }
    if (delta.month < 0) {
        delta.month += 12;
        delta.year--;
    }
    printf("Delta = %d years and %d months and %d days\n", delta.year, delta.month, delta.day);
}

int main() {

    return 0;
}
