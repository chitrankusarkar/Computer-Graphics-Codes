#include <stdio.h>
#include <graphics.h>

void boundaryFill8(int x, int y, int fill_color, int boundary_color) {
    if (getpixel(x, y) != boundary_color && getpixel(x, y) != fill_color) {
        putpixel(x, y, fill_color);
        boundaryFill8(x + 1, y, fill_color, boundary_color);
        boundaryFill8(x, y + 1, fill_color, boundary_color);
        boundaryFill8(x - 1, y, fill_color, boundary_color);
        boundaryFill8(x, y - 1, fill_color, boundary_color);
        boundaryFill8(x - 1, y - 1, fill_color, boundary_color);
        boundaryFill8(x - 1, y + 1, fill_color, boundary_color);
        boundaryFill8(x + 1, y - 1, fill_color, boundary_color);
        boundaryFill8(x + 1, y + 1, fill_color, boundary_color);
    }
}

int main() {
    int gd = DETECT, gm;
    int fill_color, boundary_color;
    int x, y;

    printf("Enter fill color: ");
    scanf("%d", &fill_color);

    printf("Enter boundary color: ");
    scanf("%d", &boundary_color);

    printf("Enter seed point (x, y): ");
    scanf("%d %d", &x, &y);

    initgraph(&gd, &gm, NULL);

    setcolor(boundary_color);
    rectangle(100, 100, 300, 300); // example rectangle

    boundaryFill8(x, y, fill_color, boundary_color);

    delay(10000); // Delay to display the result

    closegraph();
    return 0;
}
