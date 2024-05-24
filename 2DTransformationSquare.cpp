#include <stdio.h>
#include <graphics.h>
#include <math.h>

int original_square[4][2] = {
    {100, 100},
    {200, 100},
    {200, 200},
    {100, 200}
};

int square_vertices[4][2] = {
    {100, 100},
    {200, 100},
    {200, 200},
    {100, 200}
};

void draw_square() {
    for (int i = 0; i < 4; i++) {
        int next = (i + 1) % 4;
        line(square_vertices[i][0], square_vertices[i][1], square_vertices[next][0], square_vertices[next][1]);
    }
}

void reset_square() {
    for (int i = 0; i < 4; i++) {
        square_vertices[i][0] = original_square[i][0];
        square_vertices[i][1] = original_square[i][1];
    }
}

void translate(int dx, int dy) {
    for (int i = 0; i < 4; i++) {
        square_vertices[i][0] += dx;
        square_vertices[i][1] += dy;
    }
}

void rotate(int angle) {
    double radians = (double)angle * M_PI / 180.0;
    int center_x = (square_vertices[0][0] + square_vertices[1][0] + square_vertices[2][0] + square_vertices[3][0]) / 4;
    int center_y = (square_vertices[0][1] + square_vertices[1][1] + square_vertices[2][1] + square_vertices[3][1]) / 4;

    for (int i = 0; i < 4; i++) {
        int translated_x = square_vertices[i][0] - center_x;
        int translated_y = square_vertices[i][1] - center_y;
        square_vertices[i][0] = round(translated_x * cos(radians) - translated_y * sin(radians)) + center_x;
        square_vertices[i][1] = round(translated_x * sin(radians) + translated_y * cos(radians)) + center_y;
    }
}

void scale(int sx, int sy) {
    int center_x = (square_vertices[0][0] + square_vertices[1][0] + square_vertices[2][0] + square_vertices[3][0]) / 4;
    int center_y = (square_vertices[0][1] + square_vertices[1][1] + square_vertices[2][1] + square_vertices[3][1]) / 4;

    for (int i = 0; i < 4; i++) {
        int translated_x = (square_vertices[i][0] - center_x) * sx / 100;
        int translated_y = (square_vertices[i][1] - center_y) * sy / 100;
        square_vertices[i][0] = translated_x + center_x;
        square_vertices[i][1] = translated_y + center_y;
    }
}

void shear(int shx, int shy) {
    for (int i = 0; i < 4; i++) {
        square_vertices[i][0] += shx * square_vertices[i][1] / 100;
        square_vertices[i][1] += shy * square_vertices[i][0] / 100;
    }
}

int main() {
    int choice;
    int gd = DETECT, gm;
    int translate_fact1, translate_fact2;
    int angle;
    int scale_fact1, scale_fact2;
    int shear_fact1, shear_fact2;

    while (1) {
        printf("\nMenu For 2D Transformation on a Square:\n");
        printf("1. Translate\n");
        printf("2. Rotate\n");
        printf("3. Scale\n");
        printf("4. Shear\n");
        printf("5. Reset\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter translation values (x, y): ");
                scanf("%d %d", &translate_fact1, &translate_fact2);
                translate(translate_fact1, translate_fact2);
                break;
            case 2:
                printf("Enter rotation angle: ");
                scanf("%d", &angle);
                rotate(angle);
                break;
            case 3:
                printf("Enter scaling factors (sx, sy): ");
                scanf("%d %d", &scale_fact1, &scale_fact2);
                scale(scale_fact1, scale_fact2);
                break;
            case 4:
                printf("Enter shearing factors (shx, shy): ");
                scanf("%d %d", &shear_fact1, &shear_fact2);
                shear(shear_fact1, shear_fact2);
                break;
            case 5:
                reset_square();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid choice!\n");
                continue;
        }

        // Draw the square after each operation
        initgraph(&gd, &gm, NULL);
        draw_square();
        delay(2000); //after 2second each action will be terminated and will be saved
        closegraph();
    }

    return 0;
}

