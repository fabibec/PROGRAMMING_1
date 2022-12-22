//
// Created by becke on 26.10.2022.
//
#include "gwindow.h"
#include "gobjects.h"
#include "gevents.h"

int main (void) {
    GWindow win = newGWindow(325,325);

    int radius = 225;
    int circle_pos = 50;

    for (int i = 1; i <= 15; i++) {
        GOval circle  = newGOval(circle_pos,circle_pos,radius,radius);
        if (i % 2 == 0) {
            setFillColor(circle,"white");
        }
        else {
            setFillColor(circle, "red");
        }
        setFilled(circle,1);
        add(win,circle);
        radius -= 15;
        circle_pos += 7;
    }

    waitForClick();
    return 0;
}
