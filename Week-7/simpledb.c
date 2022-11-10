#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
    int time_hour, time_minutes;
    double measure;
    char* fileName = "simpledb.dat";
    FILE* fpt = fopen(fileName, "a");


    printf("\nEnter the hours of the current time (0-23):");
    scanf("%i", &time_hour);

    printf("\nEnter the minutes of the current time (00-59):");
    scanf("%i", &time_minutes);

    printf("\nEnter the measurement value as a real number:"); 
    scanf("%lf", &measure);    

    fwrite(&time_hour, sizeof(time_hour), 1, fpt);
    fwrite(&time_minutes, sizeof(time_minutes), 1, fpt);
    fwrite(&measure, sizeof(measure), 1, fpt);

    printf("\nNew measurement entered successfully in simpledb.dat");
    fclose(fpt);

    return 0;
} 
