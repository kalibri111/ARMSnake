//
// Created by kalibri on 14.12.2020.
//

#include "deque.h"

const size_t INIT_BUF_SIZE = 50;


//---------------------------------STACK------------------------------

stack_xt* new_stack() {
    stack_xt* new_stack = (stack_xt*)calloc(1, sizeof(stack_xt));

    new_stack->max_size = INIT_BUF_SIZE;
    new_stack->size     = 0;
    new_stack->buffer   = (Point_xt*)calloc(INIT_BUF_SIZE, sizeof(Point_xt));

    return new_stack;
}

void clear_stack(stack_xt* stack) {
    free(stack->buffer);
    stack->buffer = NULL;
}

void push(stack_xt* stack, Point_xt value) {
    if (stack->size == stack->max_size) {
        stack->max_size += (stack->max_size == 1);
        stack->max_size *= 2;
        stack->buffer    = (Point_xt*)realloc(stack->buffer, stack->max_size * sizeof(Point_xt));
    }
    stack->buffer[stack->size++] = value;
}

Point_xt pop(stack_xt* stack) {
    if (stack->size > 0) {
        Point_xt top_value = stack->buffer[stack->size - 1];
        --stack->size;
        return top_value;
    } else {
        fprintf(stderr, "Stack underflow");
        abort();
    }
}

//---------------------------------DEQUE-------------------------------

deque_xt* new_deque() {
    deque_xt* new_queue = (deque_xt*)calloc(1, sizeof(deque_xt));

    new_queue->stack_in  = new_stack();
    new_queue->stack_out = new_stack();
    new_queue->size      = 0;

    return new_queue;
}

Point_xt* front(deque_xt* self) {
    return &self->stack_in->buffer[self->stack_in->size - 1];
}

/*
 * положить в stack_in
 * */
void push_back(deque_xt* deque, Point_xt value) {
    push(deque->stack_in, value);
    ++deque->size;
}

/*
 * возврат из stack_in
 * */
Point_xt pop_back(deque_xt* deque) {
    if (deque->stack_in->size > 0) {
        --deque->size;
        return pop(deque->stack_in);
    } else {
//        переложим половину из stack_out в tmp
        stack_xt * tmp = new_stack();
        size_t out_size = deque->stack_out->size;
        for (int i = 0; i < out_size / 2; ++i) {
            Point_xt tmp_val = pop(deque->stack_out);
            push(tmp, tmp_val);
        }
//        другую половину в stack_in
        while (deque->stack_out->size) {
            Point_xt tmp_val = pop(deque->stack_out);
            push(deque->stack_in, tmp_val);
        }
//        вернем из tmp в stack_out
        while (tmp->size) {
            Point_xt tmp_val = pop(tmp);
            push(deque->stack_out, tmp_val);
        }
        --deque->size;
        return pop(deque->stack_in);
    }
}

/*
 * положить в stack_out
 * */
void push_front(deque_xt* deque, Point_xt value) {
    push(deque->stack_out, value);
    ++deque->size;
}

/*
 * взять из stack_out
 * */
Point_xt pop_front(deque_xt* deque) {
    if (deque->stack_out->size > 0) {
        --deque->size;
        return pop(deque->stack_out);
    } else {
//        переложим половину из stack_in в tmp
        stack_xt * tmp = new_stack();
        size_t in_size = deque->stack_in->size;
        for (int i = 0; i < in_size / 2; ++i) {
            Point_xt tmp_val = pop(deque->stack_in);
            push(tmp, tmp_val);
        }
//        другую половину в stack_out
        while (deque->stack_in->size) {
            Point_xt tmp_val = pop(deque->stack_in);
            push(deque->stack_out, tmp_val);
        }
//        вернем из tmp в stack_in
        while (tmp->size) {
            Point_xt tmp_val = pop(tmp);
            push(deque->stack_in, tmp_val);
        }
        --deque->size;
        return pop(deque->stack_out);
    }
}

void destroy_deque(deque_xt* deque) {
    clear_stack(deque->stack_in);
    free(deque->stack_in);
    deque->stack_in = NULL;

    clear_stack(deque->stack_out);
    free(deque->stack_out);
    deque->stack_out = NULL;

    free(deque);
    deque = NULL;
}