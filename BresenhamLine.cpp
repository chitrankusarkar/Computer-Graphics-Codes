#include<stdio.h>
#include<graphics.h>
#include<math.h>

void drawLineBresenham(int x1, int y1, int x2, int y2) {
    int dx, dy, p, x, y, k;
    dx = abs(x1 - x2);
    dy = abs(y1 - y2);
    p = 2 * dy - dx;
    x = x1;
    y = y1;
    putpixel(x, y, WHITE);
    for (k = 1; k <= dx; k++) {
        if (p < 0) {
            if (x < x2) {
                x = x + 1;
            } else {
                x = x - 1;
            }
            p = p + 2 * dy;
        } else {
            if (y < y2) {
                y = y + 1;
                x = x + 1;
            } else {
                y = y - 1;
                x = x - 1;
            }
            p = p + 2 * dy - 2 * dx;
        }
        putpixel(x, y, WHITE);
    }
}

int main() {
int x0, y0, x1, y1;
    printf("Enter the starting coordinates (x0, y0): ");
    scanf("%d %d", &x0, &y0);
    printf("Enter the ending coordinates (x1, y1): ");
    scanf("%d %d", &x1, &y1);

    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    drawLineBresenham(x0, y0, x1, y1);
    getch();
    closegraph();
    return 0;
}

