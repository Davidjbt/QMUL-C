#include <stdio.h>
 // main function, the program will start from this function.
void main() {
    int distance;
    char* city; // Char pointer that points to a char of characters(string).
    int flag = scanf("%i %s", &distance, city); // if scanf reads n number of inputs successfully then it will return n.
    int firstEntry = 1; // variable to flag 1st entry, 1 == TRUE

    while (flag == 2) { // if the returned value by scanf is 2 then loop.
        if (distance > 100) { // if the distance is greater than 100 (miles).
            firstEntry == 1? printf(""): printf("\n"); // if firstEntry is 1 (true) then we print nothing, if not then print new line.
            firstEntry = 0; // set firstEntry to 0 (false)
            printf("%i %s", distance, city); // print distance (from London) and the city name;
        }

        flag = scanf("%i %s", &distance, city); // gets the number of inputs successfully read in scanf, also assigns the input to their correspondet variables.
    }
}