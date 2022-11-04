#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 6;
#define MIN 1;

// It gets a random value, the remainder is obtained by dividing it by the number of different values between max and min, then min is added so that the number can be in the range, then it returns this new value.
int getRandomNumber(int min, int max) {
    // srand(time(NULL)); uncomment this, so that every time the program is run it gets a different random value.
    unsigned randomNumber = rand();
    
    return min + randomNumber % (max - min + 1); // Apply modulo operation to get the remainder of the randomNumber by the difference of the max and min + 1. then add min so that the result is between min and max.
}
// main function, the program will start from this function.
void main() {
    int max = MAX;
    int min = MIN;

    int randomNumber = getRandomNumber(min, max);
    int guessedNumber;

    printf("Guess the number (%i-%i): ", min, max);
    scanf("%d", &guessedNumber); // Stores the input integer to the address in memory of guessedNumber.

    // If the guessed number and random number are equals then it prints Well done. If not then prints another message saying Wrong guess.
    guessedNumber == randomNumber? printf("\nWell done!") : printf("\nWrong guess; better luck next time!");
    
}