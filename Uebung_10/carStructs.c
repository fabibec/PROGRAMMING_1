#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef enum{
    VW,
    Lamborghini,
    Porsche
} brand;


typedef struct {
    brand manufacturer;
    int vmax;
    int abs;
    int doors;
    int price;
} car;

car newCar();
void setCarPrice(car *car);
void sortCarList(car *list, int list_len);
void swapCars(car *a, car *b);
void displayCarList(car *list, int list_len);
char* getCarManufacturer(int code);
char* getABSValue(int code);
char* addSeparatorToNumericString(int num, char separator);

int main (void) {
    int num_of_cars;
    car* car_list;
    //Intialise car list and calculate their prices
    printf("How many cars do you want to insert?");
    scanf("%d", &num_of_cars);
    car_list = malloc(num_of_cars * sizeof(car));
    for (int i = 0; i < num_of_cars; i++) {
        car_list[i] = newCar();
    }
    //Sort the list by highest price
    sortCarList(car_list, num_of_cars);
    //Print the total price and the sorted list
    displayCarList(car_list, num_of_cars);

    free(car_list);
    return 0;
}

//Returns new car from user input
car newCar() {
    car a_new_Car;
    printf("Car brand (0 = VW, 1 = Lamborghini, 2 = Porsche):");
    scanf("%u", &a_new_Car.manufacturer);
    printf("ABS (0 = no, 1 = yes):");
    scanf("%d", &a_new_Car.abs);
    printf("V-Max:");
    scanf("%d", &a_new_Car.vmax);
    printf("Number of doors:");
    scanf("%d", &a_new_Car.doors);
    setCarPrice(&a_new_Car);
    return a_new_Car;
}

//calculates the prices of the car
void setCarPrice(car *car) {
    int brand_multiplicator;
    switch (car->manufacturer) {
        case Lamborghini: brand_multiplicator = 20; break;
        case Porsche: brand_multiplicator = 2; break;
        case VW: brand_multiplicator = 1; break;
    }
    car->price = (((car->vmax * 50) * car->doors) + (5000 * car->abs)) * brand_multiplicator;
}

//Sort the list of cars by descending price using selection sort
void sortCarList(car *list, int list_len) {
    int position;

    for (int i = 0; i < list_len; i++) {
        position = i;
        for (int j = i; j < list_len; j++) {
            if (list[position].price < list[j].price) {
                position = j;
            }
        }
        if (position != i) {
            swapCars(&list[i], &list[position]);
        }
    }
}

//Helper function for sorting: This swaps to car structs
void swapCars(car *a, car *b) {
    car *buffer = malloc(sizeof(car));
    *buffer = *b;
    *b = *a;
    *a = *buffer;
    free(buffer);
}

//Prints out the information
void displayCarList(car *list, int list_len) {
    int total_price = 0;
    for (int i = 0; i < list_len; i++) {
        total_price += list[i].price;
    }
    char *total_price_formatted = addSeparatorToNumericString(total_price,'.');
    printf("-----------------------------------\n"
           "Total price for all cars: EUR %s\n", total_price_formatted);
    free(total_price_formatted);
    printf("-----------------------------------\n");
    for (int i = 0; i < list_len; i++) {
        char *car_price = addSeparatorToNumericString(list[i].price,'.');
        printf("Car %d (%s):\n V-Max: %d km/h\n ABS: %s\n Number of doors: %d\n Price: EUR %s\n",
               (i + 1), getCarManufacturer(list[i].manufacturer), list[i].vmax, getABSValue(list[i].abs),
               list[i].doors, car_price);
        free(car_price);
    }
}

//Helper function: Decodes int into manufacturer name
char* getCarManufacturer(int code){
    switch (code) {
        case 0: return "VW";
        case 1: return "Lamborghini";
        case 2: return "Porsche";
        default: return "Unknown";
    }
}

//Helper function: Decodes int into yes/no
char* getABSValue(int code) {
    switch (code) {
        case 0: return "no";
        case 1: return "yes";
        default: return "Unknown";
    }
}

//Formats number with separators
char* addSeparatorToNumericString(int num, char separator) {
    //Convert int to char[]
    int digits = (int) floor(log10(abs(num))) + 1;
    char number[digits + 1];

    sprintf(number, "%d", num);

    //calculate number of separators
    int len = (int) strlen(number);
    int num_of_separators = (len - 1) / 3;

    //Allocate memory for the formatted number (+ \0 character)
    int formatted_length = len + num_of_separators;
    char *formattedNumber = malloc(formatted_length + 1);

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

    return formattedNumber;
}