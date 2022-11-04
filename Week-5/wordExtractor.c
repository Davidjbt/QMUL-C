#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define SIZE 500

typedef struct list_words { // Defines a structure that will use to implement a linked list. which will accesible using the word keyword.
    char value[SIZE];
    struct list_words *next;
} word;

int getSpaceIndex(char word[]) { // gets the index at which space was found. if not found returns -1;
    for (int i = 0; i < strlen(word); i++) {
        if (word[i] == ' ') return i;
    }
    return -1;
}

void deleteWhiteSpaces(char word[]) { // deletes the white spaces.
    int spaceIndex = getSpaceIndex(word);
    while (spaceIndex != -1) { // while spaceindex is found loop.
        if (word[spaceIndex] == ' ') { // if the word at space index is space then.
            char modifiedWord[strlen(word) - 1]; // create a string of size of the original word -1;
            for (int j = 0; j < sizeof(modifiedWord); j++) {
                modifiedWord[j] = j < spaceIndex? word[j]: word[j + 1]; //shift all the elements to left, removing the current white space.
            }
            modifiedWord[sizeof (modifiedWord)] = '\0'; // the last character will contain the null terminator.
            strcpy(word, modifiedWord); // copy the content of the modified word to the original word.
        }
        spaceIndex = getSpaceIndex(word); // gets the index of space, to see if there are more spaces.
    }
}
// main function, the program will start from this function.
void main() {
    char input[SIZE];
    char c;
    printf("Enter list of words separated by commas: ");

    c = getchar();
    int size = 0; 
    for (int i = 0; c != '\n' && c != EOF && i < sizeof(input); i++) { // I
        input[i] = c;
        c = getchar();
        size++;
    }
    input[size] = '\0';
    deleteWhiteSpaces(input);
    // printf("input: ->%s<- %llu\n", input, strlen(input));

    char *arr = strtok(input, ",");
    word *head, *current, *next;
    current = (word*) malloc(sizeof(word));
    assert(current != NULL);
    head = current;

    while (arr != NULL) {
        next = (word*) malloc(sizeof(word));
        assert(next != NULL);
        strcpy(current->value, arr);
        arr = strtok(NULL, ",");
        if (arr != NULL) {
            current->next = next;
            current = next;
        }
    }

    current = head;
    while (current) {
        printf("%s\n", current->value);
        current = current->next;
    }
}