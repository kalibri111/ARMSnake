//
// Created by kalibri on 14.12.2020.
//

#ifndef SNAKEGAME_DEQUE_H
#define SNAKEGAME_DEQUE_H

#endif //SNAKEGAME_DEQUE_H

#include <stdio.h>
#include <stdlib.h>
#include "Point.h"

//---------------------------------STACK------------------------------

typedef struct stack {
    Point_xt* buffer;
    int       size;
    int       max_size;
} stack_xt;

stack_xt* new_stack();

void clear_stack(stack_xt* stack);

void push(stack_xt* stack, Point_xt value);

Point_xt pop(stack_xt* stack);

//---------------------------------DEQUE-------------------------------

typedef struct deque {
    stack_xt* stack_in;
    stack_xt* stack_out;
    size_t   size;
} deque_xt;

deque_xt* new_deque();

Point_xt* front(deque_xt* self);

/*
 * положить в stack_in
 * */
void push_back(deque_xt* deque, Point_xt value);

/*
 * возврат из stack_in
 * */
Point_xt pop_back(deque_xt* deque);

/*
 * положить в stack_out
 * */
void push_front(deque_xt* deque, Point_xt value);

/*
 * взять из stack_out
 * */
Point_xt pop_front(deque_xt* deque);

void destroy_deque(deque_xt* deque);