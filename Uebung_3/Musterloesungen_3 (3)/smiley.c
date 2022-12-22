/*
 * Prints a surprised smiley face. The size depends on the canvas size.
 * Author: Florian Heinz <florian.heinz@oth-regensburg.de>
 */

#include "gwindow.h"

#define SIZE 400

// The window handle
GWindow gw;

/*
 * setupDrawingCanvas initializes the canvas with the given x/y-dimension
 * Parameter: size - the x and y dimension of the canvas
 * Return value: none
 */
void setupDrawingCanvas (int size) {
    gw = newGWindow(size, size);
}

/*
 * drawSmiley draws the smiley with the size depending on the canvas size.
 * Parameter: size - the x and y dimension of the canvas
 * Return value: none
 */
void drawSmiley (int size) {
    // Set the color of the face (yellow)
    setColorGWindow(gw, "YELLOW");
    // Draw the face exactly inside the canvas
    fillOval(gw, 0, 0, size, size);

    // Set the color of eyes and mouth (black)
    setColorGWindow(gw, "BLACK");
    // The eye diameter is one fifth of the face diameter
    int eyesize = size/5;
    // Draw the left eye. Position is calculated depending on the canvas size
    fillOval(gw, size/4-eyesize/2, size/3-eyesize/2, eyesize, eyesize);
    // Draw the right eye. Position is calculated depending on the canvas size
    fillOval(gw, 3*size/4-eyesize/2, size/3-eyesize/2, eyesize, eyesize);

    // The mouth is oval, i.e. x and y size differs. Also calculated depending
    // on the canvas size
    int mouthsizex = size/2;
    int mouthsizey = size/4;
    // Draw the mouth. The position is again calculated from the canvas size.
    fillOval(gw, size/2-mouthsizex/2, 3*size/5, mouthsizex, mouthsizey);
}

/*
 * Sets up the canvas and draws a smiley.
 * Parameter: size - the canvas size
 * Return value: none
 */
void showSmiley (int size) {
    setupDrawingCanvas(SIZE);
    drawSmiley(SIZE);
}

/*
 * The entry point of the program.
 */
int main(void) {
    showSmiley(SIZE);

    return 0;
}