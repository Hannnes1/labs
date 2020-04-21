#include <stdlib.h>
#include <math.h>
#include "game_of_life.h"  // Pasting the *.h file (compiler will check declaration and definition conform).


// ---------- Static functions are not visible (usable) outside this file -------

// Get an array of cell_t with some distribution of DEAD and ALIVE. Size should be a square.
static void get_cells(cell_t arr[], int size, double percent_alive);

// Randomly reorder alla elements of arr
static void shuffle_cells(cell_t arr[], int size);

// Convert array to matrix (assume n_rows * n_cols == size and matrix square)
static void array_to_matrix(int n_rows, int n_cols, cell_t matrix[][n_cols], const cell_t arr[]);

// Get number of living neighbours around position row and col
static int get_living_neighbours(int n_rows, int n_cols, const cell_t world[][n_cols], int row, int col);

//Copy values between matrices
void copy(int n_rows, int n_cols, cell_t dest[][n_cols], const cell_t src[][n_cols]);


// -------------------- Public API -----------------------------
// Implementations of functions to be used by other parts of program.
// (declarations are in .h-file)

void gofl_get_world(int n_rows, int n_cols, cell_t world[][n_cols], double percent_alive) {
    cell_t world_arr[n_rows * n_cols];
    get_cells(world_arr, n_rows * n_cols, percent_alive);
    shuffle_cells(world_arr, n_rows * n_cols);
    array_to_matrix(n_rows, n_cols, world, world_arr);
}

void gofl_next_state(int n_rows, int n_cols, cell_t world[][n_cols]) {
    cell_t tmp_world[n_rows][n_cols];
    for (int r = 0; r < n_rows; r++) {
        for (int c = 0; c < n_cols; c++) {
            int neighbours = get_living_neighbours(n_rows, n_cols, world, r, c);
            if(world[r][c] == ALIVE && (neighbours < 2 || neighbours > 3)){
                tmp_world[r][c] = DEAD;
            }else if(world[r][c] == DEAD && neighbours == 3){
                tmp_world[r][c] = ALIVE;
            }else{
                tmp_world[r][c] = world[r][c];
            }
        }

    }
    copy(n_rows, n_cols, world, tmp_world);
}

// ------------------- Static functions (only used here) ------------------------------


static void get_cells(cell_t arr[], int size, double percent_alive) {
    int number_of_one = (int) round(size * percent_alive);
    for (int i = 0; i < size; i++) {
        if (i < number_of_one) {
            arr[i] = 1;
        } else {
            arr[i] = 0;
        }
    }
}

static int get_living_neighbours(int n_rows, int n_cols, const cell_t world[][n_cols], int row, int col) {
    int sum = 0;
    for (int r = 0; r < n_rows; r++) {
        if (abs(r - row) <= 1) {
            for (int c = 0; c < n_cols; c++) {
                if (abs(c - col) <= 1 && !(row == r && col == c) && world[r][c] == ALIVE) {
                    sum++;
                }
            }
        }
    }
    return sum;
}


static void array_to_matrix(int n_rows, int n_cols, cell_t matrix[][n_cols], const cell_t arr[]) {
    int i = 0;
    for (int r = 0; r < n_rows; r++) {
        for (int c = 0; c < n_cols; c++) {
            matrix[r][c] = arr[i];
            i++;
        }

    }
}


static void shuffle_cells(cell_t arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int index = rand() % (size - i) + i;
        int num = arr[index];
        arr[index] = arr[i];
        arr[i] = num;
    }
}

void copy(int n_rows, int n_cols, cell_t dest[][n_cols], const cell_t src[][n_cols]) {
    for (int r = 0; r < n_rows; r++) {
        for (int c = 0; c < n_cols; c++) {
            dest[r][c] = src[r][c];
        }

    }
}


