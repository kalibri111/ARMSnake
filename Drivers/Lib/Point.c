//
// Created by kalibri on 14.12.2020.
//

#include "Point.h"

void drawPoint(Point_xt* point) {
    oled_set_pix(point->x, point->y, 255);
}

Point_xt* newPoint(PointPool_xt* pull, int x, int y) {
    if (pull->size < 1000) {
        pull->points[pull->size].x = x;
        pull->points[pull->size].y = y;

        pull->size += 1;
        return pull->points + pull->size - 1;
    } else {
        pull->points[0].x = x;
        pull->points[0].y = y;
        pull->size = 0;
        return pull->points;
    }
}

