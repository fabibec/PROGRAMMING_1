#include "gobjects.h"
#include "gwindow.h"
#include "gevents.h"
#include "random.h"

/* Constants */
#define CAR_NUM 500
#define CAR_WIDTH 15
#define CAR_HEIGHT 5
#define WIDTH 1200
#define HEIGHT 700
#define PAUSE_TIME 20
#define CAR_COLOR "CYAN"
#define MAX_SPEED 10

GRect cars[CAR_NUM];
int carSpeeds[CAR_NUM];

GWindow gw;

void setupCars() {
    for (int i = 0; i < CAR_NUM;i ++) {
        //Initialize car objects array
        int car_y = (randomInteger(0, (HEIGHT /CAR_HEIGHT) - 1)) * CAR_HEIGHT;
        GRect car = newGRect(0,car_y,CAR_WIDTH,CAR_HEIGHT);
        setFillColor(car,CAR_COLOR);
        setFilled(car,1);
        add(gw,car);
        cars[i] = car;
        //Initialize car speed array
        carSpeeds[i] = randomInteger(1,MAX_SPEED);
    }
}

void moveCars() {
    for (int i = 0; i < CAR_NUM; i++) {
        if (getX(cars[i]) >= WIDTH) {
            setLocation(cars[i], 0, getY(cars[i]));
            carSpeeds[i] = randomInteger(1,MAX_SPEED);
        }
        move(cars[i], carSpeeds[i], 0);
    }

}

void drive() {
    while (1) {
        moveCars();
        pause(PAUSE_TIME);
    }
}

void setupCanvas() {
    gw = newGWindow(WIDTH, HEIGHT);
    fillRect(gw, 0, 0, WIDTH, HEIGHT);  //draws a black background
}

int main() {
    setupCanvas();
    setupCars();
    drive();
    return 0;
}
