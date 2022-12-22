#include <stdio.h>
#include "simpio.h"

/*
 * Calculate the cycle length of the hailstone sequence
 * for the given number.
 */
int hailstone (int n) {
    int cyclelength = 0;

    // Loop until n is 1
    while (n != 1) {
        // We have to perform different calculations depending
        // on the current value being even or odd.
        if (n % 2 == 1) {
            // It is odd, so calculate 3n+1
            printf("%d ist ungerade, also nehme man 3n+1 = ", n);
            n = 3 * n + 1;
            printf("%d\n", n);
        } else {
            // It is even, so calculate n/2
            printf("%d ist gerade, also halbiere man: n/2 = ", n);
            n /= 2;
            printf("%d\n", n);
        }
        // Keep track of the cycle length
        cyclelength++;
    }

    // return the determined cycle length
    return cyclelength;
}

/*
 * Start of the program
 */
int main (void) {
    // Fetch input from the user
    printf("Zahl eingeben: ");
    int n = getInteger();
    // Calculate the cycle length
    int cyclelength = hailstone(n);
    // Tell the result
    printf("Ich habe %d Schritte benötigt um 1 zu erreichen\n", cyclelength);

    return 0;
}