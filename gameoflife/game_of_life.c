#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>
#include <time.h>
#include <stdbool.h>
#include "game_of_life.h"  // Pasting the *.h file (compiler will check declaration and definition conform).


// ---------- Static functions are not visible (usable) outside this file -------

// Get an array of cell_t with some distribution of DEAD and ALIVE. Size should be a square.
static void get_cells(cell_t arr[], int size, double percent_alive);

// Randomly reorder alla elements of arr
static void shuffle_cells(cell_t arr[], int size);

// Convert array to matrix (assume n_rows * n_cols == size and matrix square)
static void array_to_matrix(int n_rows, int n_cols, cell_t matrix[][n_cols], const cell_t arr[], int size);

// Check if row and col is inside matrix with n_rows and n_cols
static bool is_valid_location(int n_rows, int n_cols, int row, int col);

// Get number of living neighbours around position row and col
static int get_living_neighbours(int n_rows, int n_cols, const cell_t world[][n_cols], int row, int col);


// -------------------- Public API -----------------------------
// Implementations of functions to be used by other parts of program.
// (declarations are in .h-file)

void gofl_get_world(int n_rows, int n_cols, cell_t world[][n_cols], double percent_alive) {
    // TODO
}

void gofl_next_state(int n_rows, int n_cols, cell_t world[][n_cols]) {
    // TODO
}

// ------------------- Static functions (only used here) ------------------------------


static void get_cells(cell_t arr[], int size, double percent_alive) {
    // TODO
}


static bool is_valid_location(int n_rows, int n_cols, int row, int col) {
    // TODO
    return false;
}


static int get_living_neighbours(int n_rows, int n_cols, const cell_t world[][n_cols], int row, int col) {
    // TODO
    return -1;
}


static void array_to_matrix(int n_rows, int n_cols, cell_t matrix[][n_cols], const cell_t arr[], int size) {
    // TODO
}


static void shuffle_cells(cell_t arr[], int size) {
    // TODO
}


