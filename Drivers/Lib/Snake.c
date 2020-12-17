//
// Created by kalibri on 14.12.2020.
//

#include "Snake.h"

extern int is_snake_alive;

void new_food(Snake_xt* snake, int food_index) {
    int new_x = rand() % 100;
    int new_y = rand() % 100;

    snake->foods[food_index].x = new_x;
    snake->foods[food_index].y = new_y;

    draw_food(snake);
}

void move_forward(Snake_xt* snake, Point_xt* new_point) {
    if (snake->direction == UP) {

        new_point->x = snake->queue[0].x;
        new_point->y = snake->queue[0].y + 1;

    } else if (snake->direction == LEFT) {

        new_point->x = snake->queue[0].x - 1;
        new_point->y = snake->queue[0].y;

    } else if (snake->direction == RIGHT) {

        new_point->x = snake->queue[0].x + 1;
        new_point->y = snake->queue[0].y;

    } else if (snake->direction == DOWN) {

        new_point->x = snake->queue[0].x;
        new_point->y = snake->queue[0].y - 1;

    }

    if (new_point->x < 0 || new_point->x > 127 || new_point->y < 0 || new_point->y > 63) {
        oled_clr(0x00);
        xprintf("GAME OVER");
        oled_update();
        is_snake_alive = 0;
        return;
    }

    for (int i = 0; i < snake->foods_size; ++i) {
        if (new_point->x == snake->foods[i].x && new_point->y == snake->foods[i].y) {
            push(snake->queue, snake->queue_size, new_point);
            snake->queue_size += 1;
            draw_snake(snake);
            new_food(snake, i);
            return;
        }
    }


    for (int i = 0; i < snake->queue_size; ++i) {
        if (new_point->x == snake->queue[i].x && new_point->y == snake->queue[i].y) {
            oled_clr(0x00);
            xprintf("GAME OVER");
            oled_update();
            is_snake_alive = 0;
            return;
        }
    }

    push_pop(snake->queue, snake->queue_size, new_point);
    oled_clr(0x00);
    draw_snake(snake);
    draw_food(snake);

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
    for (int i = 0; i < snake->queue_size; ++i) {
        oled_set_pix(snake->queue[i].x, snake->queue[i].y, 255);
    }
}

void push_pop(Point_xt* buffer, int buf_size, Point_xt* value) {
    for (int i = buf_size - 1; i > 0; --i) {
        buffer[i].x = buffer[i - 1].x;
        buffer[i].y = buffer[i - 1].y;
    }
    buffer[0].x = value->x;
    buffer[0].y = value->y;
}

void push(Point_xt* buffer, int buf_size, Point_xt* value) {
    for (int i = 1; i < buf_size + 1; ++i) {
        buffer[i].x = buffer[i - 1].x;
        buffer[i].y = buffer[i - 1].y;
    }
    buffer[0].x = value->x;
    buffer[0].y = value->y;
}

void generate_food(Snake_xt* snake) {
    snake->foods_size = 5;
    for (int i = 0; i < snake->foods_size; ++i) {
        snake->foods[i].x = rand() % 100;
        snake->foods[i].y = rand() % 100;
    }
    draw_food(snake);
}

void draw_food(Snake_xt* snake) {
    for (int i = 0; i < snake->foods_size; ++i) {
        oled_set_pix(snake->foods[i].x, snake->foods[i].y, 125);
    }
}
