#include <stdio.h>
#include <math.h>
#define SIZE 10

// It returns the lowest integer.
int getLowestInt(int numbers[]) {
    int lowestInt = 0;
    for (int i = 0; i < SIZE; i++) { // Loop through the array.
        if (numbers[i] < lowestInt) lowestInt = numbers[i]; // if the current number is lower than the lowest, then the current number becomes the new lowest variable.
    }

    return lowestInt;
}

// It returns the highest integer.
int getHighestInt(int numbers[]) {
    int highestInt = 0;
    for (int i = 0; i < SIZE; i++) { // Loop through the array.
        if (numbers[i] > highestInt) highestInt = numbers[i]; // If the currrent number is higher than the highest, then the current number becomes the new highest variable.
    }
    return highestInt;
}

void main() {
    int numbers[SIZE];
    
    printf("Please enter %i numbers \n", SIZE);
    for (int i = 0; i < SIZE; i++) { // We collect SIZE numbers of integers and assigning it to the one cell in the numbers array.
        printf("Please enter number: ");
        scanf("%d", &numbers[i]);
    }

    int highestInt = getHighestInt(numbers);
    int lowestInt = getLowestInt(numbers);
    int rows = 0;
    int startPosition = 0;

    int index; // Holds the index at which -1 or 1, which will considered to be the starting point.
    if (highestInt > 0) { // Checks if the highest number is greater than 0.

        if (lowestInt > 0) lowestInt = 0; // If the lowest integer is greater than 0 then we set it to 0.

        for (int i = lowestInt; i <= highestInt; i++) { // Loops from the lowest int to the highest int.
            if (i == 1) startPosition = index - 1; // Once i is equals to 1 we set the start postion to index - 1;
            
            index++;
        }
        rows = fabs(lowestInt) + highestInt; // The numbers of rows used will be to absolute value of lowest int plus highest int
    } else {
        for (int i = lowestInt; i <= 0; i++) { // Loops from the lowest int to 0.
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