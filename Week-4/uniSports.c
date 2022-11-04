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

struct score { // Structure that represents the score details.
    char homeTeam[SIZE];
    int homeScore;
    char awayTeam[SIZE]; 
    int awayScore;
};
// Stores the input into a score struct.
void storeScoreInputInArray(char input[SIZE], struct score *score) { 
    int inputRealLength = strlen(input);
    char cleanInput[inputRealLength]; // Creates char array of the length of the length of the input minus the null terminator.

    for (int i = 0; i < inputRealLength; i++) { //  Copy the contents of the input array into the new array.
        cleanInput[i] = input[i];
    }

    int i = 0;
    char *p = strtok (cleanInput, " "); // strtok will return a pointer that points to a string containing the 1st word separated by a space.
    char *array[4]; // array of pointers.

    while (p != NULL) { // while strtok returns a non null pointer then it keeps looping. 
        array[i++] = p; // assign the pointer created by strtok(p) to the i cell of the array, then increment i;
        p = strtok (NULL, " "); // returns next token and assigns to p.
    }
    strcpy(score->homeTeam, array[0]); // Since the input format is know, I can directly assign the correspondent datum (in the array) to a field of the score struct.
    score->homeScore = atoi (array[1]);
    strcpy(score->awayTeam, array[2]);
    score->awayScore = atoi (array[3]); 
}

// Displays the performance of the unit in a table format.
void displayPerformanceInTable(struct score *scores, int numOfScores) {
    struct team_results results = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < numOfScores; i++) { // Loop from 0 to the number of scores - 1 
        if (strcmp(scores[i].homeTeam, TEAM) == 0) { // if the home team string is the same as our macro variable then add the score to the results from a local perspective.
            if (scores[i].homeScore > scores[i].awayScore) results.homeWins++;
            else if (scores[i].homeScore == scores[i].awayScore) results.homeDraws++;
            else results.homeLoses++;
            
            results.GF += scores[i].homeScore;
            results.GA += scores[i].awayScore;
        } else { // if not then we add the results from a visitant perspective.
            if (scores[i].homeScore < scores[i].awayScore) results.awayWins++;
            else if (scores[i].homeScore == scores[i].awayScore) results.awayDraws++;
            else results.awayLoses++;
            
            results.GF += scores[i].awayScore;
            results.GA += scores[i].homeScore;
        }
    }

    results.GD = results.GF - results.GA; // Calculates the goal difference
    results.points = 3*(results.homeWins + results.awayWins) + results.homeDraws + results.awayDraws; // Calculates the points obtained,

    int nameLength = strlen(TEAM);

    printf("\n");
    for (int i = 0; i <= nameLength; i++) printf(" "); // Prints the same of number of spaces as the number of characters in team.
    printf("Home   Away\n");
    
    for (int i = 0; i <= nameLength; i++) printf(" ");
    printf("W D L  W D L  GF GA GD  PTs\n"); // print the headers.

    printf("%s %i %i %i  %i %i %i  %2i %2i %2i  %3i", TEAM, results.homeWins, results.homeDraws, results.homeLoses, results.awayWins, results.awayDraws, results.awayLoses, results.GF, results.GA, results.GD, results.points); // prints the data under its correspondet header.
}
// main function, the program will start from this function.
void main() {
    struct score scores[30]; // array of scores structure.
    int numOfScores = 0; 
    char emptyArray[SIZE]; // creates array of length SIZE.

    char current = ' ';
    for (int i = 0; current != EOF; i++) {
        char scoreInString[SIZE]; // creates array that where input will be stored.
        strcpy(scoreInString, emptyArray); // assigns value of emptyArray into new array.
        current = getchar();

        // Collects input until new line is pressed or end of file is reached.
        for (int j = 0; current != '\n' && current != EOF; j++) {
            scoreInString[j] = current;
            current = getchar();
        }

        // if the input array is not equals to the empty array.
        if (strcmp(scoreInString, emptyArray) != 0) {
            storeScoreInputInArray(scoreInString, &scores[i]); // call function.
            numOfScores++;  // increase number of scores.
        }
    }

    displayPerformanceInTable(scores, numOfScores); // call function.
}