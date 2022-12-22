#include "gwindow.h"
#include "gobjects.h"

// The diameter of the bouncing ball
#define BALL_DIAMETER 10

// Width and height of the drawing canvas
#define WIDTH  1000
#define HEIGHT 400

// The gravity value, higher means more gravity
#define GRAVITY 0.15
// A dampening factor, lower means more dampening
#define DAMPENING 0.9

// Ball speed in x direction
int xspeed = 1;
// Initial speed in y direction
double yspeed = 0;

// The drawing canvas
GWindow gw;
// The ball object in the foreground layer
GOval ball;

/*
 * bouncingBall(): This function moves the ball approximately according
 * to physical rules (gravity and repulsion)
 */
void bouncingBall (void) {
    // Loop until the ball leaves the right window border
    while (getX(ball) < WIDTH) {
        // Move the ball according to the current x and y speed
        move(ball, xspeed, yspeed);
        // Adjust speed in y direction by the gravity value
        yspeed += GRAVITY;
        // Check if we hit the ground
        if (getY(ball) > HEIGHT - BALL_DIAMETER) {
            // The ball is probably a bit below the ground,
            // put it to ground level
            double diff = getY(ball) - (HEIGHT - BALL_DIAMETER);
            move(ball , 0, -2 * diff);
            // Adjust the speed by a dampening factor, so it will lose
            // some energy
            yspeed = -yspeed*DAMPENING;
        }

        // Delay execution. Increase for slower motion.
        pause(10);
    }
}

/*
 * setupCanvas(): creates the drawing window and the
 * ball in the upper left corner.
 */
void setupCanvas (void) {
    // Create the window
    gw = newGWindow(WIDTH, HEIGHT);
    // Create the red filled ball in the upper left corner
    ball = newGOval(0, 0, BALL_DIAMETER, BALL_DIAMETER);
    setFilled(ball, true);
    setFillColor(ball, "RED");
    // add the ball to the canvas
    add(gw, ball);
}

/*
 * Set up the drawing window and start bouncing the ball
 */
int main (void) {
    setupCanvas();
    bouncingBall();

    return 0;
}