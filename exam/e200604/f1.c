/*
 *  Skriv svar till fråga 1 i denna fil
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {

    char *str = "abcdef";   // Comments here ...
    printf("%c\n", str[0]);
    str[1] = 'X';
    printf("%s\n", str);

    return 0;
}

