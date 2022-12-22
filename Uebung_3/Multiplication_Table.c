#include <stdio.h>
#include <math.h>

char* BORDER = "====================================================\n";
int UPPER_BOUND = 12;
int PROGRAM_EXIT = 0;
int SPACE = 5;


void print_multiplication_table(int up_to);
void print_multiplication_row(int row, int bound);
int length_of_num(int num);

int main (void) {
    printf(BORDER);
    printf("    Multiplication table for numbers up to %d\n", UPPER_BOUND);
    printf(BORDER);
    print_multiplication_table(UPPER_BOUND);
    return PROGRAM_EXIT;
}

/**
 * Calculates the length of a number
 * @param num the number you want the length
 * @return length of number
 */
int length_of_num(int num) {
    int length = floor(log10(num));
    length++;
    return length;
}

/**
 * Prints an amount of spaces dependent on how long your number is
 * @param number 7Spaces - the length of this number will be printed
 */
void print_spaces(int number) {
    int num_of_spaces = SPACE - length_of_num(number);
    for (int i = 0; i < num_of_spaces; i++) {
        printf(" ");
    }
}

/**
 * Prints the Multiplication Table upto a specific number
 * @param up_to number you want the table to be printed up to
 */
void print_multiplication_table(int up_to) {
    for (int i = 1; i <= up_to; i++) {
        print_multiplication_row(i,up_to);
    }
}

/**
 * Prints the individual rows of the multiplication table
 * Is called by the print_multiplication_row() function
 * @param row the current row of the table
 * @param bound the number you want the table to be printed up to
 */
void print_multiplication_row(int row, int bound) {
    for (int i = 1; i <= bound; i++) {
        printf("%d", (i * row));
        print_spaces((i * row));
    }
    printf("\n");
}