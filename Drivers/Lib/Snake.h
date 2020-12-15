//
// Created by kalibri on 14.12.2020.
//

#ifndef SNAKEGAME_SNAKE_HPP
#define SNAKEGAME_SNAKE_HPP

#include "Point.h"
#include "oled_driver.h"
#include "xprintf.h"

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
    int foods_size;
    int queue_size;
    Point_xt foods[5];
    Point_xt queue[50];
    Direction_xt direction;
} Snake_xt;

/*
 * Generate 5 dots representing food
 * */
void generate_food(Snake_xt* snake);

/*
 * push front and pop back
 * with O(N) complecsity
 * */
void push_pop(Point_xt* buffer, int buf_size, Point_xt* value);

/*
 * push front
 * */
void push(Point_xt* buffer, int buf_size, Point_xt* value);

/*
 * check oportunity to move and move
 * */
void move_forward(Snake_xt* snake, Point_xt* new_point);

/*
 * setter for direction
 * */
void change_direction(Snake_xt* snake, Direction_xt dir);

/*
 * draw pics by pics
 * */
void draw_snake(Snake_xt* snake);

/*
 * draw pics by pics
 * */
void draw_food(Snake_xt* snake);
#endif //SNAKEGAME_SNAKE_HPP
