#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

// Returns a pointer to string containing the int paremeter as a word.
char* getTents(int tens) {
    if (tens == 1) return "Ten";
    if (tens == 2) return "Twenty";
    if (tens == 3) return "Thirty";
    if (tens == 4) return "Fourty";
    if (tens == 5) return "Fifty";
    if (tens == 6) return "Sixty";
    if (tens == 7) return "Seventy";
    if (tens == 8) return "Eighty";
    return "Ninety";
}
// Returns a pointer to string containing the int paremeter as a word.
char* get10s(int number) {
    if (number == 11) return "Eleven";
    if (number == 12) return "Twelve";
    if (number == 13) return "Thirteen";
    if (number == 14) return "Fourteen";
    if (number == 15) return "Fifteen";
    if (number == 16) return "Sixteen";
    if (number == 17) return "Seventeen";
    if (number == 18) return "Eighteen";
    return "Nineteen";
}
// Returns a pointer to string containing the int paremeter as a word.
char* getUnits(int tens, int units) {
    char *result = malloc(6*sizeof(char));

    if (units == 0) strcpy(result,"zero");  // compare the unit parameter and then assign its worded equivalent to result pointer.
    else if (units == 1) strcpy(result,"one");
    else if (units == 2) strcpy(result,"two");
    else if (units == 3) strcpy(result,"three");
    else if (units == 4) strcpy(result,"four"); 
    else if (units == 5) strcpy(result,"five");
    else if (units == 6) strcpy(result,"six");
    else if (units == 7) strcpy(result,"seven");
    else if (units == 8) strcpy(result,"eight");
    else if (units == 9) strcpy(result,"nine");

    if (tens == 0) result[0] = toupper(result[0]); // if  the tens are 0 then the 1st letter needs to be upper case.
    
    return result;
}
// main function, the program will start from this function.
void main () {
    int number;
    int tens;
    int units;

    printf("Enter number (<100): ");
    scanf("%i", &number); // Stores the input into the number variable (by using its pointer). 

    if (0 < number && number < 100) { // Checks the input is between 1 and 99.
        tens = number / 10; // Obtains the tens by performing integer division.
        units = number % 10; // Obtains the untis by performing a modulo. 

        if (tens == 1 && units != 0) { // if the tens are 1 and units 0 then it will be a number between 11 and 19, so it does not use the typical ten unit displaying.
            printf("%s", get10s(number));
        } else if (tens > 0) { // if the tens is greater than 0 then prints its correspondent word.
            printf("%s", getTents(tens));
            if (units != 0) { // if units is not 0 then prints its correspondent unit.
                printf(" %s", getUnits(tens, units));
            }
        } else { // Else tens is 0 .
            printf("%s", units); // then just print units.
        }
    } else printf("Number not allowed");

}