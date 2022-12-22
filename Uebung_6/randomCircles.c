//
// Created by Fabian Becker on 10.11.2022.
//
#include "gobjects.h"
#include "gevents.h"
#include "random.h"

#define WINDOW_SIZE 1000
#define NUMBER_OF_CIRCLES 200
#define RADIUS_MIN 5
#define RADIUS_MAX 200

void createRandomCircle(GWindow window, int radius, int x, int y);
void setRandomCircleDimension (int *radius, int *x, int *y);

int main (void) {
    GWindow window = newGWindow(WINDOW_SIZE, WINDOW_SIZE);
    requestFocus(window);
    int circle_radius = 0;
    int circle_x_pos = 0;
    int circle_y_pos = 0;
    //200 pre generated circles
    for (int i = 0; i < NUMBER_OF_CIRCLES; i++) {
        setRandomCircleDimension(&circle_radius,&circle_x_pos,&circle_y_pos);
        createRandomCircle(window, circle_radius, circle_x_pos, circle_y_pos);
    }
    //User can generate more circles through Key presses
    while(1) {
        GEvent e = waitForEvent(KEY_PRESSED);
        if (e != NULL && (getKeyChar(e) == 'n')) {
            setRandomCircleDimension(&circle_radius, &circle_x_pos, &circle_y_pos);
            createRandomCircle(window, circle_radius, circle_x_pos, circle_y_pos);
        } else if (e != NULL && (getKeyChar(e) == 'e')) {
            exit(0);
        }
    }
}

//Creates an orange circle with given dimensions
void createRandomCircle (GWindow window, int radius, int x, int y) {
    GOval circle = newGOval(x, y, radius, radius);
    setFillColor(circle,"ORANGE");
    setFilled(circle,1);
    add(window, circle);
}

//Generates random positions and sizes
void setRandomCircleDimension (int *radius, int *x, int *y) {
    *radius = randomInteger(RADIUS_MIN,RADIUS_MAX);
    *x = randomInteger(0,(WINDOW_SIZE - *radius));
    *y = randomInteger(0,(WINDOW_SIZE - *radius));
}