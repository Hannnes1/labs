/*
 *  Skriv svar till fråga 9 i denna fil
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Node {
    int value;
    struct Node *next;
} node_t;

typedef struct List {
    int len;
    node_t *head;
} list_t;

// ---- Functions you may use if you like -----

// Create a new empty list
list_t *list_new();

// Add value last in list
list_t *list_append(list_t *list, int value);

int main(void) {


    // Om ett program skriv svaret här

    return 0;
}


// Om en funktion skriv svaret här




list_t *list_new() {
    list_t *list = malloc(sizeof(list_t));
    list->head = NULL;
    list->len = 0;
}

list_t *list_append(list_t *list, int value) {
    node_t *n = malloc(sizeof(node_t));
    n->value = value;
    n->next = NULL;
    if (list->len == 0) {
        list->head = n;
    } else {
        node_t *pos = list->head;
        while (pos->next != NULL) {
            pos = pos->next;
        }
        pos->next = n;
    }
    list->len++;
}