//
// Created by becke on 02.11.2022.
//
#include <stdio.h>

int main (void) {
    char c = "d", d = "s";
    char *p1 = &c;
    char *p2 = &d;
    printf("%i",*p2);
    return 0;
}