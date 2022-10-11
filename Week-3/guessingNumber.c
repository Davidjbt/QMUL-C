#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 6;
#define MIN 1;

int getRandomNumber(int min, int max) {
    int randomNumber;

    srand(time(NULL));
    do  {
        randomNumber = rand();
    } while (!(min <= randomNumber && randomNumber <= max));

    return randomNumber;
}

void main() {
    int max = MAX;
    int min = MIN;

    int randomNumber = getRandomNumber(min, max);
    int guessedNumber;

    printf("Guess the number (%i-%i): ", min, max);
    scanf("%d", &guessedNumber);

    guessedNumber == randomNumber? printf("\nWell done!") : printf("\nWrong guess; better luck next time!");
    
}