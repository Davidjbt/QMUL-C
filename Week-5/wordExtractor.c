#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define SIZE 40

typedef struct list_words {
    char value[SIZE];
    struct list_words *next;
} word; 


void main() {
    char input[SIZE];
    
    printf("Enter list of words separated by commas: ");
    scanf("%30s", input);

    char *arr = strtok(input, ",");
    word *head, *current;
    head = NULL;
    while (arr != NULL) {
        current = (word*) malloc(sizeof(word));
        assert(current != NULL);
        strcpy(current->value, arr);
        current->next = head;
        head = current;
        arr = strtok(NULL, ",");
    }

    current = head;
    word *temp;

    // Pienso que el linkedlist va de derecha a izquierda por eso trata la primer palabra es la ultima palabra del string literal.
    //todo crear metodo para limpiar espacios.
    while (current) {
        printf("%s\n", current->value);
        temp = current;
        free(current);
        current = temp->next;
    }
    
}