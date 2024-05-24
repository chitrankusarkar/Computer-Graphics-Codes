#include <stdio.h>
#include <graphics.h>

void drawCircle(int xc, int yc, int radius) {
    int x = 0;
    int y = radius;
    int P = 3 - 2 * radius;
    
    while(x <= y) {
        putpixel(xc+x, yc+y, WHITE);
        putpixel(xc-x, yc+y, WHITE);
        putpixel(xc+x, yc-y, WHITE);
        putpixel(xc-x, yc-y, WHITE);
        putpixel(xc+y, yc+x, WHITE);
        putpixel(xc-y, yc+x, WHITE);
        putpixel(xc+y, yc-x, WHITE);
        putpixel(xc-y, yc-x, WHITE);
        
        if (P <= 0) {
            x += 1;
            P = P + 4 * x + 6;
        }
        else {
            x += 1;
            y -= 1;
            P = P + 4 * (x - y) + 10;
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
    drawCircle(xc, yc, radius);
    getch();
    closegraph();
    return 0;
}
