//
// Created by becke on 26.10.2022.
//
#include <stdio.h>
#include "simpio.h"

int number;
int steps;

int main (void) {
    // Get User input until valid number is entered
    do {
        printf("Please input a positive decimal-number");
        number = getInteger();
    }
    while (number <= 0);

    steps = 0;

    //Do Hailstone Puzzle
    while (number > 1) {
        if (number % 2 == 0) {
            int new_number = number / 2;
            printf("%d\tis even, so divide by 2:\t %d\n", number, new_number);
            number = new_number;
        } else {
            int new_number = 3 * number + 1;
            printf("%d\tis uneven, so do 3n+1:\t %d\n", number, new_number);
            number = new_number;
        }
        steps++;
    }

    printf("It took %d steps to reach the number 1", steps);
    return 0;
}