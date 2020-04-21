/*
 *  Test for Game of Life
 *
 *  NOTE: Also possible to debug from here!
 */
#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
#include <memory.h>
#include <string.h>
/* 
 * This is just for testing, to be able to test static functions,
 * we pate the file here.
 * Normally NEVER include a .c file in another .c file
 */
#include "game_of_life.c"

// Macros for testing
#define EQUALS(v1, v2) printf( (v1) == (v2) ? "true\n" : "false\n")
#define ARR_EQUALS(v1, v2) printf( memcmp(v1, v2, sizeof(v1)) == 0 ? "true\n" : "false\n")

// Test function declarations
void test_get_cells();

void test_shuffle_cells();

void test_array_to_matrix();

void test_get_living_neighbours();

void test_next_state();

/*
 *     Here the testing starts
 */
int main(void) {
    srand((unsigned int) time(NULL));
    // Run one at the time until all works
    // Then possibly run all at once.
    printf("---------\n");
    test_get_cells();
    printf("---------\n");
    test_shuffle_cells();
    printf("---------\n");
    test_array_to_matrix();
    printf("---------\n");
    test_get_living_neighbours();
    printf("---------\n");
    test_next_state();
    printf("---------\n");
    exit(0);
}

// ------------ Test functions definitions -----------------
// Don't need to understand in detail

void test_next_state() {
    cell_t world[3][3] = {{ALIVE, DEAD,  DEAD},
                          {ALIVE, ALIVE, DEAD},
                          {DEAD,  ALIVE, ALIVE}};
    gofl_next_state(3, 3, world);

    // This will give true for some before implemented!
    EQUALS(world[1][1], DEAD);  // Has 4 neighbours ALIVE -> DEAD
    EQUALS(world[2][2], ALIVE); // Has 2 neighbours ALIVE -> ALIVE
    EQUALS(world[1][2], ALIVE); // Has 3 neighbours DEAD -> ALIVE
    EQUALS(world[0][2], DEAD);  // Has 1 neighbours DEAD -> DEAD
}


void test_get_living_neighbours() {
    cell_t world[3][3] = {{ALIVE, DEAD,  DEAD},
                          {ALIVE, ALIVE, DEAD},
                          {DEAD,  ALIVE, ALIVE}};
    int n_alive = get_living_neighbours(3, 3, world, 0, 0);
    EQUALS(n_alive, 2);
    n_alive = get_living_neighbours(3, 3, world, 1, 1);
    EQUALS(n_alive, 4);
}

void test_array_to_matrix() {
    cell_t cells1[4];
    get_cells(cells1, 4, 0.5);
    cell_t world1[2][2];
    array_to_matrix(2, 2, world1, cells1);

    int expected1[] = {1, 1};
    ARR_EQUALS(world1[0], expected1); // First row


    // Test a bigger one
    cell_t cells2[9];
    get_cells(cells2, 9, 0.5);
    cell_t world2[3][3];
    array_to_matrix(3, 3, world2, cells2);
    int expected3[] = {1, 1, 0};
    ARR_EQUALS(world2[1], expected3); // Mid row
}

void test_get_cells() {
    cell_t cells1[4];   // Size should be a square
    get_cells(cells1, 4, 0.5);
    int expected1[] = {1, 1, 0, 0};
    ARR_EQUALS(cells1, expected1);

    // Test a bigger one
    cell_t cells2[9];
    get_cells(cells2, 9, 0.5);
    int expected2[] = {1, 1, 1, 1, 1, 0, 0, 0, 0};
    ARR_EQUALS(cells2, expected2);
}

void test_shuffle_cells() {
    cell_t cells[9];
    get_cells(cells, 9, 0.5);
    shuffle_cells(cells, 9);
    printf("Shuffle: ");
    for (int i = 0; i < 9; i++) {
        printf("%d", cells[i]);
    }
    printf("\n");

    // Again
    shuffle_cells(cells, 9);
    printf("Shuffle: ");
    for (int i = 0; i < 9; i++) {
        printf("%d", cells[i]);
    }
    printf("\n");
}



