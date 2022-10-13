#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 6;
#define MIN 1;

// It gets a random value, the remainder is obtained by dividing it by the number of different values between max and min, then min is added so that the number can be in the range, then it returns this new value.
int getRandomNumber(int min, int max) {
    // srand(time(NULL)); uncomment this, so that every time the program is run it gets a different random value.
    unsigned randomNumber = rand();
    
    return min + randomNumber % (max - min + 1);
}

void main() {
    int max = MAX;
    int min = MIN;

    int randomNumber = getRandomNumber(min, max);
    int guessedNumber;

    printf("Guess the number (%i-%i): ", min, max);
    scanf("%d", &guessedNumber);

    guessedNumber == randomNumber? printf("Well done!") : randomNumber > guessedNumber? printf("The correct number is bigger"): printf("The correct number is smaller");
    
}