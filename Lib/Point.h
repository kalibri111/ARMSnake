//
// Created by kalibri on 14.12.2020.
//

#ifndef SNAKEGAME_POINT_H
#define SNAKEGAME_POINT_H
#include "stdlib.h"
#include "oled_driver.h"

typedef struct Point {
    int x;
    int y;
} Point_xt;

Point_xt* newPoint(int x_val, int y_val);

void drawPoint(Point_xt* point);

void destroyPoint(Point_xt* point);

#endif //SNAKEGAME_POINT_H
