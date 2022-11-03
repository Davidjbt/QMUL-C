#include <stdio.h>

// main function, the program will start from this function.
void main() {
    int spacesCounter = 0;
    int newLinesCounter = 0;
    char current = ' ';

    // We collect input until we reach the end of file, determined by the user using Ctrl + D or the end a text file.
    for (int i = 0; current != EOF; i++) {
        current = getchar(); // It collects a character from the user input.
        if (current == '\n') newLinesCounter++; // if the current character entered is equals to enter we increase the new lines counter.
        else if (current == ' ') spacesCounter++; // if the current character entered is equals to space we increase the spaces counter.
    }

    printf("\nNew lines counter: %i\n", newLinesCounter); // Displays the new lines counter.
    printf("Spaces counter: %i", spacesCounter); // Displays the spaces counter.
}