#include <stdio.h>
#include <math.h>
#define SIZE 10

// It returns the lowest integer.
int getLowestInt(int numbers[]) {
    int lowestInt = 0;

    for (int i = 0; i < SIZE; i++) {
        if (numbers[i] < lowestInt) lowestInt = numbers[i];
    }

    return lowestInt;
}

// It returns the highest integer.
int getHighestInt(int numbers[]) {
    int highestInt = 0;
    for (int i = 0; i < SIZE; i++) {
        if (numbers[i] > highestInt) highestInt = numbers[i];
    }
    return highestInt;
}

void main() {
    int numbers[SIZE];
    
    printf("Please enter %i numbers \n", SIZE);
    for (int i = 0; i < SIZE; i++) {
        printf("Please enter number: ");
        scanf("%d", &numbers[i]);
    }

    for (int i = 0; i < SIZE; i++) numbers[i] *= -1; // Every number sign is fliped. Without this the output would be reversed.

    int highestInt = getHighestInt(numbers);
    int lowestInt = getLowestInt(numbers);
    int rows = 0;
    int startPosition = 0; // hols the index at which * will be start from.
    int index; // Holds the index at which -1 or 1.

    if (highestInt > 0) {
        if (lowestInt > 0) lowestInt = 0;

        for (int i = lowestInt; i <= highestInt; i++) {
            if (i == 1) startPosition = index - 1;
            
            index++;
        }

        rows = fabs(lowestInt) + highestInt;
    } else {
        for (int i = lowestInt; i <= 0; i++) {
            startPosition = fabs(lowestInt);
            index++;
        }

        rows = startPosition;
    }

    char arr[rows][SIZE];
    // Adding '*' to the correspondent cells.
    for (int i = 0; i < SIZE; i++) {

        for (int j = 0; j < rows; j++) arr[j][i] = ' ';

        for (int j = 0; j < fabs((double)numbers[i]); j++) {

            if (numbers[i] > 0) {
                arr[startPosition + j][i] = '*';
            } else if (numbers[i] < 0){
                arr[startPosition - 1 - j][i] = '*';
            }    
        } 
    }
    
    // Printing the 2d array to something similar to a Transpose of a Matrix
    for (int i = 0; i < rows; i++) {
        printf("\n");

        for (int j = 0; j < SIZE; j++) {
            printf("%c", arr[i][j]);
        }
    }
}