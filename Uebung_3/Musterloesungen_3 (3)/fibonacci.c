/*
 * Prints the fibonacci sequence up to a defined number.
 * Author: Florian Heinz <florian.heinz@oth-regensburg.de>
 */

#define MAX_VALUE 10000

#include <stdio.h>

/*
 * printFibonacci prints the fibonacci sequence up to a defined
 * maximum value.
 * Return value: none
 */
void printFibonacci (void) {
    int f0 = 0, f1 = 1;

    while (f0 < MAX_VALUE) { // Did we already reach the maximum number?
        // Output the current value
        printf("%d\n", f0);
        // Calculate the next value in the sequence
        int f2 = f0 + f1;
        // Shift one old value out
        f0 = f1;
        f1 = f2;
    }
}

/*
 * Entry point of the program.
 */
int main (void) {
    printFibonacci();

    return 0;
}
