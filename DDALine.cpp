#include <stdio.h>
#include <graphics.h>
#include <math.h>

void drawLineDDA(int x0, int y0, int x1, int y1) {
    int dx = x1 - x0;
    int dy = y1 - y0;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xIncrement = dx / (float) steps;
    float yIncrement = dy / (float) steps;

    float x = x0;
    float y = y0;

    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);
        x += xIncrement;
        y += yIncrement;
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

    drawLineDDA(x0, y0, x1, y1);

    getch();
    closegraph();
    return 0;
}

