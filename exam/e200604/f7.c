/*
 *  Skriv svar till fråga 7 i denna fil
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_increasing(int n_rows, int n_cols, int m[][n_cols]);

bool array_is_increasing(const int arr[], int size);

int main(void) {

    return 0;
}

bool is_increasing(int n_rows, int n_cols, int m[][n_cols]) {
    int c_arr[n_rows]; //Array for each column
    for (int r = 0; r < n_rows; r++) {
        if (!array_is_increasing(m[r], (int) (sizeof(m[r]) / sizeof(int)))) {
            return false;
        }
    }
    for (int c = 0; c < n_cols; c++) {
        for (int r = 0; r < n_rows; r++) {
            c_arr[r] = m[r][c];
        }
        if (!array_is_increasing(c_arr, n_rows)) {
            return false;
        }
    }
    return true;
}

bool array_is_increasing(const int arr[], int size) {
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}