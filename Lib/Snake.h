//
// Created by kalibri on 14.12.2020.
//

#ifndef SNAKEGAME_SNAKE_HPP
#define SNAKEGAME_SNAKE_HPP

#include "Point.h"
#include "oled_driver.h"
#include "xprintf.h"
#include "Food.h"

typedef enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
} Direction_xt;


/*
 * Singleton class of Snake
 * */
typedef struct Snake{
    Food_xt* foods;
    deque_xt* queue;
    Direction_xt direction;
} Snake_xt;

Snake_xt* newSnake();

void destroySnake(Snake_xt* snake);

void move_forward(Snake_xt* snake);

void change_direction(Snake_xt* snake, Direction_xt dir);

void draw_snake(Snake_xt* snake);
#endif //SNAKEGAME_SNAKE_HPP
