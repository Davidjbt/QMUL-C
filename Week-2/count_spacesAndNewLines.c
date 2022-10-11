#include <stdio.h>

// main function, the program will start from this function.
void main() {
    int spacesCounter = 0;
    int newLinesCounter = 0;
    char current = ' ';

    for (int i = 0; current != EOF; i++) {
        current = getchar();
        if (current == '\n') newLinesCounter++;
        else if (current == ' ') spacesCounter++;
    }

    printf("\nNew lines counter: %i\n", newLinesCounter);
    printf("Spaces counter: %i", spacesCounter);
}