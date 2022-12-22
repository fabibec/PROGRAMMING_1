//
// Created by Fabian Becker on 19.10.2022.
//

#include "simpio.h"

int main (void) {
    /**
     * Get user input
     */
    printf("Enter weight in kilos:");
    int weight = getInteger();
    printf("Enter height in meters:");
    float height = getReal();

    /**
     * Calculate BMI and print to user
     */
    float your_bmi = weight / (height * height);
    printf("Your BMI is: %.3f\n", your_bmi);

    /**
     * Print out condition based on BMI
     */
    if (your_bmi < 18.5) {
        printf("You are underweight.");
    }
    else if (your_bmi < 25)
    {
        printf("You have normal weight.");
    }
    else if (your_bmi < 30) {
        printf("You are overweight.");
    }
    else
    {
        printf("You are obese.");
    }

    return 0;
}
