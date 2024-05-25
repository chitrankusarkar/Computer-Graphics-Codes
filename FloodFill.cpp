#include <stdio.h>
#include <graphics.h>

void floodFill8(int x, int y, int fill_color, int old_color) {
    if (getpixel(x, y) == old_color) {
        putpixel(x, y, fill_color);
        floodFill8(x + 1, y, fill_color, old_color);     // Right
        floodFill8(x - 1, y, fill_color, old_color);     // Left
        floodFill8(x, y + 1, fill_color, old_color);     // Down
        floodFill8(x, y - 1, fill_color, old_color);     // Up
        floodFill8(x + 1, y + 1, fill_color, old_color); // Diagonal (Down-Right)
        floodFill8(x - 1, y - 1, fill_color, old_color); // Diagonal (Up-Left)
        floodFill8(x - 1, y + 1, fill_color, old_color); // Diagonal (Down-Left)
        floodFill8(x + 1, y - 1, fill_color, old_color); // Diagonal (Up-Right)
    }
}

int main() {
    int gd = DETECT, gm;
    int fill_color, boundary_color, x, y;

    printf("Enter fill color: ");
    scanf("%d", &fill_color);

    printf("Enter boundary color: ");
    scanf("%d", &boundary_color);

    printf("Enter seed point (x, y): ");
    scanf("%d %d", &x, &y);

    initgraph(&gd, &gm, NULL);

    // Draw a boundary for testing
    rectangle(50, 50, 250, 250);

    // Perform flood fill
    floodFill8(x, y, fill_color, boundary_color);

    delay(5000); // Delay to display the result

    closegraph();
    return 0;
}

