//
// Created by kalibri on 14.12.2020.
//

#include "Point.h"

Point_xt* newPoint(int x_val, int y_val) {
    Point_xt* self = (Point_xt*)calloc(1, sizeof(Point_xt));
    self->x = x_val;
    self->y = y_val;

    return self;
}

void drawPoint(Point_xt* point) {
    oled_set_pix(point->x, point->y, 255);
}

void destroyPoint(Point_xt* point) {
    if (point) {
        free(point);
    }
}