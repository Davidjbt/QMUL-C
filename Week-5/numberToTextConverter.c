#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

char* getTents(int tens) {
    if (tens == 1) return "Ten";
    if (tens == 2) return "Twenty";
    if (tens == 3) return "Thirty";
    if (tens == 4) return "Fourty";
    if (tens == 5) return "Fifty";
    if (tens == 6) return "Sixty";
    if (tens == 7) return "Seventy";
    if (tens == 8) return "Eighty";
    return "Ninty";
}

char* getUnits(int tens, int units) {
    char *result = malloc(6*sizeof(char));

    if (units == 0) strcpy(result,"zero"); 
    else if (units == 1) strcpy(result,"one");
    else if (units == 2) strcpy(result,"two");
    else if (units == 3) strcpy(result,"three");
    else if (units == 4) strcpy(result,"four"); 
    else if (units == 5) strcpy(result,"five");
    else if (units == 6) strcpy(result,"six");
    else if (units == 7) strcpy(result,"seven");
    else if (units == 8) strcpy(result,"eight");
    else if (units == 9) strcpy(result,"nine");

    if (tens == 0) result[0] = toupper(result[0]);
    
    return result;
}

void main () {
    int number;
    int tens;
    int units;

    printf("Enter number (<100): ");
    scanf("%i", &number);

    if (0 < number && number < 100) {
        tens = number / 10;
        units = number % 10;

        tens > 0? printf("%s ", getTents(tens)): printf("");
        printf("%s", getUnits(tens, units));
    } else printf("Number not allowed");

}