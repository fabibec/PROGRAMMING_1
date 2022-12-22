//
// Created by becke on 26.10.2022.
//
#define BRICK_WIDTH 15
#define BRICK_HEIGHT 30
#define BRICKS_IN_BASE 7
#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 500

#include "gwindow.h"
#include "gobjects.h"
#include "gevents.h"

int main (void) {
    GWindow win = newGWindow(WINDOW_WIDTH,WINDOW_HEIGHT);

    int amount_of_bricks = BRICKS_IN_BASE;
    int row_start = (WINDOW_WIDTH / 2)  - (BRICKS_IN_BASE * BRICK_WIDTH / 2);
    int y_pos = WINDOW_HEIGHT - BRICK_HEIGHT;

    while (amount_of_bricks > 0) {
        int x_pos = row_start;
        for (int i = 0; i < amount_of_bricks; i++) {
            GRect brick = newGRect(x_pos,y_pos,BRICK_WIDTH,BRICK_HEIGHT);
            setFillColor(brick, "yellow");
            setFilled(brick,1);
            add(win,brick);
            x_pos += BRICK_WIDTH;
            pause(50);
        }
        amount_of_bricks -= 1;
        y_pos -= BRICK_HEIGHT;
        row_start += BRICK_WIDTH / 2;
    }

    waitForClick();
    return 0;
}