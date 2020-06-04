/*
 *  Skriv svar till fråga 8 i denna fil
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct Point2D {
    double x;
    double y;
} point2D_t;

typedef struct Line2D {
    point2D_t p1;
    point2D_t p2;
} line2D_t;

double line_length(line2D_t *line);

int main(void) {
    line2D_t line = {3, 4, 1, 2};

    double result = line_length(&line);

    return 0;
}

double line_length(line2D_t *line) {
    return sqrt((line->p2.x - line->p1.x) * (line->p2.x - line->p1.x) +
                (line->p2.y - line->p1.y) * (line->p2.y - line->p1.y));
}