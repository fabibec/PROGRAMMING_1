//
// Created by becke on 21.10.2022.
//
#include "simpio.h"
#include <stdio.h>


enum weekdays {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

int main (void) {
    int number = getInteger() - 1;
    if (number == SUNDAY) {
        printf("Es is Sonntag\n");
    }
    return 0;
}