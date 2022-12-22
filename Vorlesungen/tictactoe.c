#include "gwindow.h"
#include "gobjects.h"
#include "gevents.h"
#include "simpio.h"


#define HEIGHT 600
#define WIDTH 600

#define MARGIN 50
#define T_SIZE 100

GWindow gw;

enum players {
    FREE,
    RED,
    BLUE,
    DRAW
};

//Defines position of lines for the correct size increase
enum lines {
    LEFT_DIAGONAL,
    RIGHT_DIAGONAL
};

struct Node {
    struct Node *next;
    enum lines type;
    int start_x;
    int start_y;
    int end_x;
    int end_y;
    GLine line;
};

void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf ("%d ", p->type);
        p = p->next;
    }
}

void addLineToList (struct Node *p, enum lines line_pos, int line_x0 , int line_x1, int line_y0, int line_y1){
    while (p->next != NULL) {
        p = p->next;
    }
    //Add new line at the end of the list
    struct Node *next_el;
    next_el = (struct Node *) malloc(sizeof(struct Node));
    next_el->type = line_pos;
    GLine new_line = newGLine(line_x0,line_y0,line_x1,line_y1);
    add(gw,new_line);
    next_el->start_x = line_x0;
    next_el->start_y = line_y0;
    next_el->end_x = line_x1;
    next_el->end_y = line_y1;
    next_el->line = new_line;
    next_el->next = NULL;
    p->next = next_el;

}

void resizeList (struct Node *p, int increment) {
    while (p != NULL)
    {
        //printf("Start(%d,%d)\n",p->start_x,p->start_y);
        //printf("End(%d,%d)\n",p->end_x,p->end_y);
        if (p->type == LEFT_DIAGONAL) {
            setStartPoint(p->line,(p->start_x) - 1, (p->start_y) - 1);
            setEndPoint(p->line,(p->end_x) + 1, (p->end_y) + 1);
        } else {
            setStartPoint(p->line,(p->start_x) + 1, (p->start_y) - 1);
            setEndPoint(p->line,(p->end_x) - 1, (p->end_y) + 1);
        }
        p = p->next;
    }
}


void placeCross (int x, int y) {
    int size = T_SIZE - 50;
    int edge = 60;
    GPolygon triangle = newGPolygon();
    for (int i = 0; i < 3; i++)
    {
        addVertex(triangle,edge,size);
    }
    addAt(gw,triangle,x,y);
}

void createCanvas (void) {
    gw = newGWindow(WIDTH, HEIGHT);

    drawLine(gw, MARGIN, MARGIN, MARGIN, 3*T_SIZE+MARGIN);
    drawLine(gw, MARGIN+T_SIZE, MARGIN, MARGIN+T_SIZE, 3*T_SIZE+MARGIN);
    drawLine(gw, MARGIN+2*T_SIZE, MARGIN, MARGIN+2*T_SIZE, 3*T_SIZE+MARGIN);
    drawLine(gw, MARGIN+3*T_SIZE, MARGIN, MARGIN+3*T_SIZE, 3*T_SIZE+MARGIN);

    drawLine(gw, MARGIN, MARGIN, 3*T_SIZE+MARGIN, MARGIN);
    drawLine(gw, MARGIN, MARGIN+T_SIZE, 3*T_SIZE+MARGIN, T_SIZE+MARGIN);
    drawLine(gw, MARGIN, MARGIN+2*T_SIZE, 3*T_SIZE+MARGIN, MARGIN+2*T_SIZE);
    drawLine(gw, MARGIN, MARGIN+3*T_SIZE, 3*T_SIZE+MARGIN, MARGIN+3*T_SIZE);
}

void xy2coords(int *x, int *y) {
    *x = (*x - MARGIN)/T_SIZE;
    *y = (*y - MARGIN)/T_SIZE;
}

void coords2xy (int *x, int *y) {
    *x = (*x*T_SIZE+MARGIN+T_SIZE/2);
    *y = (*y*T_SIZE+MARGIN+T_SIZE/2);
}

int checkPosition (int x, int y) {
    coords2xy(&x, &y);
    GObject g = getGObjectAt(gw, x, y);
    if (g == NULL)
        return FREE;
    char *color = getColorGObject(g);
    if (*color == 'r') {
        return RED;
    } else {
        return BLUE;
    }
}

void placeToken(int x, int y, int player){
    int start_size = T_SIZE-80;
    int end_size = T_SIZE-5;
    coords2xy(&x, &y);
    placeCross(50, 150);
    GOval st = newGOval(x-(start_size)/2, y-(start_size)/2, start_size, start_size);
    setFilled(st, 1);
    if (player == RED) {
        setColor(st, "red");
    } else {
        setColor(st, "blue");
    }
    add(gw, st);
    for (int i = start_size; i <= end_size; i += 5) {
        setLocation(st,x - i / 2,y - i / 2);
        setSize(st,i,i);
        pause(30);
    }
}

void KIPlayer() {
    //Set center token
    if (checkPosition(1,1) == FREE) {
        placeToken(1, 1, BLUE);
    }
    //Set random token
    else {
        int x_random;
        int y_random;
        do {
            x_random = rand() % 3;
            y_random = rand() % 3;
        } while (checkPosition(x_random, y_random) != FREE);
        placeToken(x_random, y_random, BLUE);
    }
}

int andTheWinnerIs () {
    int s00 = checkPosition(0, 0);
    int s01 = checkPosition(0, 1);
    int s02 = checkPosition(0, 2);
    int s10 = checkPosition(1, 0);
    int s11 = checkPosition(1, 1);
    int s12 = checkPosition(1, 2);
    int s20 = checkPosition(2, 0);
    int s21 = checkPosition(2, 1);
    int s22 = checkPosition(2, 2);
    //Check for win on columns
    if ((s00 == s01) && (s01 == s02) && s00 > FREE) {
        return s00;
    }
    if ((s10 == s11) && (s11 == s12) && s10 > FREE) {
        return s10;
    }
    if ((s20 == s21) && (s21 == s22) && s20 > FREE) {
        return s20;
    }
    //Check for win in rows
    if ((s00 == s10) && (s10 == s20) && s00 > FREE) {
        return s00;
    }
    if ((s01 == s11) && (s11 == s21) && s01 > FREE) {
        return s01;
    }
    if ((s02 == s12) && (s12 == s22) && s02 > FREE) {
        return s02;
    }
    //Check for win in diagonals
    if ((s00 == s11) && (s11 == s22) && s00 > FREE) {
        return s00;
    }
    if ((s02 == s11) && (s11 == s20) && s02 > FREE) {
        return s02;
    }
    //Check for draw
    if (s00 > FREE && s01 > FREE && s02 > FREE && s10 > FREE && s11 > FREE && s12 > FREE && s20 > FREE && s21 > FREE && s22 > FREE)
    {
        return DRAW;
    }

    return 0;
}

void updatePlayerLabel (GWindow wn, GLabel label, int player, enum players win) {
    string label_text = "";
    string color = "";

    if (player == RED && win == FREE) {
        label_text = "It's RED's turn!";
       color = "RED";
    } else if (player == BLUE && win == FREE) {
        label_text = "It's BLUE's turn!";
        color = "BLUE";
    } else if (win == RED) {
        label_text = "Red has won!";
        color = "RED";
    } else if (win == BLUE) {
        label_text = "Blue has won!";
        color = "BLUE";
    } else if (win == DRAW) {
        label_text = "It's a draw!";
        color = "BLACK";
    }
    setLabel(label, label_text);
    setColor(label,color);
    setFont(label, "SansSerif-30");
    addAt(wn,label,((MARGIN + T_SIZE * 3 / 2) - getWidth(label)/2), 40);
}

int main (void) {
    createCanvas();
    
    int player = RED;
    GLabel player_label = newGLabel("");
    updatePlayerLabel(gw, player_label, player, FREE);

    while (1) {
        int x;
        int y;
        if (player == RED) {
            do {
                GEvent e = waitForEvent(MOUSE_CLICKED);
                if (e != NULL) {
                    if (getEventType(e) == MOUSE_CLICKED) {
                        x = getX(e);
                        y = getY(e);
                        xy2coords(&x, &y);
                        if (checkPosition(x, y) != FREE) {
                            continue;
                        }
                    }
                    else {
                        x = 3;
                    }
                }
            } while (x > 2 || y > 2);
            placeToken(x, y, player);
        } else {
            pause(400);
            KIPlayer();
            pause(300);

        }
        int winner = andTheWinnerIs();
        if (winner != FREE) {
            updatePlayerLabel(gw,player_label,winner,winner);
            break;
        }
        //Change Player
        if (player == RED) {
            player = BLUE;
        } else {
            player = RED;
        }
        updatePlayerLabel(gw, player_label, player, FREE);
    }
    waitForClick();
    return 0;
}
