//
// Created by becke on 26.10.2022.
//
#include "gwindow.h"
#include "gobjects.h"
#include "gevents.h"

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 500
#define RADIUS 20
#define STARTING_HEIGHT 50
#define GRAVITY 0.15
#define DX 2


int main (void) {
    // Configure window and ball
    GWindow win = newGWindow(WINDOW_WIDTH,WINDOW_HEIGHT);
    GOval ball = newGOval(STARTING_HEIGHT,STARTING_HEIGHT,RADIUS,RADIUS);
    setFillColor(ball, "red");
    setFilled(ball, 1);
    add(win, ball);

    double y_shift = 1;

    while (getX(ball) < WINDOW_WIDTH - RADIUS * 1.5) {

        move(ball, DX, y_shift);
        pause(25);

        if(getY(ball) < WINDOW_HEIGHT - RADIUS * 1.5) {
            y_shift = y_shift + GRAVITY;
        } else {
            y_shift = y_shift * -0.9;
        }

    }
    waitForClick();
    return 0;
}
