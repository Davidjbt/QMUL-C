#include <stdio.h>

void main(int argc, char *argv[]) {
    FILE *fpt = fopen(argv[1], "r"); // the 2nd argument from the Command Line would be the name of the file to read. 

    if (fpt != NULL) {
        while (!feof(fpt)) {     
            int distance;
            char* name;
            fscanf(fpt , "%i %s", &distance, name);
            distance > 100? printf("%i %s\n", distance, name): printf("");            
        }
        fclose(fpt);
    } else {
        printf("File could not be opened.");
    }
    
}