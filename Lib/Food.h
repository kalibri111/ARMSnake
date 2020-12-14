//
// Created by kalibri on 14.12.2020.
//

#ifndef SNAKEGAME_FOOD_H
#define SNAKEGAME_FOOD_H

#include "Point.h"
#include "deque.h"

typedef struct Food {
    deque_xt* buffer;
} Food_xt;

Food_xt* newFood();

void generate_new_food(Food_xt* self);

void destroyFood(Food_xt* self);

#endif //SNAKEGAME_FOOD_H
