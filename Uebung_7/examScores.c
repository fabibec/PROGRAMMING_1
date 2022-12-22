#include <stdio.h>
#include <stdlib.h>
#include "simpio.h"

void printHashLine(int num);
void printThresholds(int threshold);

int main (void) {
    FILE* scoresFile;
    int examScores[11] = {0};
    //Open File
    scoresFile = fopen("../Uebung_7/examScores.txt", "r");
    //Exit if File can't be opened
    if (scoresFile == NULL) {
        printf("File does not exist!");
        exit(1);
    }
    //Read the exam scores and sort into an array
    char *line;
    int score;
    while(1) {
        line = readLine(scoresFile);
        if(line == NULL) {
            break;
        }
        score = atoi(line);
        //Sorting into array
        if (score > 0 && score <= 100) {
            int index = score / 10;
            examScores[index]++;
        } else {
            fprintf(stderr, "ERROR: Score out of range: %d", score);
            exit(EXIT_FAILURE);
        }
    }
    fclose(scoresFile);
    //print Scores
    printf("--Exam Scores--\n");
    for (int i = 0; i < 11; i++) {
        printThresholds(i);
        printHashLine(examScores[i]);
    }
    return 0;
}

void printHashLine(int num) {
    for (int i = 0; i < num; i++) {
        printf("*");
    }
    printf("\n");
}

void printThresholds(int threshold) {
    if (threshold  * 10 == 100) {
        printf("%d:", threshold * 10);
    }
    else {
        printf("%02d-%02d:", threshold * 10, (threshold * 10) + 9);
    }
}
