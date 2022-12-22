#include "gwindow.h"
#include "simpio.h"
#include <random.h>

#define WIDTH 800
#define HEIGHT 600

#define NRCIRCLES 250
#define COLOR "ORANGE"
#define MINDIAMETER 5
#define MAXDIAMETER 100

void drawRandomCircle (GWindow gw) {
    int x, y, diameter;

    diameter = randomInteger(MINDIAMETER, MAXDIAMETER);

    x = randomInteger(0, getWidth(gw) - diameter);
    y = randomInteger(0, getHeight(gw) - diameter);
    setColor(gw, COLOR);
    fillOval(gw, x, y, diameter, diameter);
    setColor(gw, "BLACK");
    drawOval(gw, x, y, diameter, diameter);
}

void drawRandomCircles (GWindow gw) {
    for (int i = 0; i < NRCIRCLES; i++) {
        drawRandomCircle (gw);
    }
}

GWindow createCanvas (void) {
    GWindow window = newGWindow(WIDTH, HEIGHT);

    return window;
}

int main (void) {
    GWindow gw = createCanvas();
    drawRandomCircles(gw);

    pause(5000);
    closeGWindow(gw);
    return 0;
}
