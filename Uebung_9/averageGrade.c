#include <stdio.h>
#include <stdlib.h>

void calculateAverage(int num);

int main (void) {
    //Get number of grades
    int num_of_grades = 0;
    printf("How many grades to enter?:");
    scanf("%d", &num_of_grades);
    if (num_of_grades < 1) {
        fprintf(stderr, "ERROR - Falscher Datentyp oder zu kleine Zahl eingegeben.");
        exit(EXIT_FAILURE);
    }
    //Calculate the average grade
    calculateAverage(num_of_grades);
    return 0;
}

void calculateAverage(int num) {
    int *grades = malloc(num * sizeof(int));
    int current_grade;
    double avg = 0.0;

    //Collect all grades from user
    for (int i = 0; i < num; i++) {
        printf("Enter grade %d (1-6):", i + 1);
        current_grade = 0;
        scanf("%d",&current_grade);
        while (current_grade < 1 || current_grade > 6) {
            fflush(stdin);
            fprintf(stderr,"Grade of wrong type entered! Please reenter grade %d (1-6):", i + 1);
            scanf("%d",&current_grade);
        }
        grades[i] = current_grade;
    }

    for (int i = 0; i < num; i++) {
        avg += grades[i];
    }

    free(grades);

    avg /= num;

    printf("The average grade is %.2f", avg);
}