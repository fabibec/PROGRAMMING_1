/*
 * Prints a multiplication table up to a given number.
 * Author: Florian Heinz <florian.heinz@oth-regensburg.de>
 */

// Set the maximum number here
#define N 15

#include <stdio.h>

/*
 * printNumbers prints the numbers inside the multiplication table
 * Parameter: limit - upper limit of each factor (i.e. number of cols/rows)
 * Return value: none
 */
void printNumbers (int limit) {
    for (int row = 1; row <= limit; row++) {
        for (int col = 1; col <= limit; col++) {
            printf("%5d", row*col);
        }
        printf("\n");
    }
}

/*
 * printHeader prints the header of the multiplication table.
 * Parameter: limit - upper limit of each factor.
 * Return value: none
 */
void printHeader (int limit) {
    printf("=================================================\n");
    printf("    Multiplication table for numbers up to %d:\n", limit);
    printf("=================================================\n");
}

/*
 * Prints the whole multiplication table (header and numbers).
 * Parameter: limit - upper limit of each factor.
 * Return value: none
 */
void printTable (int limit) {
    printHeader(limit);
    printNumbers(limit);
}

/*
 * Entry point of the program
 */
int main (void) {
    printTable(N);

    return 0;
}