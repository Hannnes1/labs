/*
 *  Skriv svar till fråga 5 i denna fil
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


// Use if you like, get numerical value of digit-char
#define NUM_VALUE(ch) (ch -'0')

void expand_string(char *expanded, const char *str);

int main(void) {

    return 0;

}

void expand_string(char *expanded, const char *str) {
    int repeat;
    char *start = strstr(str, "(") + 1; //Start of first substring
    char *end;
    char *substring;
    for (int i = 0; str[i] != 0; i++) {

        end = strstr(start, ")");

        substring = (char *) malloc(end - start + 1);
        memcpy(substring, start, end - start);
        substring[end - start] = '\0';

        start = strstr(start + strlen(substring), "(") + 1; //Move start to next substring

        repeat = NUM_VALUE(str[i]);
        while (repeat-- > 0) {
            strcat(expanded, substring);
        }
        i += (int) strlen(substring) + 2;
        free(substring);
    }
}