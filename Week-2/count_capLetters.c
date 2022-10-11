#include <stdio.h>

// main function, the program will start from this function.
void main() {
    int capitalLettersCounter = 0;
    char current = ' ';

    for (int i = 0; current != EOF; i++) {
        current = getchar();
        if ('A' <= current && current <= 'Z') capitalLettersCounter++;
    }

    printf("\nCapital letters counter: %i", capitalLettersCounter);

}