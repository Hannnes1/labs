/*
 *      *** Nothing to do here ***
 *
 *  Tests for the snake
 *
 *  NOTE: Also possible to debug from here!
 */
#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
#include <memory.h>

/* 
 * This is just for testing, to be able to test static functions,
 * normally NEVER include a .c file in another .c file
 */
#include "snake.c"

// Macros for testing
#define EQUALS(v1, v2) printf( (v1) == (v2) ? "true\n" : "false\n")
#define STR_EQUALS(s1, s2) printf( strcmp((s1), (s2)) == 0 ? "true\n" : "false\n")

// ----- The test methods ----------------------------

void test_segment_new();

void test_snake_new();

void test_snake_append();

void test_snake_turn_move();

void test_snake_move();

void test_snake_hit_self();

// ---------- Helper methods ----------

// Check that things that always should be true are true, see below
bool check_invariants(snake_t *the_snake);

// Convert snake to string
static char *to_str(snake_t *the_snake);

// Convert snake segment to string
static char *seg_to_str(seg_t *segment);

/*
 *     Here the testing starts
 *
 *     NOTE: testing assumes the snake moves are distance as
 *     snake->width and that with and height are the same
 */
int main(void) {

    // Test are dependent must implement in this order.
    test_segment_new();
    test_snake_new();
    test_snake_move();  // Move will call snake_shift.
    test_snake_append();
    //test_snake_turn_move();
    //test_snake_hit_self();

    return 0;
}


// ----------- Test methods ------------------

void test_segment_new() {
    printf("Test_segment_new\n");
    seg_t *segment = segment_new(12, 345, NULL);
    EQUALS(segment->prev, NULL);
    EQUALS(segment->x, 12);
    EQUALS(segment->y, 345);
    STR_EQUALS(seg_to_str(segment), "(12, 345)");
}

void test_snake_new() {
    printf("Test_snake_new\n");

    snake_t *snake = snake_new(100, 100, 10, 10);
    EQUALS(check_invariants(snake), true);
    EQUALS(snake->dir, RIGHT);   // Default direction
    EQUALS(snake->head, snake->last->prev);
    // Convert snake to string, h = head, t = tail (last)
    STR_EQUALS(to_str(snake), "h(100, 100) t(90, 100)");
}

void test_snake_move() {
    printf("Test_snake_move\n");
    snake_t *snake = snake_new(100, 100, 10, 10);

    snake_move(snake);
    EQUALS(check_invariants(snake), true);
    EQUALS(snake->dir, RIGHT);  // Default direction (unchanged)
    EQUALS(snake->head->x, 110);
    EQUALS(snake->last->x, 100);
    STR_EQUALS(to_str(snake), "h(110, 100) t(100, 100)");

    snake_move(snake);
    EQUALS(check_invariants(snake), true);
    STR_EQUALS(to_str(snake), "h(120, 100) t(110, 100)");
}

void test_snake_append() {
    printf("Test_snake_append\n");
    snake_t *snake = snake_new(100, 100, 10, 10);

    snake_append_segment(snake);

    EQUALS(check_invariants(snake), true);
    EQUALS(snake->length, 3);
    // Convert snake to string, s = segment
    STR_EQUALS(to_str(snake), "h(100, 100) s(90, 100) t(0, 0)");
    snake_move(snake);
    EQUALS(check_invariants(snake), true);
    STR_EQUALS(to_str(snake), "h(110, 100) s(100, 100) t(90, 100)");

    snake_append_segment(snake);
    EQUALS(check_invariants(snake), true);
    EQUALS(snake->length, 4);
    STR_EQUALS(to_str(snake), "h(110, 100) s(100, 100) s(90, 100) t(0, 0)");

    snake_move(snake);
    EQUALS(check_invariants(snake), true);
    STR_EQUALS(to_str(snake), "h(120, 100) s(110, 100) s(100, 100) t(90, 100)");
}

void test_snake_turn_move() {
    printf("Test_snake_turn_move\n");
    snake_t *snake = snake_new(100, 100, 10, 10);
    snake_append_segment(snake);
    snake_move(snake);
    STR_EQUALS(to_str(snake), "h(110, 100) s(100, 100) t(90, 100)");

    snake_turn(snake, DOWN);
    EQUALS(check_invariants(snake), true);
    snake_move(snake);
    STR_EQUALS(to_str(snake), "h(110, 110) s(110, 100) t(100, 100)"); // y increase
}

void test_snake_hit_self() {
    printf("Test_snake_hit_self\n");
    snake_t *snake = snake_new(100, 100, 10, 10);

    EQUALS(snake->length, 2);
    EQUALS(snake->dir, RIGHT);
    snake_move(snake);
    EQUALS(snake_hit_self(snake), false);

    snake_turn(snake, LEFT);    // Opposite direction
    snake_move(snake);          // If length 2 never will collide!
    EQUALS(snake_hit_self(snake), false);

    snake_append_segment(snake);
    EQUALS(snake->length, 3);   // If length > 2 possibly will collide!
    EQUALS(snake->dir, LEFT);
    snake_turn(snake, RIGHT);    // Opposite direction
    snake_move(snake);
    EQUALS(snake_hit_self(snake), true);
}



// ------------ Helper for test functions  --------------------------

bool check_invariants(snake_t *the_snake) {
    // This should always be true (i.e. invariant)
    return the_snake->head != NULL &&
           the_snake->last != NULL &&
           the_snake->head->prev == NULL;
}

// ------------  Helpers to convert to string  --------------------------

#define BUF_SIZE 32

static char *seg_to_str(seg_t *segment) {
    char buffer[BUF_SIZE];
    char x_str[12];
    sprintf(x_str, "%d", segment->x);
    char y_str[12];
    sprintf(y_str, "%d", segment->y);
    sprintf(buffer, "(%s, %s)", x_str, y_str);
    char *str = malloc(sizeof(char) * strlen(buffer) + 1);
    strcpy(str, buffer);
    return str;
}

static char *to_str(snake_t *the_snake) {
    char *seg_str[BUF_SIZE] = {0};
    int seg_str_index = 0;
    seg_t *pos = the_snake->last;
    while (pos != NULL) {
        seg_str[seg_str_index++] = seg_to_str(pos);
        pos = pos->prev;
    }
    char buffer[BUF_SIZE * BUF_SIZE] = {0};
    int i = seg_str_index - 1;
    strcat(buffer, "h");
    strcat(buffer, seg_str[i--]);
    strcat(buffer, " ");
    while (i > 0) {
        strcat(buffer, "s");
        strcat(buffer, seg_str[i--]);
        strcat(buffer, " ");
    }
    strcat(buffer, "t");
    strcat(buffer, seg_str[i]);
    char *str = malloc(sizeof(char) * strlen(buffer) + 1);
    strcpy(str, buffer);
    return str;
}

// --- Not used right now -----------
void test_to_string() {
    printf("Test_to_string\n");

    seg_t *segment = segment_new(12, 345, NULL);
    char *str = seg_to_str(segment);
    STR_EQUALS(str, "(12, 345)");

    snake_t *snake = snake_new(100, 100, 10, 10);
    str = to_str(snake);
    STR_EQUALS(str, "h(100, 100) t(90, 100)");
}

