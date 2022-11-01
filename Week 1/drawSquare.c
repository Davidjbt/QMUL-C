#include <stdio.h>
#define N 4

void main() {
    char character = '*';

    //  Outer loop to print N lines representing the height
    for (int i = 0; i < N; i++) {
        // Print char variable N times, when j is in the last inner iteration we go to the next line.
        for (int j = 0; j < N; j++) {
            (j < N - 1)? printf("%c", character): printf("%c\n", character);
        }
    }
}