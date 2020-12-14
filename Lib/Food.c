//
// Created by kalibri on 14.12.2020.
//

#include "Food.h"


Food_xt* newFood() {
    Food_xt* self = (Food_xt*)calloc(1, sizeof(Food_xt));
    self->buffer = new_deque();
    return self;
}

void generate_new_food(Food_xt* self) {
    int new_x = rand() % 100;
    int new_y = rand() % 100;

    Point_xt* new_food = newPoint(new_x, new_y);
    push_front(self->buffer, *new_food);
}

void destroyFood(Food_xt* self) {
    destroy_deque(self->buffer);
    free(self);
}
