#include <stdio.h>
#include <string.h>
#define SIZE 20

void stringInsert(char str[], char c, int position);

void main() {
    char str[SIZE];
    char c;
    int position;

    printf("Type in the word and press Enter: ");
    // fgets(str, sizeof(str), stdin);
    scanf("%20s", str);

    printf("Type in the the character to be inserted: ");
    scanf(" %c", &c);

    printf("Type in the position of the character to be inserted: ");
    scanf("%i", &position);

    printf("\nOriginal word = %s", str);
    stringInsert(str, c, position);
    printf("\nModified word = %s", str);
}

void stringInsert(char str[], char c, int position) {
    char modifiedWord[strlen(str)+1];

    for(int i = 0; i < sizeof(modifiedWord) + 1; i++) {
        if (i < position - 1) {
            modifiedWord[i] = str[i];
        } else if (i == position - 1){
            modifiedWord[i] = c;
        } else {
            modifiedWord[i] = str[i - 1];
        }
    }

    strcpy(str, modifiedWord);
}