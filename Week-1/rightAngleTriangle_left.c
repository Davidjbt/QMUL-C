#include <stdio.h>
#define N 4

void main() {
    char character = '*';

    //  Outer loop to print N lines representing the height
    for (int i = 0; i < N; i++) {
        // 1st inner loop to print the character variable (i + 1) times .
        for (int j = 0; j <= i; j++) {
            printf("%c", character);
        }
        // 2nd inner loop to print N - i - 1 number of spaces.
        for (int j = 0; j < N - i; j++) {
            printf(" ");
        }
        printf("\n");
    }
}