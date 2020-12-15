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

/*
 * static buffer for Points
 * */
typedef struct PointPool {
    Point_xt points[100];
    int size;
} PointPool_xt;

void drawPoint(Point_xt* point);

/*
 * stack type allocator for Point with overflow
 * */
Point_xt* newPoint(PointPool_xt* pull, int x, int y);

#endif //SNAKEGAME_POINT_H
