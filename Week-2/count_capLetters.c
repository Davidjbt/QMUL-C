#include <stdio.h>

// main function, the program will start from this function.
void main() {
    int capitalLettersCounter = 0;
    char current = ' ';

    // We collect input until we reach the end of file, determined by the user using Ctrl + D or the end a text file.
    for (int i = 0; current != EOF; i++) {
        current = getchar();
        // if the current character is between the ASCII value of A and Z capital then we increase the capital letter counter.
        if ('A' <= current && current <= 'Z') capitalLettersCounter++;
    }
    // Displays capital letter counter
    printf("\nCapital letters counter: %i", capitalLettersCounter);
}