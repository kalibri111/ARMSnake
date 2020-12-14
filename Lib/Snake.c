//
// Created by kalibri on 14.12.2020.
//

#include "Snake.h"

Snake_xt* newSnake() {
    Snake_xt* self = (Snake_xt*)calloc(1, sizeof(Snake_xt));
    
    self->direction = UP;
    self->queue = new_deque();
    
    Point_xt* start_point = newPoint(64, 32);
    push_front(self->queue, *start_point);
    
    self->foods = newFood();
    
    return self;
}

void move_forward(Snake_xt* snake) {
    Point_xt* new_point = newPoint(0, 0);
    if (snake->direction == UP) {

        new_point->x = front(snake->queue)->x;
        new_point->y = front(snake->queue)->y + 1;

    } else if (snake->direction == LEFT) {

        new_point->x = front(snake->queue)->x - 1;
        new_point->y = front(snake->queue)->y;

    } else if (snake->direction == RIGHT) {

        new_point->x = front(snake->queue)->x + 1;
        new_point->y = front(snake->queue)->y;

    } else if (snake->direction == DOWN) {

        new_point->x = front(snake->queue)->x;
        new_point->y = front(snake->queue)->y - 1;

    }

    if (new_point->x < 0 || new_point->x > 127 || new_point->y < 0 || new_point->y > 63) {
        xprintf("GAME OVER\nPRESS RESET");
        return;
    }

    for (int i = 0; i < snake->foods->buffer->stack_in->size; ++i) {
        if (   new_point->x == snake->foods->buffer->stack_in->buffer[i].x
            && new_point->y == snake->foods->buffer->stack_in->buffer[i].y) {

            push_front(snake->queue, *new_point);
            draw_snake(snake);
            generate_new_food(snake->foods);
            return;
        }
    }

    for (int i = 0; i < snake->foods->buffer->stack_out->size; ++i) {
        if (   new_point->x == snake->foods->buffer->stack_out->buffer[i].x
               && new_point->y == snake->foods->buffer->stack_out->buffer[i].y) {

            push_front(snake->queue, *new_point);
            draw_snake(snake);
            generate_new_food(snake->foods);
            return;
        }
    }

    for (int i = 0; i < snake->queue->stack_in->size; ++i) {
        if (   new_point->x == snake->queue->stack_in->buffer[i].x
            && new_point->y == snake->queue->stack_in->buffer[i].y) {
            xprintf("GAME OVER\nPRESS RESET");
            return;
        }
    }

    for (int i = 0; i < snake->queue->stack_out->size; ++i) {
        if (   new_point->x == snake->queue->stack_out->buffer[i].x
               && new_point->y == snake->queue->stack_out->buffer[i].y) {
            xprintf("GAME OVER\nPRESS RESET");
            return;
        }
    }

    push_front(snake->queue, *new_point);
    pop_back(snake->queue);
    draw_snake(snake);
}

void change_direction(Snake_xt* snake, Direction_xt dir) {
    if (snake->direction == UP && dir != DOWN) {
        snake->direction = dir;
    } else if (snake->direction == DOWN && dir != UP) {
        snake->direction = dir;
    } else if (snake->direction == LEFT && dir != RIGHT) {
        snake->direction = dir;
    } else if (snake->direction == RIGHT && dir != LEFT) {
        snake->direction = dir;
    }
}

void draw_snake(Snake_xt* snake) {
    for (int i = 0; i < snake->queue->stack_in->size; ++i) {
        oled_set_pix(snake->queue->stack_in->buffer[i].x,
                     snake->queue->stack_in->buffer[i].y,
                     255
                     );
    }

    for (int i = 0; i < snake->queue->stack_out->size; ++i) {
        oled_set_pix(snake->queue->stack_out->buffer[i].x,
                     snake->queue->stack_out->buffer[i].y,
                     255
        );
    }
}

void destroy_snake(Snake_xt* snake) {
    if (snake) {
        destroyFood(snake->foods);
        destroy_deque(snake->queue);
        free(snake);
        snake = NULL;
    }
}
