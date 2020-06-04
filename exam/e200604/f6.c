/*
 *  Skapa en bild av denna kod och
 *  spara i projektet (samma mapp som denna fil)
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int *do_it(int *a, int *b) {
    a--;
    b++;
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return a + 2;
}


int main(void) {


    int m[][2] = {
            {1, 2},
            {3, 4}
    };
    int a[] = {60, 70};
    int *p1 = m[1];
    int *p2 = a;         // Before

    p2 = do_it(p1, p2); // Call
    // After
    return 0;
}


// Om en funktion skriv svaret här
