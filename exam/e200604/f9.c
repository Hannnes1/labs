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

list_t *sub_list(list_t *list, int from_index, int to_index);

int main(void) {

    return 0;
}

list_t *sub_list(list_t *list, int from_index, int to_index) {
    node_t *node = list->head;
    int i = 0;
    //Traverse to first node
    while (i++ < from_index) {
        node = node->next;
    }
    list_t *new_list = list_new(); //The sublist
    while (i++ <= to_index) {
        list_append(new_list, node->value);
        node = node->next;
    }
    return new_list;
}

list_t *list_new() {
    list_t *list = malloc(sizeof(list_t));
    list->head = NULL;
    list->len = 0;
    return list;
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