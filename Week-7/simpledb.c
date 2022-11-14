#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
 // main function, the program will start from this function.
int main() {
    int time_hour, time_minutes;
    double measure;
    char* fileName = "simpledb.dat"; // char pointer that will point to the memory space where this string is.
    FILE* fpt = fopen(fileName, "a"); // opens a file with the name of the filename string, if one does not exist then one file will be created.

    printf("\nEnter the hours of the current time (0-23):");
    scanf("%i", &time_hour); // collects input and stores to the memory space pointed by the variable address.

    printf("\nEnter the minutes of the current time (00-59):");
    scanf("%i", &time_minutes); // collects input and stores to the memory space pointed by the variable address.

    printf("\nEnter the measurement value as a real number:"); 
    scanf("%lf", &measure); // collects input and stores to the memory space pointed by the variable address.

    fwrite(&time_hour, sizeof(time_hour), 1, fpt); // writes, into file pointed by the fpt (file pointer), the time hour. 
    fwrite(&time_minutes, sizeof(time_minutes), 1, fpt); // writes, into file pointed by the fpt (file pointer), the time minutes. 
    fwrite(&measure, sizeof(measure), 1, fpt); // writes, into file pointed by the fpt (file pointer), the measure. 

    printf("\nNew measurement entered successfully in simpledb.dat");
    fclose(fpt); // closes the file.

    return 0;
} 
