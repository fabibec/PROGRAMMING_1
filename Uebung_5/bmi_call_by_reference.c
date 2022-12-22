/*
 * Calculates and evaluates the BMI from user input
 * Author: Florian Heinz <florian.heinz@oth-regensburg.de>
 */

#include "simpio.h"
/*
 * evaluateBMI calculates the BMI from height and weight,
 * outputs it as well as the category.
 * Parameter: kg     - the weight of the user
 *            height - the height of the user
 * Return value: none
 */
void evaluateBMI (double *kg, double *height) {
    double bmi = *kg / *height / *height;

    printf("Your BMI is %f\n", bmi);
    if (bmi < 18.5) {
        printf("You are underweight.\n");
    } else if (bmi <= 25) {
        printf("You have normal weight.\n");
    } else if (bmi <= 30) {
        printf("You are overweight.\n");
    } else {
        printf("You are heavy overweight.\n");
    }
}

/*
 * getWeight requests the weight from the user.
 * Return value: The entered weight
 */
void getWeight(double *kg) {
    printf("Enter weight in kilos: ");
    *kg = getReal();
}

/*
 * getHeight requests the height from the user.
 * Return value: The entered height
 */
void getHeight(double *height) {
    printf("Enter height in meters: ");
    *height = getReal();
}

/*
 * checkYourBMI fetches weight and height from the user, outputs the BMI
 * as well as a category.
 * Return value: none
 */
void checkYourBMI (void) {
    double kg, height;

    getWeight(&kg);
    getHeight(&height);
    evaluateBMI(&kg, &height);
}

/*
 * Entry point of the program.
 */
int main (void) {
    checkYourBMI();

    return 0;
}
