/*
 *  Skriv svar till fråga 3 i denna fil
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int generate_rand(int lower, int upper);

int main(void) {
    int correct = 0; //Number of correct answers

    srand((unsigned int) time(NULL));

    for (int i = 0; i < 10; i++) {
        int n1 = generate_rand(1, 20);
        int n2 = generate_rand(1, 9);
        int input;

        printf("Är %d delbart med %d?", n1, n2);
        scanf("%d", &input);

        if (input == -1) {
            break;
        } else if (input == (n1 % n2 == 0)) {
            printf("Rätt på fråga %d\n", i + 1);
            correct++;
        } else {
            printf("Fel på fråga %d\n", i + 1);
        }
    }

    printf("Du hade rätt på %d av 10 frågor", correct);

    return 0;
}

int generate_rand(int lower, int upper) {
    //Random number between lower and upper (inclusive)
    return rand() % (upper - lower + 1) + lower;
}