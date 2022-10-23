#include <stdio.h>
#include <string.h>
#define SIZE 20

void stringDelete(char *input, int position) {
    for (int i = position - 1; i < strlen(input); i++) {
        input[i] = i + 1 < strlen(input)? input[i + 1]: ' ';
    }
}

void main() {
    char input[SIZE];
    int position;

    printf("Type in the word and press Enter: ");
    fgets(input, sizeof(input), stdin);

    printf("Type in the position of the character to be deleted: ");
    scanf("%i", &position);

    printf("\nOriginal word = %s", input);

    stringDelete(input, position);

    printf("Modified word = %s", input);
}