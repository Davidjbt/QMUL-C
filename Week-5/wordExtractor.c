#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define SIZE 500

typedef struct list_words {
    char value[SIZE];
    struct list_words *next;
} word;

int getSpaceIndex(char word[]) {
    for (int i = 0; i < strlen(word); i++) {
        if (word[i] == ' ') return i;
    }
    return -1;
}

void deleteWhiteSpaces(char word[]) {
    // printf("Original: '%s' %llu\n", word, strlen(word));
    int spaceIndex = getSpaceIndex(word);
    while (spaceIndex != -1) {
        if (word[spaceIndex] == ' ') {
//            char *modifiedWord = (char*) malloc(strlen(word) - 1);
            char modifiedWord[strlen(word) - 1];
            for (int j = 0; j < sizeof(modifiedWord); j++) {
                modifiedWord[j] = j < spaceIndex? word[j]: word[j + 1];
            }
            modifiedWord[sizeof (modifiedWord)] = '\0';
            // printf("%i mw: '%s' %llu\n", spaceIndex, modifiedWord, sizeof modifiedWord);
            strcpy(word, modifiedWord);
            // printf("w: '%s'\n", word);
        }
        spaceIndex = getSpaceIndex(word);
    }
}

void main() {
    char input[SIZE];
    char c;
    printf("Enter list of words separated by commas: ");

    c = getchar();
    for (int i = 0; c != '\n' && c != EOF && i < sizeof(input); i++) {
        input[i] = c;
        c = getchar();
    }

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