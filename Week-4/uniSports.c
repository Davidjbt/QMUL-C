#include <stdio.h>
#include <stdlib.h> // if we want to use atoi()
#include <string.h>
#define SIZE 20
#define SCORES_SIZE 30
#define TEAM "QMUL"

struct team_results { // Results from the Team's perspective
    int homeWins;
    int homeDraws;
    int homeLoses;
    int awayWins;
    int awayDraws;
    int awayLoses;
    int GF;
    int GA;
    int GD;
    int points;
};

struct score {
    char homeTeam[SIZE];
    int homeScore;
    char awayTeam[SIZE];
    int awayScore;
};

void storeScoreInputInArray(char input[SIZE], struct score *score) {
    int inputRealLength = strlen(input);
    char cleanInput[inputRealLength];

    for (int i = 0; i < inputRealLength; i++) {
        cleanInput[i] = input[i];
    }

    int i = 0;
    char *p = strtok (cleanInput, " ");
    char *array[4];

    while (p != NULL) {
        array[i++] = p;
        p = strtok (NULL, " ");
    }

    score->awayScore = atoi (array[3]);
    strcpy(score->awayTeam, array[2]);
    score->homeScore = atoi (array[1]);
    strcpy(score->homeTeam, array[0]);
}

void displayPerformanceInTable(struct score *scores, int numOfScores) {
    struct team_results results = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    // printf("\nHome team: '%s', Home score: '%i', Away team: '%s', Away score: '%i'", scores->homeTeam, scores->homeScore, scores->awayTeam, scores->awayScore); 

    for (int i = 0; i < numOfScores; i++) {
        if (strcmp(scores[i].homeTeam, TEAM) == 0) {
            if (scores[i].homeScore > scores[i].awayScore) results.homeWins++;
            else if (scores[i].homeScore == scores[i].awayScore) results.homeDraws++;
            else results.homeLoses++;
            
            results.GF += scores[i].homeScore;
            results.GA += scores[i].awayScore;
        } else {
            if (scores[i].homeScore < scores[i].awayScore) results.awayWins++;
            else if (scores[i].homeScore == scores[i].awayScore) results.awayDraws++;
            else results.awayLoses++;
            
            results.GF += scores[i].awayScore;
            results.GA += scores[i].homeScore;
        }
    }

    results.GD = results.GF - results.GA;
    results.points = 3*(results.homeWins + results.awayWins) + results.homeDraws + results.awayDraws;

    int nameLength = strlen(TEAM);

    printf("\n");
    for (int i = 0; i <= nameLength; i++) printf(" ");
    printf("Home   Away\n");
    
    for (int i = 0; i <= nameLength; i++) printf(" ");
    printf("W D L  W D L  GF GA GD  PTs\n");

    printf("%s %i %i %i  %i %i %i  %2i %2i %2i  %3i", TEAM, results.homeWins, results.homeDraws, results.homeLoses, results.awayWins, results.awayDraws, results.awayLoses, results.GF, results.GA, results.GD, results.points);
}

void main() {
    struct score scores[30];
    int numOfScores = 0; 
    char emptyArray[SIZE];

    char current = ' ';
    for (int i = 0; current != EOF; i++) {
        char scoreInString[SIZE];
        strcpy(scoreInString, emptyArray);
        current = getchar();

        for (int j = 0; current != '\n' && current != EOF; j++) {
            scoreInString[j] = current;
            current = getchar();
        }

        if (strcmp(scoreInString, emptyArray) != 0) {
            storeScoreInputInArray(scoreInString, &scores[i]);
            numOfScores++;  
        }
    }

    displayPerformanceInTable(scores, numOfScores);
}