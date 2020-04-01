/*
 *     The bulls and cows game
 *     See https://en.wikipedia.org/wiki/Bulls_and_Cows
 *
 *     NOTE: Only int's, if, while and functions used!
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TEST false    // If true run tests (only) else run program
#define DEBUG false    // If true, print answer

// ----------- Declare functions used in main ----------

// Get the number of digits in a number
int n_digits(int number);

// Check if a digit is in a number
bool digit_is_in(int number, int digit);

int get_digit_at_index(int number, int index);

// Generates a 4-digit random number with no repeated digits
// (digits in range 1-9)
int get_random_4digit();

bool unique_4digits(int number);

// Returns number of bulls in guessed number
int count_bulls(int guess, int answer);

// Returns number of bulls and cows in guessed number
int count_cows_and_bulls(int guess, int answer);

// Get input from player
int get_player_guess();

// Testing of functions, see far below
void test();

/*
 *
 *  Program starts
 *
 */

int main(void) {
    srand((unsigned int) time(NULL));     // Init random number generator

    if (TEST) {
        test();
    }

    int answer = get_random_4digit();
    if (DEBUG) {
        printf("Answer is %d\n", answer);
    }

    printf("Welcome to Bulls and Cows\n");
    printf("Try to guess a 4 digit number with digits 1-9\n");
    printf("and no repeating digits (-1 to abort).\n\n");
    printf("Bulls = correct digits in correct positions.\n");
    printf("Cows = correct digits.\n\n");

    bool aborted = false;
    int n_guess = 0;
    int guess = 0;
    int bulls = 0;
    int cows = 0;

    // ----- The game loop ------

    while (!aborted) {
        guess = get_player_guess();
        n_guess++;
        if (n_digits(guess) == 4) {
            if (guess == answer) {
                break;
            } else {
                bulls = count_bulls(guess, answer);
                cows = count_cows_and_bulls(guess, answer) - bulls;
                printf("There are %d bulls and %d cows", bulls, cows);
            }
        } else if(guess == -1){
            aborted = true;
        } else{
            printf("Bad guess");
        }

    }

    // --- End game loop --------

    if (aborted) {
        printf("Game aborted\n");
    } else {
        printf("Done, number was %d you needed %d guesses\n", answer, n_guess);
    }
    return 0;
}

// ------- Functions definitions --------------------------------

int n_digits(int number) {
    int count = 0;
    while (number > 0) {
        count++;
        number /= 10;
    }
    return count;
}

bool digit_is_in(int number, int digit) {
    while (number > 0) {
        if (number % 10 == digit) {
            return true;
        }
        number /= 10;
    }
    return false;
}

int get_digit_at_index(int number, int index) {
    int currentIndex = n_digits(number);
    int digit = 0;
    while (number > 0) {
        if (index == --currentIndex) {
            digit = number % 10;
        }
        number /= 10;
    }
    return digit;
}

bool unique_4digits(int number) {
    while (number > 0) {
        if (digit_is_in(number / 10, number % 10)) {
            return false;
        }
        number /= 10;
    }
    return true;
}

int get_random_4digit() {
    int number = 0;
    // For loop would be better
    int i = 0;
    while (i < 4) {
        //Generate one digit at a time to avoid any zeroes
        number += (rand() % 9 + 1) * (int) pow(10, i++);
    }
    return number;
}

int count_bulls(int guess, int answer) {
    int bulls = 0;
    while (guess > 0) {
        if (guess % 10 == answer % 10) bulls++;
        guess /= 10;
        answer /= 10;
    }
    return bulls;
}

int count_cows_and_bulls(int guess, int answer) {
    int cowsAndBulls = 0;
    while (guess > 0) {
        if (digit_is_in(answer, guess % 10)) cowsAndBulls++;
        guess /= 10;
    }
    return cowsAndBulls;
}

int get_player_guess() {
    int guess;
    printf("Guess > ");
    scanf("%d", &guess);
    return guess;
}

// ---------------- The function to do all tests --------------------

#define EQUALS(v1, v2) printf((v1) == (v2) ? "true\n" : "false\n")

void test() {

    EQUALS(n_digits(123), 3);
    EQUALS(n_digits(12345), 5);
    EQUALS(n_digits(1023945), 7);

    EQUALS(digit_is_in(2637, 2), true);
    EQUALS(!digit_is_in(2637, 4), true);

    EQUALS(get_digit_at_index(12345, 0), 1);
    EQUALS(get_digit_at_index(12345, 2), 3);
    EQUALS(get_digit_at_index(12345, 4), 5);

    EQUALS(unique_4digits(1234), true);
    EQUALS(unique_4digits(8765), true);
    EQUALS(unique_4digits(1224), false);

    printf("Random answer %d\n", get_random_4digit());
    printf("Random answer %d\n", get_random_4digit());
    printf("Random answer %d\n", get_random_4digit());

    EQUALS(count_bulls(1827, 7814), 1);
    EQUALS(count_bulls(2647, 2837), 2);

    EQUALS(count_cows_and_bulls(1827, 7813), 3);
    EQUALS(count_cows_and_bulls(2647, 2837), 2);

    exit(0);  // End program
}