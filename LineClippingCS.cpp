#include <conio.h>
#include <stdio.h>
#include <graphics.h>
#include <math.h>
// Bit code for the regions of the window
#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8

int computeCode(float x, float y, float xl, float yl, float xh, float yh) {
    int code = 0;
    if (x < xl)
        code |= LEFT;
    else if (x > xh)
        code |= RIGHT;
    if (y < yl)
        code |= BOTTOM;
    else if (y > yh)
        code |= TOP;
    return code;
}

int main() {
    float xl, yl, xh, yh; // Rectangle Are
    float xa, ya, xb, yb; // Line Co-ordinates
    printf("Enter window coordinates (xl, yl, xh, yh): ");
    scanf("%f %f %f %f", &xl, &yl, &xh, &yh); //100 100 300 300 

    printf("Enter coordinates of line (x1, y1, x2, y2): ");
    scanf("%f %f %f %f", &xa, &ya, &xb, &yb); //10 200 250 150
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    setcolor(5);
    line(xa, ya, xb, yb);
    setcolor(12);
    rectangle(xl, yl, xh, yh);

    int code1 = computeCode(xa, ya, xl, yl, xh, yh);
    int code2 = computeCode(xb, yb, xl, yl, xh, yh);
    int accept = 0;
    while (1) {
        if ((code1 == 0) && (code2 == 0)) {
            accept = 1;
            break;
        } else if (code1 & code2) {
            break;
        } else {
            float x, y;
            int outcode = code1 ? code1 : code2;
            if (outcode & TOP) {
                x = xa + (xb - xa) * (yh - ya) / (yb - ya);
                y = yh;
            } else if (outcode & BOTTOM) {
                x = xa + (xb - xa) * (yl - ya) / (yb - ya);
                y = yl;
            } else if (outcode & RIGHT) {
                y = ya + (yb - ya) * (xh - xa) / (xb - xa);
                x = xh;
            } else if (outcode & LEFT) {
                y = ya + (yb - ya) * (xl - xa) / (xb - xa);
                x = xl;
            }
            if (outcode == code1) {
                xa = x;
                ya = y;
                code1 = computeCode(xa, ya, xl, yl, xh, yh);
            } else {
                xb = x;
                yb = y;
                code2 = computeCode(xb, yb, xl, yl, xh, yh);
            }
        }
    }
    printf("Press a key to continue");
    getch();
    if (accept) {
        setcolor(15);
        line(xa, ya, xb, yb);
    } else {
        printf("Line discarded\n");
    }
    getch();
    closegraph();
    return 0;
}
