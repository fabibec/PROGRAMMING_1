#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addSeparatorToNumericString(char number[], char formattedNumber[], char separator);
void removeNewlines(char word[]);

const char numberSeparator = '.';

int main (void) {
    //Get string and copy to char array
    char* input_number = NULL;
    size_t buffer_len;
    size_t word_len;
    printf("Enter your number:");
    word_len = getline(&input_number, &buffer_len, stdin);
    char* formatted_number = NULL;
    char number[word_len];
    strcpy(number,input_number);
    removeNewlines(number);
    free(input_number);
    addSeparatorToNumericString(number, formatted_number, numberSeparator);
    free(formatted_number);
    return 0;
}

//Replaces \n Character with \0
void removeNewlines(char word[]) {
    int i = -1;
    while(word[++i] != '\n');
    word[i] = '\0';
}

void addSeparatorToNumericString(char number[], char formattedNumber[], char separator) {
    //calculate number of separators
    int len = (int) strlen(number);
    int num_of_separators = (len - 1) / 3;

    //Allocate memory for the formatted number (+ \0 character)
    int formatted_length = len + num_of_separators;
    formattedNumber = malloc(formatted_length + 1);

    //Fill array
    formattedNumber[formatted_length] = '\0';
    for (int i = 0; i < formatted_length; i++) {
        if ((i + 1) % 4 == 0) {
            formattedNumber[(formatted_length - 1) - i] = separator;
        } else {
            formattedNumber[(formatted_length - 1) - i] = number[len - 1];
            len--;
        }
    }

    //Print String
    printf("Formatted Number: %s",formattedNumber);
}

