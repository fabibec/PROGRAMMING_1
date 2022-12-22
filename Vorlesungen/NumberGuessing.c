//
// Während Vorlesung 6 am 21.10.2022
//
#include <stdio.h>
#include "simpio.h"
#include "random.h"

int main (void) {
    int number = randomInteger(0,100);
    while (1)
    {
        printf("Bitte raten: \n");
        int input = getInteger();

        if (number == input) {
            printf("Richtig!\n");
            break;
        } else {
            if (input > number) {
                printf("Zu Gross!\n");
            } else {
                printf("Zu klein!\n");
            }
        }
    }
    return 0;
}