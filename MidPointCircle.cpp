#include <stdio.h>
#include <graphics.h>

void drawCircleMidPoint(int xc, int yc, int radius) {
    int x = 0;
    int y = radius;
    int P = 1 - radius;
    
    while(x <= y) {
        putpixel(xc+x, yc+y, WHITE);
        putpixel(xc-x, yc+y, WHITE);
        putpixel(xc+x, yc-y, WHITE);
        putpixel(xc-x, yc-y, WHITE);
        putpixel(xc+y, yc+x, WHITE);
        putpixel(xc-y, yc+x, WHITE);
        putpixel(xc+y, yc-x, WHITE);
        putpixel(xc-y, yc-x, WHITE);
        
        if (P < 0) {
            x += 1;
            P = P + 2 * x + 3;
        }
        else {
            x += 1;
            y -= 1;
            P = P + 2 * (x - y) + 5;
        }
    }
}

int main() {
    int xc, yc, radius;
    printf("Enter the centers of the circle: ");
    scanf("%d %d", &xc, &yc);
    printf("Enter the radius of the circle: ");
    scanf("%d", &radius);
    
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    drawCircleMidPoint(xc, yc, radius);
    getch();
    closegraph();
    return 0;
}

