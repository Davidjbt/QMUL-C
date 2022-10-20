#include <stdio.h>
#include <stdlib.h> // if we want to use atoi()

#define SIZE 20
#define SCORES_SIZE 30

struct score {
    char homeTeam[SIZE];
    int homeScore;
    char awayTeam[SIZE];
    int awayScore;
};

void emptyArray(char arr[SIZE]) {
    int i = 0;
    while (arr[i] != '\0') {
        arr[i] = ' ';
    }
}

void convertStringToScore(char scoreInString[SIZE], struct score *score) {
    char data[SIZE];
    
    int i = 0;
    int current = 0;
    while (scoreInString[current] != ' ') {
        data[i] = scoreInString[current];
        current++;
        i;
    }

    current++;
    i = 0;
    score->homeTeam = data;
    emptyArray(data);

    while (scoreInString[current] != ' ') {
        data[i] = scoreInString[current];
        current++;
        i++;
    }

    current++
    i = 0;
    score->homeScore = atoi(data);
    emptyArray(data);

    while (scoreInString[current] != ' ') {
        data[i] = scoreInString[current];
        current++;
        i++;
    }

    current++;
    i = 0;
    score->homeTeam = data;    
    emptyArray(data);

    while (scoreInString[current] != ' ') {
        data[i] = scoreInString[current];
        current++;
    }

    current++;
    i = 0;
    score->homeScore = atoi(data);
    emptyArray(data);
}

void main() {
    struct score scores[30];
    char scoreInString[SIZE];

    int numOfScores = 0; // also represent index of array
    while (scoreInString != EOF) {
        scanf("%30s", scoreInString);
        convertStringToScore(scoreInString, &scores[numOfScores]);
        numOfScores++;
    }

}