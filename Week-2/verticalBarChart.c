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
// main function, the program will start from this function.
void main() {
    int numbers[SIZE];
    
    printf("Please enter %i numbers \n", SIZE);
    for (int i = 0; i < SIZE; i++) { // We collect SIZE numbers of integers and assigning it to the one cell in the numbers array.
        printf("Please enter number: ");
        scanf("%d", &numbers[i]);
    }

    for (int i = 0; i < SIZE; i++) numbers[i] *= -1; // Every number sign is fliped. Without this the output would be reversed.

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
        startPosition = fabs(lowestInt); // 
        rows = startPosition; // This will be the there is no positive numbers, and the number of rows used will be the absolute value of the lowest int
    }
    char arr[rows][SIZE]; // Creates an array of character rows rows x SIZE columns
    // Adding '*' to the correspondent cells.
    for (int i = 0; i < SIZE; i++) { // Loops from 0 to SIZE (columns);
        for (int j = 0; j < rows; j++) arr[j][i] = ' '; // It fills the current column with spaces.
        for (int j = 0; j < fabs((double)numbers[i]); j++) { // Loops from 0 to the absolute value of the current number input.
            if (numbers[i] > 0) { // if the current number is greater than 0.
                arr[startPosition + j][i] = '*'; // Then it will start placing the '*' from the row indicated by the startPosition, then startPosition + 1, and so on.
            } else if (numbers[i] < 0) { // if the current number is less than 0.
                arr[startPosition - 1 - j][i] = '*'; // Then it will start placing the '*' from one row below the one indicated by the startPosition, then startPosition - 1, and so on.
            } 
        }
    }
    
    // Display the contents of the 2d array.
    for (int i = 0; i < rows; i++) { // Loops through all the rows
        printf("\n"); // new line to separate the rows.
        for (int j = 0; j < SIZE; j++) { // Loops through all the contents of the current rows and displays it.
            printf("%c", arr[i][j]);
        }
    }
}