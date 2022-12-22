//
// Created by becke on 19.10.2022.
//
#include <stdio.h>

#define MAX_VALUE 10000

int num = 1;
int prev_num = 1;
int prev_prev_num = 0;

void fib() {
    int fib_num = prev_num + prev_prev_num;
    num = fib_num;
    prev_prev_num = prev_num;
    prev_num = num;
    num = fib_num;
    if (num < MAX_VALUE) {
        printf("%d\n",fib_num);
    }
}

int main (void) {
    printf("%d\n",0);
    while (num < MAX_VALUE) {
        fib();
    }
    return 0;
}