//
// Created by becke on 12.10.2022.
//
#include "stdio.h"

int num1;
int num2;
int num3;
int num4;
int num5;

/**
 * Prints histogram of variable length
 * @param num length of the histogram
 */
void printHistogramm(int num) {
    for (int i = 0; i < num; i++) {
        printf("*");
    }
    printf("\n");
}


int main (void) {
    printf("Please enter five numbers (press Enter for next number):\n");
    scanf( "%i", &num1 );
    scanf( "%i", &num2 );
    scanf( "%i", &num3 );
    scanf( "%i", &num4 );
    scanf( "%i", &num5 );
    printf("Printing histogram:\n");
    printHistogramm(num1);
    printHistogramm(num2);
    printHistogramm(num3);
    printHistogramm(num4);
    printHistogramm(num5);
}

