#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct point {
    int x;
    int y;
    int z;
};

struct date {
    int day;
    int month;
    int year;
};

bool isFirstDateLaterThanSecondDate(struct date firstDate, struct date secondDate) {
    if (firstDate.year > secondDate.year) {
        return true;
    } else if (firstDate.year < secondDate.year) {
        return false;
    }

    if (firstDate.month > secondDate.month) {
        return true;
    } else if (firstDate.month < secondDate.month) {
        return false;
    }

    if (firstDate.day > secondDate.day) {
        return true;
    } else {
        return false;
    }
}

int calculateTotalDaysFromDate(struct date inputDate) {
    return inputDate.year * 365 + inputDate.month * 30 + inputDate.day;
}

int numberOfDaysBetweenTwoDates(struct date firstDate, struct date secondDate) {
    int numberOfDaysForFirstDate = calculateTotalDaysFromDate(firstDate);
    int numberOfDaysForSecondDate = calculateTotalDaysFromDate(secondDate);

    return abs(numberOfDaysForFirstDate - numberOfDaysForSecondDate);
}

int main() {
    struct point firstPoint = {1, 2, 3};
    printf("Sizeof(firstpoint) = %zu\n", sizeof(firstPoint));

    struct date firstDate = {10, 10, 2020};
    struct date secondDate = {5, 1, 2021};
    printf("Is 10/10/2020 later than 05/01/2021: %d\n", isFirstDateLaterThanSecondDate(firstDate, secondDate));
    printf("The gap between 10/10/2020 and 05/01/2021 is: %d days\n", numberOfDaysBetweenTwoDates(firstDate, secondDate));
    return 0;
}