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

    int highestInt = getHighestInt(numbers);
    int lowestInt = getLowestInt(numbers);
    int rows = 0;
    int startPosition = 0;

    int index; // Holds the index at which -1 or 1, which will considered to be the starting point.
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

    char breakSpace[rows];

    char arr[SIZE][rows];

    // Initializing the 2d array with whitespaces.
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < rows; j++) {
            arr[i][j] = ' ';
        }
    }

    // Adding '*' to the correspondent cells.
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < fabs((double)numbers[i]); j++) {
            if (numbers[i] > 0) {
                arr[i][startPosition + j] = '*';
            } else if (numbers[i] < 0){
                arr[i][startPosition - 1 - j] = '*';
                // printf("i:%i, j:%i  ", i, j);
            }    
        }
    }

    // printf("%s\n", breakSpace);

    // for (int i = 0; i < SIZE; i++) {
    //     for (int j = 0; j < rows; j++) {
    //             printf("%c", arr[i][j]);
    //     }
    //     printf("\n");
    // }

    printf("\n");

    // Printing the 2d array to something similar to a Transpose of a Matrix
    for (int i = rows - 1; i >= 0; i--) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c", arr[j][i]);
        }
        printf("\n");
    }
    
}