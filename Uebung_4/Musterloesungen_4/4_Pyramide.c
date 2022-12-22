#include "gwindow.h"

// The width of a single brick
#define BRICK_WIDTH 30
// The height of a single brick
#define BRICK_HEIGHT 12
// Number of bricks in the base layer. Each layer
// above has one brick less
#define BRICKS_IN_BASE 14
// Margin to the sides and to the top
#define MARGIN 100

// The drawing canvas
GWindow gw;

/*
 * drawBrickLine: draws a single line of bricks consisting of nr elements
 * Parameters: x/y - upper left coordinates of the first brick
 *             nr  - Number of bricks in this line
 */
void drawBrickLine (int x, int y, int nr) {
    int i;
    for (i = 0; i < nr; i++) {
        // First draw the orange filling of the brick
        setColor(gw, "ORANGE");
        fillRect(gw, x+i*BRICK_WIDTH, y, BRICK_WIDTH, BRICK_HEIGHT);
        // Then the black border
        setColor(gw, "BLACK");
        drawRect(gw, x+i*BRICK_WIDTH, y, BRICK_WIDTH, BRICK_HEIGHT);
    }
}

/*
 * drawPyramid(): Draw the whole pyramid layer by layer
 */
void drawPyramid (void) {
    int i;

    // Center the base layer
    int start_x = getWidth(gw)/2-(BRICK_WIDTH*BRICKS_IN_BASE)/2;
    // Y start coordinate is one brick height less than the window height
    int start_y = getHeight(gw)-BRICK_HEIGHT;

    // Now count down from the bricks in the base layer to 1 and
    // draw each layer
    for (i = BRICKS_IN_BASE; i > 0; i--) {
        // Draw a single brick layer
        drawBrickLine(start_x, start_y, i);
        // Adjust the x coordinate for the next layer
        // (indent one half brick width)
        start_x += BRICK_WIDTH/2;
        // Adjust the y coordinate for the next layer
        // (one brick height higher)
        start_y -= BRICK_HEIGHT;
    }
}

/*
 * setupCanvas(): Set up the drawing window. The size depends on
 * the number of bricks and their dimension.
 */
void setupCanvas (void) {
    int size_x, size_y;

    // The x size of the window depends on the largest layer
    // (the base layer) and the width of a single brick.
    // Finally, add some margin to get a nice picture
    size_x = BRICKS_IN_BASE*BRICK_WIDTH+MARGIN;
    // The number of brick layers corresponds to the
    // number of bricks in the base layer.
    // The margin is halved because there is none to the bottom
    size_y = BRICKS_IN_BASE*BRICK_HEIGHT+MARGIN/2;

    // Create the window
    gw = newGWindow(size_x, size_y);
}

/*
 * Set up the drawing window and draw the pyramid
 */
int main (void) {
    setupCanvas();
    drawPyramid();

    return 0;
}