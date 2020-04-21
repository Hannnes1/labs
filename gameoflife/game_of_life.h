/*
 *   (this is a header file (ending in .h).
 *
 *    *** NOTHING TO DO HERE ***
 *
 *   This file contains declarations of functions and types that other
 *   part of the program may use (no executable code).
 *   Other parts (files) may "paste" this into the
 *   the file using #include. See main.c and game_of_life.c.
 *
 *   For Game Of Life See : https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life
 *
 */
#ifndef GAME_OF_LIFE_H    // Avoid pasting it more times by ...(if not defined)
#define GAME_OF_LIFE_H    // .. define this (i.e. set it to true)

typedef enum Cell {  // The type for cells
    DEAD, ALIVE      // The values in the type
} cell_t;            // Simpler name: enum Cell is called cell_t

/*
 * Get the initial randomly ordered distribution of cells in the world.
 * Usage: See function init() in main.c.
*/
void gofl_get_world(int n_rows, int n_cols, cell_t world[][n_cols], double percent_alive);

/*
 * Calculate the next state of the world according to the rules and the
 * actual state. I.e. this will mark all cells in the world as alive or dead.
 * See function update in main.c
 */
void gofl_next_state(int n_rows, int n_cols, cell_t world[][n_cols]);

#endif // End of what should be pasted if not defined.
