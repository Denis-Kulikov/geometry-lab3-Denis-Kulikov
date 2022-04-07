#pragma once

#define COORDINATES_X_Y 2

typedef struct figur_circle {
    double point[COORDINATES_X_Y];
    double radius;
} StructCircle;

struct info {
    double perimeter;
    double area;
};