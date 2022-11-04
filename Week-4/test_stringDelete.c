#include <stdio.h>
#include <string.h>
#define SIZE 20

void stringDelete(char *input, int position) { // Function that will delete one character
    for (int i = position - 1; i < strlen(input); i++) { // Loops from position indicated by the inoput to the index of the last character.
        input[i] = i + 1 < strlen(input)? input[i + 1]: '\0'; // current character will obtain the value of the next character, then in the iteration the last character will be now the null terminator.
    }
}
// main function, the program will start from this function.
void main() {
    char input[SIZE];
    int position;

    printf("Type in the word and press Enter: ");
    scanf("%30s", input); // Collects the input from the user and assign it to the input variable (which is a pointer).

    printf("Type in the position of the character to be deleted: ");
    scanf("%i", &position); // Collects the input from the user and assign it to the address of the variable position.

    printf("\nOriginal word = %s", input); // Displays the original word.

    stringDelete(input, position); // call to function.

    printf("Modified word = %s", input); // Displays the modified word.
}