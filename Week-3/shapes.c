#include <stdio.h>
#include "shapes.h"

extern char character;

// By n we refer to the size parameter.
// It prints a square of size, it prints n lines with n characters.
void drawSquare(int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%c", character);
    }
    printf("\n"); // 
  }
}

// It prints a right angled left sided triangle of same base and height, it prints n lines with one more character that the previous line.
void drawRightAngleLeft(int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < i + 1; j++)
    {
      printf("%c", character);
    }
    printf("\n");
  }
}

// It prints a right angled right sided triangle of same base and height, it prints n lines with one more whitespace and one less character than the previous line.
void drawRightAngleRight(int size) {

  for (int i = 0; i < size; i++) {

    for (int k = 0; k < i; k++) {
      printf(" ");
    }

    for (int k = 0; k < size - i; k++) {
      printf("%c", character);
    }
    printf("\n");
  }
}

// It prints a palarallelogram, it prints it by using the previous functions and passing them its own parameter.
void drawParallelogram(int size) {
  drawRightAngleLeft(size);
  drawSquare(size);
  drawRightAngleRight(size);
}