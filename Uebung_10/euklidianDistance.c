#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    double x;
    double y;
} point;

void getUserInput(point *p1, point *p2);
double distance (point p1, point p2);

int main (void) {
    point point1;
    point point2;
    double d;
    getUserInput(&point1,&point2);
    d = distance(point1,point2);
    printf("Der Abstand zwischen den Punkten beträgt: %.2lf", d);
    return 0;
}

//Get coordinates and insert them into the two structs
void getUserInput(point *p1, point *p2) {
    printf("Bitte die erste x-Koordinate eingeben:");
    scanf("%lf", &p1->x);
    printf("Bitte die erste y-Koordinate eingeben:");
    scanf("%lf", &p1->y);
    printf("Bitte die zweite x-Koordinate eingeben:");
    scanf("%lf", &p2->x);
    printf("Bitte die zweite y-Koordinate eingeben:");
    scanf("%lf", &p2->y);
}

//Calculate the euklidian distance between to points
double distance (point p1, point p2) {
    return sqrt(pow((p2.x - p1.x),2) + pow(p2.y - p1.y,2));
}

char[] itoc(int num) {
    int len = floor(log10(abs(num))) + 1;
    int counter = 0;
    while (x > 0)
    {
        counter = counter + x % 10;
        x = x / 10;
    }
}