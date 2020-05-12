/*
 *
 *   Implementation of public API (snake.h)
 *   and helper functions
 *
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include <memory.h>
#include "snake.h"  // Include to check declaration/definition the same


// -----------------------  Segment functions ------------------

static seg_t *segment_new(int x, int y, seg_t *prev) {
    seg_t *seg = malloc(sizeof(seg_t));
    if (seg == NULL) {
        perror("Couldn't create segment, giving up");
        exit(EXIT_FAILURE);
    }
    seg->x = x;
    seg->y = y;
    seg->prev = prev;
    return seg;
}

//--------------- Snake functions  --------------------------

snake_t *snake_new(int x, int y, int width, int height) {

    seg_t *head = segment_new(x, y, NULL);
    seg_t *last = segment_new(x - width, y, head);

    snake_t *a_snake = malloc(sizeof(snake_t));
    if (a_snake == NULL) {
        perror("Couldn't create snake, giving up");
        exit(EXIT_FAILURE);
    }

    // TODO

    return a_snake;
}


/*
 *  Alt1: Shift all positions (values) from head towards last, set new position for head
 *  Alt2: Move last seg to head. Set new positions for head
 */
static void shift(snake_t *the_snake, int new_x_head, int new_y_head) {

    // TODO

}

void snake_move(snake_t *the_snake) {

    // TODO

    //shift(the_snake, new_x_head, new_y_head);
}

// NOTE: The position of the appended segment doesn't
// matter. The new segment will get a positions at next
// move.
void snake_append_segment(snake_t *the_snake) {
    // TODO
}

void snake_turn(snake_t *the_snake, dir_t dir) {
    the_snake->dir = dir;
}

/*
 *  If length 2 snake may take opposite direction without colliding
 *  Else if length > 2 it will collide. Default length is 2.
 */
bool snake_hit_self(snake_t *the_snake) {
     // TODO
    return false;
}



bool snake_hit_wall(snake_t *the_snake) {
    // TODO
}

bool snake_hit_apple(snake_t *the_snake, apple_t *the_apple) {
    return abs(the_snake->head->x - the_apple->x) < SEGMENT_WIDTH &&
           abs(the_snake->head->y - the_apple->y) < SEGMENT_HEIGHT;
}

// ------------ Apple function  --------------------------

apple_t *apple_new() {
    apple_t *a_apple = malloc(sizeof(apple_t));
    if (a_apple == NULL) {
        perror("Couldn't create apple, giving up ...");
        exit(EXIT_FAILURE);
    }

    // Make x and y coincide to grid
    int x = SEGMENT_WIDTH * (rand() % (GAME_MAX_X / 10));
    int y = SEGMENT_HEIGHT * (rand() % (GAME_MAX_Y / 10));

    a_apple->x = x;
    a_apple->y = y;
    a_apple->width = SEGMENT_WIDTH;
    a_apple->height = SEGMENT_HEIGHT;

    return a_apple;
}

void apple_destroy(apple_t *the_apple) {
    free(the_apple);
}







