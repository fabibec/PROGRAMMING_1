#include <stdio.h>

int lucky13 (int a[], int size);
void printArray (int a[], int size);

int main (void) {
    int test1[] = {0,2,4};
    int test1size = sizeof test1 / sizeof test1[0];
    int test2[] = {1,2,3};
    int test2size = sizeof test2 / sizeof test2[0];

    printf("--Test 1--\n");
    printf("Array\n");
    printArray(test1, test1size);
    printf("Output\n");
    printf("%d\n", lucky13(test1,test1size));


    printf("\n");

    printf("--Test 2--\n");
    printf("Array\n");
    printArray(test2, test2size);
    printf("Output\n");
    printf("%d\n", lucky13(test2,test2size));

    return 0;
}

int lucky13(int a[], int size) {
    int contains1 = 0;
    int contains3 = 0;
    int returnval = 0;

    for(int i = 0; i < size; i++) {
        if (!returnval) {
            switch (a[i]) {
                case 1:
                    contains1 = 1;
                    break;
                case 3:
                    contains3 = 1;
                    break;
            }
            returnval = (contains1 && contains3);
        }
        else {
            break;
        }
    }
    return returnval;
}

void printArray (int a[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
