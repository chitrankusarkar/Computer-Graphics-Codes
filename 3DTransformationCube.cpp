#include <stdio.h>
#include <math.h>
#include <graphics.h>

int original_cube[8][3] = {
    {270, 190, -50}, {370, 190, -50}, {370, 290, -50}, {270, 290, -50}, // Bottom square
    {270, 190, 50}, {370, 190, 50}, {370, 290, 50}, {270, 290, 50}      // Top square
};
// Current cube vertices (Took this vertices for the centered position of the cube)
int cube_vertices[8][3] = {
    {270, 190, -50}, {370, 190, -50}, {370, 290, -50}, {270, 290, -50}, 
    {270, 190, 50}, {370, 190, 50}, {370, 290, 50}, {270, 290, 50} 
};

// Function to draw the cube using simple projection
void draw_cube() {
    // Project the 3D coordinates to 2D plane
    int projected_cube[8][2];
    for (int i = 0; i < 8; i++) {
        projected_cube[i][0] = cube_vertices[i][0] - cube_vertices[i][2] / 2;
        projected_cube[i][1] = cube_vertices[i][1] - cube_vertices[i][2] / 2;
    }

    // Draw the edges of the cube
    for (int i = 0; i < 4; i++) {
        line(projected_cube[i][0], projected_cube[i][1], projected_cube[(i + 1) % 4][0], projected_cube[(i + 1) % 4][1]);
        line(projected_cube[i + 4][0], projected_cube[i + 4][1], projected_cube[((i + 1) % 4) + 4][0], projected_cube[((i + 1) % 4) + 4][1]);
        line(projected_cube[i][0], projected_cube[i][1], projected_cube[i + 4][0], projected_cube[i + 4][1]);
    }
}
// To reset the cube 
void reset_cube() {
    for (int i = 0; i < 8; i++) {
        cube_vertices[i][0] = original_cube[i][0];
        cube_vertices[i][1] = original_cube[i][1];
        cube_vertices[i][2] = original_cube[i][2];
    }
}
// Function to translate the cube
void translate(int dx, int dy, int dz) {
    for (int i = 0; i < 8; i++) {
        cube_vertices[i][0] += dx;
        cube_vertices[i][1] += dy;
        cube_vertices[i][2] += dz;
    }
}

// Function to rotate the cube around the X-axis
void rotate_x(int angle) {
    double radians = angle * M_PI / 180.0;
    double cos_a = cos(radians);
    double sin_a = sin(radians);
    
    for (int i = 0; i < 8; i++) {
        int y = cube_vertices[i][1];
        int z = cube_vertices[i][2];
        cube_vertices[i][1] = round(y * cos_a - z * sin_a);
        cube_vertices[i][2] = round(y * sin_a + z * cos_a);
    }
}

// Function to rotate the cube around the Y-axis
void rotate_y(int angle) {
    double radians = angle * M_PI / 180.0;
    double cos_a = cos(radians);
    double sin_a = sin(radians);
    
    for (int i = 0; i < 8; i++) {
        int x = cube_vertices[i][0];
        int z = cube_vertices[i][2];
        cube_vertices[i][0] = round(x * cos_a + z * sin_a);
        cube_vertices[i][2] = round(-x * sin_a + z * cos_a);
    }
}

// Function to rotate the cube around the Z-axis
void rotate_z(int angle) {
    double radians = angle * M_PI / 180.0;
    double cos_a = cos(radians);
    double sin_a = sin(radians);
    
    for (int i = 0; i < 8; i++) {
        int x = cube_vertices[i][0];
        int y = cube_vertices[i][1];
        cube_vertices[i][0] = round(x * cos_a - y * sin_a);
        cube_vertices[i][1] = round(x * sin_a + y * cos_a);
    }
}
// Function to scale the cube
void scale(int sx, int sy, int sz) {
    int center_x = (cube_vertices[0][0] + cube_vertices[6][0]) / 2;
    int center_y = (cube_vertices[0][1] + cube_vertices[6][1]) / 2;
    int center_z = (cube_vertices[0][2] + cube_vertices[6][2]) / 2;

    for (int i = 0; i < 8; i++) {
        cube_vertices[i][0] = round(center_x + (cube_vertices[i][0] - center_x) * sx);
        cube_vertices[i][1] = round(center_y + (cube_vertices[i][1] - center_y) * sy);
        cube_vertices[i][2] = round(center_z + (cube_vertices[i][2] - center_z) * sz);
    }
}
int main() {
	
    int choice;
    int gd = DETECT, gm;
    int translate_fact1, translate_fact2, translate_fact3;
    int angle_x, angle_y, angle_z;
    int scale_fact1, scale_fact2, scale_fact3;

    while (1) {
        printf("\nMenu For 3D Transformation on a Cube:\n");
        printf("1. Translate\n");
        printf("2. Rotate Around X-Axis\n");
        printf("3. Rotate Around Y-Axis\n");
        printf("4. Rotate Around Z-Axis\n");
        printf("5. Scale\n");
        printf("6. Reset\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter translation values (dx, dy, dz): ");
                scanf("%d %d %d", &translate_fact1, &translate_fact2, &translate_fact3);
                translate(translate_fact1, translate_fact2, translate_fact3);
                break;
            case 2:
                printf("Enter rotation angle around x-axis: ");
                scanf("%d", &angle_x);
                rotate_x(angle_x);
                break;
            case 3:
                printf("Enter rotation angle around y-axis: ");
                scanf("%d", &angle_y);
                rotate_y(angle_y);
                break;
            case 4:
                printf("Enter rotation angle around z-axis: ");
                scanf("%d", &angle_z);
                rotate_z(angle_z);
                break;
            case 5:
                printf("Enter scaling factors (sx, sy, sz): ");
                scanf("%d %d %d", &scale_fact1, &scale_fact2, &scale_fact3);
                scale(scale_fact1, scale_fact2, scale_fact3);
                break;
            case 6:
                reset_cube();
                break;
            case 7:
                return 0;
            default:
                printf("Invalid choice!\n");
                continue;
        }

        // Draw the square after each operation
        initgraph(&gd, &gm, NULL);
        draw_cube();
        delay(2000); //after 2second each action will be terminated and will be saved
        closegraph();
    }

    return 0;

}