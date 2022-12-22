#include "simpio.h"

int main (void) {
    int balance_owed;

    printf("Enter number of dollars owed: ");
    balance_owed = getInteger();

    // Fehler: Einfaches = ist Zuweisung. Der Wert des Ausdrucks
    // entspricht dem zugewiesenen Wert, deswegen ist die if-
    // Bedingung nie erfüllt!
    // if (balance_owed = 0) {
    // Korrekt ist, == als Vergleichsoperator zu verwenden:
    if (balance_owed == 0) {
        printf("You owe nothing\n");
    } else {
        printf("You owe %d dollars.\n", balance_owed);
    }

    return 0;
}