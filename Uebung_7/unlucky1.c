#include <stdio.h>

int unlucky1 (int a[], int size);
void printArray (int a[], int size);

int main (void) {
    int test1[] = {1,3,4,5};
    int test1size = sizeof test1 / sizeof test1[0];
    int test2[] = {1,1,1,4,3,1,2};
    int test2size = sizeof test2 / sizeof test2[0];

    printf("--Test 1--\n");
    printf("Array\n");
    printArray(test1, test1size);
    printf("Output\n");
    printf("%d\n", unlucky1(test1,test1size));


    printf("\n");

    printf("--Test 2--\n");
    printf("Array\n");
    printArray(test2, test2size);
    printf("Output\n");
    printf("%d\n", unlucky1(test2,test2size));

    return 0;
}

int unlucky1(int a[], int size) {
    int oneBefore = 0;
    int val = 0;

    for (int i = 0; i < size; i++) {
        if (oneBefore) {
            if (a[i] == 3) {
                val = 1;
                break;
            }
            if (a[i] != 1) {
                oneBefore = 0;
            }
        }
        else if (a[i] == 1){
            oneBefore = 1;
        }
    }
    return val;
}

void printArray (int a[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
