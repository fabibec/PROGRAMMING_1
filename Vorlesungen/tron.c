#include "gwindow.h"
#include "gobjects.h"
#include "gevents.h"

#define T_SIZE 10

#define D_NORTH 0
#define D_EAST 1
#define D_SOUTH 2
#define D_WEST 3

// The canvas
GWindow gw;
// x and y position of the bicycle
int tx, ty;
// direction of bicycle
int dir;
// speed of the bicycle, lower is faster
int speed = 100;
// the dimensions of the logical grid
int gridx, gridy;

/*
 * calculateStep():
 * Calculate the next position of the tron bicycle according
 * to the current direction.
 * Check if a crash happened (hit a wall or its own trail)
 */
int calculateStep (void) {
    // Change tx/ty coordinates according to current direction
    if (dir == D_NORTH) {
        ty--;
    } else if (dir == D_SOUTH) {
        ty++;
    } else if (dir == D_WEST) {
        tx--;
    } else if (dir == D_EAST) {
        tx++;
    }

    // Check for a crash
    int crash = 0;
    // Did the bicycle hit the border?
    if ((ty > gridy) || (ty < 0) || (tx > gridx) || (tx < 0)) {
        crash = 1;
    }

    // Did it hit its own trail?
    if (getGObjectAt(gw, tx*T_SIZE+1, ty*T_SIZE+1) != NULL) {
        crash = 1;
    }

    return crash;
}

/*
 * showStep(): Draw the next step of tron on the canvas.
 */
void showStep (void) {
    // Draw a filled rectangle. Calculate the real canvas position from
    // the logical grid position and the size of a grid cell (T_SIZE)
    GRect r = newGRect(tx*T_SIZE, ty*T_SIZE, T_SIZE, T_SIZE);
    setFilled(r, true);
    // Add it to the canvas
    add(gw, r);
}

/*
 * userInput():
 * Check user input. If the user has pressed an arrow key,
 * set the direction variable to the corresponding value.
 */
void userInput (void) {
    // Check if a key event is pending
    GKeyEvent e = getNextEvent(KEY_EVENT);
    if (e != NULL) {
        // We really got a key event, check which one
        int key = getKeyCode(e);
        // Set the direction which corresponds to the arrow key pressed
        if (key == UP_ARROW_KEY) {
            dir = D_NORTH;
        } else if (key == DOWN_ARROW_KEY) {
            dir = D_SOUTH;
        } else if (key == LEFT_ARROW_KEY) {
            dir = D_WEST;
        } else if (key == RIGHT_ARROW_KEY) {
            dir = D_EAST;
        }
    }
}

/*
 * play() starts the actual gameplay.
 * The main loop is ended as soon as a crash is detected.
 */
void play (void) {
    int crash = 0;
    // Repeat until a crash is detected
    while (crash == 0) {
        // calculateStep returns 1 if a crash was detected
        crash = calculateStep();
        // Print the current position of the bicycle
        showStep();
        // Make a small break
        pause(speed);
        // Check for user interaction
        userInput();
    }
}

/*
 * Setup a canvas with given width and height.
 * Initializes the grid variables:
 * gridx and gridy contain the dimension of the logical grid, which is used
 * for drawing the bicycle trail.
 * Initializes the bicycle position: the middle of the grid
 * Initial direction: north
 */
void setupCanvas() {
    // Create a canvas window of given height and width
    gw = newGWindow(800, 800);
    // Set the focus on this window, so keypresses can be registered
    requestFocus(gw);
    // Calculate the logical grid dimension
    gridx = getWidth(gw)/T_SIZE;
    gridy = getHeight(gw)/T_SIZE;
    // initialize the bicycle position and direction
    tx = gridx/2;
    ty = gridy/2;
    dir = D_NORTH;
}

/*
 * doExit() prints "CRASH!!" on the canvas, waits 2 seconds
 * and closes the graphic window
 */
void doExit () {
    // Create a label, set font and size, as well as color
    GLabel gl = newGLabel("CRASH!!");
    setFont(gl, "SansSerif-50");
    setColor(gl, "RED");
    setLocation(gl, getWidth(gw)/2, getHeight(gw)/2);
    // Show it on the canvas
    add(gw, gl);
    // Wait two seconds
    pause(2000);
    // Then close the canvas
    closeGWindow(gw);
}

/*
 * Setup the canvas, start the game and exit after a crash
 */
int main (void) {
    setupCanvas();
    play();
    doExit();

    return 0;
}