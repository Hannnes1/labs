/*
 *  Skriv svar till fråga 4 i denna fil
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void partial_sums(int p_sums[], const int arr[], int size);

int main(void) {

    return 0;
}

void partial_sums(int p_sums[], const int arr[], int size) {
    for (int p_index = 0; p_index < size; p_index++) {
        p_sums[p_index] = 0;
        for (int arr_index = 0; arr_index <= p_index; arr_index++) {
            p_sums[p_index] += arr[arr_index];
        }
    }
}
