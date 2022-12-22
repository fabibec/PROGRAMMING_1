#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* getString(void);
void sortStringArray(char** array, int length);
void swapPointers(char** string1, char** string2);
void printStringArray(char** array, int length);

int main (void) {
    int num_of_strings;
    printf("How many string do you want to enter:");
    scanf("%d", &num_of_strings);
    fflush(stdin);
    char** stringPtrArray = malloc(num_of_strings * sizeof(char*));
    for (int i = 0; i < num_of_strings; i++) {
        printf("Please enter a word:");
        stringPtrArray[i] = getString();
    }
    sortStringArray(stringPtrArray, num_of_strings);
    printStringArray(stringPtrArray, num_of_strings);
    for (int i = 0; i < num_of_strings; i++) {
        free(stringPtrArray[i]);
    }
    free(stringPtrArray);
    return 0;
}

char* getString(void) {
    char *stringPtr = NULL;
    size_t buffer_len;
    int str_len;
    str_len = getline(&stringPtr,&buffer_len,stdin);
    stringPtr[str_len - 1] = '\0';
    fflush(stdin);
    return stringPtr;
}

void sortStringArray(char** array, int length) {
    int i, j;
    int swapped;
    for (i = 0; i < length - 1; i++)
    {
        swapped = 0;
        for (j = 0; j < length -i-1; j++)
        {
            if (strcmp(array[j], array[j + 1]) > 0)
            {
                swapPointers(&array[j], &array[j + 1]);
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

void swapPointers(char** string1, char** string2) {
    char *address_buffer = *string1;
    *string1 = *string2;
    *string2 = address_buffer;

}

void printStringArray(char **array, int length) {
    printf("-----Array contains-----\n");
    for (int i = 0; i < length; i++) {
        printf("String %d: ", i + 1);
        int j = 0;
        while (array[i][j] != '\0') {
            printf("%c", array[i][j]);
            j++;
        }
        printf("\n");
    }
}