/*
 *  Skriv svar till fråga 2 i denna fil
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main(void) {
    double x1;
    double y1;
    double x2;
    double y2;
    double x;
    double y;

    printf("Skriv in x1 och y1 > ");
    scanf("%lf %lf", &x1, &y1);

    printf("Skriv in x2 och y2 > ");
    scanf("%lf %lf", &x2, &y2);

    printf("Skriv in x för sökt y-värde > ");
    scanf("%lf", &x);

    y = y1 + (x - x1) * (y2 - y1) / (x2 - x1);

    printf("Linjär interpolation ger y = %lf", y);

    return 0;
}


// Om en funktion skriv svaret här
