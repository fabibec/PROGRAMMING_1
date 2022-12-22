#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void handleConsoleInput();
void handleFileInput();
void countLetterOccurrence(int occurrence[26], char word[], unsigned int* chars_read);
void calculateScale(const int occurrence[26], int *scale);
void printHistogram(int occurrence[26], int step);
void printHashedLine(int length, int step);
void removeNewlines(char word[]);

int main (void) {
    //Choose between console input or test data
    char input[3] = {0};
    do {
        printf("Do yo want to use text or file? Type in (t) ord (f):");
        fgets(input, 3, stdin);
    } while (input[0] != 'f' && input[0] != 't' && input[0] != 70 && input[0] != 84);
    if (input[0] == 102 || input[0] == 70) {
        handleFileInput();
    } else if (input[0] == 116 || input[0] == 84) {
        handleConsoleInput();
    }
}

void countLetterOccurrence(int occurrence[26], char word[], unsigned int* chars_read) {
    int i = 0;
    while (word[i] != '\0') {
        //lowercase word
        if(word[i] >= 97 && word[i] <= 122) {
            word[i] -= 32;
        }
        if(word[i] >= 65 && word[i] <= 90) {
            occurrence[word[i] - 65] += 1;
            *chars_read = *chars_read + 1;
        }
        i++;
    }
}

void printHistogram(int occurrence[26], int step) {
    //print histogram
    for (int j = 0; j < 26; j++) {
        if (occurrence[j] > 0) {
            printf("%c:", j + 97);
            printHashedLine(occurrence[j], step);
        }
    }
}

void printHashedLine(int length, int step) {

    for(int i = 0; i < length; i += step) {
        printf("*");
    }
    printf("\n");
}

//Replaces \n Character with \ß
void removeNewlines(char word[]) {
    int i = -1;
    while(word[++i] != '\n');
    word[i] = '\0';
}

void handleConsoleInput(){
    //Variables
    int letterOccurrence[26] = {0};
    char word[1000];
    unsigned int chars_read = 0;

    //Get user input
    printf("Enter your word:");
    fgets(word,1000,stdin);

    countLetterOccurrence(letterOccurrence, word, &chars_read);

    printf("--- Read Input with %d letters ---\n", chars_read);
    printHistogram(letterOccurrence, 1);
}

void handleFileInput(){
    //Variables
    char path[1000];
    FILE* text;
    char* line = NULL;
    size_t buffer_length;
    int line_length;
    int scale = 0;
    unsigned int chars_read = 0;
    int letterOccurrence[26] = {0};

    //Get File Path and strip \n
    printf("The file-path to your data can be entered absolute or relative\nEnter your file path:");
    fgets(path,1000,stdin);
    removeNewlines(path);

    //Open File
    text = fopen(path,"r");
    if (text == NULL) {
        fprintf(stderr, "ERROR - File path not found!");
        exit(EXIT_FAILURE);
    }

    //Read line by line and update occurrence array
    while((line_length = getline(&line,&buffer_length,text)) != -1) {
        countLetterOccurrence(letterOccurrence,line, &chars_read);
        removeNewlines(line);
    }
    free(line);
    fclose(text);

    //calculate scale
    calculateScale(letterOccurrence, &scale);

    //print results
    printf("--- Read File with %d letters ---\n", chars_read);
    printHistogram(letterOccurrence, scale);
    printf("\nScale * ca.%d", scale);
}

void calculateScale(const int occurrence[26], int *scale) {
    int greatest_number = -1;
    //find biggest number in array
    for (int i = 0; i < 26; i++) {
        if (occurrence[i] > greatest_number) greatest_number = occurrence[i];
    }
    //Calculate and return scale
    *scale = (greatest_number > 100) ? (int) ceil(greatest_number / 100.00) : 1;
}