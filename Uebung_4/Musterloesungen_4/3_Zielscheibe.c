#include "gwindow.h"

// Number of circles (red and white)
#define NR_CIRCLES 15
// Diameter of the most inner circle
#define DIAMETER 15
// Margin between circles and window border
#define MARGIN 100

// Some macros to avoid magic numbers
#define COLOR_RED 0
#define COLOR_WHITE 1

// The drawing canvas
GWindow gw;

/*
 * drawCircle: draws a circle with given diameter in the middle of the window
 * Parameter: diameter - the diameter of the circle
 *            color    - COLOR_RED or COLOR_WHITE
 * Returns: nothing
 */
void drawCircle (int diameter, int color) {
    // Calculate the center from the window size
    int center_x = getWidth(gw)/2;
    int center_y = getWidth(gw)/2;
    // radius is half the diameter
    int radius = diameter / 2;
    // Check, which color to use and set it
    if (color == COLOR_RED) {
        setColor(gw, "RED");
    } else if (color == COLOR_WHITE) {
        setColor(gw, "WHITE");
    }
    // Draw a filled oval. Since height and width are both _diameter_, it is a
    // circle. x and y specify the upper left corner of the bounding box, so
    // we have to subtract the radius from it to center the circle properly.
    fillOval(gw, center_x-radius, center_y-radius, diameter, diameter);
}

/*
 * drawCircles(): Draws the defined number of circles alternating
 * red and white.
 */
void drawCircles(void) {
    int i;
    // Count down from NR_CIRCLES to 1 to draw the outermost circle first
    for (i = NR_CIRCLES; i > 0; i--) {
        int color;
        if (i % 2 == 1) {
            // If the current counter is odd, draw in red
            color = COLOR_RED;
        } else {
            // else, draw a white circle
            color = COLOR_WHITE;
        }
        // Draw a single circle. i counts from NR_CIRCLES to 1,
        // so the diameter of the circles are decreasing
        drawCircle(DIAMETER*i, color);
    }
}

/*
 * setupCanvas(): Set up the drawing window. The size depends on
 * the number of circles, the diameter and the specified margin to
 * the window border.
 */
void setupCanvas (void) {
    int size = DIAMETER*NR_CIRCLES+MARGIN;
    gw = newGWindow(size, size);
}

/*
 * Set up the window and draw the circles.
 */
int main (void) {
    setupCanvas();
    drawCircles();

    return 0;
}