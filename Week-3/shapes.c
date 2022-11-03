#include <stdio.h>
#include "shapes.h"

extern char character;

// By N I refer to the size parameter.
// It prints a square of size, it prints n lines with n characters.
void drawSquare(int size) {
  //  Outer loop to print N lines representing the height
    for (int i = 0; i < size; i++) {
        // Print char variable N times, when j is in the last inner iteration we go to the next line.
        for (int j = 0; j < size; j++) {
            (j < size - 1)? printf("%c", character): printf("%c\n", character);
        }
    }
}

// It prints a right angled left sided triangle of same base and height, it prints n lines with one more character that the previous line.
void drawRightAngleLeft(int size) {
  //  Outer loop to print N lines representing the height
    for (int i = 0; i < size; i++) {
        // 1st inner loop to print the character variable (i + 1) times .
        for (int j = 0; j <= i; j++) {
            printf("%c", character);
        }
        // 2nd inner loop to print N - i - 1 number of spaces.
        for (int j = 0; j < size - i; j++) {
            printf(" ");
        }
        printf("\n");
    }
}

// It prints a right angled right sided triangle of same base and height, it prints n lines with one more whitespace and one less character than the previous line.
void drawRightAngleRight(int size) {

  //  Outer loop to print N lines representing the height.
    for (int i = 0; i < size; i++) {
        // 1st inner loop to print i number of spaces.
        for (int j = 0; j < i; j++) {
            printf(" ");
        }
        // 2nd inner loop to print the character variable (N - i - 1) times.
        for (int j = 0; j < size - i; j++) {
            printf("%c", character);
        }
        printf("\n");
    }
}

// It prints a parallelogram, it prints it by using the previous functions and passing them its own parameter.
void drawParallelogram(int size) {
  drawRightAngleLeft(size);
  drawSquare(size);
  drawRightAngleRight(size);
}