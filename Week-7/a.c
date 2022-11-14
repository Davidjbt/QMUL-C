#include <stdio.h>
 // main function, the program will start from this function.
void main(int argc, char *argv[]) {
    FILE *fpt = fopen(argv[1], "r"); // the 2nd argument from the Command Line would be the name of the file to read. 

    if (fpt != NULL) { // if fpt is not null then proceed.
        while (!feof(fpt)) { // while the end of the file (pointed by fpt) loop.
            int distance; 
            char* name; // char pointer that will point to a string of char (string).
            fscanf(fpt , "%i %s", &distance, name); // gets input from the file, and stores the contents into the 2 variables.
            distance > 100? printf("%i %s\n", distance, name): printf(""); // if the distance is greater than 100,then precceed to print the distance and city name, if not then print nothing.
        }
        fclose(fpt); // closes the file.
    } else {
        printf("File could not be opened."); // else (fpt was NULL) print this message.
    }
}