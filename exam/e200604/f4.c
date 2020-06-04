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
    for (int i = 0; i < size; i++) {
        p_sums[i] = 0;
        for (int j = 0; j <= i; j++) {
            p_sums[i] += arr[j];
        }
    }
}
