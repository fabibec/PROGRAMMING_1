#include <stdio.h>

void swapEnds (int a[], int size);
void printArray (int a[], int size);

int main (void) {
    int test1[] = {1,2,3,4};
    int test1size = sizeof test1 / sizeof test1[0];
    int test2[] = {1};
    int test2size = 1;

    printf("--Test 1--\n");
    printf("Array before\n");
    printArray(test1, test1size);
    swapEnds(test1, test1size);
    printf("Swapped Array\n");
    printArray(test1, test1size);

    printf("\n");

    printf("--Test 2--\n");
    printf("Array before\n");
    printArray(test2, test2size);
    swapEnds(test2, test2size);
    printf("Swapped Array\n");
    printArray(test2, test2size);

    return 0;
}

void swapEnds(int a[], int size) {
    if (size != 1) {
        int buffer = a[0];
        a[0] = a[size - 1];
        a[size - 1] = buffer;
    }
}

void printArray (int a[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
